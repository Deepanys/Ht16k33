/*************************************************** 
This is example for Ht16k33 driver with 7 segment display

pin config:
scl - On Arduino UNO thats Analog #5, on the Leonardo its Digital #3, on the Mega its digital #21
sda - On Arduino UNO thats Analog #4, on the Leonardo its Digital #2, on the Mega its digital #20
vcc - +5 V
Gnd - 0 V
A0 - A segment
A1 - B
A2 - C
A3 - D
.
.
.
.
A7 - Decimal point

c0 - cathode 1
c1 - cathode 2
c2 - colon cathode
c3 - cathode 3
c4 - cathode 4


created 12 Dec. 2017
  by Deepan

 ****************************************************/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"



Adafruit_7segment matrix = Adafruit_7segment();    // creating function for first Ht16k33 (0x70)
Adafruit_7segment matrix1 = Adafruit_7segment();    // creating function for second Ht16k33 (0x71)

void setup() {
  Serial.begin(9600);
  Serial.println(" Seven Segment Display Test");
  matrix.begin(0x70);                               // creating first matrix
  matrix1.begin(0x71);                              // creating second matrix
  matrix.setBrightness(15);                         // setting brightness for display (0 - 15)
  //matrix.blinkRate(1) ;                           // You can blink the entire display. 0 is no blinking. 1, 2 or 3 is for display blinking.
  
}


void loop() {
  /*for(int i=0;i<4;i++)
  {
    
    for(int j=0;j<10;j++)
    {
      matrix.clear();
      matrix.writeDigitNum(i, j) ;
      matrix.writeDisplay();
      delay(1000);
     }                                 // uncomment this for write numbers from 0000 to 9999
   } */
  
     for(int z=0000;z<10000;z++)         // printing no 0 to 9999
    {  
      matrix.clear();                    // clearing chip memory
      matrix.print(z);                   // printing no stored in var "z"
      matrix.writeDisplay();             // writing srored var to chip
     delay(1000);
      
    }
}
