#include <Servo.h>

int ldrPin = A0;        // LDR analog pin
int servoPin = 6;       // Servo signal pin
int ldrValue;           // Stores LDR readings

Servo myservo;

void setup() {
  pinMode(ldrPin, INPUT);
  myservo.attach(servoPin);

  Serial.begin(9600);
}

void loop() {

  // Read LDR value
  ldrValue = analogRead(ldrPin);
  Serial.println(ldrValue); // Debugging output

  // Always keep servo ready in default position (not pressing)
  myservo.write(180);

  // If screen goes dark → cactus detected
  if (ldrValue < 600) {
    myservo.write(180);  // Move down (press)
    delay(30);

    myservo.write(50);   // Move up (release)
    delay(500);
  }
}
