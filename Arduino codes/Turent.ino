#include <SoftwareSerial.h>

#include <Servo.h> // servo library 
Servo myservo1, myservo2, myservo3, myservo4, myservo5; 

int bluetoothTx = 0;
int bluetoothRx = 1;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  myservo1.attach(3);
  myservo2.attach(5);
  myservo3.attach(6);
  myservo4.attach(9);
  myservo5.attach(10,900,2000);
    myservo5.writeMicroseconds(900);
    delay(1000);
 
  Serial.begin(9600);

  bluetooth.begin(9600);
}

void loop()
{
  if(bluetooth.available()>= 2 )
  {
    unsigned int servopos = bluetooth.read();
    unsigned int servopos1 = bluetooth.read();
    unsigned int realservo = (servopos1 *256) + servopos;
    Serial.println(realservo);

    if (realservo >= 1000 && realservo <1180) {
      int servo1 = realservo;
      servo1 = map(servo1, 1000, 1180, 0, 180);
      myservo1.write(servo1);
      Serial.println("Servo 1 Rotate");
      delay(10);
    }
    if (realservo >= 2000 && realservo <2180) {
      int servo2 = realservo;
      servo2 = map(servo2, 2000, 2180, 0, 180);
      myservo2.write(servo2);
      Serial.println("Servo 2 Rotate");
      delay(10);
    }
    if (realservo >= 3000 && realservo <3180) {
      int servo3 = realservo;
      servo3 = map(servo3, 3000, 3180, 0, 180);
      myservo3.write(servo3);
      Serial.println("Servo 3 Rotate");
      delay(10);
    }
    if (realservo >= 4000 && realservo <4180) {
      int servo4 = realservo;
      servo4 = map(servo4, 4000, 4180, 0, 180);
      myservo4.write(servo4);
      Serial.println("Servo 4 Rotate");
      delay(10);
    }
    if (realservo >= 5000 && realservo <5180) {
      int servo5 = realservo;
      servo5 = map(servo5, 5000, 5180, 1000, 2000);
      //myservo5.writeMicroseconds(val);
      Serial.println("Servo 5 Rotate");
      delay(2000);
    }
  }
}
