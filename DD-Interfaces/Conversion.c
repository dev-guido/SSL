#include "Conversion.h"

double Celcius(int fahr) {
    return (5.0/9.0)*(fahr-32);
}

double Farenheit(double celcius) {
    return (9.0/5.0)*celcius + 32;
}
