#include "Thermistor.h"
#include "Arduino.h"

Thermistor::~Thermistor(){}

Thermistor::Thermistor(){}

Thermistor::Thermistor(uint8_t t_pin, int t_ro, int t_rf) : m_pin(t_pin), m_ro(t_ro), m_rf(t_rf){}

Thermistor::Thermistor(uint8_t t_pin, int t_ro, int t_rf, int t_beta) : m_pin(t_pin), m_ro(t_ro), m_rf(t_rf), m_beta(t_beta){}

Thermistor::Thermistor(uint8_t t_pin, int t_ro, int t_rf, double t_ka, double t_kb, double t_kc) : m_pin(t_pin), m_ro(t_ro), m_rf(t_rf), m_ka(t_ka), m_kb(t_kb), m_kc(t_kc){
  
  m_mode = STEINHART;
  }

void Thermistor::calcTemperature(){
  
  float r;
  int adc_value = 0;
 
  for(int i = 0; i < m_resolution; i++){
    adc_value += analogRead(m_pin);
  }

  adc_value /= m_resolution;
  r = m_rf *(ADC_RESOLUTION/adc_value - 1);
  
  switch (m_mode){
    case BETA:
      m_temperature = (1.0/(((log(r/m_ro))/m_beta) + (1.0/m_to))) - 273;
    break;
    case STEINHART:
      double ln_r = log(r);
      m_temperature = ((1.0)/ (m_ka + (m_kb * ln_r) + (m_kc * pow(ln_r,3)))) - 273;
    
    break;
  }
}

double Thermistor::getTemperature(){
  
  calcTemperature();
  
  return m_temperature;
}

double Thermistor::getTemperature( char scale){
  
  calcTemperature();
  
  switch (scale){
    case 'C':
        return m_temperature;
      break;
    case 'K':
        return m_temperature + 273;
      break;
    case 'F':
        return ((m_temperature * 1.8) + 32);    
      break;
  }
}
