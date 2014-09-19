/*** LPC810 Arduino compatible library example ***/

/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  This example code is in the public domain.
 */

void setup() {
  // initialize the digital pin as an output.
  // Pin 2 has an LED connected on LPC810 mini-kit
  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH);    // set the LED on
  delay(1000);              // wait for a second
  digitalWrite(2, LOW);     // set the LED off
  delay(1000);              // wait for a second
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
