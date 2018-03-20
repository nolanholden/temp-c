# temp-c
Simple, configurable C temperature type.

### Take a peek!
```c
#ifndef _TEMPERATURE_H_
#define _TEMPERATURE_H_

typedef struct temperature temp_t;

// Specify library precision:
#define TEMPERATURE_FLOAT_TYPE long double
typedef TEMPERATURE_FLOAT_TYPE temp_float_t;

// Getters:
void temp_celsius(const temp_t* temperature, temp_float_t* celsius);
void temp_kelvin(const temp_t* temperature, temp_float_t* kelvin);
void temp_fahr(const temp_t* temperature, temp_float_t* fahrenheit);

// Setters:
void temp_set_c(temp_t* temperature, const temp_float_t* celsius);
void temp_set_k(temp_t* temperature, const temp_float_t* kelvin);
void temp_set_f(temp_t* temperature, const temp_float_t* fahrenheit);

// Conversions:
void temp_ftoc(const temp_float_t* fahrenheit, temp_float_t* celsius);
void temp_ftok(const temp_float_t* fahrenheit, temp_float_t* kelvin);
void temp_ctof(const temp_float_t* celsius, temp_float_t* fahrenheit);
void temp_ctok(const temp_float_t* celsius, temp_float_t* kelvin);
void temp_ktoc(const temp_float_t* kelvin, temp_float_t* celsius);
void temp_ktof(const temp_float_t* kelvin, temp_float_t* fahrenheit);

// Conversion equations taken from:
// https://www.nist.gov/pml/weights-and-measures/si-units-temperature

#endif // _TEMPERATURE_H_
```
