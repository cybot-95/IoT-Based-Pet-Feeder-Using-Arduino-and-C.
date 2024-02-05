code started

 #define servo = D8
 

#include <Servo.h>

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>

Servo servo;

char auth[] = " ****** ";//Enter your Blynk auth token

char ssid[] = "*****";//Enter your WIFI name

char pass[] = "*****"" ";//Enter your WIFI password

BLYNK_WRITE(V2){

  servo.write(param.asInt());

  }

  void setup() {

    Serial.begin(9600);

      servo.attach(D8);

        Blynk.begin(auth, ssid, pass);

 }

void loop() {

  Blynk.run();

  }
