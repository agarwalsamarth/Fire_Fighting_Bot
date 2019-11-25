/*------ Arduino Fire Fighting Robot Code----- */
#include <Servo.h>
Servo myservo;

int pos = 90;
boolean fire = false;

/*-------defining Inputs------*/
#define Left_S 7      // left sensor
#define Right_S 2      // right sensor
#define Forward_S 4 //forward sensor

/*-------defining Outputs------*/
#define LM1 9       // left motor
#define LM2 11       // left motor
#define RM1 12     // right motor
#define RM2 6       // right motor
#define pump 3

void setup()
{
  pinMode(Left_S, INPUT);
  pinMode(Right_S, INPUT);
  pinMode(Forward_S, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(pump, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(5, OUTPUT);


  myservo.attach(3);
  myservo.write(pos);////90
  Serial.begin(9600);
  Serial.println(pos);
}

void put_off_fire()
{
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, HIGH);
  /* int count = 0;
    while (count<500)
    {
     digitalWrite(8, HIGH);
     count++;
     Serial.println(count);
    }
    digitalWrite(8, LOW);
  */for (; pos <= 130; pos += 1) {
    //Serial.println(pos);
    digitalWrite(10, HIGH);
    digitalWrite(5, LOW);
    Serial.println("f1");
    myservo.write(pos);
    delay(30);
  }
  for (pos = 130; pos >= 50; pos -= 1) {
    digitalWrite(10, HIGH);
    digitalWrite(5, LOW);
    Serial.println("f2");
    myservo.write(pos);
    delay(30);
  }


  /*
    digitalWrite(pump, HIGH);
    delay(500);

    for (pos = 50; pos <= 130; pos += 1) {
      myservo.write(pos);
      delay(10);
    }
    for (pos = 130; pos >= 50; pos -= 1) {
      myservo.write(pos);
      delay(10);
    }

    digitalWrite(pump, LOW);
  */
  //myservo.write(pos);/////90

   fire = false;
   
    digitalWrite(10, LOW);
    digitalWrite(5, LOW);
   Serial.println("off");
}

void loop()
{


  // myservo.write(0); //Sweep_Servo();
  /*  while (1)
    {
      ////Serial.println(pos)
      for (; pos <= 130; pos += 1) {
        //Serial.println(pos);
        analogWrite(8, 200);
        myservo.write(pos);
        delay(50);
      }
      for (pos = 130; pos >= 50; pos -= 1) {
        analogWrite(8, 130);
        myservo.write(pos);
        delay(50);
      }
    }
      digitalWrite(13,HIGH);
      myservo.write(180);
      delay(1500);
      myservo.write(0);
      delay(1500);
  */
  if (digitalRead(Left_S) == 1 && digitalRead(Right_S) == 1 && digitalRead(Forward_S) == 1) //If Fire not detected all sensors are zero
  {
    Serial.println("no fire detected");
    //Do not move the robot
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
  }
  else if (digitalRead(Left_S) == 0) //If Fire is to the left
  {
    Serial.println("left");
    //Move the robot left
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);

  }

  else if (digitalRead(Right_S) == 0) //If Fire is to the right
  {
    Serial.println("Right");
    //Move the robot rightmmmm
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }

  else if (digitalRead(Forward_S) == 0) //If Fire is straight ahead
  {
    Serial.println("straight");
    //Move the robot forward
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    fire = true;
  }

  while (fire == true)
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
    put_off_fire();
    Serial.println("fire");


  }
}
