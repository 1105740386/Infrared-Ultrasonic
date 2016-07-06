#include <Arduino.h>
#include <HardwareSerial.h>
#include <Print.h>
#include <WString.h>

#include "header/IRremote/IRremote.h"

#define PIN_RED 2
#define PIN_GREEN 3
#define PIN_YELLOW 4
#define PIN_RADAR 10
#define PIN_RELAY 11

// leds
int leds[3] = { 2, 3, 4 };

// radar
IRrecv irrecv(PIN_RADAR);
decode_results results;

//
const String RADAR_OK = "111111110000001011111101";

void setup() {
	Serial.begin(9600);

	pinMode(PIN_RED, OUTPUT);
	pinMode(PIN_GREEN, OUTPUT);
	pinMode(PIN_YELLOW, OUTPUT);
	pinMode(PIN_RELAY, OUTPUT);

	irrecv.enableIRIn();
}

void loop() {

	if (irrecv.decode(&results)) {
		//Serial.println(results.value, BIN);
		String tempRadarValue = String(results.value, BIN);
		Serial.println(tempRadarValue);

		controlMotor(tempRadarValue);

		irrecv.resume();
	}

	for (int i = 0; i <= 2; i++) {
		digitalWrite(leds[i], HIGH);
		delay(50);
		digitalWrite(leds[i], LOW);
		delay(50);
	}
}

void controlMotor(String radarValue) {
	if (radarValue.equals(RADAR_OK)) {
		digitalWrite(PIN_RELAY, LOW);
	} else {
		digitalWrite(PIN_RELAY, HIGH);
	}
}
