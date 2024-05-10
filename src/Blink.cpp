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

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(SENSOR, INPUT);
    Serial.begin(115200);

}

char str_sensor[10];

void loop() {
    static long counter = 0;
    counter++;

    float sensor = analogRead(SENSOR);
    dtostrf(sensor, 4, 2, str_sensor);


    printf("%d %s\n", counter, str_sensor);
}
