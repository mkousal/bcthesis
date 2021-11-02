EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
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
L iotAirMonitoring-rescue:USB_C_Receptacle_USB2.0-Connector-iotAirMonitoring-rescue-iotAirMonitoring-rescue-iotAirMonitoring-rescue-iotAirMonitoring-rescue J?
U 1 1 617675BE
P 1300 1600
AR Path="/617675BE" Ref="J?"  Part="1" 
AR Path="/61767442/617675BE" Ref="J9"  Part="1" 
F 0 "J9" H 1300 2450 50  0000 C CNN
F 1 "USB_C_Receptacle_USB2.0" H 1300 2350 50  0000 C CNN
F 2 "Connector_USB:USB_C_Receptacle_HRO_TYPE-C-31-M-12" H 1450 1600 50  0001 C CNN
F 3 "https://www.usb.org/sites/default/files/documents/usb_type-c.zip" H 1450 1600 50  0001 C CNN
	1    1300 1600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R27
U 1 1 61768A42
P 2150 1200
F 0 "R27" V 2050 1200 50  0000 C CNN
F 1 "5k1" V 2150 1200 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 2080 1200 50  0001 C CNN
F 3 "~" H 2150 1200 50  0001 C CNN
F 4 "C25905" V 2150 1200 50  0001 C CNN "LCSC"
	1    2150 1200
	0    1    1    0   
$EndComp
$Comp
L Device:R R28
U 1 1 61768FB6
P 2150 1300
F 0 "R28" V 2250 1300 50  0000 C CNN
F 1 "5k1" V 2150 1300 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 2080 1300 50  0001 C CNN
F 3 "~" H 2150 1300 50  0001 C CNN
F 4 "C25905" V 2150 1300 50  0001 C CNN "LCSC"
	1    2150 1300
	0    1    1    0   
$EndComp
Wire Wire Line
	1900 1200 2000 1200
Wire Wire Line
	1900 1300 2000 1300
Text HLabel 2450 1200 2    50   UnSpc ~ 0
GND
Wire Wire Line
	2300 1300 2350 1300
Wire Wire Line
	2350 1300 2350 1200
Wire Wire Line
	2350 1200 2450 1200
Wire Wire Line
	2350 1200 2300 1200
Connection ~ 2350 1200
Text GLabel 2050 1000 2    50   Input ~ 0
USB_VDD
Text HLabel 1300 2600 3    50   UnSpc ~ 0
GND
Wire Wire Line
	1300 2500 1300 2550
Wire Wire Line
	1000 2500 1000 2550
Wire Wire Line
	1000 2550 1300 2550
Connection ~ 1300 2550
Wire Wire Line
	1300 2550 1300 2600
NoConn ~ 1900 2100
NoConn ~ 1900 2200
$Comp
L Device:R R29
U 1 1 6176C055
P 5500 1650
F 0 "R29" V 5293 1650 50  0000 C CNN
F 1 "100k" V 5384 1650 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 5430 1650 50  0001 C CNN
F 3 "~" H 5500 1650 50  0001 C CNN
F 4 "C25741" V 5500 1650 50  0001 C CNN "LCSC"
	1    5500 1650
	0    1    1    0   
$EndComp
$Comp
L Device:C C9
U 1 1 6176C5D5
P 5750 1900
F 0 "C9" H 5865 1946 50  0000 L CNN
F 1 "22u" H 5865 1855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5788 1750 50  0001 C CNN
F 3 "~" H 5750 1900 50  0001 C CNN
F 4 "C45783" H 5750 1900 50  0001 C CNN "LCSC"
	1    5750 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R30
U 1 1 6176C9DB
P 6100 1900
F 0 "R30" H 6170 1946 50  0000 L CNN
F 1 "100k" H 6170 1855 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 6030 1900 50  0001 C CNN
F 3 "~" H 6100 1900 50  0001 C CNN
F 4 "C25741" H 6100 1900 50  0001 C CNN "LCSC"
	1    6100 1900
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7002 Q11
U 1 1 6176CD66
P 6600 2350
F 0 "Q11" H 6805 2396 50  0000 L CNN
F 1 "2N7002" H 6805 2305 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 6800 2275 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7002.pdf" H 6600 2350 50  0001 L CNN
	1    6600 2350
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R32
U 1 1 6176FC61
P 6900 2550
F 0 "R32" H 6970 2596 50  0000 L CNN
F 1 "100k" H 6970 2505 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 6830 2550 50  0001 C CNN
F 3 "~" H 6900 2550 50  0001 C CNN
F 4 "C25741" H 6900 2550 50  0001 C CNN "LCSC"
	1    6900 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C10
U 1 1 6176FFEF
P 7300 2550
F 0 "C10" H 7415 2596 50  0000 L CNN
F 1 "22u" H 7415 2505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 7338 2400 50  0001 C CNN
F 3 "~" H 7300 2550 50  0001 C CNN
F 4 "C45783" H 7300 2550 50  0001 C CNN "LCSC"
	1    7300 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R31
U 1 1 6177040A
P 7300 2100
F 0 "R31" H 7370 2146 50  0000 L CNN
F 1 "10k" H 7370 2055 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 7230 2100 50  0001 C CNN
F 3 "~" H 7300 2100 50  0001 C CNN
F 4 "C25744" H 7300 2100 50  0001 C CNN "LCSC"
	1    7300 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 1350 5250 1350
Wire Wire Line
	5350 1650 5250 1650
Wire Wire Line
	5250 1650 5250 1350
Connection ~ 5250 1350
Wire Wire Line
	5250 1350 6300 1350
Wire Wire Line
	5650 1650 5750 1650
Wire Wire Line
	6100 1650 6100 1750
Wire Wire Line
	5750 1750 5750 1650
Connection ~ 5750 1650
Wire Wire Line
	5750 1650 6100 1650
Wire Wire Line
	6100 1650 6500 1650
Connection ~ 6100 1650
Wire Wire Line
	6500 2150 6500 1650
Wire Wire Line
	6800 2350 6900 2350
Wire Wire Line
	6900 2350 6900 2400
Wire Wire Line
	6900 2350 7300 2350
Wire Wire Line
	7300 2350 7300 2400
Connection ~ 6900 2350
Wire Wire Line
	7300 2350 7300 2250
Connection ~ 7300 2350
Text HLabel 7300 1900 1    50   Input ~ 0
3V3
Wire Wire Line
	7300 1950 7300 1900
Wire Wire Line
	6700 1350 6850 1350
Text HLabel 6500 2600 3    50   UnSpc ~ 0
GND
Text HLabel 6900 2750 3    50   UnSpc ~ 0
GND
Text HLabel 7300 2750 3    50   UnSpc ~ 0
GND
Wire Wire Line
	7300 2750 7300 2700
Wire Wire Line
	6900 2750 6900 2700
Wire Wire Line
	6500 2600 6500 2550
Text HLabel 6900 1350 2    50   Output ~ 0
VDD
Text HLabel 5000 1700 3    50   UnSpc ~ 0
GND
Wire Wire Line
	5000 1700 5000 1650
Wire Wire Line
	4800 1350 4700 1350
Text GLabel 4700 1350 0    50   Input ~ 0
USB_VDD
Wire Wire Line
	6100 2050 6100 2150
Wire Wire Line
	6100 2150 5750 2150
Wire Wire Line
	5750 2050 5750 2150
Connection ~ 5750 2150
Wire Wire Line
	5750 2150 5600 2150
Text HLabel 5600 2150 0    50   Input ~ 0
PWR_ON
Wire Wire Line
	7300 2350 7450 2350
Text HLabel 7450 2350 2    50   Input ~ 0
PWR_OFF
Text Notes 4850 1000 0    50   ~ 0
ON/OFF & REVERSE POLARITY PROTECTION
$Comp
L Device:Q_PMOS_GSD Q9
U 1 1 61779B42
P 5000 1450
F 0 "Q9" V 5342 1450 50  0000 C CNN
F 1 "AO3401A" V 5251 1450 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 5200 1550 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/lcsc/1810171817_Alpha-&-Omega-Semicon-AO3401A_C15127.pdf" H 5000 1450 50  0001 C CNN
F 4 "C15127" V 5000 1450 50  0001 C CNN "LCSC"
	1    5000 1450
	0    -1   -1   0   
$EndComp
$Comp
L Device:Q_PMOS_GSD Q10
U 1 1 6177AF3F
P 6500 1450
F 0 "Q10" V 6842 1450 50  0000 C CNN
F 1 "AO3401A" V 6751 1450 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 6700 1550 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/lcsc/1810171817_Alpha-&-Omega-Semicon-AO3401A_C15127.pdf" H 6500 1450 50  0001 C CNN
F 4 "C15127" V 6500 1450 50  0001 C CNN "LCSC"
	1    6500 1450
	0    1    -1   0   
$EndComp
Connection ~ 6500 1650
$Comp
L iotAirMonitoring:TPS54331 U4
U 1 1 6177EA26
P 3500 4700
F 0 "U4" H 3500 5075 50  0000 C CNN
F 1 "TPS54331" H 3500 4984 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 3500 4700 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/lcsc/1808272040_Texas-Instruments-TPS54331DR_C9865.pdf" H 3500 4700 50  0001 C CNN
	1    3500 4700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C11
U 1 1 6177F276
P 2850 4300
F 0 "C11" H 2965 4346 50  0000 L CNN
F 1 "100n/16V" H 2965 4255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 2888 4150 50  0001 C CNN
F 3 "~" H 2850 4300 50  0001 C CNN
F 4 "C1525" H 2850 4300 50  0001 C CNN "LCSC"
	1    2850 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 4550 2850 4550
Wire Wire Line
	2850 4550 2850 4450
$Comp
L Device:D_Schottky D5
U 1 1 617809E1
P 4100 4400
F 0 "D5" V 4054 4480 50  0000 L CNN
F 1 "SS54" V 4145 4480 50  0000 L CNN
F 2 "Diode_SMD:D_SMA" H 4100 4400 50  0001 C CNN
F 3 "~" H 4100 4400 50  0001 C CNN
F 4 "C22452" V 4100 4400 50  0001 C CNN "LCSC"
	1    4100 4400
	0    1    1    0   
$EndComp
$Comp
L Device:L L1
U 1 1 61781508
P 4400 4100
F 0 "L1" V 4590 4100 50  0000 C CNN
F 1 "4u7" V 4499 4100 50  0000 C CNN
F 2 "Inductor_SMD:L_Bourns-SRN6028" H 4400 4100 50  0001 C CNN
F 3 "https://www.tme.eu/cz/details/djnr6028-4r7-s/vykonne-tlumivky-smd/ferrocore/" H 4400 4100 50  0001 C CNN
	1    4400 4100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3850 4650 4100 4650
Wire Wire Line
	4100 4650 4100 4550
Wire Wire Line
	3850 4550 4000 4550
Wire Wire Line
	4000 4550 4000 4100
Wire Wire Line
	4100 4100 4100 4250
Wire Wire Line
	4000 4100 4100 4100
Connection ~ 4100 4100
Wire Wire Line
	4100 4100 4250 4100
Wire Wire Line
	4000 4100 2850 4100
Wire Wire Line
	2850 4100 2850 4150
Connection ~ 4000 4100
$Comp
L Device:C C12
U 1 1 61785555
P 4700 4350
F 0 "C12" H 4815 4396 50  0000 L CNN
F 1 "47u/6V3" H 4815 4305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4738 4200 50  0001 C CNN
F 3 "~" H 4700 4350 50  0001 C CNN
F 4 "C16780" H 4700 4350 50  0001 C CNN "LCSC"
	1    4700 4350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C13
U 1 1 61785B32
P 5250 4350
F 0 "C13" H 5365 4396 50  0000 L CNN
F 1 "47u/6V3" H 5365 4305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5288 4200 50  0001 C CNN
F 3 "~" H 5250 4350 50  0001 C CNN
F 4 "C16780" H 5250 4350 50  0001 C CNN "LCSC"
	1    5250 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 4100 4700 4100
Wire Wire Line
	4700 4100 4700 4200
Wire Wire Line
	4700 4100 5250 4100
Wire Wire Line
	5250 4100 5250 4200
Connection ~ 4700 4100
Text HLabel 4900 4700 3    50   UnSpc ~ 0
GND
Wire Wire Line
	4700 4500 4700 4650
Wire Wire Line
	4700 4650 4900 4650
Wire Wire Line
	5250 4650 5250 4500
Wire Wire Line
	4900 4700 4900 4650
Connection ~ 4900 4650
Wire Wire Line
	4900 4650 5250 4650
Wire Wire Line
	4100 4650 4700 4650
Connection ~ 4100 4650
Connection ~ 4700 4650
Connection ~ 5250 4100
Text HLabel 5900 4100 2    50   Output ~ 0
3V3
$Comp
L Device:C C19
U 1 1 6178FFC6
P 4100 5000
F 0 "C19" H 4215 5046 50  0000 L CNN
F 1 "1n" H 4215 4955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 4138 4850 50  0001 C CNN
F 3 "~" H 4100 5000 50  0001 C CNN
F 4 "C1523" H 4100 5000 50  0001 C CNN "LCSC"
	1    4100 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R37
U 1 1 617909D6
P 4100 5350
F 0 "R37" H 4170 5396 50  0000 L CNN
F 1 "30k" H 4170 5305 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4030 5350 50  0001 C CNN
F 3 "~" H 4100 5350 50  0001 C CNN
F 4 "C22984" H 4100 5350 50  0001 C CNN "LCSC"
	1    4100 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 5200 4100 5150
Wire Wire Line
	3850 4750 4100 4750
Wire Wire Line
	4100 4750 4100 4850
$Comp
L Device:C C20
U 1 1 617936BF
P 4450 5000
F 0 "C20" H 4565 5046 50  0000 L CNN
F 1 "47p" H 4565 4955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 4488 4850 50  0001 C CNN
F 3 "~" H 4450 5000 50  0001 C CNN
F 4 "C1567" H 4450 5000 50  0001 C CNN "LCSC"
	1    4450 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 4750 4450 4750
Wire Wire Line
	4450 4750 4450 4850
Connection ~ 4100 4750
Wire Wire Line
	4100 5500 4100 5550
Wire Wire Line
	4100 5550 4300 5550
Wire Wire Line
	4450 5550 4450 5150
Text HLabel 4300 5600 3    50   UnSpc ~ 0
GND
Wire Wire Line
	4300 5600 4300 5550
Connection ~ 4300 5550
Wire Wire Line
	4300 5550 4450 5550
$Comp
L Device:R R34
U 1 1 61798780
P 5800 4400
F 0 "R34" H 5870 4446 50  0000 L CNN
F 1 "15k" H 5870 4355 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 5730 4400 50  0001 C CNN
F 3 "~" H 5800 4400 50  0001 C CNN
F 4 "C25756" H 5800 4400 50  0001 C CNN "LCSC"
	1    5800 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R35
U 1 1 617988E3
P 5800 4800
F 0 "R35" H 5870 4846 50  0000 L CNN
F 1 "4k7" H 5870 4755 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 5730 4800 50  0001 C CNN
F 3 "~" H 5800 4800 50  0001 C CNN
F 4 "C25900" H 5800 4800 50  0001 C CNN "LCSC"
	1    5800 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 4250 5800 4100
Wire Wire Line
	5800 4550 5800 4600
Text HLabel 5800 5000 3    50   UnSpc ~ 0
GND
Wire Wire Line
	5800 5000 5800 4950
Wire Wire Line
	5800 4600 5700 4600
Connection ~ 5800 4600
Wire Wire Line
	5800 4600 5800 4650
Text GLabel 5700 4600 0    50   Input ~ 0
VSNS
Text GLabel 3900 4950 3    50   Input ~ 0
VSNS
Wire Wire Line
	3850 4850 3900 4850
Wire Wire Line
	3900 4850 3900 4950
$Comp
L Device:C C21
U 1 1 617A7390
P 3050 5100
F 0 "C21" H 3165 5146 50  0000 L CNN
F 1 "10n" H 3165 5055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 3088 4950 50  0001 C CNN
F 3 "~" H 3050 5100 50  0001 C CNN
F 4 "C15195" H 3050 5100 50  0001 C CNN "LCSC"
	1    3050 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 4950 3050 4850
Wire Wire Line
	3050 4850 3150 4850
Text HLabel 3050 5300 3    50   UnSpc ~ 0
GND
Wire Wire Line
	3050 5300 3050 5250
$Comp
L Device:C C16
U 1 1 617B0F30
P 1300 4900
F 0 "C16" H 1415 4946 50  0000 L CNN
F 1 "4u7/16V" H 1415 4855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1338 4750 50  0001 C CNN
F 3 "~" H 1300 4900 50  0001 C CNN
F 4 "C19666" H 1300 4900 50  0001 C CNN "LCSC"
	1    1300 4900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C17
U 1 1 617B1A49
P 1850 4900
F 0 "C17" H 1965 4946 50  0000 L CNN
F 1 "4u7/16V" H 1965 4855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1888 4750 50  0001 C CNN
F 3 "~" H 1850 4900 50  0001 C CNN
F 4 "C19666" H 1850 4900 50  0001 C CNN "LCSC"
	1    1850 4900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C18
U 1 1 617B1DB1
P 2400 4900
F 0 "C18" H 2515 4946 50  0000 L CNN
F 1 "10n/50V" H 2515 4855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 2438 4750 50  0001 C CNN
F 3 "~" H 2400 4900 50  0001 C CNN
F 4 "C15195" H 2400 4900 50  0001 C CNN "LCSC"
	1    2400 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 4750 1300 4650
Wire Wire Line
	1300 4650 1850 4650
Wire Wire Line
	2400 4750 2400 4650
Wire Wire Line
	1850 4750 1850 4650
Connection ~ 1850 4650
Wire Wire Line
	1850 4650 2400 4650
Wire Wire Line
	1300 5050 1300 5100
Wire Wire Line
	1300 5100 1850 5100
Wire Wire Line
	1850 5100 1850 5050
Wire Wire Line
	1850 5100 2400 5100
Wire Wire Line
	2400 5100 2400 5050
Connection ~ 1850 5100
Text HLabel 1850 5150 3    50   UnSpc ~ 0
GND
Wire Wire Line
	1850 5150 1850 5100
Text HLabel 1200 4650 0    50   UnSpc ~ 0
VDD
Wire Wire Line
	1200 4650 1300 4650
Connection ~ 1300 4650
Text Notes 3050 4000 0    50   ~ 0
STEPDOWN 5V -> 3V3
Text Notes 5950 4600 0    50   ~ 0
R_down=(R_up*Vref)/(Vout-Vref)
Connection ~ 5800 4100
Wire Wire Line
	5800 4100 5900 4100
Wire Wire Line
	5250 4100 5800 4100
Text Notes 3150 5400 0    50   ~ 0
SLOW START\n10nF -> 4ms
NoConn ~ 3150 4750
Wire Wire Line
	2400 4650 3150 4650
Connection ~ 2400 4650
$Comp
L Connector_Generic:Conn_01x02 J10
U 1 1 617E973D
P 3150 1600
F 0 "J10" H 3230 1592 50  0000 L CNN
F 1 "USB_DATA" H 3230 1501 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3150 1600 50  0001 C CNN
F 3 "~" H 3150 1600 50  0001 C CNN
	1    3150 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 1500 1950 1500
Wire Wire Line
	1950 1500 1950 1600
Wire Wire Line
	1950 1600 1900 1600
Wire Wire Line
	1950 1600 2150 1600
Connection ~ 1950 1600
Wire Wire Line
	1900 1800 1950 1800
Wire Wire Line
	1950 1800 1950 1700
Wire Wire Line
	1950 1700 1900 1700
Wire Wire Line
	1950 1700 2150 1700
Connection ~ 1950 1700
$Comp
L Regulator_Linear:AMS1117-3.3 U3
U 1 1 6177D292
P 8800 4100
F 0 "U3" H 8800 4342 50  0000 C CNN
F 1 "AMS1117-3.3" H 8800 4251 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 8800 4300 50  0001 C CNN
F 3 "http://www.advanced-monolithic.com/pdf/ds1117.pdf" H 8900 3850 50  0001 C CNN
F 4 "C6186" H 8800 4100 50  0001 C CNN "LCSC"
	1    8800 4100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C15
U 1 1 6177EB7E
P 9200 4350
F 0 "C15" H 9315 4396 50  0000 L CNN
F 1 "22u" H 9315 4305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 9238 4200 50  0001 C CNN
F 3 "~" H 9200 4350 50  0001 C CNN
F 4 "C45783" H 9200 4350 50  0001 C CNN "LCSC"
	1    9200 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9100 4100 9200 4100
Wire Wire Line
	9200 4100 9200 4200
Wire Wire Line
	9200 4100 9300 4100
Connection ~ 9200 4100
Text HLabel 9300 4100 2    50   Output ~ 0
3V3_L
Text HLabel 8800 4700 3    50   UnSpc ~ 0
GND
Wire Wire Line
	8800 4400 8800 4550
Wire Wire Line
	8800 4550 9200 4550
Wire Wire Line
	9200 4550 9200 4500
Connection ~ 8800 4550
Wire Wire Line
	8800 4550 8800 4700
$Comp
L Device:C C14
U 1 1 6178E735
P 8300 4350
F 0 "C14" H 8415 4396 50  0000 L CNN
F 1 "22u" H 8415 4305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 8338 4200 50  0001 C CNN
F 3 "~" H 8300 4350 50  0001 C CNN
F 4 "C45783" H 8300 4350 50  0001 C CNN "LCSC"
	1    8300 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 4200 8300 4100
Wire Wire Line
	8300 4100 8500 4100
Wire Wire Line
	8300 4500 8300 4550
Wire Wire Line
	8300 4550 8800 4550
Connection ~ 8300 4100
Text HLabel 7300 4100 0    50   Output ~ 0
VDD
Text Notes 8200 3750 0    50   ~ 0
3V3 LDO FOR ANALOG SENSORS
Text HLabel 8250 4900 2    50   Input ~ 0
LDO_EN
Wire Wire Line
	7300 4100 7400 4100
Wire Wire Line
	7900 4100 8200 4100
$Comp
L power:PWR_FLAG #FLG01
U 1 1 617C9D81
P 6850 1350
F 0 "#FLG01" H 6850 1425 50  0001 C CNN
F 1 "PWR_FLAG" H 6850 1523 50  0000 C CNN
F 2 "" H 6850 1350 50  0001 C CNN
F 3 "~" H 6850 1350 50  0001 C CNN
	1    6850 1350
	1    0    0    -1  
$EndComp
Connection ~ 6850 1350
Wire Wire Line
	6850 1350 6900 1350
$Comp
L Transistor_FET:2N7002 Q13
U 1 1 617CFE10
P 7800 4900
F 0 "Q13" H 8005 4946 50  0000 L CNN
F 1 "2N7002" H 8005 4855 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8000 4825 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7002.pdf" H 7800 4900 50  0001 L CNN
	1    7800 4900
	-1   0    0    -1  
$EndComp
$Comp
L Device:Q_PMOS_GSD Q12
U 1 1 617D359D
P 7700 4200
F 0 "Q12" V 8042 4200 50  0000 C CNN
F 1 "AO3401A" V 7951 4200 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 7900 4300 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/lcsc/1810171817_Alpha-&-Omega-Semicon-AO3401A_C15127.pdf" H 7700 4200 50  0001 C CNN
F 4 "C15127" V 7700 4200 50  0001 C CNN "LCSC"
	1    7700 4200
	0    1    -1   0   
$EndComp
$Comp
L Device:R R33
U 1 1 617D5008
P 7400 4350
F 0 "R33" H 7470 4396 50  0000 L CNN
F 1 "100k" H 7470 4305 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 7330 4350 50  0001 C CNN
F 3 "~" H 7400 4350 50  0001 C CNN
F 4 "C25741" H 7400 4350 50  0001 C CNN "LCSC"
	1    7400 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 4100 7400 4200
Connection ~ 7400 4100
Wire Wire Line
	7400 4100 7500 4100
Text HLabel 7700 5400 3    50   UnSpc ~ 0
GND
$Comp
L Device:R R36
U 1 1 617E233B
P 8050 5100
F 0 "R36" H 8120 5146 50  0000 L CNN
F 1 "100k" H 8120 5055 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 7980 5100 50  0001 C CNN
F 3 "~" H 8050 5100 50  0001 C CNN
F 4 "C25741" H 8050 5100 50  0001 C CNN "LCSC"
	1    8050 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 4900 8050 4900
Wire Wire Line
	8050 4900 8050 4950
Wire Wire Line
	7700 4400 7700 4600
Wire Wire Line
	7400 4500 7400 4600
Wire Wire Line
	7400 4600 7700 4600
Connection ~ 7700 4600
Wire Wire Line
	7700 4600 7700 4700
Wire Wire Line
	7700 5100 7700 5300
Wire Wire Line
	7700 5300 8050 5300
Wire Wire Line
	8050 5300 8050 5250
Connection ~ 7700 5300
Wire Wire Line
	7700 5300 7700 5400
Wire Wire Line
	8050 4900 8250 4900
Connection ~ 8050 4900
$Comp
L iotAirMonitoring-rescue:USB_B_Micro-Connector-iotAirMonitoring-rescue J12
U 1 1 617FE196
P 1050 3450
AR Path="/617FE196" Ref="J12"  Part="1" 
AR Path="/61767442/617FE196" Ref="J12"  Part="1" 
F 0 "J12" H 1107 3917 50  0000 C CNN
F 1 "USB_B_Micro" H 1107 3826 50  0000 C CNN
F 2 "Connector_USB:USB_Micro-B_Amphenol_10118194_Horizontal" H 1200 3400 50  0001 C CNN
F 3 "https://www.tme.eu/Document/224991b12752feb77f9b8261a1cec430/10118194-0001LF.pdf" H 1200 3400 50  0001 C CNN
	1    1050 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 3250 1500 3250
Text GLabel 1500 3250 2    50   Input ~ 0
USB_VDD
Text HLabel 1050 3950 3    50   UnSpc ~ 0
GND
Wire Wire Line
	950  3850 950  3900
Wire Wire Line
	950  3900 1050 3900
Wire Wire Line
	1050 3900 1050 3850
Wire Wire Line
	1050 3900 1050 3950
Connection ~ 1050 3900
Text GLabel 2150 1600 2    50   Input ~ 0
D-
Text GLabel 2150 1700 2    50   Input ~ 0
D+
Text GLabel 2950 1600 0    50   Input ~ 0
D-
Text GLabel 2950 1700 0    50   Input ~ 0
D+
Text GLabel 1400 3450 2    50   Input ~ 0
D+
Text GLabel 1400 3550 2    50   Input ~ 0
D-
Wire Wire Line
	1350 3450 1400 3450
Wire Wire Line
	1400 3550 1350 3550
NoConn ~ 1350 3650
$Comp
L Connector_Generic:Conn_01x02 J11
U 1 1 6182FBA0
P 3500 2200
F 0 "J11" H 3418 1875 50  0000 C CNN
F 1 "PWR" H 3418 1966 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3500 2200 50  0001 C CNN
F 3 "~" H 3500 2200 50  0001 C CNN
	1    3500 2200
	1    0    0    1   
$EndComp
Wire Wire Line
	3300 2100 3250 2100
Wire Wire Line
	3300 2200 3250 2200
Text GLabel 3250 2100 0    50   Input ~ 0
USB_VDD
Text HLabel 3250 2200 0    50   Input ~ 0
GND
Wire Wire Line
	1900 1000 2050 1000
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 6188BF27
P 8200 4100
F 0 "#FLG0102" H 8200 4175 50  0001 C CNN
F 1 "PWR_FLAG" H 8200 4273 50  0000 C CNN
F 2 "" H 8200 4100 50  0001 C CNN
F 3 "~" H 8200 4100 50  0001 C CNN
	1    8200 4100
	1    0    0    -1  
$EndComp
Connection ~ 8200 4100
Wire Wire Line
	8200 4100 8300 4100
$Comp
L Connector_Generic:Conn_02x02_Counter_Clockwise J14
U 1 1 6182A26C
P 3450 2950
F 0 "J14" H 3500 3167 50  0000 C CNN
F 1 "Battery_shield" H 3500 3076 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x02_P2.54mm_Vertical" H 3450 2950 50  0001 C CNN
F 3 "~" H 3450 2950 50  0001 C CNN
	1    3450 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 2950 3200 2950
Wire Wire Line
	3200 2950 3200 3050
Wire Wire Line
	3200 3050 3250 3050
Wire Wire Line
	3750 2950 3800 2950
Wire Wire Line
	3800 2950 3800 3050
Wire Wire Line
	3800 3050 3750 3050
Text GLabel 3150 2950 0    50   Input ~ 0
USB_VDD
Wire Wire Line
	3150 2950 3200 2950
Connection ~ 3200 2950
Text HLabel 3850 2950 2    50   Input ~ 0
GND
Wire Wire Line
	3800 2950 3850 2950
Connection ~ 3800 2950
$Comp
L Device:R R?
U 1 1 6188824F
P 9200 1400
AR Path="/6188824F" Ref="R?"  Part="1" 
AR Path="/61767442/6188824F" Ref="R1"  Part="1" 
F 0 "R1" H 9270 1446 50  0000 L CNN
F 1 "R" H 9270 1355 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 9130 1400 50  0001 C CNN
F 3 "~" H 9200 1400 50  0001 C CNN
	1    9200 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 61888255
P 9200 1800
AR Path="/61888255" Ref="R?"  Part="1" 
AR Path="/61767442/61888255" Ref="R2"  Part="1" 
F 0 "R2" H 9270 1846 50  0000 L CNN
F 1 "R" H 9270 1755 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 9130 1800 50  0001 C CNN
F 3 "~" H 9200 1800 50  0001 C CNN
	1    9200 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 1550 9200 1600
Wire Wire Line
	9200 1600 9300 1600
Connection ~ 9200 1600
Wire Wire Line
	9200 1600 9200 1650
Wire Wire Line
	9200 1250 9200 1200
Wire Wire Line
	9200 1950 9200 2000
Text Notes 9350 1200 0    50   ~ 0
Optional voltage\ndivider for Vin
Text GLabel 9200 1200 1    50   Input ~ 0
USB_VDD
Text GLabel 9200 2000 3    50   Input ~ 0
GND
Text HLabel 9300 1600 2    50   Output ~ 0
ADC_VIN
$EndSCHEMATC
