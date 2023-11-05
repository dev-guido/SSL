#include <stdio.h>
#include <ctype.h>

int T(int q, int x);

int esta_en(int caracter, int *lista, int largo_lista){
    for(int i=0; i<largo_lista; i++){
        if(caracter==lista[i]){
            return 1;
        }
        return 0;
    }
}

int main(int argc, char **argv) {
    char *input_filename = "expresiones.txt";
    FILE *input_fp = fopen(input_filename, "r");

    FILE *output_fptr;
    output_fptr = fopen("tokens.csv", "w");

    int caract_ignorados[2] = {'\t', ' '};
    int operadores[6] = {'+', '-', '*', '/', '(', ')'};
    int x, input_tabla;
    int estado_actual = 0;

    while ((x = fgetc(input_fp)) != EOF) {
        if (!esta_en(x, caract_ignorados, 2)) {
            printf("estado ant:%d, caracter ingresado:%c ", estado_actual, x);
            if(isdigit(x)){
                input_tabla = 0;
                if(estado_actual==0){
                    fputs("Constante numerica,", output_fptr);
                }
                fputc(x, output_fptr);
            }
            else if(esta_en(x,operadores,6)){
                input_tabla = 1;
                if(estado_actual==1){
                    fputc('\n', output_fptr);
                }
                fputs("Operador,", output_fptr);
                fputc(x, output_fptr);
                fputc('\n', output_fptr);
            }
            else if(x=='\n'){
                input_tabla = 1;
                if(estado_actual==1){
                    fputc('\n', output_fptr);
                }
            }
            else{
                input_tabla = 2;
            }
            estado_actual = T(estado_actual, x);
            printf("estado actual:%d\n", estado_actual);
        }
        if (estado_actual == 2) {
            printf("RECHAZADA\n");
            estado_actual = 0;
        }
    }
    fclose(input_fp);
    fclose(output_fptr);
    return 0;
}

int T(int q, int x) {
    static int tabla[3][3] = {
        {1, 0, 2},
        {1, 0, 2},
        {2, 2, 2}
    };
    return tabla[q][x];
}