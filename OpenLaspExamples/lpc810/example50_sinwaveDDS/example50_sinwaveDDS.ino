/*
  simple DDS sin wave generator

  DDS:
    http://en.wikipedia.org/wiki/Direct_digital_synthesizer

  generate an audio signal on analog output

   created 2014
   by ChrisMicro

   This example code is in the public domain.

*/

int analogOutPin=3;

void setup() {
  // initialize the digital pin as an output.
  pinMode(analogOutPin, OUTPUT);
}

int8_t sintab[256]=
{
  0 ,3 ,6 ,9 ,12 ,15 ,18 ,21 ,24 ,27 ,30 ,33 ,36 ,39 ,42 ,45 ,48 ,51 ,54 ,57 ,59 ,62 ,65 ,67 ,70 ,73 ,75 ,78 ,80 ,82 ,85 ,87 ,
  89 ,91 ,94 ,96 ,98 ,100 ,102 ,103 ,105 ,107 ,108 ,110 ,112 ,113 ,114 ,116 ,117 ,118 ,119 ,120 ,121 ,122 ,123 ,123 ,124 ,125 ,
  125 ,126 ,126 ,126 ,126 ,126 ,127 ,126 ,126 ,126 ,126 ,126 ,125 ,125 ,124 ,123 ,123 ,122 ,121 ,120 ,119 ,118 ,117 ,116 ,114 ,
  113 ,112 ,110 ,108 ,107 ,105 ,103 ,102 ,100 ,98 ,96 ,94 ,91 ,89 ,87 ,85 ,82 ,80 ,78 ,75 ,73 ,70 ,67 ,65 ,62 ,59 ,57 ,54 ,51 ,
  48 ,45 ,42 ,39 ,36 ,33 ,30 ,27 ,24 ,21 ,18 ,15 ,12 ,9 ,6 ,3 ,0 ,-3 ,-6 ,-9 ,-12 ,-15 ,-18 ,-21 ,-24 ,-27 ,-30 ,-33 ,-36 ,-39 ,
  -42 ,-45 ,-48 ,-51 ,-54 ,-57 ,-59 ,-62 ,-65 ,-67 ,-70 ,-73 ,-75 ,-78 ,-80 ,-82 ,-85 ,-87 ,-89 ,-91 ,-94 ,-96 ,-98 ,-100 ,-102 ,
  -103 ,-105 ,-107 ,-108 ,-110 ,-112 ,-113 ,-114 ,-116 ,-117 ,-118 ,-119 ,-120 ,-121 ,-122 ,-123 ,-123 ,-124 ,-125 ,-125 ,-126 ,
  -126 ,-126 ,-126 ,-126 ,-127 ,-126 ,-126 ,-126 ,-126 ,-126 ,-125 ,-125 ,-124 ,-123 ,-123 ,-122 ,-121 ,-120 ,-119 ,-118 ,-117 ,
  -116 ,-114 ,-113 ,-112 ,-110 ,-108 ,-107 ,-105 ,-103 ,-102 ,-100 ,-98 ,-96 ,-94 ,-91 ,-89 ,-87 ,-85 ,-82 ,-80 ,-78 ,-75 ,-73 ,
  -70 ,-67 ,-65 ,-62 ,-59 ,-57 ,-54 ,-51 ,-48 ,-45 ,-42 ,-39 ,-36 ,-33 ,-30 ,-27 ,-24 ,-21 ,-18 ,-15 ,-12 ,-9 ,-6 ,-3
};


int frequency=440;
int samplingTime_us=100;

int phase=0;
int phaseDelta;

void loop()
{
  phaseDelta=frequency*samplingTime_us*65536/1000000UL;

  while(1)
  {
    // sin wave DDS ( direct digital synthesis )
    int value=128+sintab[(phase>>8)&0xFF];

    analogWrite(analogOutPin,value);
    // increment phase accumulator
    phase+=phaseDelta;

    delayMicroseconds(samplingTime_us);

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
             speaker -|  810  |- +3.3V
            test led -|       |- ISP switch
                      |_______|

 */



