/*** LPC810 Arduino compatible library example ***/

/*
  Button
 
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 2, when pressing a pushbutton attached to pin 1.
 
 
 The circuit:
 * LED attached from pin 2 to VCC
 * pushbutton attached to pin 1 from GND
 * 10K resistor attached to pin 2 to VCC
 
 * Note: On the LPC810 Minikit there is already an LED on the board
 attached to pin 2.
 
 reworked for LPC810 2014 ChrisMicro
 
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 1;     // the number of the pushbutton pin
const int ledPin =  2;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);     
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {     
    // turn LED off:
    digitalWrite(ledPin, HIGH);  
  } 
  else {
    // turn LED on:
    digitalWrite(ledPin, LOW); 
  }
}




/*

     LPC800 Pining ( Arduino pin numbering )
     =======================================
                      ________
                      |   U   |
          reset      -|       |- digital 0 / analog in A0 / RX
     TX / digital 4  -|  LPC  |- GND
          digital 3  -|  810  |- +3.3V
          digital 2  -|       |- digital 1 / analog in A1
                      |_______|


     Mini Kit Board ( http://www.lpcware.com/lpc800-mini-kit )
     =========================================================
                      ________
                      |   U   |
        reset switch -|       |- RX
                  TX -|  LPC  |- GND
                     -|  810  |- +3.3V
            test led -|       |- ISP switch
                      |_______|

 */
