int buttonPin = 2;     // Push button pin
int ledPin = 13;       // LED pin

void setup() {
  pinMode(ledPin, OUTPUT);          // LED output
  pinMode(buttonPin, INPUT_PULLUP); // Internal pull-up ON
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {  
    // Button pressed
    digitalWrite(ledPin, HIGH);
  } 
  else {
    // Button not pressed
    digitalWrite(ledPin, LOW);
  }
}