#include <stdio.h>
#include <ctype.h>
#define NUEVO_TOKEN 0
#define ESCRIBIENDO_NUMERO 1
#define RECHAZADO 2

#define INPUT_DIGITO 0
#define INPUT_OPERADOR 1
#define INPUT_CARACTER_DESCONOCIDO 2

int T(int q, int x);

int esta_en(int caracter, int *lista, int largo_lista){
    for(int i=0; i<largo_lista; i++){
        if(caracter==lista[i]){
            return 1;
        }
    }
    return 0;
}

int main(int argc, char **argv) {
    char *input_filename = "expresiones.txt";
    FILE *input_fp = fopen(input_filename, "r");

    FILE *output_fptr;
    output_fptr = fopen("tokens.csv", "w");

    int caract_ignorados[2] = {'\t', ' '};
    int operadores[6] = {'+', '-', '*', '/', '(', ')'};
    int caracter, input_tabla;
    int estado_actual = NUEVO_TOKEN;
    int fila = 1, columna=1;

    while ((caracter = fgetc(input_fp)) != EOF) {
        columna+=1;
        if (!esta_en(caracter, caract_ignorados, 2)) {
            printf("estado ant:%d, caracter ingresado:%c ", estado_actual, caracter);
            if(isdigit(caracter)){
                input_tabla = INPUT_DIGITO;
                if(estado_actual==NUEVO_TOKEN){
                    fputs("Constante numerica,", output_fptr);
                }
                fputc(caracter, output_fptr);
            }
            else if(esta_en(caracter,operadores,6)){
                input_tabla = INPUT_OPERADOR;
                if(estado_actual==ESCRIBIENDO_NUMERO){
                    fputc('\n', output_fptr);
                }
                fputs("Operador,", output_fptr);
                fputc(caracter, output_fptr);
                fputc('\n', output_fptr);
            }
            else if(caracter=='\n'){
                input_tabla = 1;
                fila += 1;
                columna = 1;
                if(estado_actual==ESCRIBIENDO_NUMERO){
                    fputc('\n', output_fptr);
                }
            }
            else{
                input_tabla = INPUT_CARACTER_DESCONOCIDO;
            }
            estado_actual = T(estado_actual, input_tabla);
            printf("estado actual:%d\n", estado_actual);
        }
        if (estado_actual == RECHAZADO) {
            fprintf(
                stderr, "[ERROR]: Caracter desconocido en: fila=%d columna=%d\n", fila, columna-1
            );
            fclose(input_fp);
            fclose(output_fptr);
            return 0;
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