#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
#include "GravityTDS.h"

#define turbidityPin A0
#define TdsSensorPin A1
#define greenLEDPin 8
#define yellowLEDPin 9
#define redLEDPin 10

GravityTDS gravityTds;

// Initialize the LCD with the I2C address (usually 0x27 or 0x3F for 16x2 LCDs)
LiquidCrystal_I2C lcd(0x27, 16, 2);

float temperature = 25, tdsValue = 0;

void setup() {
    Serial.begin(9600);
    pinMode(turbidityPin, INPUT);

    // Set up LCD
    lcd.begin();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Water Quality");

    // Initialize TDS sensor
    gravityTds.setPin(TdsSensorPin);
    gravityTds.setAref(5.0);  // Reference voltage on ADC, default 5.0V on Arduino UNO
    gravityTds.setAdcRange(1024);  // 1024 for 10bit ADC; 4096 for 12bit ADC
    gravityTds.begin();  // Initialization

    // Initialize LED pins
    pinMode(greenLEDPin, OUTPUT);
    pinMode(yellowLEDPin, OUTPUT);
    pinMode(redLEDPin, OUTPUT);

    delay(2000);  // Allow time to read "Water Quality" message on LCD
}

void loop() {
    // Read turbidity sensor
    int turbiditysensorValue = analogRead(turbidityPin);
    int turbidity = map(turbiditysensorValue, 0, 750, 100, 0);

    // Temperature setting and TDS value calculation
    gravityTds.setTemperature(temperature);  // Set temperature for compensation
    gravityTds.update();  // Sample and calculate
    tdsValue = gravityTds.getTdsValue();  // Get the TDS value

    // Display turbidity and TDS on Serial Monitor
    Serial.print("Turbidity: ");
    Serial.print(turbidity);
    Serial.println(" NTU");

    Serial.print("TDS: ");
    Serial.print(tdsValue);
    Serial.println(" ppm");

    // Determine water quality and update LEDs and LCD display
    String quality;
    if (turbidity <= 5 && tdsValue < 300) {
        // Good water quality
        digitalWrite(greenLEDPin, HIGH);
        digitalWrite(yellowLEDPin, LOW);
        digitalWrite(redLEDPin, LOW);
        quality = "Good";
    } else if ((turbidity > 5 && turbidity <= 50) || (tdsValue >= 300 && tdsValue < 600)) {
        // Moderate water quality
        digitalWrite(greenLEDPin, LOW);
        digitalWrite(yellowLEDPin, HIGH);
        digitalWrite(redLEDPin, LOW);
        quality = "Moderate";
    } else {
        // Poor water quality
        digitalWrite(greenLEDPin, LOW);
        digitalWrite(yellowLEDPin, LOW);
        digitalWrite(redLEDPin, HIGH);
        quality = "Poor";
    }

    // Update LCD with quality, turbidity, and TDS values
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Quality: ");
    lcd.print(quality);  // Display quality on the first line

    lcd.setCursor(0, 1);
    lcd.print("T:");
    lcd.print(turbidity);
    lcd.print("NTU ");
    lcd.print("D:");
    lcd.print(tdsValue);
    lcd.print("ppm");

    delay(1000);  // Delay for 1 second
}
