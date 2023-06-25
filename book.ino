// Links:
// https://docs.arduino.cc/built-in-examples/digital/Button

// Pin declarations
const int buttonPin = 2;  // the number of the pushbutton pin
const int button2Pin = 3;
const int buildInLedPin = 13;    // the number of the LED pin
const int ledPin = 4;
const int page1LightPin = A7;
const int page2LightPin = A6;
const int lightThreshold = 15;

// States
int buttonState = 0;  // variable for reading the pushbutton status
int button2State = 0;
int page1LightIntensity = 0;
int page2LightIntensity = 0;

void setup() {
  // Enable Serial
  Serial.begin(9600); 
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(button2Pin, INPUT);
}

void loop() {
  
  buttonState = digitalRead(buttonPin);
  button2State = digitalRead(button2Pin);
  page1LightIntensity = analogRead(page1LightPin);
  page2LightIntensity = analogRead(page2LightPin);
  bool isPage1 = page1LightIntensity > lightThreshold;
  bool isPage2 = page2LightIntensity > lightThreshold;

  Serial.print("page1LightIntensity:");
  Serial.print(page1LightIntensity);
  Serial.print(",page2LightIntensity:");
  Serial.println(page2LightIntensity);

  if (isPage2) {
      // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
      if (buttonState == HIGH || button2State == HIGH) {
        digitalWrite(ledPin, HIGH);
      } else {
        digitalWrite(ledPin, LOW);
      }
  } else if (isPage1) {
    if (buttonState == HIGH && button2State == HIGH) {
        digitalWrite(ledPin, HIGH);
      } else {
        digitalWrite(ledPin, LOW);
      }
  } else {
    digitalWrite(ledPin, LOW);
  }
  
  delay(500);
}
