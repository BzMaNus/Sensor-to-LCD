#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>

float temp;
float humid;
LiquidCrystal_I2C lcd(0x27, 16, 2);  
DHT dht11(D4,DHT11);

void setup() {
  temp = 0.0;
  humid = 0.0;
  Serial.begin(9600);
  dht11.begin();
  lcd.begin();
  lcd.setCursor(0,0);
  lcd.print("Humid:");
  lcd.setCursor(0, 1);
  lcd.print("Temp:");
}

void loop() {
  humid = (dht11.readHumidity());
  temp = (dht11.readTemperature());
  lcd.setCursor(7,0);
  lcd.print(humid);
  lcd.print(" %");
  lcd.setCursor(6, 1);
  lcd.print(temp);
  lcd.print(" C");
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print("\t");
  Serial.print("Humid: ");
  Serial.println(humid);
  delay(1000);
}