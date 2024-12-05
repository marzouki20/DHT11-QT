#include <DHT.h>

#define DHTPIN 2        // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
#define BUZZER 9        // Buzzer connected to pin 9
#define LED 8           // LED connected to pin 8

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  //Serial.println(F("DHTxx, Buzzer, and LED Test"));

  dht.begin();
  pinMode(BUZZER, OUTPUT); // Set buzzer pin as output
  pinMode(LED, OUTPUT);    // Set LED pin as output
}

void loop() {
  // Wait a few milliseconds between measurements.
  delay(100);

  // Read temperature and humidity values
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if readings are valid
  if (isnan(h) || isnan(t)) {
    //Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Print temperature and humidity values to the Serial Monitor
  //Serial.print(F("Humidity: "));
  //Serial.print(h);
  //Serial.print(F("%  Temperature: "));
  Serial.print(t);
  //Serial.println(F("°C"));

  // Check if temperature exceeds 25°C
  if (t > 23) {
    tone(BUZZER, 1000);   // Activate buzzer with 1KHz signal
    digitalWrite(LED, HIGH); // Turn LED on
    Serial.print("1");
  } else {
    noTone(BUZZER);       // Deactivate buzzer
    digitalWrite(LED, LOW); // Turn LED off
  }
}
