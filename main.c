 const int trigPin = D5;   
 const int echoPin = D6;   
 long duration;  
 int distance;  
 void setup() {  
 pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output  
 pinMode(echoPin, INPUT); // Sets the echoPin as an Input  
 Serial.begin(9600); // Starts the serial communication  
 }  
 void loop() {  
 // Clears the trigPin  
 digitalWrite(trigPin, LOW);  
 delayMicroseconds(2);  
 // Sets the trigPin on HIGH state for 10 micro seconds  
 digitalWrite(trigPin, HIGH);  
 delayMicroseconds(10);  
 digitalWrite(trigPin, LOW);  
 // Reads the echoPin, returns the sound wave travel time in microseconds  
 duration = pulseIn(echoPin, HIGH);  
 // Calculating the distance  
 distance= duration*0.034/2;  
 // Prints the distance on the Serial Monitor  
 Serial.print("Distance: ");  
 Serial.println(distance);  
 delay(2000);  
 }  
------------------------------------------------------------------------------

->RTCDS3231
#include <Wire.h> // Library for I2C communication
#include <SPI.h>  // not used here, but needed to prevent a RTClib compile error
#include "RTClib.h"
//#include <LiquidCrystal_I2C.h> // Library for LCD
//LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
//connect SDA to D2, SCL to D1 
RTC_DS1307 RTC;     // Setup an instance of DS1307 naming it RTC
 
void setup () 
{
  Serial.begin(57600); // Set serial port speed
 // lcd.begin();
  Wire.begin(); // Start the I2C
  RTC.begin();  // Init RTC
  RTC.adjust(DateTime(__DATE__, __TIME__));  // Time and date is expanded to date and time on your computer at compiletime
  Serial.print('Time and date set');
 // lcd.setCursor(0, 0);
 // lcd.print("Real Time Clock");
  delay(3000);
  //lcd.clear();
}
 
void loop () {
  DateTime now = RTC.now();
 
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
 
  
  lcd.setCursor(0, 0);
  lcd.print("Date: ");
  lcd.setCursor(0, 1);
  lcd.print("Time: ");
  
  lcd.setCursor(6, 0);
  lcd.print(now.year(), DEC);
  lcd.print(":");
  lcd.print(now.month(), DEC);
  lcd.print(":");
  lcd.print(now.day(), DEC);
 
  lcd.setCursor(6, 1);
  lcd.print(now.hour(), DEC);
  lcd.print(":");
  lcd.print(now.minute(), DEC);
  lcd.print(":");
  lcd.print(now.second(), DEC); 
  delay(1000);
  lcd.clear();
}

//-----------------------------------------------------------------------------

//->Servo

 #include <Servo.h> // servo library  
 Servo s1;  
 void setup()  
 {   
  s1.attach(0);  // servo attach D3 pin of arduino  
 }  
 void loop()   
 {  
   s1.write(0);
   Serial.print("Rotation is at 0 degree");
   delay(1000);  
  // s1.write(90);  
   //delay(1000);  
   s1.write(180);
   Serial.print("Rotation is at 180 degree");
   delay(1000);  
 }  

//--------------------------------------------------------------------------------

//-> 1st APF Non-LCD Display Code

#include <Wire.h>
#include <RTClib.h>
#include <Servo.h>

#define const int trigpin = D5; // Ultrasonic sensor echo pin
#define const int echoPin = D6; // Ultrasonic sensor trigger pin
#define SERVO_PIN 1 // Servo motor control pin
 long duration;  
 int distance; 
 
RTC_DS3231 rtc; // RTC module object
Servo servo; // Servo motor object

void setup() {
  Serial.begin(9600);

  // Initialize the ultrasonic sensor pins
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW);
  pinMode(ECHO_PIN, INPUT);

  // Initialize the servo motor pin
  servo.attach(SERVO_PIN);

  // Initialize the RTC module
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  // Check if the RTC module has the correct time
  if (rtc.lostPower()) {
    Serial.println("RTC lost power");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  DateTime now = rtc.now(); // Get the current time

  // Check if it's time to dispense food
  if (now.minute() % 5 == 0) { // Change the interval as desired
    long duration, cm;
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);
    duration = pulseIn(ECHO_PIN, HIGH);
    cm = duration / 58.2;

    // Check if the pet is in front of the feeder
    if (cm <= 10) { // Change the distance as desired
      Serial.println("Pet detected");
      servo.write(180); // Dispense food
      delay(2000); // Wait for the food to dispense
      servo.write(0); // Return to initial position
    } else {
      Serial.println("No pet detected");
    }
  }
  delay(1000);
}


//Serial.println((char*)output, HEX);
