#include <Servo.h>

Servo myServo;  // create a servo object

int angle = 90;   // variable to hold the angle for the servo motor
int lightPin = A0;  //define a pin for Photo resistor
int lightReading;
int flag = 0;

void setup() {
  myServo.attach(9); // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); // open a serial connection to your computer
}

void loop() {
  // set the servo position
  lightReading = analogRead(lightPin); //Write the value of the photoresistor to the serial monitor.

  Serial.println(lightReading);
  if (lightReading > 200){ // if the samsung phone green light is on (done charging)
    // move the servo to knock the phone off charging
    if (flag == 0){
      Serial.println("Move");
      myServo.write(0);
      delay(1000);
      myServo.write(90);
      flag = 1;
    } else {
       myServo.write(90);
    }
  }
}
