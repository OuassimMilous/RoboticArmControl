#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

SoftwareSerial LEDB(2, 3);
LiquidCrystal_I2C lcd(0x27, 20, 4);
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
String data;
int dataint;
int LED = 6;
int btnID = 8;
int btn ;
int i;
char state = 0;

void setup() {
  servo1.attach(11);
  servo1.write(0);
  servo2.attach(5);
  servo2.write(0);
  servo3.attach(6);
  servo3.write(0);
  servo4.attach(9);
  servo4.write(0);
  servo5.attach(10);
  servo5.write(0);

  delay(500);
  delay(1000);
  lcd.init();
  lcd.backlight();
  lcd.clear();

  pinMode(LED, OUTPUT);
  pinMode(btnID, INPUT);
  btn = 0;
  i = 0;
  analogWrite(LED, 0);
  Serial.begin(9600);
  LEDB.begin(9600);
  LEDB.println("OI MATE");


}

void loop() {

  if (LEDB.available() > 0) {
    data = LEDB.readString();
    Serial.println(data);
    Serial.println(data[0]);


    if (data[0] == '1') {
      for (int j = 1; j < data.length(); j++) {
        data[j - 1] = data[j];
      }
      data.remove(data.length() - 1);
      Serial.println(data);
      dataint = data.toInt();
      dataint = dataint * 180 / 100;
      servo1.write(dataint);

    } else  if (data[0] == '2') {
      for (int j = 1; j < data.length(); j++) {
        data[j - 1] = data[j];
      }
      data.remove(data.length() - 1);
      Serial.println(data);
      dataint = data.toInt();
      dataint = dataint * 180 / 100;
      servo2.write(dataint);
    } else  if (data[0] == '3') {
      for (int j = 1; j < data.length(); j++) {
        data[j - 1] = data[j];
      }
      data.remove(data.length() - 1);
      Serial.println(data);
      dataint = data.toInt();
      dataint = dataint * 180 / 100;
      servo3.write(dataint);
    } else  if (data[0] == '4') {
      for (int j = 1; j < data.length(); j++) {
        data[j - 1] = data[j];
      }
      data.remove(data.length() - 1);
      Serial.println(data);
      dataint = data.toInt();
      dataint = dataint * 180 / 100;
      servo4.write(dataint);
    } else  if (data[0] == '5') {
      for (int j = 1; j < data.length(); j++) {
        data[j - 1] = data[j];
      }
      data.remove(data.length() - 1);
      Serial.println(data);
      dataint = data.toInt();
      dataint = dataint * 180 / 100;
      servo5.write(dataint);
    }

  }

  if (digitalRead(btnID) == 1) {
    while (digitalRead(btnID) == 1) {
    }
    i = i + 1;
    Serial.println(i);
  }
}
