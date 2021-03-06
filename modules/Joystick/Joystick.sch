EESchema Schematic File Version 4
LIBS:Joystick-cache
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
P 7500 2500
F 0 "H1" H 7600 2546 50  0000 L CNN
F 1 "MountingHole" H 7600 2455 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 7500 2500 50  0001 C CNN
F 3 "~" H 7500 2500 50  0001 C CNN
	1    7500 2500
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 5D793188
P 7500 3000
F 0 "H2" H 7600 3046 50  0000 L CNN
F 1 "MountingHole" H 7600 2955 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 7500 3000 50  0001 C CNN
F 3 "~" H 7500 3000 50  0001 C CNN
	1    7500 3000
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H3
U 1 1 5D793224
P 7500 3500
F 0 "H3" H 7600 3546 50  0000 L CNN
F 1 "MountingHole" H 7600 3455 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 7500 3500 50  0001 C CNN
F 3 "~" H 7500 3500 50  0001 C CNN
	1    7500 3500
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H4
U 1 1 5D7932CC
P 7500 4000
F 0 "H4" H 7600 4046 50  0000 L CNN
F 1 "MountingHole" H 7600 3955 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 7500 4000 50  0001 C CNN
F 3 "~" H 7500 4000 50  0001 C CNN
	1    7500 4000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5E4E1E07
P 5300 3750
F 0 "#PWR0101" H 5300 3500 50  0001 C CNN
F 1 "GND" H 5305 3577 50  0000 C CNN
F 2 "" H 5300 3750 50  0001 C CNN
F 3 "" H 5300 3750 50  0001 C CNN
	1    5300 3750
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0102
U 1 1 5E4E268A
P 5300 3500
F 0 "#PWR0102" H 5300 3350 50  0001 C CNN
F 1 "VCC" H 5317 3673 50  0000 C CNN
F 2 "" H 5300 3500 50  0001 C CNN
F 3 "" H 5300 3500 50  0001 C CNN
	1    5300 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 3500 5300 3550
Wire Wire Line
	5300 3700 5300 3750
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5E4E36FF
P 5300 3550
F 0 "#FLG0101" H 5300 3625 50  0001 C CNN
F 1 "PWR_FLAG" V 5300 3677 50  0000 L CNN
F 2 "" H 5300 3550 50  0001 C CNN
F 3 "~" H 5300 3550 50  0001 C CNN
	1    5300 3550
	0    -1   -1   0   
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5E4E3D09
P 5300 3700
F 0 "#FLG0102" H 5300 3775 50  0001 C CNN
F 1 "PWR_FLAG" V 5300 3827 50  0000 L CNN
F 2 "" H 5300 3700 50  0001 C CNN
F 3 "~" H 5300 3700 50  0001 C CNN
	1    5300 3700
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
P 4450 2400
F 0 "J2" H 4475 2875 50  0000 C CNN
F 1 "Conn_01x10_Male" H 4275 1800 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x10_P2.54mm_Vertical" H 4450 2400 50  0001 C CNN
F 3 "~" H 4450 2400 50  0001 C CNN
	1    4450 2400
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
Text Label 4250 2000 0    50   ~ 0
11
Text Label 4250 2900 0    50   ~ 0
2
Text Label 4250 2800 0    50   ~ 0
3
Text Label 4250 2700 0    50   ~ 0
4
Text Label 4250 2600 0    50   ~ 0
5
Text Label 4250 2500 0    50   ~ 0
6
Text Label 4250 2400 0    50   ~ 0
7
Text Label 4250 2300 0    50   ~ 0
8
Text Label 4250 2200 0    50   ~ 0
9
Text Label 4250 2100 0    50   ~ 0
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
L CommonLibrary:joystick VR1
U 1 1 5E9BDFF4
P 3150 2700
F 0 "VR1" H 3062 2679 50  0000 R CNN
F 1 "joystick" H 3062 2588 50  0000 R CNN
F 2 "CommonLibrary:Joystick" H 3100 2650 50  0001 C CNN
F 3 "" H 3100 2650 50  0001 C CNN
	1    3150 2700
	-1   0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0103
U 1 1 5E9BF527
P 3150 2500
F 0 "#PWR0103" H 3150 2350 50  0001 C CNN
F 1 "VCC" H 3167 2673 50  0000 C CNN
F 2 "" H 3150 2500 50  0001 C CNN
F 3 "" H 3150 2500 50  0001 C CNN
	1    3150 2500
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0104
U 1 1 5E9BFFAB
P 2500 3000
F 0 "#PWR0104" H 2500 2850 50  0001 C CNN
F 1 "VCC" V 2518 3127 50  0000 L CNN
F 2 "" H 2500 3000 50  0001 C CNN
F 3 "" H 2500 3000 50  0001 C CNN
	1    2500 3000
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5E9C084A
P 3150 3000
F 0 "#PWR0105" H 3150 2750 50  0001 C CNN
F 1 "GND" H 3155 2827 50  0000 C CNN
F 2 "" H 3150 3000 50  0001 C CNN
F 3 "" H 3150 3000 50  0001 C CNN
	1    3150 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 3000 3150 3000
Wire Wire Line
	3150 2900 3150 3000
Connection ~ 3150 3000
Wire Wire Line
	1750 2300 3000 2300
Wire Wire Line
	3000 2300 3000 2700
Wire Wire Line
	1750 2400 2700 2400
Wire Wire Line
	2700 2400 2700 2850
NoConn ~ 1750 2100
NoConn ~ 1750 2200
NoConn ~ 1750 2500
NoConn ~ 1750 2600
NoConn ~ 1750 2700
NoConn ~ 1750 2800
NoConn ~ 4250 2000
NoConn ~ 4250 2100
NoConn ~ 4250 2200
NoConn ~ 4250 2300
NoConn ~ 4250 2400
NoConn ~ 4250 2500
NoConn ~ 4250 2600
NoConn ~ 4250 2700
NoConn ~ 4250 2800
NoConn ~ 4250 2900
$EndSCHEMATC
