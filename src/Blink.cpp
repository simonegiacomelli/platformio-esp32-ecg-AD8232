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
#define LEADSOFF_M_PIN 10
#define LEADSOFF_P_PIN 9

char str_sensor[10];

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(SENSOR, INPUT);
    pinMode(LEADSOFF_M_PIN, INPUT);
    pinMode(LEADSOFF_P_PIN, INPUT);
    Serial.begin(115200);
}

void loop() {
    static long counter = 0;
    static long skipped = 0;

    static unsigned long lastRead = 0;
    unsigned long currentMillis = millis();

    if (currentMillis - lastRead >= 4) {
        lastRead = currentMillis;
        counter++;

        float sensor = analogRead(SENSOR);
        dtostrf(sensor, 4, 2, str_sensor);

        int loMinuValue = digitalRead(LEADSOFF_M_PIN);
        int loPlusValue = digitalRead(LEADSOFF_P_PIN);


        printf("all %d %d %s %ld %ld\n"
               ">ecg:%s\n"
               ">lo+:%d\n"
               ">lo-:%d\n",
               loMinuValue, loPlusValue, str_sensor, counter, skipped,
               str_sensor,
               loPlusValue,
               loMinuValue);
//        printf(">ecg:%s\n", str_sensor);
//        printf(">lo+:%d\n", loPlusValue);
//        printf(">lo-:%d\n", loMinuValue);
    } else {
        skipped++;
    }
}
