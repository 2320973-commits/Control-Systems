int ldrPin = A0;

int led1 = 9;
int led2 = 10;
int led3 = 11;

void setup() {

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int ldrValue = analogRead(ldrPin);

  // DEBUG (check values in Serial Monitor)
  Serial.println(ldrValue);

  // FIXED adaptive brightness
  int brightness = map(ldrValue, 100, 900, 255, 0);

  // safety clamp
  brightness = constrain(brightness, 0, 500);

  // output to all LEDs
  analogWrite(led1, brightness);
  analogWrite(led2, brightness);
  analogWrite(led3, brightness);

  delay(50);
}