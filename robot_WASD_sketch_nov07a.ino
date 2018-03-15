//Robot Shop WASD

int E1 = 6; //Motor 1 Speed
int E2 = 5; //Motor 2 Speed
int M1 = 8; //Motor 1 Direction
int M2 = 7; //Motor 2 Direction

void setup (void)
{
  int i;
  for (i = 5; i <= 8; i++)
    pinMode(i, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  while (Serial.available()<1){}
  char val = Serial.read();
  int leftspeed = 255;
  int rightspeed = 255;
  switch(val)
    {
      case 'w': //Move Forward
        forward (leftspeed,rightspeed);
        break;
      case 's': //Move Backwards  
        reverse (leftspeed,rightspeed);
        break;
      case 'a': //Move Left 
        left (leftspeed,rightspeed);
        break;
      case 'd': //Move Right
        right (leftspeed,rightspeed);
        break;
      default:
        stop();
        break;
    }
  delay (100);
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

