#include <SoftwareSerial.h>

#define rxPin 10
#define txPin 11
char data_in ;
int led_communication = 7;
int led_message = 6;

SoftwareSerial mySerial = SoftwareSerial(rxPin, txPin);
void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(led_communication, OUTPUT);
  pinMode(led_message, OUTPUT);

  mySerial.begin(9600);
  Serial.begin(9600);
}
void loop() {
  if (mySerial.available() > 0) {
    data_in = (char)mySerial.read();
    Serial.println("Communication OK");
    Serial.print(data_in);
    digitalWrite(led_communication, HIGH);
    //delay(100);
   }
   else {
    Serial.println("Pas de communication");
    digitalWrite(led_communication, LOW);
    //delay(100);
    }

  if (data_in == 'a') {
    if (digitalRead(led_message) == LOW) {
        digitalWrite(led_message, HIGH); // Allume la LED si elle est éteinte
    } 
    else {
        digitalWrite(led_message, LOW); // Éteint la LED si elle est allumée
    }
    //delay(5);
  }
}
