#include "pedometer.h"
#include <ADXL345.h>
#include <Wire.h>
#include <SeeedOLED.h>

Pedometer pedometer;

void setup(){
    Serial.begin(9600);
    oledInit();
    pedometer.init();
}


void loop(){
    pedometer.stepCalc();
    SeeedOled.setTextXY(5,10);
    char number[2];
    SeeedOled.putString(itoa(pedometer.stepCount,number,10)); //Print the String    
}

void oledInit(){
    //oled init
    Wire.begin();
    SeeedOled.init();  //initialze SEEED OLED display
    DDRB|=0x21;        //digital pin 8, LED glow indicates Film properly Connected .
    PORTB |= 0x21;
    
    SeeedOled.clearDisplay();          //clear the screen and set start position to top left corner
    SeeedOled.setNormalDisplay();      //Set display to normal mode (i.e non-inverse mode)
    SeeedOled.setPageMode();           //Set addressing mode to Page Mode
    SeeedOled.setTextXY(0,0);
    SeeedOled.putString("****************");
    SeeedOled.setTextXY(1,0);
    SeeedOled.putString("** PEDOMETER  **");
    SeeedOled.setTextXY(2,0);
    SeeedOled.putString("****************");
    SeeedOled.setTextXY(3,0);
    SeeedOled.putString("*");
    SeeedOled.setTextXY(3,15);
    SeeedOled.putString("*");
    SeeedOled.setTextXY(4,0);
    SeeedOled.putString("*");
    SeeedOled.setTextXY(4,15);
    SeeedOled.putString("*");
    SeeedOled.setTextXY(5,0);
    SeeedOled.putString("*");
    SeeedOled.setTextXY(5,15);
    SeeedOled.putString("*");
    SeeedOled.setTextXY(6,0);
    SeeedOled.putString("*");
    SeeedOled.setTextXY(6,15);
    SeeedOled.putString("*");
    SeeedOled.setTextXY(7,0);
    SeeedOled.putString("****************");
    SeeedOled.setTextXY(4,1);
    SeeedOled.putString("   Walker   "); 
  
   for(int i = 5; i > 0; i--){
      SeeedOled.setTextXY(4,1);          //Set the cursor to Xth Page, Yth Column  
      SeeedOled.putString("             ");
      SeeedOled.setTextXY(4,1);          //Set the cursor to Xth Page, Yth Column  
      SeeedOled.putString("   Wait:     "); 
      SeeedOled.setTextXY(4,10);
      char number[2];
      SeeedOled.putString(itoa(i,number,10)); //Print the String
      delay(1000);
    }
    SeeedOled.setTextXY(4,1);          //Set the cursor to Xth Page, Yth Column  
    SeeedOled.putString("             ");
    SeeedOled.setTextXY(5,1);          //Set the cursor to Xth Page, Yth Column  
    SeeedOled.putString("             ");
    SeeedOled.setTextXY(5,1);          //Set the cursor to Xth Page, Yth Column  
    SeeedOled.putString("  STEP:");  
}

