const int pinBut = 18;  // the number of the pushbutton pin
const int pinLed = 13;    // the number of the LED pin
int buttonState = 0;  // variable for reading the pushbutton status
void setup() {
  pinMode(pinLed, OUTPUT);
  pinMode(pinBut, INPUT);
}
void loop() {
  buttonState = digitalRead(pinBut);
  if (buttonState == HIGH) {
    digitalWrite(pinLed, HIGH);
  } else {
    digitalWrite(pinLed, LOW);
  }
}
