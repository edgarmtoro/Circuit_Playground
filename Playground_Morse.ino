//Libraries
#include <Adafruit_CircuitPlayground.h>

//Variables
int pixeln=0;
boolean redLED=true;
char input;
int s = 100; //short dash
int l = s*3;//long dash
int e = s*7;//space or end of word
int R = 128;
int G = 0;
int B = 128;
int f = 440; //sound frequency

void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Heartbeat
  HeartBeat();
  
    switch(Serial.read())
      {
      case 'a':
        Dot();
        Dash();
        delay(l);
      break;

      case 'b':
        Dash();
        Dot();
        Dot();
        Dot();  
        delay(l);
      break;

      case 'c':
        Dash();
        Dot();
        Dash();
        Dot();
        delay(l);
      break;
      
      case 'd':
        Dash();
        Dot();  
        Dot();  
        delay(l);
      break;
      
      case 'e':
        Dot();  
        delay(l);
      break;

      case 'f':
        Dot();  
        Dot();
        Dash();
        Dot();
        delay(l);
      break;

      case 'g':
        Dash();
        Dash();
        Dot();
        delay(l);
      break;

      case 'h':
        Dot();
        Dot();
        Dot();
        Dot();
        delay(l);
      break;

      case 'i':
        Dot();
        Dot();
        delay(l);
      break;

      case 'j':
        Dot();
        Dash();
        Dash();
        Dash();
        delay(l);
      break;

      case 'k':
        Dash();
        Dot();
        Dash();
        delay(l);
      break;

      case 'l':
        Dot();
        Dash();
        Dot();
        Dot();
        delay(l);
      break;

      case 'm':
        Dash();
        Dash();
        delay(l);
      break;

      case 'n':
        Dash();
        Dot();
        delay(l);
      break;

      case 'o':
        Dash();
        Dash();
        Dash();
        delay(l);
      break;

      case 'p':
        Dot();
        Dash();
        Dash();
        Dot();
        delay(l);
      break;

      case 'q':
        Dash();
        Dash();
        Dot();
        Dash();
        delay(l);
      break;

      case 'r':
        Dot();
        Dash();
        Dot();
        delay(l);
      break;

      case 's':
        Dot();
        Dot();
        Dot();
        delay(l);
      break;

      case 't':
        Dash();
        delay(l);
      break;

      case 'u':
        Dot();
        Dot();
        Dash();
        delay(l);
      break;

      case 'v':
        Dot();
        Dot();
        Dot();
        Dash();
        delay(l);
      break;

      case 'w':
        Dot();
        Dash();
        Dash();
        delay(l);
      break;

      case 'x':
        Dash();
        Dot();
        Dot();
        Dash();
        delay(l);
      break;

      case 'y':
        Dash();
        Dot();
        Dash();
        Dash();
        delay(l);
      break;

      case 'z':
        Dash();
        Dash();
        Dot();
        Dot();
        delay(l);
      break;

      case '1':
        Dot();
        Dash();
        Dash();
        Dash();
        Dash();
        delay(l);
      break;

      case '2':
        Dot();
        Dot();
        Dash();
        Dash();
        Dash();
        delay(l);
      break;

      case '3':
        Dot();
        Dot();
        Dot();
        Dash();
        Dash();
        delay(l);
      break;

      case '4':
        Dot();
        Dot();
        Dot();
        Dot();
        Dash();
        delay(l);
      break;

      case '5':
        Dot();
        Dot();
        Dot();
        Dot();
        Dot();        
        delay(l);
      break;

      case '6':
        Dash();
        Dot();
        Dot();
        Dot();
        Dot();        
        delay(l);
      break;

      case '7':
        Dash();
        Dash();
        Dot();
        Dot();
        Dot();        
        delay(l);
      break;

      case '8':
        Dash();
        Dash();
        Dash();
        Dot();
        Dot();        
        delay(l);
      break;

      case '9':
        Dash();
        Dash();
        Dash();
        Dash();
        Dot();        
        delay(l);
      break;

      case '0':
        Dash();
        Dash();
        Dash();
        Dash();
        Dash();        
        delay(l);
      break;
      
      default:
        delay(e); //space or end of word
      }
    }

void HeartBeat()
  {
  CircuitPlayground.redLED(true);
  delay(100);
  CircuitPlayground.redLED(false);
  delay(100);
  }

void LightAllPixels()
  {
  for (pixeln=0;pixeln<=11;pixeln++)
    {  
    CircuitPlayground.setPixelColor(pixeln,R,G,B);
    }
  }

void Dash()
  {
  if (CircuitPlayground.slideSwitch()) //switch positive leds
    {
    LightAllPixels();
    delay(l);
    CircuitPlayground.clearPixels();
    delay(s);
    }
  else //switch negative sound
    {
    CircuitPlayground.playTone(f, l);
    delay (s);
    }
  }

void Dot()
  {
  if (CircuitPlayground.slideSwitch()) //switch positive leds
    {
    LightAllPixels();
    delay(s);
    CircuitPlayground.clearPixels();
    delay(s);
    }
  else //switch negative sound
    {
    CircuitPlayground.playTone(f, s);
    delay (s);
    }
  }

