all: build

build: mainBoard.kicad_pcb
	mkdir -p gerber
	kikit fab jlcpcb mainBoard.kicad_pcb gerber

clean:
	rm -r gerber