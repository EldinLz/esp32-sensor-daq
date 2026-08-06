#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// Pin connections from your KiCad PCB
const int LIGHT_SENSOR_PIN = 0;
const int SDA_PIN = 4;
const int SCL_PIN = 5;
const int STATUS_LED_PIN = 7;

Adafruit_BME280 bme;
bool bmeAvailable = false;

void setup() {
  Serial.begin(115200);
  delay(500);

  pinMode(STATUS_LED_PIN, OUTPUT);
  digitalWrite(STATUS_LED_PIN, LOW);

  analogReadResolution(12);
  Wire.begin(SDA_PIN, SCL_PIN);

  // Adafruit BME280 normally uses 0x77.
  // Try 0x76 as a backup.
  bmeAvailable = bme.begin(0x77, &Wire);

  if (!bmeAvailable) {
    bmeAvailable = bme.begin(0x76, &Wire);
  }

  if (bmeAvailable) {
    Serial.println("BME280 detected");
  } else {
    Serial.println("BME280 not detected");
  }

  Serial.println(
    "time_ms,light_raw,light_percent,"
    "temperature_C,humidity_percent,pressure_hPa"
  );
}

void loop() {
  digitalWrite(STATUS_LED_PIN, HIGH);

  int lightRaw = analogRead(LIGHT_SENSOR_PIN);
  float lightPercent = (lightRaw / 4095.0) * 100.0;

  Serial.print(millis());
  Serial.print(",");
  Serial.print(lightRaw);
  Serial.print(",");
  Serial.print(lightPercent, 1);
  Serial.print(",");

  if (bmeAvailable) {
    Serial.print(bme.readTemperature(), 2);
    Serial.print(",");
    Serial.print(bme.readHumidity(), 2);
    Serial.print(",");
    Serial.println(bme.readPressure() / 100.0, 2);
  } else {
    Serial.println("NA,NA,NA");
  }

  digitalWrite(STATUS_LED_PIN, LOW);
  delay(1000);
}