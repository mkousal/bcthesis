EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 1900 1750 650  800 
U 61767442
F0 "powerManagement" 50
F1 "powerManagement.sch" 50
F2 "GND" U R 2550 2450 50 
F3 "PWR_ON" I R 2550 2150 50 
F4 "PWR_OFF" I R 2550 2250 50 
F5 "VDD" O R 2550 1850 50 
F6 "3V3_L" O R 2550 2050 50 
F7 "3V3" O R 2550 1950 50 
$EndSheet
Text GLabel 2550 1850 2    50   Input ~ 0
VDD
Text GLabel 2550 1950 2    50   Input ~ 0
3V3
Text GLabel 2550 2150 2    50   Input ~ 0
PWR_ON
Text GLabel 2550 2250 2    50   Input ~ 0
PWR_OFF
Text GLabel 2550 2450 2    50   Input ~ 0
GND
Text GLabel 2550 2050 2    50   Input ~ 0
3V3_L
$Comp
L RF_Module:ESP32-WROOM-32 U?
U 1 1 6179D141
P 6350 3400
F 0 "U?" H 5900 4850 50  0000 C CNN
F 1 "ESP32-WROOM-32" H 5900 4750 50  0000 C CNN
F 2 "RF_Module:ESP32-WROOM-32" H 6350 1900 50  0001 C CNN
F 3 "https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf" H 6050 3450 50  0001 C CNN
F 4 "C82899" H 6350 3400 50  0001 C CNN "LCSC"
	1    6350 3400
	1    0    0    -1  
$EndComp
Text HLabel 6350 4850 3    50   UnSpc ~ 0
GND
Wire Wire Line
	6350 4850 6350 4800
NoConn ~ 5750 3400
NoConn ~ 5750 3500
NoConn ~ 5750 3600
NoConn ~ 5750 3700
NoConn ~ 5750 3800
NoConn ~ 5750 3900
Text HLabel 6350 1900 1    50   Output ~ 0
VDD
Wire Wire Line
	6350 1900 6350 2000
$EndSCHEMATC
