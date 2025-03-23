// For mono-stable buttons it will trigger state: LOW - when button is pressed, HIGH - when button is released
const uint8_t MONO_STABLE_TRIGGER = LOW;

// time interval for RELAY_IMPULSE type relay, ignored when button type is DING_DONG or REED_SWITCH
const unsigned long RELAY_IMPULSE_INTERVAL = 250;

// debounce interval in milliseconds
const unsigned long BUTTON_DEBOUNCE_INTERVAL = 50;

// double-click interval in milliseconds
const unsigned long BUTTON_DOUBLE_CLICK_INTERVAL = 350;

// long-press interval in milliseconds
const unsigned long BUTTON_LONG_PRESS_INTERVAL = 800;

#ifdef USE_EXPANDER
  const uint8_t gExpanderAddresses[] = {0x3D, 0x39, 0x3A, 0x26, 0x3C, 0x38, 0X20, 0X21, 0X22}; //dodanie 0x23 psuje wszystko, oczywiście trzeba go fizycznie podłączyć i od komentować sekcję "przycisków"
  //const uint8_t gExpanderAddresses[] = {0X20, 0x21, 0x22, 0X23, 0X24, 0x25,0x27}; //0x27 nie jest używany obecnie
#endif

const char MULTI_RELAY_DESCRIPTION[] PROGMEM = "Multi Relay";

// Relays config - ID and PIN MUST BE UNIQUE (can't be repeated)!
// Row params: relay ID - [0-254] sensor ID reported on MySensor Gateway
//             relay pin - pin used for relay, can be expander pin via "E(x, y)" macro
//             relay options - [RELAY_TRIGGER_LOW|RELAY_TRIGGER_HIGH] {RELAY_STARTUP_ON|RELAY_STARTUP_OFF} {RELAY_IMPULSE}
//             relay dependOn - ID of relay that needs to be turned on before this one
//             relay description - reported on MySensor Gateway, can help identify device on initial configuration in Home Automation App, max. 30 chars, can be empty ("")
const RelayConfigDef gRelayConfig[] PROGMEM = {
// 0x3D
{1, E(0,0), RELAY_TRIGGER_LOW, -1,"Kinkiet - Drzwi tarasowe"}, //K1K2
{2, E(0,1), RELAY_TRIGGER_LOW, -1,"Kinkiet - Drzwi wejściowe"}, //K8
{3, E(0,2), RELAY_TRIGGER_LOW, -1,"ZB1"},
{4, E(0,3), RELAY_TRIGGER_LOW, -1,"ZB2"},
{5, E(0,4), RELAY_TRIGGER_LOW, -1,"ZB3"},
{6, E(0,5), RELAY_TRIGGER_LOW, -1,""},
{7, E(0,6), RELAY_TRIGGER_LOW, -1,""},
{8, E(0,7), RELAY_TRIGGER_LOW, -1,""},

// 0x39
{9,  E(1,0), RELAY_TRIGGER_HIGH, -1,"Oś. Korytarz obok łazienki"}, //K7
{10, E(1,1), RELAY_TRIGGER_HIGH, -1,"Oś. Garderoby"}, //K18
{11, E(1,2), RELAY_TRIGGER_HIGH, -1,"Oś. Garaż wejście"}, //K24
{12, E(1,3), RELAY_TRIGGER_HIGH, -1,"Oś. Garaż kotłownia"}, //K24
{13, E(1,4), RELAY_TRIGGER_HIGH, -1,"Oś. Kotłowni"}, //K25
{14, E(1,5), RELAY_TRIGGER_HIGH, -1,""},
{15, E(1,6), RELAY_TRIGGER_HIGH, -1,"Oś. Jadalni"}, //K4
{16, E(1,7), RELAY_TRIGGER_HIGH, -1,"Oś. Spiżarni"}, //K11

// 0x3A
{17, E(2,0), RELAY_TRIGGER_HIGH, -1,"Oś. Gabinetu"}, //K6
{18, E(2,1), RELAY_STARTUP_OFF, -1,""}, //K6
{19, E(2,2), RELAY_TRIGGER_HIGH, -1,"Oś. Sypialnia bliźniaki"}, //K12
{20, E(2,3), RELAY_TRIGGER_HIGH, -1,"Oś. Sypialnia bliźniaki"}, //K12
{21, E(2,4), RELAY_TRIGGER_HIGH, -1,"Oś. Pokój zabaw"}, //K13
{22, E(2,5), RELAY_TRIGGER_HIGH, -1,"Oś. Pokój zabaw"}, //K13
{23, E(2,6), RELAY_TRIGGER_HIGH, -1,"Oś. Pokój Mateusza"}, //K14
{24, E(2,7), RELAY_TRIGGER_HIGH, -1,"Oś. Pokój Mateusza"}, //K14

// 0x27
{25, E(3,0), RELAY_TRIGGER_LOW, -1,"Sypialnia kinkiet Prawy"}, // KSP
{26, E(3,1), RELAY_TRIGGER_LOW, -1,"Sypialnia kinkiet Lewy"}, // KLP
{27, E(3,2), RELAY_TRIGGER_LOW, -1,"Oś. Pralni"}, // K22
{28, E(3,3), RELAY_TRIGGER_LOW, -1,"Oś. Sypialni"}, // K21
{29, E(3,4), RELAY_TRIGGER_LOW, -1,"Oś. Strychu"}, // K29
{30, E(3,5), RELAY_TRIGGER_LOW, -1,""},
{31, E(3,6), RELAY_TRIGGER_LOW, -1,""},
{32, E(3,7), RELAY_TRIGGER_LOW, -1,""},

// 0x3C
{33, E(4,0), RELAY_TRIGGER_HIGH | RELAY_STARTUP_ON, -1,"Oś. Łazienka dół lustro"}, //K19 MOŻNA PODŁĄCZYĆ BEZPOŚREDNIO I UWOLNIĆ TEN PRZEKAŹNIK
{34, E(4,1), RELAY_TRIGGER_HIGH, -1,"Oś. Łazienka dół sufit"}, //K20
{35, E(4,2), RELAY_TRIGGER_HIGH, -1,"Oś. Łazienka góra sufit"}, //K16
{36, E(4,3), RELAY_TRIGGER_HIGH, -1,"Oś. Łazienka góra sufit"}, //K16 TRZEBA PODŁĄCZYĆ POD STYKI OBOK I UWOLNIĆ TEN PRZEKAŹNIK
{37, E(4,4), RELAY_TRIGGER_HIGH | RELAY_STARTUP_ON, -1,"Oś. Łazienka góra lustro"}, //K27 MOŻNA PODŁĄCZYĆ BEZPOŚREDNIO I UWOLNIĆ TEN PRZEKAŹNIK
{38, E(4,5), RELAY_TRIGGER_HIGH | RELAY_STARTUP_ON, -1,"Oś. Łazienka góra lustro"}, //K27 MOŻNA PODŁĄCZYĆ BEZPOŚREDNIO I UWOLNIĆ TEN PRZEKAŹNIK
{39, E(4,6), RELAY_TRIGGER_HIGH, -1,"Oś. Wiatrołapu wejście"}, //K9
{40, E(4,7), RELAY_TRIGGER_HIGH, -1,"Oś. Wiatrołapu garaż"}, //K9

// 0x38
{41, E(5,0), RELAY_TRIGGER_LOW, -1,"Oś. Korytarz piętro schody"}, //K15
{42, E(5,1), RELAY_TRIGGER_LOW, -1,"Oś. Korytarz piętro"}, //K15
{43, E(5,2), RELAY_TRIGGER_LOW, -1,"Oś. Kuchnia okno"}, //K3
{44, E(5,3), RELAY_TRIGGER_LOW, -1,"Oś. Kuchnia środek"}, //K3
{45, E(5,4), RELAY_TRIGGER_LOW, -1,"Oś. Salon TV"}, //K5
{46, E(5,5), RELAY_TRIGGER_LOW, -1,"Oś. Salon kanapa"}, //K5
{47, E(5,6), RELAY_TRIGGER_LOW, -1,"Oś. Barek"}, //K10
{48, E(5,7), RELAY_TRIGGER_LOW, -1,"Oś. Schodów Kinkiet"}, //K17

//wirtualne przekaźniki dla PIR i detekcji w HA. Nazwy pokazywane są w HA
{100, 1, RELAY_TRIGGER_HIGH, -1,"PIR Wiatrołap Garaż"},
{101, 2, RELAY_TRIGGER_HIGH, -1,"PIR Wiatrołap Wejście"},
{102, 3, RELAY_TRIGGER_HIGH, -1,"PIR Spiżarnia"},
{103, 4, RELAY_TRIGGER_HIGH, -1,"PIR Kuchnia"},
{104, 5, RELAY_TRIGGER_HIGH, -1,"PIR Garaż Brama"},
{105, 6, RELAY_TRIGGER_HIGH, -1,"PIR Łazienka dół"},
{106, 7, RELAY_TRIGGER_HIGH, -1,"PIR Zewnętrzna nad tarasem"},
{107, 8, RELAY_TRIGGER_HIGH, -1,"PIR Wejście do kotłowni"},

{108, 9, RELAY_TRIGGER_HIGH, -1,"PIR Kotłownia"},
{109, 10, RELAY_TRIGGER_HIGH, -1,"PIR Garderoba"},
{110, 11, RELAY_TRIGGER_HIGH, -1,"PIR Piętro nad schodami"},
{111, 12, RELAY_TRIGGER_HIGH, -1,"PIR Wejście na schody"},
{112, 13, RELAY_TRIGGER_HIGH, -1,"PIR Pokój zabaw"},
{113, 14, RELAY_TRIGGER_HIGH, -1,"PIR Pokój Mateusza"},
{114, 15, RELAY_TRIGGER_HIGH, -1,"PIR Sypialnia bliźniaków"},
{115, 16, RELAY_TRIGGER_HIGH, -1,"PIR8"},

};

// Buttons config
// Row params: button pin - pin used for button, can be expander pin (but NOT RECOMMENDED) via "E(x, y)" macro
//             button type - [MONO_STABLE|BI_STABLE|DING_DONG|REED_SWITCH]
//             click action relay ID - MUST be defined in gRelayConfig
//             long-press action relay ID - ignored for BI_STABLE, DING_DONG, REED_SWITCH
//             double-click action relay ID - ignored for DING_DONG, REED_SWITCH
//             button description - debug only, max. 30 chars, can be empty ("")
const ButtonConfigDef gButtonConfig[] PROGMEM = {
/*
{A0, BI_STABLE,  1, -1, -1, "Kinkiet - Drzwi tarasowe"}, //K1K2 POWINIEN BYĆ W2 KOŁO DRZWI TARASOWYCH
{A1, BI_STABLE,  2, -1, -1, "Kinkiet - Drzwi wejściowe"}, //K8 BRAK PRZYCISKU
{A2, BI_STABLE,  9, -1, -1, "Oś. Korytarz obok łazienki"}, //K7 W7
{A3, BI_STABLE,  10, -1, -1, "Oś. Garderoby"}, //K18 BRAK PRZYCISKU, UŻYWANY OD OŚWIETLENIA GARDEROBY PRZEZ PODWÓJNE KLIKNIĘCIE
{A4, BI_STABLE,  11, -1, -1, "Oś. Garaż wejście"}, //K24 W24
{A5, BI_STABLE,  12, -1, -1, "Oś. Garaż kotłownia"}, //K24 W24
{A6, BI_STABLE,  13, -1, -1, "Oś. Kotłowni "}, //K25 BRAK PRZYCISKU, UŻYWANY OD OŚWIETLENIA GARAŻU
{A7, BI_STABLE,  15, -1, -1, "Oś. Jadalni"}, //K4 W4
{A8, BI_STABLE,  16, -1, -1, "Oś. Spiżarni"}, //K11 BRAK PRZYCISKU, UŻYWANY OD OŚWIETLENIA BARKU PRZEZ PODWÓJNE KLIKNIĘCIE
{A9, BI_STABLE,  17, -1, -1, "Oś. Gabinetu"}, //K6 W6
{A10, BI_STABLE,  18, -1, -1, "Oś. Gabinetu 2"}, //K6 DRUGI NIE UŻYWANY
{A11, BI_STABLE,  19, -1, -1, "Oś. Sypialnia bliźniaki"}, //K12 W12
{A12, BI_STABLE,  20, -1, -1, "Oś. Sypialnia bliźniaki"}, //K12 W12
{A13, BI_STABLE,  21, -1, -1, "Oś. Pokój zabaw"}, //K13 W13
{A14, BI_STABLE,  22, -1, -1, "Oś. Pokój zabaw"}, //K13 W13

{22, BI_STABLE,  23, -1, -1, "Oś. Pokój Mateusza"}, //K14 W14
{23, BI_STABLE,  24, -1, -1, "Oś. Pokój Mateusza"}, //K14 W14
{24, BI_STABLE,  25, -1, -1, "Sypialnia kinkiet Prawy"}, // KSP 
{25, BI_STABLE,  26, -1, -1, "Sypialnia kinkiet Lewy"}, // KLP
{26, BI_STABLE,  27, -1, 2, "Oś. Pralni"},// K22 Podwójne Kliknięcie wybudza Oświetlenie zewnętrzne
{27, BI_STABLE,  28, -1, 10, "Oś. Sypialni"},// K21 Podwójne klinięcie steruje oświetleniem garderoby (10)
{45, BI_STABLE,  10, -1, 41, "Oś. Garderoby"},//K21 Podwójne klinięcie steruje oświetleniem góra schody (41)
{28, BI_STABLE,  29, -1, -1, "Oś. Strychu"},// K29
{29, BI_STABLE,  33, -1, -1, "Oś. Łazienka dół lustro"},//K19
{30, BI_STABLE,  34, -1, -1, "Oś. Łazienka dół sufit"},//K20 

{31, BI_STABLE,  35, -1, -1, "Oś. Łazienka góra sufit"},//K16
{32, BI_STABLE,  36, -1, -1, "Oś. Łazienka góra sufit"},//K16
{33, BI_STABLE,  37, -1, -1, "Oś. Łazienka góra lustro"},//K27
{34, BI_STABLE,  38, -1, -1, "Oś. Łazienka góra lustro"}, //K27
{35, BI_STABLE,  39, -1, -1, "Oś. Wiatrołapu wejście"}, //K9
{36, BI_STABLE,  40, -1, -1, "Oś. Wiatrołapu garaż"}, //K9
{37, BI_STABLE,  41, -1, -1, "Oś. Korytarz piętro schody"}, //K15
{38, BI_STABLE,  42, -1, -1, "Oś. Korytarz piętro"}, //K15
{39, BI_STABLE,  43, -1, -1, "Oś. Kuchnia okno"}, //K3
{40, BI_STABLE,  44, -1, -1, "Oś. Kuchnia środek"}, //K3
{41, BI_STABLE,  45, -1, -1, "Oś. Salon kanapa"}, //K5
{42, BI_STABLE,  46, -1, -1, "Oś. Salon TV"}, //K5
{43, BI_STABLE,  47, -1, 16, "Oś. Barek"}, //K10 Podwójne kliknięcie włącza oświetlenie w spiżarni (16)
{44, BI_STABLE,  48, -1, -1, "Oś. Schodów Kinkiet"}, //K17

{14, BI_STABLE,  39, -1, -1, "Oś. Wiatrołapu wejście"}, //K20 - przycisk koło łazienki na dole
{14, BI_STABLE,  40, -1, -1, "Oś. Wiatrołapu garaż"}, //K20 - przycisk koło łazienki na 
*/

// 0X20 PRZYCISKI WŁĄCZAJĄCE ŚWIATŁA NAZWY NIE SĄ PRZENOSZONE DO HA TO TYLKO OPIS DLA JASNOŚCI SYTUACJI - PODOBNIE KOMENTARZE
{E(6,0), BI_STABLE,  39, -1, -1, "WIATROŁAP WEJŚCIE"}, //W1 - ŚCIANA WIATROŁAPU ZAPLA ŚWIATŁO NAD WEJŚCIEM GŁÓWNYM
//{E(6,0), BI_STABLE,  40, -1, -1, "WIATROŁAP WEJŚCIE"}, //W1 - ŚCIANA WIATROŁAPU ZAPLA ŚWIATŁO NAD WEJŚCIEM DO GARAŻU
{E(6,1), BI_STABLE,  1, -1, -1, "WYJŚCIE NA TARAS"}, //W2 - ZAPALA ŚWIATŁO ZEWNĘTRZNE NA TARASIE KINKIETY K1K2 
{E(6,2), BI_STABLE,  43, -1, -1, "KUCHNIA OKNO"}, //W3 - ŚCIANA SALONU ZAPALA ŚWIATŁO NAD OKNEM W KUCHNI
{E(6,3), BI_STABLE,  44, -1, -1, "KUCHNIA ŚRODEK"}, //W3 - ŚCIANA SALONU ZAPALA ŚWIATŁO W KUCHNI
{E(6,4), BI_STABLE,  47, -1, 16, "BAREK"}, //W3 - ŚCIANA SALONU ZAPALA ŚWIATŁO NAD BARAKIEM - podwójne kliknięcie włącza światło w spiżarni
{E(6,5), BI_STABLE,  45, -1, -1, "SALON KANAPA"}, //W4 - ŚCIANA SALONU ZAPALA ŚWIATŁO NAD KANAPĄ
{E(6,6), BI_STABLE,  46, -1, -1, "SALON TV"}, //W4 - ŚCIANA SALONU ZAPALA ŚWIATŁO NAD TV
{E(6,7), BI_STABLE,  15, -1, -1, "JADALNIA"}, //W4 - ŚCIANA SALONU ZAPALA ŚWIATŁO W JADALNI

//0X21 CZUJKI PIR/(+_
{E(7,0), REED_SWITCH,  100, -1, -1, "PIR Wiatrołap Garaż"}, //C1 - Wysyła sygnał do wirtualnego przekaźnika 100
{E(7,1), REED_SWITCH,  101, -1, -1, "PIR Wiatrołap Wejście"}, //C2 - wysyła sygnał do wirtualnego przekaźnika 101
{E(7,2), REED_SWITCH,  102, -1, -1, "PIR Spiżarnia"}, //C3 -wysyła sygnał do wirtualnego przekaźnika 102
{E(7,3), REED_SWITCH,  103, -1, -1, "PIR KUCHNIA"}, //C4 - wysyła sygnał do wirtualnego przekaźnika 103
{E(7,4), REED_SWITCH,  104, -1, -1, "PIR Garaż Brama"}, //C9 - wysyła sygnał do wirtualnego przekaźnika 104
{E(7,5), REED_SWITCH,  105, -1, -1, "PIR Łazienka dół"}, //C11 - wysyła sygnał do wirtualnego przekaźnika 105
{E(7,6), REED_SWITCH,  106, -1, -1, "PIR Zewnętrzna nad tarasem"}, //C12 - wysyła sygnał do wirtualnego przekaźnika 106
{E(7,7), REED_SWITCH,  107, -1, -1, "PIR Wejście do Kotłowni"}, //C13 - wysyła sygnał do wirtualnego przekaźnika 105 */

//0X22 PRZYCISKI WYŁĄCZAJĄCE ŚWIATŁA
{E(8,0), BI_STABLE,  17, -1, -1, "GABINET"}, //W6 - ŚCIANA GABINETU
{E(8,1), BI_STABLE,  9, -1, -1, "KORYTARZ"}, //W7 - KORYTARZ NA PRZECIWKO ŁAZIENKI
{E(8,2), BI_STABLE,  19, -1, -1, "SYPIALNIA BLIŹNIAKÓW"}, //W12 - ŚCIANA SYPIALNI BLIŹNIAKÓW
{E(8,3), BI_STABLE,  20, -1, -1, "SYPIALNIA BLIŹNIAKÓW"}, //W12 - ŚCIANA SYPIALNI BLIŹNIAKÓW
{E(8,4), BI_STABLE,  21, -1, -1, "POKÓJ ZABAW"}, //W13 - ŚCIANA POKÓJ ZABAW
{E(8,5), BI_STABLE,  22, -1, -1, "POKÓJ ZABAW"}, //W13 - ŚCIANA POKÓJ ZABAW
{E(8,6), BI_STABLE,  23, -1, -1, "POKÓJ MATEUSZA"}, //W14 - ŚCIANA POKÓJ MATEUSZA
{E(8,7), BI_STABLE,  24, -1, -1, "POKÓJ MATEUSZA"}, //W14 - ŚCIANA POKÓJ MATEUSZA

/*0X23 PRZYCISKI WŁĄCZAJĄCE ŚWIATŁA
{E(9,0), BI_STABLE,  42, -1, 41, "KORYTARZ PIĘTRO"}, //W15 - KORYTARZ NA PIĘTRZE (KOŁO POKOJU MATEUSZA) Podwójne kliknięcie włącza drugie światło nad schodami
{E(9,1), BI_STABLE,  35, -1, -1, "ŁAZIENKA GÓRA"}, //W16 - ŁAZIENKA GÓRA SUFIT
//{E(9,1), BI_STABLE,  36, -1, -1, "ŁAZIENKA GÓRA"}, //W16 - ŁAZIENKA GÓRA SUFIT
{E(9,2), BI_STABLE,  48, -1, -1, "ŁAZIENKA GÓRA"}, //W16 - KINKIET NA GÓRZE SCHODÓW (OŚWIETLENIE SCHODÓW KINKIET)
{E(9,3), BI_STABLE,  37, -1, -1, "ŁAZIENKA DÓŁ"}, //W18 - ŁAZIENKA DÓŁ K20
{E(9,4), BI_STABLE,  39, -1, -1, "ŁAZIENKA DÓŁ"}, //W18 - ŁAZIENKA DÓŁ OŚWIETLENIE WIATROŁAPU K9
{E(9,4), BI_STABLE,  40, -1, -1, "ŁAZIENKA DÓŁ"}, //W18 - ŁAZIENKA DÓŁ OŚWIETLENIE WIATROŁAPU K9
{E(9,5), BI_STABLE,  28, -1, 10, "SYPIALNIA"}, //W19 - SYPIALNIA - PODWÓJNE KLIKNIĘCIE WŁĄCZA OŚWIETLENIE GARDEROBY
{E(9,6), BI_STABLE,  25, -1, -1, "SYPIALNIA - KINKIET LEWY"}, //W19 - SYPIALNIA - KINKIET LEWY
{E(9,7), BI_STABLE,  26, -1, -1, "SYPIALNIA - KINKIET PRAWY"}, //W19 - SYPIALNIA - KINKIET PRAWY

/*0X24 PRZYCISKI WYŁĄCZAJĄCE ŚWIATŁA
{E(10,0), BI_STABLE,  25, -1, -1, "SYPIALNIA - KINKIET LEWY"}, //W20 - SYPIALNIA - KINKIET LEWY KL
{E(10,1), BI_STABLE,  26, -1, -1, "SYPIALNIA - KINKIET LEWY"}, //W20 - SYPIALNIA - KINKIET PRAWY KP
{E(10,2), BI_STABLE,  25, -1, -1, "SYPIALNIA - KINKIET PRAWY"}, //W21 - SYPIALNIA - KINKIET LEWY  KL
{E(10,3), BI_STABLE,  26, -1, -1, "SYPIALNIA - KINKIET PRAWY"}, //W21 - SYPIALNIA - KINKIET PRAWY KP
{E(10,4), BI_STABLE,  48, -1, -1, "SCHODY DÓŁ"}, //W22 - WŁĄCZA ŚWIATŁO NA SCHODACH - KINKIET K17
{E(10,5), BI_STABLE,  28, -1, -1, "PRALNIA"}, //W23 - WŁĄCZA ŚWIATŁO W PRALNI K22
{E(10,6), BI_STABLE,  11, -1, -1, "GARAŻ"}, //W24 - WŁĄCZA ŚWIATŁO KOŁO BRAMY K24
{E(10,7), BI_STABLE,  12, -1, -1, "GARAŻ"}, //W24 - WŁĄCZA ŚWIATŁO KOŁO KOTŁOWNI K24 */



//Poniższe nazwy są tylko dla debugu, nie mają wpływu na działanie ani nie są pokazywane w HA
/*
//0X25
{E(11,0), REED_SWITCH,  108, -1, -1, "PIR Kotłownia"}, //C15 - Wysyła sygnał do wirtualnego przekaźnika 100
{E(11,1), REED_SWITCH,  109, -1, -1, "PIR Garderoba"}, //C16
{E(11,2), REED_SWITCH,  110, -1, -1, "PIR Piętro nad schodami"}, //C18
{E(11,3), REED_SWITCH,  111, -1, -1, "PIR Wejście na schody"}, //C19
{E(11,4), REED_SWITCH,  112, -1, -1, "PIR Pokój zabaw"}, //CC
{E(11,5), REED_SWITCH,  113, -1, -1, "PIR Pokój Mateusza"}, //CE
{E(11,6), REED_SWITCH,  114, -1, -1, "PIR Sypialnia bliźniaków"}, //CF
{E(11,7), REED_SWITCH,  115, -1, -1, "PIR8"}, //Do wykorzystania w przyszłości */
}; 
// Hostname for the WiFi Client. This is the hostname passed to the DHCP server if not static.
#define MY_HOSTNAME "MEGA_LAN"

// Enable MY_IP_ADDRESS here if you want a static ip address (no DHCP)
#define MY_IP_ADDRESS 192,168,1,224
//#define MY_MAC_ADDRESS 0xDE, 0xAA, 0xBE, 0xEF, 0xFE, 0xED
// If using static ip you can define Gateway and Subnet address as well
#define MY_IP_GATEWAY_ADDRESS 192,168,1,1
#define MY_IP_SUBNET_ADDRESS 255,255,255,0


//#define MY_MAC_ADDRESS 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
#define MY_PORT 5003
#define MY_USE_tcp
//#define MY_USE_UDP
