#include <LiquidCrystal.h>

const int sensorPin = A0;
const float baselineTem = 20.0;
int temp;
int wind;
int windCount;
LiquidCrystal lcd (12, 11, 5, 4, 3, 7);

// the setup routine runs once when you press reset:
void setup() {
  lcd.begin(16, 2);
  lcd.clear();
}

// the loop routine runs over and over again forever:
void loop() {
  attachInterrupt(digitalPinToInterrupt(2), windteller, RISING);  
  LCDprints();
  resetCounters();
  delay(1000);
  lcd.clear();
}

float temperatuur_berekening() {
  int sensor = analogRead(sensorPin);
  float volt = sensor *5.0;
  volt /= 1024.0;
  float temp = (volt -0.5) * 100; 
  return temp; 
}

void windteller(){
  windCount++;
  }

void LCDprints() {
  lcd.print("Temp:");
  lcd.setCursor(0, 1);
  lcd.print(temperatuur_berekening());
  lcd.setCursor(6, 1);
  lcd.print("C");
  
  lcd.setCursor(9,0);
  lcd.print("Wind:");
  lcd.setCursor(9,1);
  lcd.print(windCount*3);
 
  lcd.setCursor(13,1);
  lcd.print("m/s");
}

void resetCounters() {
 windCount = 0;
 wind = 0;
}

