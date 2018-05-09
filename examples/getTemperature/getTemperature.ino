
#include "Thermistor.h"

//Thermistor sensor;


Thermistor sensor(A0, 10000,10000,0.001108042, 0.000238192, 0.000000067);

void setup() {

Serial.begin(9600);

}

void loop() {
    Serial.print(" Temperature: ");Serial.println(sensor.getTemperature());
    delay(2000);
}
