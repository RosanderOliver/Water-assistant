/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 
 This example code is in the public domain.
 */

// the setup routine runs once when you press reset:

#define PUMP1_PIN 13
#define EARTH1_PIN A0

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(PUMP1_PIN, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the resistance, lower is more humid
  int earth_humidity_1 = analogRead(EARTH1_PIN);
  
  Serial.println(earth_humidity_1);
  
  // Water if resistance is higher than 500
  boolean water = earth_humidity_1 > 500;
  if (water) {
    while (analogRead(EARTH1_PIN) > 350) {
      digitalWrite(PUMP1_PIN, HIGH);
      Serial.println("Water");
    } 
  } else {
    digitalWrite(PUMP1_PIN, LOW);
  }  
  
  delay(10000);
}
