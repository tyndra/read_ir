#include <IRrecv.h>

#include "debug.h"
#define DEBUG               1

IRrecv* irRecv;                 // infrared sender
decode_results results;

//SET TO MATCH YOUR HARDWARE 
#define SERIAL_BAUD_RATE    9600

#define RESET_PIN           0
#define IR_PIN              14

/*---------------------------------------*/
//Runs once, when device is powered on or code has just been flashed 
void setup()
{
    //if set wrong, your serial debugger will not be readable 
    Serial.begin(SERIAL_BAUD_RATE);

     digitalWrite(RESET_PIN, LOW);

    //initialize the IR 
    irRecv = new IRrecv(IR_PIN);
    irRecv->enableIRIn(); // Start the receiver

    digitalWrite(IR_PIN, HIGH);

    debugPrint("Test");
}

/*---------------------------------------*/
//Runs constantly 
void loop()
{
  if (irRecv->decode(&results)) {
    debugPrintlnHex(results.value);
    delay(300);
    irRecv->resume(); // Continue receiving
  }
}
