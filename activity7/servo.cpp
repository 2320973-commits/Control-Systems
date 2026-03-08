#include <Servo.h>

Servo myServo;
const int servoPin = 9;

void setup() {
Serial.begin(9600);
myServo.attach(servoPin);
Serial.println("Arduino ready. Enter 0-180:");
}

void loop() {
if (Serial.available() > 0) {
// Read the incoming integer
int inputVal = Serial.parseInt();

// Clear buffer of any leftover characters (like
)
while (Serial.available() > 0) { Serial.read(); }

// Error proofing: Check if within range
if (inputVal >= 0 && inputVal <= 180) {
myServo.write(inputVal);
Serial.print("Moved to: ");
Serial.println(inputVal);
} else {
Serial.print("Invalid input ignored: ");
Serial.println(inputVal);
}
}
}