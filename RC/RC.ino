/* This code has to be uploaded on the Arduino Uno or similaqr dev. board.
 *  
 *  L298 connections:
 *  
 *  M1Pin1 --> Pin D2
 *  M1Pin2 --> Pin D3
 *  M2Pin1 --> Pin D4
 *  M2Pin2 --> Pin D5
 *  M1En --> Pin D6
 *  M1En --> Pin D7
 *  
 *  Connect the Vin and Power to Motors appropriately
 *    
 *  BT connections:
 *  TX --> Arduino RX
 *  RX --> Arduino TX
 *  Vin --> 3.3V
 *  Gnd --> Gnd
 */

 //Motor1 Right Wheel
int m1d1=2;
int m1d2=3;
int m1e=6;

//Motor2 Left Wheel
int m2d1=4;
int m2d2=5;
int m2e=7;

void setup() {
  //Serial communication initialization
  Serial.begin(9600);

  //Defining the pins of L298D

  pinMode(m1d1, OUTPUT);
  pinMode(m1d2, OUTPUT);
  pinMode(m1e, OUTPUT);
  pinMode(m2d1, OUTPUT);
  pinMode(m2d2, OUTPUT);
  pinMode(m2e, OUTPUT);
}

void loop() {

  //Initialize the Serial Interface:

  if(Serial.available() > 0)
  {
    int inco=Serial.read();

    switch(inco)
    {
      case 'F':
      forward();
      break;

      case 'R':
      right();
      break;

      case 'L':
      left();
      break;

      case 'B':
      back();
      break;

      default:
      halt();
    }
  }

}

void forward()
{
  //Enabling the motors
  digitalWrite(m1e, HIGH);
  digitalWrite(m2e, HIGH);

  //Right wheel forward
  digitalWrite(m1d1, HIGH);
  digitalWrite(m1d2, LOW);

  //Left wheel forward
  digitalWrite(m2d1, HIGH);
  digitalWrite(m2d2, LOW);
}

void right()
{
  //Enabling the motors
  digitalWrite(m1e, HIGH);
  digitalWrite(m2e, HIGH);

  //Right wheel backwards
  digitalWrite(m1d1, LOW);
  digitalWrite(m1d2, HIGH);

  //Left wheel forward
  digitalWrite(m2d1, HIGH);
  digitalWrite(m2d2, LOW);
}

void left()
{
  //Enabling the motors
  digitalWrite(m1e, HIGH);
  digitalWrite(m2e, HIGH);

  //Right wheel forward
  digitalWrite(m1d1, HIGH);
  digitalWrite(m1d2, LOW);

  //Left wheel backward
  digitalWrite(m2d1, LOW);
  digitalWrite(m2d2, HIGH);
}

void back()
{
  //Enabling the motors
  digitalWrite(m1e, HIGH);
  digitalWrite(m2e, HIGH);

  //Right wheel backwards
  digitalWrite(m1d1, LOW);
  digitalWrite(m1d2, HIGH);

  //Left wheel backwards
  digitalWrite(m2d1, LOW);
  digitalWrite(m2d2, HIGH);
}

void halt()
{
  //Disable motors
  digitalWrite(m1e, LOW);
  digitalWrite(m2e, LOW);
}

