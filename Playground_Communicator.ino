//Libraries
#include <Adafruit_CircuitPlayground.h>

//Variables
int pixeln=0;
boolean redLED=true;

void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  //Heartbeat
  CircuitPlayground.redLED(true);
  delay(100);
  CircuitPlayground.redLED(false);
  delay(100);

  //Communicator Start
  if (CircuitPlayground.leftButton() && CircuitPlayground.slideSwitch())
    {
    //Sound
    CircuitPlayground.playTone(1000, 100);
    delay (50);
    CircuitPlayground.playTone(1500, 100);
    delay (50);
    CircuitPlayground.playTone(1000, 100);

    //Pixels Sequence
    for (pixeln=0;pixeln<=11;pixeln++)
      {
      CircuitPlayground.setPixelColor(pixeln, 255,255,0);
      delay (50);
      }
    }

  //Communicator Off
  if (CircuitPlayground.rightButton())
    {
    //Sound
    CircuitPlayground.playTone(500, 100);
    delay (50);
    CircuitPlayground.playTone(500, 100);

    //Pixel Sequence Reverse
    for (pixeln=11;pixeln>=0;pixeln--)
      {
      CircuitPlayground.setPixelColor(pixeln,0,0,0);
      delay (50);
      }
    }
  }                                                                 
