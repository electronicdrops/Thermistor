
#include "Thermistor.h"

Thermistor sensor;

// Passing sensor pin
// Thermistor sensor(A0);

// Passing sensor pin, RO, Rf, Beta      
// Thermistor sensor(A0, 10000,10000,3800);

// Passing sensor pin, RO, Rf, Steinhart-Hart coeficients
// Thermistor sensor(A0, 10000,10000,0.001108042, 0.000238192, 0.000000067);

void setup() {

Serial.begin(9600);

}

void loop() {
    Serial.print(" Temperature: ");Serial.println(sensor.getTemperature());
    delay(2000);
}
