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

int ledPin=2;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(ledPin, OUTPUT);
  pinMode(3, OUTPUT);
  Serial_begin(9600); // attention: slightly different syntax compared to Arduino
  Serial_println("I'm LPC810");
}

int sensorValue = 0;        // value read from the pot
const int analogInPin = A1;  // Analog input pin that the potentiometer is attached to
int outputValue = 0;        // value output to the PWM (analog out)

// the loop function runs over and over again forever
void loop() {

  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  //digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)

  delay(100);              		// wait for 00ms
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  //digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW

  delay(100);              		// wait for 100ms

  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 31, 0, 3300);
  Serial_print("ms time: ");
  Serial_printnumber(millis());
  Serial_print("ADC: ");
  Serial_printnumber(outputValue);
  Serial_println("mV ");
  static int k=0;
  analogWrite(0, k++);

}
