//Robot Shop with IR Control
#include <IRremote.h>
#include <IRremoteInt.h>

int E1 = 6; //Motor 1 Speed
int E2 = 5; //Motor 2 Speed
int M1 = 8; //Motor 1 Direction
int M2 = 7; //Motor 2 Direction

int RECV_PIN = 9;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() 
{
  int i;
  for (i = 5; i <= 8; i++)
    pinMode(i, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop()
{
  int leftspeed = 255;
  int rightspeed = 255;

  if (irrecv.decode (&results))
  {
    if (results.value == 752) //Forward
    {
      forward (leftspeed, rightspeed);
      delay (1000);
    }
    
    if (results.value == 3280) //Right
    {
      right (leftspeed, rightspeed);
      delay (500);
    }
    
    if (results.value == 2800) //Reverse
    {
      reverse (leftspeed, rightspeed);
      delay (1000);
    }
    
    if (results.value == 720) //Left
    {
      left (leftspeed, rightspeed);
      delay (500);
    }

    stop();
    irrecv.resume();
  }

}

void forward (char a, char b)
{
  analogWrite (E1, a);
  digitalWrite (M1, LOW);
  analogWrite (E2, b);
  digitalWrite (M2, LOW);
}

void reverse (char a, char b)
{
  analogWrite (E1, a);
  digitalWrite (M1, HIGH);
  analogWrite (E2, b);
  digitalWrite (M2, HIGH);
}

void left (char a, char b)
{
  analogWrite (E1, a);
  digitalWrite (M1, HIGH);
  analogWrite (E2, b);
  digitalWrite (M2, LOW);
}

void right (char a, char b)
{
  analogWrite (E1, a);
  digitalWrite (M1, LOW);
  analogWrite (E2, b);
  digitalWrite (M2, HIGH);
}

void stop (void)
{
  digitalWrite (E1, LOW);
  digitalWrite (E2, LOW);
}
