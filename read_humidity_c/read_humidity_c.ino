
// Define PIN slots
#define PUMP1_PIN 13
#define EARTH1_PIN A0

void setup() {
  Serial.begin(9600);
  pinMode(PUMP1_PIN, OUTPUT);
}

void loop() {
  // read the resistance, lower is more humid
  int earth_humidity_1 = analogRead(EARTH1_PIN);
  
  Serial.println(earth_humidity_1);
  
  // Water if resistance is higher than 500
  boolean water = earth_humidity_1 > 500;
  if (water) {
    while (analogRead(EARTH1_PIN) > 380) {
      digitalWrite(PUMP1_PIN, HIGH);
      Serial.println("Water");
    } 
    digitalWrite(PUMP1_PIN, LOW);
  }
  
  delay(10000);
}
