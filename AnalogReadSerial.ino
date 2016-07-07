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
#define ECHO  8
#define TE1G  9
#define MIN_DISTANCE 20

int leds[3] = { 2, 3, 4 };
IRrecv irrecv(PIN_RADAR);
decode_results results;
const String RADAR_OK = "111111110000001011111101";
String oldInfraredData;
int relayState = 0;

/**
 * 初始化函数，只在电源接通时执行一次
 */
void setup() {
	Serial.begin(9600);

	pinMode(PIN_RED, OUTPUT);
	pinMode(PIN_GREEN, OUTPUT);
	pinMode(PIN_YELLOW, OUTPUT);
	pinMode(PIN_RELAY, OUTPUT);
	pinMode(ECHO, INPUT);
	pinMode(TE1G, OUTPUT);
	irrecv.enableIRIn();
}

/**
 * Arduino循环函数，每秒钟被执行1W次
 */
void loop() {

	String currentInfraredData = getInfraredData();

	unsigned long distance = getUltrasonicData();

	controlMotorWithInfraredSignal(currentInfraredData);
	controlMotorWithUltrasonicSignal(distance);

	for (int i = 0; i <= 2; i++) {
		digitalWrite(leds[i], HIGH);
		delay(50);
		digitalWrite(leds[i], LOW);
		delay(50);
	}
}

/**
 * 用红外信号控制继电器，按下OK开启接通继电器，启动马达
 */
void controlMotorWithInfraredSignal(String currentInfraredData) {
	if (currentInfraredData.equals(RADAR_OK) && !oldInfraredData.equals(RADAR_OK)) {
		relayState = 1 - relayState;
		delay(100);
	}

	oldInfraredData = currentInfraredData;
	Serial.print("oldInfraredData = ");
	Serial.println(oldInfraredData);

	if (relayState == 1) {
		digitalWrite(PIN_RELAY, LOW);
	} else {
		digitalWrite(PIN_RELAY, HIGH);
	}
}

/**
 * 用超声波信号控制继电器，距离小于20CM，断开继电器，断开马达电源
 */
void controlMotorWithUltrasonicSignal(unsigned long distance) {

	int relayVoltage = digitalRead(PIN_RELAY);

	Serial.print("relayVoltage = ");
	Serial.println(relayVoltage);

	if (relayVoltage == LOW && distance <= MIN_DISTANCE) {
		digitalWrite(PIN_RELAY, HIGH);
	}
}

/**
 * 读取红外信号数据
 */
String getInfraredData() {
	String currentRadarValue;
	if (irrecv.decode(&results)) {
		currentRadarValue = String(results.value, BIN);
		irrecv.resume();
		Serial.println(currentRadarValue);
		delay(100);
	}
	return currentRadarValue;
}

/**
 * 读取超声波数据
 */
unsigned long getUltrasonicData() {
	// 使发出发出超声波信号接口低电平2μs
	digitalWrite(TE1G, LOW);
	delayMicroseconds(2);
	// 使发出发出超声波信号接口高电平10μs，这里是至少10μs
	digitalWrite(TE1G, HIGH);
	delayMicroseconds(10);
	// 保持发出超声波信号接口低电平
	digitalWrite(TE1G, LOW);
	delayMicroseconds(2);
	// 读出脉冲时间 // 将脉冲时间转化为距离（单位：厘米）
	unsigned long distance = pulseIn(ECHO, HIGH) / 58;
	//输出距离值
	Serial.println(distance);
	return distance;
}
