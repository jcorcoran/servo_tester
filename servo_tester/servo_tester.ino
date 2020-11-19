#include <Servo.h>

// WIRING
#define ANALOG_IN1_PIN A0
#define ANALOG_IN2_PIN A1
#define ANALOG_IN3_PIN A2

#define SERVO_OUT1_PIN 9
#define SERVO_OUT2_PIN 10
#define SERVO_OUT3_PIN 11

// These values control the range of expected inputs, manipulate to match the range on your hardware's ADC
// 1024 should work for targets with 10bit ADCs (e.g. Unos/Megas)
#define MIN_ANALOG_VAL 0
#define MAX_ANALOG_VAL 1024

// These values control the output range of the servo, manipulte to match your hardware's range.
// If it sounds like it's fighting at one end of travel, adjust the range up/down.
// Units are "degrees"
#define MIN_SERVO_DEGREES 0
#define MAX_SERVO_DEGREES 160

int pot1, pot2, pot3;
Servo servo1, servo2, servo3;

void setup() {
  servo1.attach(SERVO_OUT1_PIN);
  servo2.attach(SERVO_OUT2_PIN);
  servo3.attach(SERVO_OUT3_PIN);  
}

void loop() {
  //read the potentiometer positions
  pot1 = analogRead(ANALOG_IN1_PIN);
  pot2 = analogRead(ANALOG_IN2_PIN);
  pot3 = analogRead(ANALOG_IN3_PIN);

  //set the servo output positions
  servo1.write(map(pot1, MIN_ANALOG_VAL, MAX_ANALOG_VAL, MIN_SERVO_DEGREES, MAX_SERVO_DEGREES));
  servo2.write(map(pot2, MIN_ANALOG_VAL, MAX_ANALOG_VAL, MIN_SERVO_DEGREES, MAX_SERVO_DEGREES));
  servo3.write(map(pot3, MIN_ANALOG_VAL, MAX_ANALOG_VAL, MIN_SERVO_DEGREES, MAX_SERVO_DEGREES));
  
  delay(20);
}
