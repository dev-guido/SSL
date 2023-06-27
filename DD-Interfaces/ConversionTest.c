#include <assert.h>
#include <math.h>
#include "Conversion.h"

double dameUnDecimal(double num) {
    return round(num*10)/10;
}

int main(void) {
    /* F -> C */
    assert(dameUnDecimal(Celcius(0)) == -17.8);
    assert(dameUnDecimal(Celcius(20)) == -6.7);
    assert(dameUnDecimal(Celcius(40)) == 4.4);
    assert(dameUnDecimal(Celcius(60)) == 15.6);
    assert(dameUnDecimal(Celcius(80)) == 26.7);
    assert(dameUnDecimal(Celcius(100)) == 37.8);
    assert(dameUnDecimal(Celcius(120)) == 48.9);
    assert(dameUnDecimal(Celcius(140)) == 60.0);
    assert(dameUnDecimal(Celcius(160)) == 71.1);
    assert(dameUnDecimal(Celcius(180)) == 82.2);
    assert(dameUnDecimal(Celcius(200)) == 93.3);
    assert(dameUnDecimal(Celcius(220)) == 104.4);
    assert(dameUnDecimal(Celcius(240)) == 115.6);
    assert(dameUnDecimal(Celcius(260)) == 126.7);
    assert(dameUnDecimal(Celcius(280)) == 137.8);
    assert(dameUnDecimal(Celcius(300)) == 148.9);

    /* F -> C */
    assert(dameUnDecimal(Farenheit(-20.0)) == -4.0);
    assert(dameUnDecimal(Farenheit(-8.9)) == 16.0);
    assert(dameUnDecimal(Farenheit(2.2)) == 36.0);
    assert(dameUnDecimal(Farenheit(13.3)) == 55.9);
    assert(dameUnDecimal(Farenheit(24.4)) == 75.9);
    assert(dameUnDecimal(Farenheit(35.5)) == 95.9);
    assert(dameUnDecimal(Farenheit(46.6)) == 115.9);
    assert(dameUnDecimal(Farenheit(57.7)) == 135.9);
    assert(dameUnDecimal(Farenheit(68.8)) == 155.8);
    assert(dameUnDecimal(Farenheit(79.9)) == 175.8);
    assert(dameUnDecimal(Farenheit(91.0)) == 195.8);
    assert(dameUnDecimal(Farenheit(102.1)) == 215.8);
    assert(dameUnDecimal(Farenheit(113.2)) == 235.8);
    assert(dameUnDecimal(Farenheit(124.3)) == 255.7);
    assert(dameUnDecimal(Farenheit(135.4)) == 275.7);
    assert(dameUnDecimal(Farenheit(146.5)) == 295.7);
    return 0;
}