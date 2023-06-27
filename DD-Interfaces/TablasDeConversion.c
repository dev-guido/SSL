#include <stdio.h>
#include "Conversion.h"

/* imprime la tabla Fahrenheit-Celsius */

int main() {
    const int f_lower = 0, f_upper = 300, f_step = 20;
    int fahr;
    printf("F -> C\n");
    for (fahr=f_lower; fahr<=f_upper; fahr=fahr+f_step){
        printf("%3d %6.1f\n", fahr, Celcius(fahr));
    }

    const double c_lower = -20.0, c_upper = 150.0, c_step = 11.1;
    double celcius;
    printf(" C -> F\n");
    for (celcius=c_lower; celcius<=c_upper; celcius=celcius+c_step){
        printf("%6.1f %6.1f\n", celcius, Farenheit(celcius));
    }

    return 0;
}