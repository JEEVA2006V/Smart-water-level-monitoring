#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TRIG_PIN 8
#define ECHO_PIN 7
#define RED_LED 13
#define YELLOW_LED 12
#define GREEN_LED 11

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  lcd.init();
  lcd.backlight();
}

long readDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}

void loop() {
  long distance = readDistance();
  lcd.clear();

  if (distance <= 5) {
    // Tank Full
    digitalWrite(RED_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Water Level: Full");
  } else if (distance <= 15) {
    // Medium
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Water Level: Mid");
  } else {
    // Empty
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Water Level: Low");
  }

  delay(1000);
}
