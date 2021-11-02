all: build

build: iotAirMonitoring.kicad_pcb iotAirMonitoring.sch
	mkdir -p gerber
	kikit fab jlcpcb --assembly --schematic iotAirMonitoring.sch \
		--ignore AE1,H1,H2,H3,H4,J1,J2,J3,J4,J5,J6,J7,J8,J9,J10,J11,J12,J13,J14,J15,JP1,JP2,JP3,L2,C22,C23,SW1,SW2,SW3,SW4,R1,R2,R21,S1,TP1,TP2,TP3,TP4,TP5,TP6,TP7,TP8,TP9,U5,D1,D2,D3,D4,U2,L1 \
		--missingError \
		iotAirMonitoring.kicad_pcb gerber

clean:
	rm -r gerber