EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 3
Title "iotAirMonitoring"
Date ""
Rev "v0.1"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_01x04 J?
U 1 1 61D6FFBE
P 1500 3300
AR Path="/61D6FFBE" Ref="J?"  Part="1" 
AR Path="/61D2D467/61D6FFBE" Ref="J3"  Part="1" 
F 0 "J3" H 1418 2875 50  0000 C CNN
F 1 "SHT40" H 1418 2966 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 1500 3300 50  0001 C CNN
F 3 "~" H 1500 3300 50  0001 C CNN
	1    1500 3300
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x05 J?
U 1 1 61D6FFC4
P 1500 4000
AR Path="/61D6FFC4" Ref="J?"  Part="1" 
AR Path="/61D2D467/61D6FFC4" Ref="J5"  Part="1" 
F 0 "J5" H 1418 3575 50  0000 C CNN
F 1 "ML8511" H 1418 3666 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x05_P2.54mm_Vertical" H 1500 4000 50  0001 C CNN
F 3 "~" H 1500 4000 50  0001 C CNN
	1    1500 4000
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J?
U 1 1 61D6FFCA
P 1500 5050
AR Path="/61D6FFCA" Ref="J?"  Part="1" 
AR Path="/61D2D467/61D6FFCA" Ref="J7"  Part="1" 
F 0 "J7" H 1418 4425 50  0000 C CNN
F 1 "BMP388" H 1418 4516 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Vertical" H 1500 5050 50  0001 C CNN
F 3 "~" H 1500 5050 50  0001 C CNN
	1    1500 5050
	-1   0    0    1   
$EndComp
Wire Wire Line
	1700 3100 1800 3100
Wire Wire Line
	1800 3200 1700 3200
Wire Wire Line
	1700 3300 1800 3300
Wire Wire Line
	1800 3400 1700 3400
$Comp
L Connector_Generic:Conn_01x08 J?
U 1 1 61D6FFD6
P 1500 6800
AR Path="/61D6FFD6" Ref="J?"  Part="1" 
AR Path="/61D2D467/61D6FFD6" Ref="J8"  Part="1" 
F 0 "J8" H 1418 6175 50  0000 C CNN
F 1 "PMS5003" H 1418 6266 50  0000 C CNN
F 2 "Connector_Molex:Molex_PicoBlade_53048-0810_1x08_P1.25mm_Horizontal" H 1500 6800 50  0001 C CNN
F 3 "https://www.tme.eu/Document/48db6664d1820be2d7958b46105daf6e/mx53048.pdf" H 1500 6800 50  0001 C CNN
	1    1500 6800
	-1   0    0    1   
$EndComp
Wire Wire Line
	1700 7000 1800 7000
Wire Wire Line
	1700 6900 2250 6900
Wire Wire Line
	1700 6800 1800 6800
Wire Wire Line
	1700 6700 1800 6700
Wire Wire Line
	1700 6600 1900 6600
NoConn ~ 1700 6400
NoConn ~ 1700 6500
Wire Wire Line
	1800 3800 1700 3800
NoConn ~ 1700 3900
Wire Wire Line
	1800 4000 1700 4000
Wire Wire Line
	1700 4100 1800 4100
Text Notes 1250 4000 0    50   ~ 0
5V
Text Notes 1250 3250 0    50   ~ 0
3V3
Wire Wire Line
	1700 4650 1800 4650
NoConn ~ 1700 4750
Wire Wire Line
	1800 4850 1700 4850
Wire Wire Line
	1800 4950 1700 4950
NoConn ~ 1700 5050
Wire Wire Line
	1800 5150 1700 5150
NoConn ~ 1700 5250
Wire Wire Line
	1700 5350 1800 5350
Text Notes 1550 5600 0    50   ~ 0
BMP_INT\n-> interrupt
Text Notes 1300 5050 0    50   ~ 0
5V
$Comp
L Transistor_FET:2N7002 Q?
U 1 1 61D6FFFF
P 8750 3850
AR Path="/61D6FFFF" Ref="Q?"  Part="1" 
AR Path="/61D2D467/61D6FFFF" Ref="Q6"  Part="1" 
F 0 "Q6" V 9092 3850 50  0000 C CNN
F 1 "2N7002" V 9001 3850 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8950 3775 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/NDS7002A-D.PDF" H 8750 3850 50  0001 L CNN
F 4 "C8545" V 8750 3850 50  0001 C CNN "LCSC"
	1    8750 3850
	-1   0    0    -1  
$EndComp
$Comp
L Device:Q_PMOS_GSD Q?
U 1 1 61D70007
P 8650 3300
AR Path="/61767442/61D70007" Ref="Q?"  Part="1" 
AR Path="/61D70007" Ref="Q?"  Part="1" 
AR Path="/61D2D467/61D70007" Ref="Q5"  Part="1" 
F 0 "Q5" V 8992 3300 50  0000 C CNN
F 1 "AO3401A" V 8901 3300 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8850 3400 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/lcsc/1810171817_Alpha-&-Omega-Semicon-AO3401A_C15127.pdf" H 8650 3300 50  0001 C CNN
F 4 "C15127" V 8650 3300 50  0001 C CNN "LCSC"
	1    8650 3300
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 61D7000E
P 8950 3400
AR Path="/61767442/61D7000E" Ref="R?"  Part="1" 
AR Path="/61D7000E" Ref="R?"  Part="1" 
AR Path="/61D2D467/61D7000E" Ref="R22"  Part="1" 
F 0 "R22" H 9020 3446 50  0000 L CNN
F 1 "100k" H 9020 3355 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 8880 3400 50  0001 C CNN
F 3 "~" H 8950 3400 50  0001 C CNN
F 4 "C25741" H 8950 3400 50  0001 C CNN "LCSC"
	1    8950 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 3200 8950 3200
Wire Wire Line
	8950 3250 8950 3200
Connection ~ 8950 3200
Wire Wire Line
	8950 3200 9100 3200
Wire Wire Line
	8650 3500 8650 3600
Wire Wire Line
	8650 3600 8950 3600
Wire Wire Line
	8950 3600 8950 3550
Connection ~ 8650 3600
Wire Wire Line
	8650 3600 8650 3650
$Comp
L Device:R R?
U 1 1 61D7001E
P 9000 4050
AR Path="/61767442/61D7001E" Ref="R?"  Part="1" 
AR Path="/61D7001E" Ref="R?"  Part="1" 
AR Path="/61D2D467/61D7001E" Ref="R25"  Part="1" 
F 0 "R25" H 9070 4096 50  0000 L CNN
F 1 "100k" H 9070 4005 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 8930 4050 50  0001 C CNN
F 3 "~" H 9000 4050 50  0001 C CNN
F 4 "C25741" H 9000 4050 50  0001 C CNN "LCSC"
	1    9000 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8950 3850 9000 3850
Wire Wire Line
	9000 3850 9000 3900
Wire Wire Line
	9000 3850 9250 3850
Connection ~ 9000 3850
Wire Wire Line
	8650 4050 8650 4250
Wire Wire Line
	8650 4250 9000 4250
Wire Wire Line
	9000 4250 9000 4200
Wire Wire Line
	8350 3200 8450 3200
Text GLabel 8350 3200 0    50   Input ~ 0
SEN_VDD
Text GLabel 1800 3800 2    50   Input ~ 0
SEN_VDD
Text GLabel 1800 4650 2    50   Input ~ 0
SEN_VDD
Wire Wire Line
	9750 2150 9550 2150
$Comp
L Device:R R?
U 1 1 61D70032
P 9400 3850
AR Path="/61D70032" Ref="R?"  Part="1" 
AR Path="/61D2D467/61D70032" Ref="R23"  Part="1" 
F 0 "R23" V 9350 4100 50  0000 C CNN
F 1 "220" V 9400 3850 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 9330 3850 50  0001 C CNN
F 3 "~" H 9400 3850 50  0001 C CNN
F 4 "C25091" V 9400 3850 50  0001 C CNN "LCSC"
	1    9400 3850
	0    1    1    0   
$EndComp
Wire Wire Line
	9550 3850 9750 3850
$Comp
L Device:R R?
U 1 1 61D70040
P 1900 6400
AR Path="/61767442/61D70040" Ref="R?"  Part="1" 
AR Path="/61D70040" Ref="R?"  Part="1" 
AR Path="/61D2D467/61D70040" Ref="R39"  Part="1" 
F 0 "R39" H 1970 6446 50  0000 L CNN
F 1 "100k" H 1970 6355 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 1830 6400 50  0001 C CNN
F 3 "~" H 1900 6400 50  0001 C CNN
F 4 "C25741" H 1900 6400 50  0001 C CNN "LCSC"
	1    1900 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 6550 1900 6600
Wire Wire Line
	1900 6200 1900 6250
$Comp
L Device:R R?
U 1 1 61D7004A
P 2250 6400
AR Path="/61767442/61D7004A" Ref="R?"  Part="1" 
AR Path="/61D7004A" Ref="R?"  Part="1" 
AR Path="/61D2D467/61D7004A" Ref="R40"  Part="1" 
F 0 "R40" H 2320 6446 50  0000 L CNN
F 1 "100k" H 2320 6355 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 2180 6400 50  0001 C CNN
F 3 "~" H 2250 6400 50  0001 C CNN
F 4 "C25741" H 2250 6400 50  0001 C CNN "LCSC"
	1    2250 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 6550 2250 6900
Wire Wire Line
	2250 6200 2250 6250
$Comp
L Device:R R?
U 1 1 61D70054
P 2450 4000
AR Path="/61767442/61D70054" Ref="R?"  Part="1" 
AR Path="/61D70054" Ref="R?"  Part="1" 
AR Path="/61D2D467/61D70054" Ref="R24"  Part="1" 
F 0 "R24" H 2520 4046 50  0000 L CNN
F 1 "100k" H 2520 3955 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 2380 4000 50  0001 C CNN
F 3 "~" H 2450 4000 50  0001 C CNN
F 4 "C25741" H 2450 4000 50  0001 C CNN "LCSC"
	1    2450 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 3800 2450 3850
Wire Wire Line
	2450 4200 2450 4150
Text Label 2150 4200 0    50   ~ 0
UV_EN
Wire Wire Line
	1700 4200 2450 4200
Text Label 1750 6600 0    50   ~ 0
RST
Text Label 2000 6900 0    50   ~ 0
SET
$Comp
L Device:R R?
U 1 1 61D70066
P 9400 2150
AR Path="/61D70066" Ref="R?"  Part="1" 
AR Path="/61D2D467/61D70066" Ref="R18"  Part="1" 
F 0 "R18" V 9350 2400 50  0000 C CNN
F 1 "220" V 9400 2150 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 9330 2150 50  0001 C CNN
F 3 "~" H 9400 2150 50  0001 C CNN
F 4 "C25091" V 9400 2150 50  0001 C CNN "LCSC"
	1    9400 2150
	0    1    1    0   
$EndComp
Text GLabel 1800 2200 2    50   Input ~ 0
SEN_VDD
Wire Wire Line
	9000 2550 9000 2500
Wire Wire Line
	8650 2550 9000 2550
Wire Wire Line
	8650 2350 8650 2550
Connection ~ 9000 2150
Wire Wire Line
	9000 2150 9250 2150
Wire Wire Line
	9000 2150 9000 2200
Wire Wire Line
	8950 2150 9000 2150
$Comp
L Device:R R?
U 1 1 61D7007A
P 9000 2350
AR Path="/61767442/61D7007A" Ref="R?"  Part="1" 
AR Path="/61D7007A" Ref="R?"  Part="1" 
AR Path="/61D2D467/61D7007A" Ref="R20"  Part="1" 
F 0 "R20" H 9070 2396 50  0000 L CNN
F 1 "100k" H 9070 2305 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 8930 2350 50  0001 C CNN
F 3 "~" H 9000 2350 50  0001 C CNN
F 4 "C25741" H 9000 2350 50  0001 C CNN "LCSC"
	1    9000 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	8650 1900 8650 1950
Connection ~ 8650 1900
Wire Wire Line
	8950 1900 8950 1850
Wire Wire Line
	8650 1900 8950 1900
Wire Wire Line
	8650 1800 8650 1900
Wire Wire Line
	8950 1500 9100 1500
Connection ~ 8950 1500
Wire Wire Line
	8950 1550 8950 1500
Wire Wire Line
	8850 1500 8950 1500
$Comp
L Device:R R?
U 1 1 61D7008A
P 8950 1700
AR Path="/61767442/61D7008A" Ref="R?"  Part="1" 
AR Path="/61D7008A" Ref="R?"  Part="1" 
AR Path="/61D2D467/61D7008A" Ref="R17"  Part="1" 
F 0 "R17" H 9020 1746 50  0000 L CNN
F 1 "100k" H 9020 1655 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 8880 1700 50  0001 C CNN
F 3 "~" H 8950 1700 50  0001 C CNN
F 4 "C25741" H 8950 1700 50  0001 C CNN "LCSC"
	1    8950 1700
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_PMOS_GSD Q?
U 1 1 61D70091
P 8650 1600
AR Path="/61767442/61D70091" Ref="Q?"  Part="1" 
AR Path="/61D70091" Ref="Q?"  Part="1" 
AR Path="/61D2D467/61D70091" Ref="Q3"  Part="1" 
F 0 "Q3" V 8992 1600 50  0000 C CNN
F 1 "AO3401A" V 8901 1600 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8850 1700 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/lcsc/1810171817_Alpha-&-Omega-Semicon-AO3401A_C15127.pdf" H 8650 1600 50  0001 C CNN
F 4 "C15127" V 8650 1600 50  0001 C CNN "LCSC"
	1    8650 1600
	0    -1   -1   0   
$EndComp
$Comp
L Transistor_FET:2N7002 Q?
U 1 1 61D70097
P 8750 2150
AR Path="/61D70097" Ref="Q?"  Part="1" 
AR Path="/61D2D467/61D70097" Ref="Q4"  Part="1" 
F 0 "Q4" V 9092 2150 50  0000 C CNN
F 1 "2N7002" V 9001 2150 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8950 2075 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/NDS7002A-D.PDF" H 8750 2150 50  0001 L CNN
F 4 "C8545" V 8750 2150 50  0001 C CNN "LCSC"
	1    8750 2150
	-1   0    0    -1  
$EndComp
Text Notes 1300 2400 0    50   ~ 0
5V
Text Notes 1150 1700 0    50   ~ 0
5V\n150mA
Wire Wire Line
	1800 2200 1700 2200
NoConn ~ 1700 2300
Wire Wire Line
	1700 2400 1800 2400
Wire Wire Line
	1700 2500 1800 2500
Wire Wire Line
	1700 2600 1800 2600
Wire Wire Line
	1700 1500 1800 1500
NoConn ~ 1700 1600
Wire Wire Line
	1700 1700 1800 1700
$Comp
L Connector_Generic:Conn_01x04 J?
U 1 1 61D700AB
P 1500 1700
AR Path="/61D700AB" Ref="J?"  Part="1" 
AR Path="/61D2D467/61D700AB" Ref="J1"  Part="1" 
F 0 "J1" H 1418 1275 50  0000 C CNN
F 1 "MQ-7" H 1418 1366 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 1500 1700 50  0001 C CNN
F 3 "~" H 1500 1700 50  0001 C CNN
	1    1500 1700
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x05 J?
U 1 1 61D700B1
P 1500 2400
AR Path="/61D700B1" Ref="J?"  Part="1" 
AR Path="/61D2D467/61D700B1" Ref="J2"  Part="1" 
F 0 "J2" H 1418 1975 50  0000 C CNN
F 1 "VEML7700" H 1418 2066 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x05_P2.54mm_Vertical" H 1500 2400 50  0001 C CNN
F 3 "~" H 1500 2400 50  0001 C CNN
	1    1500 2400
	-1   0    0    1   
$EndComp
$Comp
L Transistor_FET:2N7002 Q?
U 1 1 61D91F73
P 8750 5600
AR Path="/61D91F73" Ref="Q?"  Part="1" 
AR Path="/61D2D467/61D91F73" Ref="Q8"  Part="1" 
F 0 "Q8" V 9092 5600 50  0000 C CNN
F 1 "2N7002" V 9001 5600 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8950 5525 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/NDS7002A-D.PDF" H 8750 5600 50  0001 L CNN
F 4 "C8545" V 8750 5600 50  0001 C CNN "LCSC"
	1    8750 5600
	-1   0    0    -1  
$EndComp
$Comp
L Device:Q_PMOS_GSD Q?
U 1 1 61D91F7B
P 8650 5050
AR Path="/61767442/61D91F7B" Ref="Q?"  Part="1" 
AR Path="/61D91F7B" Ref="Q?"  Part="1" 
AR Path="/61D2D467/61D91F7B" Ref="Q7"  Part="1" 
F 0 "Q7" V 8992 5050 50  0000 C CNN
F 1 "AO3401A" V 8901 5050 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8850 5150 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/lcsc/1810171817_Alpha-&-Omega-Semicon-AO3401A_C15127.pdf" H 8650 5050 50  0001 C CNN
F 4 "C15127" V 8650 5050 50  0001 C CNN "LCSC"
	1    8650 5050
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 61D91F82
P 8950 5150
AR Path="/61767442/61D91F82" Ref="R?"  Part="1" 
AR Path="/61D91F82" Ref="R?"  Part="1" 
AR Path="/61D2D467/61D91F82" Ref="R26"  Part="1" 
F 0 "R26" H 9020 5196 50  0000 L CNN
F 1 "100k" H 9020 5105 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 8880 5150 50  0001 C CNN
F 3 "~" H 8950 5150 50  0001 C CNN
F 4 "C25741" H 8950 5150 50  0001 C CNN "LCSC"
	1    8950 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 4950 8950 4950
Wire Wire Line
	8950 5000 8950 4950
Connection ~ 8950 4950
Wire Wire Line
	8950 4950 9100 4950
Wire Wire Line
	8650 5250 8650 5350
Wire Wire Line
	8650 5350 8950 5350
Wire Wire Line
	8950 5350 8950 5300
Connection ~ 8650 5350
Wire Wire Line
	8650 5350 8650 5400
$Comp
L Device:R R?
U 1 1 61D91F92
P 9000 5800
AR Path="/61767442/61D91F92" Ref="R?"  Part="1" 
AR Path="/61D91F92" Ref="R?"  Part="1" 
AR Path="/61D2D467/61D91F92" Ref="R38"  Part="1" 
F 0 "R38" H 9070 5846 50  0000 L CNN
F 1 "100k" H 9070 5755 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 8930 5800 50  0001 C CNN
F 3 "~" H 9000 5800 50  0001 C CNN
F 4 "C25741" H 9000 5800 50  0001 C CNN "LCSC"
	1    9000 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	8950 5600 9000 5600
Wire Wire Line
	9000 5600 9000 5650
Wire Wire Line
	9000 5600 9250 5600
Connection ~ 9000 5600
Wire Wire Line
	8650 5800 8650 6000
Wire Wire Line
	8650 6000 9000 6000
Wire Wire Line
	9000 6000 9000 5950
Text Notes 1300 6800 0    50   ~ 0
5V
Wire Wire Line
	1700 1800 1800 1800
Text GLabel 1800 1800 2    50   Input ~ 0
MQ-7_VDD
Wire Wire Line
	8450 1500 8400 1500
Text GLabel 8400 1500 0    50   Input ~ 0
MQ-7_VDD
Wire Wire Line
	8450 4950 8400 4950
Wire Wire Line
	1700 7100 1800 7100
Text GLabel 1800 7100 2    50   Input ~ 0
DUST_VDD
Text GLabel 8400 4950 0    50   Input ~ 0
DUST_VDD
Text HLabel 1800 6800 2    50   Input ~ 0
TX1
Text HLabel 1800 6700 2    50   Input ~ 0
RX1
Text HLabel 1800 7000 2    50   Input ~ 0
GND
Text HLabel 2250 6200 1    50   Input ~ 0
3V3
Text HLabel 1900 6200 1    50   Input ~ 0
3V3
Text HLabel 1800 5350 2    50   Input ~ 0
BMP_INT
Text HLabel 1800 5150 2    50   Input ~ 0
SDA
Text HLabel 1800 4950 2    50   Input ~ 0
SCL
Text HLabel 1800 4850 2    50   Input ~ 0
GND
Text HLabel 2450 3800 1    50   Input ~ 0
3V3
Text HLabel 1800 4000 2    50   Input ~ 0
GND
Text HLabel 1800 4100 2    50   Input ~ 0
ADC_1
Text HLabel 1800 3400 2    50   Input ~ 0
3V3
Text HLabel 1800 3300 2    50   Input ~ 0
GND
Text HLabel 1800 3200 2    50   Input ~ 0
SDA
Text HLabel 1800 3100 2    50   Input ~ 0
SCL
Text HLabel 1800 2600 2    50   Input ~ 0
SDA
Text HLabel 1800 2500 2    50   Input ~ 0
SCL
Text HLabel 1800 2400 2    50   Input ~ 0
GND
Text HLabel 1800 1500 2    50   Input ~ 0
ADC_0
Text HLabel 1800 1700 2    50   Input ~ 0
GND
Text HLabel 8650 6050 3    50   Input ~ 0
GND
Wire Wire Line
	8650 6000 8650 6050
Connection ~ 8650 6000
Text HLabel 9250 5600 2    50   Input ~ 0
PMS_EN
Text HLabel 9100 4950 2    50   Input ~ 0
VDD
Text HLabel 9100 3200 2    50   Input ~ 0
VDD
Text HLabel 8650 4300 3    50   Input ~ 0
GND
Wire Wire Line
	8650 4250 8650 4300
Connection ~ 8650 4250
Text HLabel 9750 3850 2    50   Input ~ 0
SEN_VDD_EN
Text HLabel 8650 2600 3    50   Input ~ 0
GND
Wire Wire Line
	8650 2600 8650 2550
Connection ~ 8650 2550
Text HLabel 9750 2150 2    50   Input ~ 0
MQ_EN
Text HLabel 9100 1500 2    50   Input ~ 0
VDD
$Comp
L Connector_Generic:Conn_01x05 J13
U 1 1 61F8EE98
P 3350 6750
F 0 "J13" H 3268 7167 50  0000 C CNN
F 1 "PM1003" H 3268 7076 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 3350 6750 50  0001 C CNN
F 3 "~" H 3350 6750 50  0001 C CNN
	1    3350 6750
	-1   0    0    -1  
$EndComp
Text HLabel 3700 6550 2    50   Input ~ 0
GND
Wire Wire Line
	3550 6950 3700 6950
Wire Wire Line
	3550 6750 3700 6750
Wire Wire Line
	3550 6550 3700 6550
Text GLabel 3700 6750 2    50   Input ~ 0
DUST_VDD
NoConn ~ 3550 6850
Wire Wire Line
	3550 6650 3700 6650
Text GLabel 3700 6650 2    50   Input ~ 0
PM_TX
Text GLabel 3700 6950 2    50   Input ~ 0
PM_RX
$Comp
L Transistor_FET:2N7002 Q?
U 1 1 61FB4A66
P 5550 5800
AR Path="/61FB4A66" Ref="Q?"  Part="1" 
AR Path="/61D2D467/61FB4A66" Ref="Q16"  Part="1" 
F 0 "Q16" V 5892 5800 50  0000 C CNN
F 1 "2N7002" V 5801 5800 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 5750 5725 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/NDS7002A-D.PDF" H 5550 5800 50  0001 L CNN
F 4 "C8545" V 5550 5800 50  0001 C CNN "LCSC"
	1    5550 5800
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 61FCF4B6
P 5150 5650
AR Path="/61767442/61FCF4B6" Ref="R?"  Part="1" 
AR Path="/61FCF4B6" Ref="R?"  Part="1" 
AR Path="/61D2D467/61FCF4B6" Ref="R43"  Part="1" 
F 0 "R43" H 5220 5696 50  0000 L CNN
F 1 "100k" H 5220 5605 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 5080 5650 50  0001 C CNN
F 3 "~" H 5150 5650 50  0001 C CNN
F 4 "C25741" H 5150 5650 50  0001 C CNN "LCSC"
	1    5150 5650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 61FD00E9
P 5850 5650
AR Path="/61767442/61FD00E9" Ref="R?"  Part="1" 
AR Path="/61FD00E9" Ref="R?"  Part="1" 
AR Path="/61D2D467/61FD00E9" Ref="R44"  Part="1" 
F 0 "R44" H 5920 5696 50  0000 L CNN
F 1 "100k" H 5920 5605 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 5780 5650 50  0001 C CNN
F 3 "~" H 5850 5650 50  0001 C CNN
F 4 "C25741" H 5850 5650 50  0001 C CNN "LCSC"
	1    5850 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 5900 5850 5900
Wire Wire Line
	5850 5900 5850 5800
Wire Wire Line
	5550 5600 5550 5450
Wire Wire Line
	5550 5450 5150 5450
Wire Wire Line
	5150 5450 5150 5500
Wire Wire Line
	5150 5800 5150 5900
Wire Wire Line
	5150 5900 5350 5900
Wire Wire Line
	5150 5900 5050 5900
Connection ~ 5150 5900
Wire Wire Line
	5150 5450 5150 5400
Connection ~ 5150 5450
Wire Wire Line
	5850 5500 5850 5400
Connection ~ 5850 5900
Wire Wire Line
	5850 5900 5950 5900
$Comp
L Transistor_FET:2N7002 Q?
U 1 1 61FFFBBD
P 5550 7050
AR Path="/61FFFBBD" Ref="Q?"  Part="1" 
AR Path="/61D2D467/61FFFBBD" Ref="Q17"  Part="1" 
F 0 "Q17" V 5892 7050 50  0000 C CNN
F 1 "2N7002" V 5801 7050 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 5750 6975 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/NDS7002A-D.PDF" H 5550 7050 50  0001 L CNN
F 4 "C8545" V 5550 7050 50  0001 C CNN "LCSC"
	1    5550 7050
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 61FFFBC4
P 5150 6900
AR Path="/61767442/61FFFBC4" Ref="R?"  Part="1" 
AR Path="/61FFFBC4" Ref="R?"  Part="1" 
AR Path="/61D2D467/61FFFBC4" Ref="R45"  Part="1" 
F 0 "R45" H 5220 6946 50  0000 L CNN
F 1 "100k" H 5220 6855 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 5080 6900 50  0001 C CNN
F 3 "~" H 5150 6900 50  0001 C CNN
F 4 "C25741" H 5150 6900 50  0001 C CNN "LCSC"
	1    5150 6900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 61FFFBCB
P 5850 6900
AR Path="/61767442/61FFFBCB" Ref="R?"  Part="1" 
AR Path="/61FFFBCB" Ref="R?"  Part="1" 
AR Path="/61D2D467/61FFFBCB" Ref="R46"  Part="1" 
F 0 "R46" H 5920 6946 50  0000 L CNN
F 1 "100k" H 5920 6855 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 5780 6900 50  0001 C CNN
F 3 "~" H 5850 6900 50  0001 C CNN
F 4 "C25741" H 5850 6900 50  0001 C CNN "LCSC"
	1    5850 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 7150 5850 7150
Wire Wire Line
	5850 7150 5850 7050
Wire Wire Line
	5550 6850 5550 6700
Wire Wire Line
	5550 6700 5150 6700
Wire Wire Line
	5150 6700 5150 6750
Wire Wire Line
	5150 7050 5150 7150
Wire Wire Line
	5150 7150 5350 7150
Wire Wire Line
	5150 7150 5050 7150
Connection ~ 5150 7150
Wire Wire Line
	5150 6700 5150 6650
Connection ~ 5150 6700
Wire Wire Line
	5850 6750 5850 6650
Connection ~ 5850 7150
Wire Wire Line
	5850 7150 5950 7150
Text HLabel 5150 6650 1    50   Input ~ 0
3V3
Text HLabel 5150 5400 1    50   Input ~ 0
3V3
Text GLabel 5850 6650 1    50   Input ~ 0
DUST_VDD
Text GLabel 5850 5400 1    50   Input ~ 0
DUST_VDD
Text GLabel 5950 5900 2    50   Input ~ 0
PM_TX
Text GLabel 5950 7150 2    50   Input ~ 0
PM_RX
Text HLabel 5050 5900 0    50   Input ~ 0
TX1
Text HLabel 5050 7150 0    50   Input ~ 0
RX1
$EndSCHEMATC
