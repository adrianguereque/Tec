#include <Arduino.h>

// Working with ultrasonic sensor
const int echoPin = D0;
const int trigPin = D1;

#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701
#define SOUND_SPEED 0.034
long duration;
float distanceCm, distanceInch;

void setup() {
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() {
    handleUltrasonicSensor();
}

void handleUltrasonicSensor() {
    // Working with ultrasonic sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distanceCm = duration / 2 * SOUND_VELOCITY;
    distanceInch = distanceCm * CM_TO_INCH;
    Serial.print("Distance: ");
    Serial.print(distanceCm);
    Serial.print("cm or ");
    Serial.print(distanceInch);
    Serial.println(" inches");
    delay(1000);
}