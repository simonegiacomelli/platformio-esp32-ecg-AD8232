/*
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */

#include <Arduino.h>

// Set LED_BUILTIN if it is not defined by Arduino framework
// #ifndef LED_BUILTIN
// #define LED_BUILTIN 2
// #endif

#define SENSOR A0
#define SD2_PIN 9
#define SD3_PIN 10

char str_sensor[10];

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(SENSOR, INPUT);
    pinMode(SD2_PIN, INPUT);
    pinMode(SD3_PIN, INPUT);
    Serial.begin(115200);
}

void loop() {
    static long counter = 0;
    counter++;

    float sensor = analogRead(SENSOR);
    dtostrf(sensor, 4, 2, str_sensor);

    int sd2Value = digitalRead(SD2_PIN);
    int sd3Value = digitalRead(SD3_PIN);

    printf("%d %d %s %d\n", sd2Value, sd3Value, str_sensor, counter);
}
