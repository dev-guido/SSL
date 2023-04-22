#include <stdio.h>

int main()
{
    FILE *fptr;
    fptr = fopen("output.txt", "w");
    fprintf(fptr, "Hello, World!");
    fclose(fptr);
    return 0;
}