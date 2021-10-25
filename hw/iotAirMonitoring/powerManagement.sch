EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:USB_C_Receptacle_USB2.0 J1
U 1 1 617675BE
P 1500 2000
F 0 "J1" H 1500 2850 50  0000 C CNN
F 1 "USB_C_Receptacle_USB2.0" H 1500 2750 50  0000 C CNN
F 2 "" H 1650 2000 50  0001 C CNN
F 3 "https://www.usb.org/sites/default/files/documents/usb_type-c.zip" H 1650 2000 50  0001 C CNN
	1    1500 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 1400 2200 1400
$Comp
L Device:R R1
U 1 1 61768A42
P 2350 1600
F 0 "R1" V 2250 1600 50  0000 C CNN
F 1 "5k1" V 2350 1600 50  0000 C CNN
F 2 "" V 2280 1600 50  0001 C CNN
F 3 "~" H 2350 1600 50  0001 C CNN
	1    2350 1600
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 61768FB6
P 2350 1700
F 0 "R2" V 2450 1700 50  0000 C CNN
F 1 "5k1" V 2350 1700 50  0000 C CNN
F 2 "" V 2280 1700 50  0001 C CNN
F 3 "~" H 2350 1700 50  0001 C CNN
	1    2350 1700
	0    1    1    0   
$EndComp
Wire Wire Line
	2100 1600 2200 1600
Wire Wire Line
	2100 1700 2200 1700
Text HLabel 2650 1600 2    50   UnSpc ~ 0
GND
Wire Wire Line
	2500 1700 2550 1700
Wire Wire Line
	2550 1700 2550 1600
Wire Wire Line
	2550 1600 2650 1600
Wire Wire Line
	2550 1600 2500 1600
Connection ~ 2550 1600
Text GLabel 2250 1400 2    50   Input ~ 0
USB_C_VDD
$Comp
L power:PWR_FLAG #FLG01
U 1 1 61769B61
P 2200 1400
F 0 "#FLG01" H 2200 1475 50  0001 C CNN
F 1 "PWR_FLAG" H 2200 1573 50  0000 C CNN
F 2 "" H 2200 1400 50  0001 C CNN
F 3 "~" H 2200 1400 50  0001 C CNN
	1    2200 1400
	1    0    0    -1  
$EndComp
Connection ~ 2200 1400
Wire Wire Line
	2200 1400 2250 1400
Text HLabel 1500 3000 3    50   UnSpc ~ 0
GND
Wire Wire Line
	1500 2900 1500 2950
Wire Wire Line
	1200 2900 1200 2950
Wire Wire Line
	1200 2950 1500 2950
Connection ~ 1500 2950
Wire Wire Line
	1500 2950 1500 3000
NoConn ~ 2100 2500
NoConn ~ 2100 2600
$Comp
L Device:R R3
U 1 1 6176C055
P 5500 1650
F 0 "R3" V 5293 1650 50  0000 C CNN
F 1 "100k" V 5384 1650 50  0000 C CNN
F 2 "" V 5430 1650 50  0001 C CNN
F 3 "~" H 5500 1650 50  0001 C CNN
	1    5500 1650
	0    1    1    0   
$EndComp
$Comp
L Device:C C1
U 1 1 6176C5D5
P 5750 1900
F 0 "C1" H 5865 1946 50  0000 L CNN
F 1 "22u" H 5865 1855 50  0000 L CNN
F 2 "" H 5788 1750 50  0001 C CNN
F 3 "~" H 5750 1900 50  0001 C CNN
	1    5750 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 6176C9DB
P 6100 1900
F 0 "R4" H 6170 1946 50  0000 L CNN
F 1 "100k" H 6170 1855 50  0000 L CNN
F 2 "" V 6030 1900 50  0001 C CNN
F 3 "~" H 6100 1900 50  0001 C CNN
	1    6100 1900
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7002 Q3
U 1 1 6176CD66
P 6600 2350
F 0 "Q3" H 6805 2396 50  0000 L CNN
F 1 "2N7002" H 6805 2305 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 6800 2275 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7002.pdf" H 6600 2350 50  0001 L CNN
	1    6600 2350
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 6176FC61
P 6900 2550
F 0 "R5" H 6970 2596 50  0000 L CNN
F 1 "100k" H 6970 2505 50  0000 L CNN
F 2 "" V 6830 2550 50  0001 C CNN
F 3 "~" H 6900 2550 50  0001 C CNN
	1    6900 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 6176FFEF
P 7300 2550
F 0 "C2" H 7415 2596 50  0000 L CNN
F 1 "22u" H 7415 2505 50  0000 L CNN
F 2 "" H 7338 2400 50  0001 C CNN
F 3 "~" H 7300 2550 50  0001 C CNN
	1    7300 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 6177040A
P 7300 2100
F 0 "R6" H 7370 2146 50  0000 L CNN
F 1 "10k" H 7370 2055 50  0000 L CNN
F 2 "" V 7230 2100 50  0001 C CNN
F 3 "~" H 7300 2100 50  0001 C CNN
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
	6700 1350 6900 1350
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
USB_C_VDD
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
L Device:Q_PMOS_GSD Q?
U 1 1 61779B42
P 5000 1450
F 0 "Q?" V 5342 1450 50  0000 C CNN
F 1 "AO3401A" V 5251 1450 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 5200 1550 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/lcsc/1810171817_Alpha-&-Omega-Semicon-AO3401A_C15127.pdf" H 5000 1450 50  0001 C CNN
F 4 "C15127" V 5000 1450 50  0001 C CNN "LCSC"
	1    5000 1450
	0    -1   -1   0   
$EndComp
$Comp
L Device:Q_PMOS_GSD Q?
U 1 1 6177AF3F
P 6500 1450
F 0 "Q?" V 6842 1450 50  0000 C CNN
F 1 "AO3401A" V 6751 1450 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 6700 1550 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/lcsc/1810171817_Alpha-&-Omega-Semicon-AO3401A_C15127.pdf" H 6500 1450 50  0001 C CNN
F 4 "C15127" V 6500 1450 50  0001 C CNN "LCSC"
	1    6500 1450
	0    -1   -1   0   
$EndComp
Connection ~ 6500 1650
$Comp
L iotAirMonitoring:TPS54331 U?
U 1 1 6177EA26
P 3500 4700
F 0 "U?" H 3500 5075 50  0000 C CNN
F 1 "TPS54331" H 3500 4984 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 3500 4700 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/lcsc/1808272040_Texas-Instruments-TPS54331DR_C9865.pdf" H 3500 4700 50  0001 C CNN
	1    3500 4700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 6177F276
P 3000 4300
F 0 "C?" H 3115 4346 50  0000 L CNN
F 1 "100n" H 3115 4255 50  0000 L CNN
F 2 "" H 3038 4150 50  0001 C CNN
F 3 "~" H 3000 4300 50  0001 C CNN
	1    3000 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 4550 3000 4550
Wire Wire Line
	3000 4550 3000 4450
$Comp
L Device:D_Schottky D?
U 1 1 617809E1
P 4100 4400
F 0 "D?" V 4054 4480 50  0000 L CNN
F 1 "D_Schottky" V 4145 4480 50  0000 L CNN
F 2 "" H 4100 4400 50  0001 C CNN
F 3 "~" H 4100 4400 50  0001 C CNN
	1    4100 4400
	0    1    1    0   
$EndComp
$Comp
L Device:L L?
U 1 1 61781508
P 4400 4100
F 0 "L?" V 4590 4100 50  0000 C CNN
F 1 "L" V 4499 4100 50  0000 C CNN
F 2 "" H 4400 4100 50  0001 C CNN
F 3 "~" H 4400 4100 50  0001 C CNN
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
	4000 4100 3000 4100
Wire Wire Line
	3000 4100 3000 4150
Connection ~ 4000 4100
$Comp
L Device:C C?
U 1 1 61785555
P 4700 4350
F 0 "C?" H 4815 4396 50  0000 L CNN
F 1 "47u" H 4815 4305 50  0000 L CNN
F 2 "" H 4738 4200 50  0001 C CNN
F 3 "~" H 4700 4350 50  0001 C CNN
	1    4700 4350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 61785B32
P 5050 4350
F 0 "C?" H 5165 4396 50  0000 L CNN
F 1 "47u" H 5165 4305 50  0000 L CNN
F 2 "" H 5088 4200 50  0001 C CNN
F 3 "~" H 5050 4350 50  0001 C CNN
	1    5050 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 4100 4700 4100
Wire Wire Line
	4700 4100 4700 4200
Wire Wire Line
	4700 4100 5050 4100
Wire Wire Line
	5050 4100 5050 4200
Connection ~ 4700 4100
Text HLabel 4900 4700 3    50   UnSpc ~ 0
GND
Wire Wire Line
	4700 4500 4700 4650
Wire Wire Line
	4700 4650 4900 4650
Wire Wire Line
	5050 4650 5050 4500
Wire Wire Line
	4900 4700 4900 4650
Connection ~ 4900 4650
Wire Wire Line
	4900 4650 5050 4650
Wire Wire Line
	4100 4650 4700 4650
Connection ~ 4100 4650
Connection ~ 4700 4650
Wire Wire Line
	5050 4100 5600 4100
Connection ~ 5050 4100
Text HLabel 5900 4100 2    50   Output ~ 0
3V3
$Comp
L Device:C C?
U 1 1 6178FFC6
P 4100 5000
F 0 "C?" H 4215 5046 50  0000 L CNN
F 1 "C" H 4215 4955 50  0000 L CNN
F 2 "" H 4138 4850 50  0001 C CNN
F 3 "~" H 4100 5000 50  0001 C CNN
	1    4100 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 617909D6
P 4100 5350
F 0 "R?" H 4170 5396 50  0000 L CNN
F 1 "R" H 4170 5305 50  0000 L CNN
F 2 "" V 4030 5350 50  0001 C CNN
F 3 "~" H 4100 5350 50  0001 C CNN
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
L Device:C C?
U 1 1 617936BF
P 4450 5000
F 0 "C?" H 4565 5046 50  0000 L CNN
F 1 "C" H 4565 4955 50  0000 L CNN
F 2 "" H 4488 4850 50  0001 C CNN
F 3 "~" H 4450 5000 50  0001 C CNN
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
L Device:R R?
U 1 1 61798780
P 5600 4400
F 0 "R?" H 5670 4446 50  0000 L CNN
F 1 "R" H 5670 4355 50  0000 L CNN
F 2 "" V 5530 4400 50  0001 C CNN
F 3 "~" H 5600 4400 50  0001 C CNN
	1    5600 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 617988E3
P 5600 4800
F 0 "R?" H 5670 4846 50  0000 L CNN
F 1 "R" H 5670 4755 50  0000 L CNN
F 2 "" V 5530 4800 50  0001 C CNN
F 3 "~" H 5600 4800 50  0001 C CNN
	1    5600 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 4250 5600 4100
Connection ~ 5600 4100
Wire Wire Line
	5600 4100 5900 4100
Wire Wire Line
	5600 4550 5600 4600
Text HLabel 5600 5000 3    50   UnSpc ~ 0
GND
Wire Wire Line
	5600 5000 5600 4950
Wire Wire Line
	5600 4600 5500 4600
Connection ~ 5600 4600
Wire Wire Line
	5600 4600 5600 4650
Text GLabel 5500 4600 0    50   Input ~ 0
VSNS
Text GLabel 3900 4950 3    50   Input ~ 0
VSNS
Wire Wire Line
	3850 4850 3900 4850
Wire Wire Line
	3900 4850 3900 4950
$Comp
L Device:R R?
U 1 1 617A1D7D
P 2600 4850
F 0 "R?" H 2670 4896 50  0000 L CNN
F 1 "R" H 2670 4805 50  0000 L CNN
F 2 "" V 2530 4850 50  0001 C CNN
F 3 "~" H 2600 4850 50  0001 C CNN
	1    2600 4850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 617A276B
P 2600 5250
F 0 "R?" H 2670 5296 50  0000 L CNN
F 1 "R" H 2670 5205 50  0000 L CNN
F 2 "" V 2530 5250 50  0001 C CNN
F 3 "~" H 2600 5250 50  0001 C CNN
	1    2600 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 5100 2600 5050
Wire Wire Line
	2600 5050 2900 5050
Wire Wire Line
	2900 5050 2900 4750
Wire Wire Line
	2900 4750 3150 4750
Connection ~ 2600 5050
Wire Wire Line
	2600 5050 2600 5000
$Comp
L Device:C C?
U 1 1 617A7390
P 3050 5100
F 0 "C?" H 3165 5146 50  0000 L CNN
F 1 "C" H 3165 5055 50  0000 L CNN
F 2 "" H 3088 4950 50  0001 C CNN
F 3 "~" H 3050 5100 50  0001 C CNN
	1    3050 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 4950 3050 4850
Wire Wire Line
	3050 4850 3150 4850
Text HLabel 3050 5300 3    50   UnSpc ~ 0
GND
Text HLabel 2600 5450 3    50   UnSpc ~ 0
GND
Wire Wire Line
	2600 5450 2600 5400
Wire Wire Line
	3050 5300 3050 5250
Wire Wire Line
	3150 4650 2600 4650
Wire Wire Line
	2600 4650 2600 4700
$Comp
L Device:C C?
U 1 1 617B0F30
P 1500 4900
F 0 "C?" H 1615 4946 50  0000 L CNN
F 1 "C" H 1615 4855 50  0000 L CNN
F 2 "" H 1538 4750 50  0001 C CNN
F 3 "~" H 1500 4900 50  0001 C CNN
	1    1500 4900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 617B1A49
P 1850 4900
F 0 "C?" H 1965 4946 50  0000 L CNN
F 1 "C" H 1965 4855 50  0000 L CNN
F 2 "" H 1888 4750 50  0001 C CNN
F 3 "~" H 1850 4900 50  0001 C CNN
	1    1850 4900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 617B1DB1
P 2200 4900
F 0 "C?" H 2315 4946 50  0000 L CNN
F 1 "C" H 2315 4855 50  0000 L CNN
F 2 "" H 2238 4750 50  0001 C CNN
F 3 "~" H 2200 4900 50  0001 C CNN
	1    2200 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 4750 1500 4650
Wire Wire Line
	1500 4650 1850 4650
Connection ~ 2600 4650
Wire Wire Line
	2200 4750 2200 4650
Connection ~ 2200 4650
Wire Wire Line
	2200 4650 2600 4650
Wire Wire Line
	1850 4750 1850 4650
Connection ~ 1850 4650
Wire Wire Line
	1850 4650 2200 4650
Wire Wire Line
	1500 5050 1500 5100
Wire Wire Line
	1500 5100 1850 5100
Wire Wire Line
	1850 5100 1850 5050
Wire Wire Line
	1850 5100 2200 5100
Wire Wire Line
	2200 5100 2200 5050
Connection ~ 1850 5100
Text HLabel 1850 5200 3    50   UnSpc ~ 0
GND
Wire Wire Line
	1850 5200 1850 5100
Text HLabel 1450 4650 0    50   UnSpc ~ 0
VDD
Wire Wire Line
	1450 4650 1500 4650
Connection ~ 1500 4650
Text Notes 3050 4000 0    50   ~ 0
STEPDOWN 5V -> 3V3
$EndSCHEMATC
