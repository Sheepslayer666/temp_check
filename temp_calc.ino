#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>


#define I2C_ADDR    0x27
#define LCD_COLUMNS 16
#define LCD_ROWS    2
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_ROWS);
#define DHTPIN 2 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.begin(LCD_COLUMNS, LCD_ROWS);
  lcd.backlight();
  lcd.print("Boot up");
  dht.begin();
  delay(3000);
}

void loop() {
  float temperature = dht.readTemperature();
  if (isnan(temperature)) {
    lcd.clear();
    lcd.print("ERROR");
    delay(2000);
    return;
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print((char)223);
  lcd.print("C");

  delay(4000);