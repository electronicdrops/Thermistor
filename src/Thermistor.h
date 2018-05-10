#ifndef Thermistor_h
#define Thermistor_h

#include "Arduino.h"

/*
 * Default NTC Thermistor 10K -- most common.
 */

#define NTC_TO  298.15

#define NTC_RF 10000
#define NTC_RO 10000
#define NTC_BETA 3977
#define NTC_PIN A0
#define NTC_RESOLUTION 16

#define ADC_RESOLUTION 1023.0

class Thermistor{
  
  private:
      enum Mode {
      BETA, STEINHART
      }     m_mode{BETA};
    uint8_t m_pin{NTC_PIN};
    float   m_to{NTC_TO};
    int     m_beta{NTC_BETA};
    int     m_ro{NTC_RO};
    int     m_rf{NTC_RF};
    int     m_resolution{NTC_RESOLUTION};
    double  m_ka;
    double  m_kb;
    double  m_kc;
    double  m_temperature;
    void calcTemperature();
    
  public:
    ~Thermistor();
    Thermistor();
    Thermistor(uint8_t t_pin_);
    Thermistor(uint8_t t_pin_, int t_ro, int t_rf);
    Thermistor(uint8_t t_pin_, int t_ro, int t_rf, int t_beta);
    Thermistor(uint8_t t_pin_, int t_ro, int t_rf, double t_ka, double t_kb, double t_kc);
    
    double getTemperature();
    double getTemperature(char scale);

    boolean calibrateWithBeta(float t_temp1, float t_r1, float t_temp2, float t_r2);
    boolean calibrateWithSteinhart(float t_temp1, float t_r1, float t_temp2, float t_r2, float t_temp3, float t_r3);       
};

#endif
