all: build

build: batteryCharger.kicad_pcb
	mkdir -p gerber
	kikit fab jlcpcb batteryCharger.kicad_pcb gerber

clean:
	rm -r gerber