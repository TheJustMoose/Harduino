EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L Mechanical:MountingHole H1
U 1 1 5D791BF4
P 6250 1500
F 0 "H1" H 6350 1546 50  0000 L CNN
F 1 "MountingHole" H 6350 1455 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 6250 1500 50  0001 C CNN
F 3 "~" H 6250 1500 50  0001 C CNN
	1    6250 1500
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 5D793188
P 6250 2000
F 0 "H2" H 6350 2046 50  0000 L CNN
F 1 "MountingHole" H 6350 1955 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 6250 2000 50  0001 C CNN
F 3 "~" H 6250 2000 50  0001 C CNN
	1    6250 2000
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H3
U 1 1 5D793224
P 6250 2500
F 0 "H3" H 6350 2546 50  0000 L CNN
F 1 "MountingHole" H 6350 2455 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 6250 2500 50  0001 C CNN
F 3 "~" H 6250 2500 50  0001 C CNN
	1    6250 2500
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H4
U 1 1 5D7932CC
P 6250 3000
F 0 "H4" H 6350 3046 50  0000 L CNN
F 1 "MountingHole" H 6350 2955 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 6250 3000 50  0001 C CNN
F 3 "~" H 6250 3000 50  0001 C CNN
	1    6250 3000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5E4E1E07
P 4050 3750
F 0 "#PWR0101" H 4050 3500 50  0001 C CNN
F 1 "GND" H 4055 3577 50  0000 C CNN
F 2 "" H 4050 3750 50  0001 C CNN
F 3 "" H 4050 3750 50  0001 C CNN
	1    4050 3750
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0102
U 1 1 5E4E268A
P 4050 3500
F 0 "#PWR0102" H 4050 3350 50  0001 C CNN
F 1 "VCC" H 4067 3673 50  0000 C CNN
F 2 "" H 4050 3500 50  0001 C CNN
F 3 "" H 4050 3500 50  0001 C CNN
	1    4050 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 3500 4050 3550
Wire Wire Line
	4050 3700 4050 3750
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5E4E36FF
P 4050 3550
F 0 "#FLG0101" H 4050 3625 50  0001 C CNN
F 1 "PWR_FLAG" V 4050 3677 50  0000 L CNN
F 2 "" H 4050 3550 50  0001 C CNN
F 3 "~" H 4050 3550 50  0001 C CNN
	1    4050 3550
	0    -1   -1   0   
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5E4E3D09
P 4050 3700
F 0 "#FLG0102" H 4050 3775 50  0001 C CNN
F 1 "PWR_FLAG" V 4050 3827 50  0000 L CNN
F 2 "" H 4050 3700 50  0001 C CNN
F 3 "~" H 4050 3700 50  0001 C CNN
	1    4050 3700
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x10_Male J1
U 1 1 5E7C174E
P 1550 2400
F 0 "J1" H 1550 2900 50  0000 C CNN
F 1 "Conn_01x10_Male" H 1400 1800 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x10_P2.54mm_Vertical" H 1550 2400 50  0001 C CNN
F 3 "~" H 1550 2400 50  0001 C CNN
	1    1550 2400
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x10_Male J2
U 1 1 5E7C1FC2
P 3700 2400
F 0 "J2" H 3725 2875 50  0000 C CNN
F 1 "Conn_01x10_Male" H 3525 1800 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x10_P2.54mm_Vertical" H 3700 2400 50  0001 C CNN
F 3 "~" H 3700 2400 50  0001 C CNN
	1    3700 2400
	-1   0    0    -1  
$EndComp
Text Label 1750 2100 0    50   ~ 0
12
Text Label 1750 2200 0    50   ~ 0
13
Text Label 1750 2300 0    50   ~ 0
A0
Text Label 1750 2400 0    50   ~ 0
A1
Text Label 1750 2500 0    50   ~ 0
A2
Text Label 1750 2600 0    50   ~ 0
A3
Text Label 1750 2700 0    50   ~ 0
A4
Text Label 1750 2800 0    50   ~ 0
A5
Text Label 3500 2000 0    50   ~ 0
11
Text Label 3500 2900 0    50   ~ 0
2
Text Label 3500 2800 0    50   ~ 0
3
Text Label 3500 2700 0    50   ~ 0
4
Text Label 3500 2600 0    50   ~ 0
5
Text Label 3500 2500 0    50   ~ 0
6
Text Label 3500 2400 0    50   ~ 0
7
Text Label 3500 2300 0    50   ~ 0
8
Text Label 3500 2200 0    50   ~ 0
9
Text Label 3500 2100 0    50   ~ 0
10
$Comp
L power:GND #PWR01002
U 1 1 5E7CB82A
P 1750 2900
F 0 "#PWR01002" H 1750 2650 50  0001 C CNN
F 1 "GND" H 1755 2727 50  0000 C CNN
F 2 "" H 1750 2900 50  0001 C CNN
F 3 "" H 1750 2900 50  0001 C CNN
	1    1750 2900
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR01001
U 1 1 5E7CBCBE
P 1750 2000
F 0 "#PWR01001" H 1750 1850 50  0001 C CNN
F 1 "VCC" H 1767 2173 50  0000 C CNN
F 2 "" H 1750 2000 50  0001 C CNN
F 3 "" H 1750 2000 50  0001 C CNN
	1    1750 2000
	1    0    0    -1  
$EndComp
$Comp
L Display_Character:WC1602A DS1
U 1 1 5E9C831B
P 2800 2200
F 0 "DS1" H 2800 1219 50  0000 C CNN
F 1 "WC1602A" H 2800 1310 50  0000 C CNN
F 2 "Display:WC1602A" H 2800 1300 50  0001 C CIN
F 3 "http://www.wincomlcd.com/pdf/WC1602A-SFYLYHTC06.pdf" H 3500 2200 50  0001 C CNN
	1    2800 2200
	-1   0    0    1   
$EndComp
Wire Wire Line
	3200 2000 3500 2000
Wire Wire Line
	3200 2100 3500 2100
Wire Wire Line
	3200 2200 3500 2200
Wire Wire Line
	3200 2300 3500 2300
Wire Wire Line
	3200 2600 3350 2600
Wire Wire Line
	3350 2600 3350 2400
Wire Wire Line
	3350 2400 3500 2400
Wire Wire Line
	3200 2800 3350 2800
Wire Wire Line
	3350 2800 3350 2900
Wire Wire Line
	3350 2900 3500 2900
$Comp
L Mechanical:MountingHole H5
U 1 1 5E9CFED0
P 7250 1500
F 0 "H5" H 7350 1546 50  0000 L CNN
F 1 "MountingHole" H 7350 1455 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 7250 1500 50  0001 C CNN
F 3 "~" H 7250 1500 50  0001 C CNN
	1    7250 1500
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H6
U 1 1 5E9CFED6
P 7250 2000
F 0 "H6" H 7350 2046 50  0000 L CNN
F 1 "MountingHole" H 7350 1955 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 7250 2000 50  0001 C CNN
F 3 "~" H 7250 2000 50  0001 C CNN
	1    7250 2000
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H7
U 1 1 5E9CFEDC
P 7250 2500
F 0 "H7" H 7350 2546 50  0000 L CNN
F 1 "MountingHole" H 7350 2455 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 7250 2500 50  0001 C CNN
F 3 "~" H 7250 2500 50  0001 C CNN
	1    7250 2500
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H8
U 1 1 5E9CFEE2
P 7250 3000
F 0 "H8" H 7350 3046 50  0000 L CNN
F 1 "MountingHole" H 7350 2955 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 7250 3000 50  0001 C CNN
F 3 "~" H 7250 3000 50  0001 C CNN
	1    7250 3000
	1    0    0    -1  
$EndComp
$EndSCHEMATC
