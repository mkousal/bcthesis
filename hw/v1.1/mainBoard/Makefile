all: build

build: boards/main.kicad_pcb boards/sensors.kicad_pcb
	mkdir -p gerber/main
	mkdir -p gerber/sensors
	kikit fab jlcpcb --no-drc boards/sensors.kicad_pcb gerber/sensors
	kikit fab jlcpcb --no-drc boards/main.kicad_pcb gerber/main

separate: mainBoard.kicad_pcb
	mkdir -p boards
	kikit separate --source 'rectangle; tlx: 60mm; tly: 27mm; brx: 120mm; bry: 152mm' mainBoard.kicad_pcb boards/sensors.kicad_pcb
	kikit separate --source 'annotation; ref: B2' mainBoard.kicad_pcb boards/main.kicad_pcb

clean:
	rm -r gerber