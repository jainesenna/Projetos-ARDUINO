#include <Servo.h> 
Servo myservo;
int pos = 0;
// constants won't change. Used here to set a pin number:
const int buttonPin = 2;
const int ledPin1 = 10;
const int ledPin2 = 9;
const int ledPin3 = 8;

// Variables will change:
int buttonState = 0;
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  myservo.attach(6);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(115200);
}

void loop() {
 
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
      Serial.print(ledState);
    } else {
      ledState = LOW;
      Serial.print(ledState);
    }
    digitalWrite(ledPin3, ledState); 
    for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
      myservo.write(pos);              // tell servo to go to position in variable 'pos' 
      delay(15);                       // waits 15ms for the servo to reach the position 
    } 
    for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
    {                                
      myservo.write(pos);              // tell servo to go to position in variable 'pos' 
      delay(15);                       // waits 15ms for the servo to reach the position 
    }
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH){
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
    }else{
      digitalWrite(ledPin1, LOW); 
      digitalWrite(ledPin2, HIGH);
    }
   
  }
   
  
  
}
