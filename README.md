# Thermistor
Arduino-like Library to Work with Thermistor Sensor

Thermistor is a Temperature Sensor whose resistance varies as its temperature varies. You could find many kinds of thermistors, this library controls a NTC type.

## Simple Connection


![Schematic](https://github.com/electronicdrops/Thermistor/img/schematic.png)

## Sensor characteristics you need to know

**RO**: Resistance of Operation - Thermistor resistance at 25<sup>o</sup>C. ___Common Value: 10000 ohms___

**Rf**: Resistance of Reference - Resistor connected in series with thermistor. Making an Voltage Divider. ___Common Value: 10000ohms___

**Beta**: Thermistor constant, is a resistance-temperature characteristic used to calculate the temperature. ___Common Value: 3977___

Or 

**Steinhart-Hart constants**: Constants A,B,C for more precise temperature calculation.


## How to use this library

- Download and include this library using Arduino IDE.
- Include the header.

```c++
#include <Thermistor.h>
```

- Create a Sensor Object.

There are many ways to do this.

Using default parameters. 

```c++
Thermistor sensor;
```
There are other initialization parameters. You could pass the pin which the sensor is connected, the resistance of operation, resistance of reference, the beta constante and pass the steinhart-hart constants.

Ex:

```c++
Thermistor sensor(A0, 10000, 4700,3800); // Passing the PIN: A0, RO: 10.000, Rf: 4.7K, and Beta: 3800
```

To get Temperature:

```c++

float temperature = sensor.getTemperature();

float fahrenheit = sensor.getTemperature('F');

```

**See examples to Know more details.**
