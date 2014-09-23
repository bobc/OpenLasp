/*** LPC810 Arduino compatible library example ***/


/*
  AnalogReadSerial
 Reads an analog input on pin 1, prints the result to the serial monitor

 This example code is in the public domain.
 */

void setup() {
  Serial_begin(9600);
}

void loop() {
  int sensorValue = analogRead(A1);
  Serial_printnumber(sensorValue);
  Serial_println("");
  delay(500);
}





/*
     Arduino LPC810 compatibility test program

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
