#include<Servo.h>
Servo servo1;//alt dönüş
Servo servo2;//
Servo servo3;//ağır olan
Servo servo4;//ağız

int servo1Poskayit[7] = {1, 1, 1, 1, 1, 1, 1};
int servo2Poskayit[7] = {1, 1, 1, 1, 1, 1, 1};
int servo3Poskayit[7] = {1, 1, 1, 1, 1, 1, 1};
int servo4Poskayit[7] = {1, 1, 1, 1, 1, 1, 1};

int pot1aci;
int pot2aci;
int pot3aci;
int pot4aci;

int pot1last;
int pot2last;
int pot3last;
int pot4last;

int delaySuresi = 4;

int button1deger;

bool button2deger = false;

#define kLed 12
#define yLed 11

#define button1 2
#define button2 10
void setup() {
  Serial.begin(9600);
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(yLed, OUTPUT);
  pinMode(kLed, OUTPUT);


}

void servoDeger(int ser1, int ser2, int ser3, int ser4) {

  //pot2------------------------------------------------------
  if (ser2 > pot2last) {

    for (int i = pot2last; i < ser2; i++) {

      delay(delaySuresi);
      servo2.write(i);
    }
    pot2last = ser2;
  }
  else if (pot2last > ser2) {
    for (int i = pot2last; i > ser2; i--) {
      delay(delaySuresi);
      servo2.write(i);
    }
  }
  pot2last = ser2;
  //pot3------------------------------------------------------
  if (ser3 > pot3last) {

    for (int i = pot3last; i < ser3; i++) {

      delay(delaySuresi);
      servo3.write(i);
    }
    pot3last = ser3;
  }
  else if (pot3last > ser3) {
    for (int i = pot3last; i > ser3; i--) {
      delay(delaySuresi);
      servo3.write(i);
    }
  }
  pot3last = ser3;
  //pot4------------------------------------------------------
  if (ser4 > pot4last) {

    for (int i = pot4last; i < ser4; i++) {

      delay(delaySuresi);
      servo4.write(i);
    }
    pot4last = ser4;
  }
  else if (pot4last > ser4) {
    for (int i = pot4last; i > ser4; i--) {
      delay(delaySuresi);
      servo4.write(i);
    }
  }
  pot4last = ser4;
  //pot1------------------------------------------------------
  if (ser1 > pot1last) {

    for (int i = pot1last; i < ser1; i++) {

      delay(delaySuresi);
      servo1.write(i);
    }
    pot1last = ser1;
  }
  else if (pot1last > ser1) {
    for (int i = pot1last; i > ser1; i--) {
      delay(delaySuresi);
      servo1.write(i);
    }
  }
  pot1last = ser1;
}




void loop() {

  pot1aci = map(analogRead(A0), 0, 1023, 0, 180);
  pot2aci = map(analogRead(A1), 0, 1023, 0, 180);
  pot3aci = map(analogRead(A2), 0, 1023, 0, 180);
  pot4aci = map(analogRead(A3), 0, 1023, 0, 180);

  servo1.write(pot1aci);
  pot1last = pot1aci;
  servo2.write(pot2aci);
  pot2last = pot2aci;
  servo3.write(pot3aci);
  pot3last = pot3aci;
  servo4.write(pot4aci);
  pot4last = pot4aci;
  /*
    Serial.print("pot 1 : "); Serial.println(pot1aci);
    Serial.print("pot 2 : "); Serial.println(pot2aci);
  */
  //Serial.print("pot 3 : "); Serial.println(pot3aci);

  // Serial.print("pot 4 : "); Serial.println(pot4aci);

  if (digitalRead(button1) == HIGH) {
    digitalWrite(kLed, HIGH);
    delay(300);
    button1deger++;
    switch (button1deger) {
      case 1:
        servo1Poskayit[0] = pot1aci;
        servo2Poskayit[0] = pot2aci;
        servo3Poskayit[0] = pot3aci;
        servo4Poskayit[0] = pot4aci;
        //digitalWrite(LED1, HIGH);
        Serial.println("Pos 1 Kayit");
        digitalWrite(yLed, HIGH);
        delay(150);
        digitalWrite(yLed, LOW);
        break;
      case 2:
        servo1Poskayit[1] = pot1aci;
        servo2Poskayit[1] = pot2aci;
        servo3Poskayit[1] = pot3aci;
        servo4Poskayit[1] = pot4aci;
        //digitalWrite(LED2, HIGH);
        Serial.println("Pos 2 Kayit");
        digitalWrite(yLed, HIGH);
        delay(150);
        digitalWrite(yLed, LOW);
        break;
      case 3:
        servo1Poskayit[2] = pot1aci;
        servo2Poskayit[2] = pot2aci;
        servo3Poskayit[2] = pot3aci;
        servo4Poskayit[2] = pot4aci;
        //digitalWrite(LED3, HIGH);
        Serial.println("Pos 3 Kayit");
        digitalWrite(yLed, HIGH);
        delay(150);
        digitalWrite(yLed, LOW);
        break;
      case 4:
        servo1Poskayit[3] = pot1aci;
        servo2Poskayit[3] = pot2aci;
        servo3Poskayit[3] = pot3aci;
        servo4Poskayit[3] = pot4aci;
        //digitalWrite(LED4, HIGH);
        Serial.println("Pos 4 Kayit");
        digitalWrite(yLed, HIGH);
        delay(150);
        digitalWrite(yLed, LOW);
        break;
      case 5:
        servo1Poskayit[4] = pot1aci;
        servo2Poskayit[4] = pot2aci;
        servo3Poskayit[4] = pot3aci;
        servo4Poskayit[4] = pot4aci;
        //digitalWrite(LED5, HIGH);
        Serial.println("Pos 5 Kayit");
        digitalWrite(yLed, HIGH);
        delay(150);
        digitalWrite(yLed, LOW);
        break;
      case 6:
        servo1Poskayit[5] = pot1aci;
        servo2Poskayit[5] = pot2aci;
        servo3Poskayit[5] = pot3aci;
        servo4Poskayit[5] = pot4aci;
        //digitalWrite(LED5, HIGH);
        Serial.println("Pos 6 Kayit");
        digitalWrite(yLed, HIGH);
        delay(150);
        digitalWrite(yLed, LOW);
        break;
      case 7:
        servo1Poskayit[6] = pot1aci;
        servo2Poskayit[6] = pot2aci;
        servo3Poskayit[6] = pot3aci;
        servo4Poskayit[6] = pot4aci;
        //digitalWrite(LED5, HIGH);
        Serial.println("Pos 7 Kayit");
        digitalWrite(yLed, HIGH);
        digitalWrite(kLed, HIGH);
        delay(150);
        digitalWrite(yLed, LOW);
        digitalWrite(kLed, LOW);
        delay(150);
        digitalWrite(yLed, HIGH);
        digitalWrite(kLed, HIGH);
        delay(150);
        digitalWrite(yLed, LOW);
        digitalWrite(kLed, LOW);
        delay(150);
        digitalWrite(yLed, HIGH);
        digitalWrite(kLed, HIGH);
        delay(150);
        digitalWrite(yLed, LOW);
        digitalWrite(kLed, LOW);
        break;
    }
  }

  if (digitalRead(button2) == HIGH) {
    button2deger = true;
  }

  if (button2deger) {
    digitalWrite(yLed, HIGH);
    digitalWrite(kLed, HIGH);
    for (int i = 0; i < 7; i++) {
      delay(1500);
      if (digitalRead(button2) == HIGH) {
        button2deger = false;
        break;
      }/*
      servo1.write(servo1Poskayit[i]);
      servo2.write(servo2Poskayit[i]);
      servo3.write(servo3Poskayit[i]);
      servo4.write(servo4Poskayit[i]);*/
      servoDeger(servo1Poskayit[i], servo2Poskayit[i], servo3Poskayit[i], servo4Poskayit[i]);

      /*
        Serial.println(" Potansiyometre acilari: ");
        Serial.println(servo1Poskayit[i]);
        Serial.println(servo2Poskayit[i]);
        Serial.println(servo3Poskayit[i]);
      */
      if (digitalRead(button2) == HIGH) {
        button2deger = false;
        break;
      }
    }
  }

}
