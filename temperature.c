#include "temperature.h"

// absolute difference between Celsius and Kelvin
#define DELTA_CK 273.15


struct temperature {
  temp_float_t kelvin;
};


// Getters:

void temp_celsius(const temp_t* temperature, temp_float_t* celsius) {
  temp_ktoc(&temperature->kelvin, celsius);
}
void temp_kelvin(const temp_t* temperature, temp_float_t* kelvin) {
  *kelvin = temperature->kelvin;
}
void temp_fahr(const temp_t* temperature, temp_float_t* fahrenheit) {
  temp_ktof(&temperature->kelvin, fahrenheit);
}


// Setters:

void temp_set_c(temp_t* temperature, const temp_float_t* celsius) {
  temp_ctok(celsius, &temperature->kelvin);
}
void temp_set_k(temp_t* temperature, const temp_float_t* kelvin) {
  temperature->kelvin = *kelvin;
}
void temp_set_f(temp_t* temperature, const temp_float_t* fahrenheit) {
  temp_ftok(fahrenheit, &temperature->kelvin);
}


// Conversions:

// Conversion equations taken from:
// https://www.nist.gov/pml/weights-and-measures/si-units-temperature

void temp_ftoc(const temp_float_t* fahrenheit, temp_float_t* celsius) {
  *celsius = (*fahrenheit - 32.) / 1.8;
}
void temp_ftok(const temp_float_t* fahrenheit, temp_float_t* kelvin) {
  *kelvin = (*fahrenheit - 32.) / 1.8 + DELTA_CK;
}
void temp_ctof(const temp_float_t* celsius, temp_float_t* fahrenheit) {
  *fahrenheit = *celsius * 1.8 + 32.;
}
void temp_ctok(const temp_float_t* celsius, temp_float_t* kelvin) {
  *kelvin = *celsius + DELTA_CK;
}
void temp_ktoc(const temp_float_t* kelvin, temp_float_t* celsius) {
  *celsius = *kelvin - DELTA_CK;
}
void temp_ktof(const temp_float_t* kelvin, temp_float_t* fahrenheit) {
  *fahrenheit = (*kelvin - DELTA_CK) * 1.8 + 32.;
}
