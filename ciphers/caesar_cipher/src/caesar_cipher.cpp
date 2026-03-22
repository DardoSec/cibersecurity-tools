#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 🔹 Mostrar ayuda
void print_help()
{
    printf("Caesar Cipher Tool\n");
    printf("==================\n\n");
    printf("Uso:\n");
    printf("  caesar.exe -e <shift> <input.txt> <output.txt>\n");
    printf("  caesar.exe -d <shift> <input.txt> <output.txt>\n\n");
    printf("Opciones:\n");
    printf("  -e        Cifrar\n");
    printf("  -d        Descifrar\n");
    printf("  -h        Mostrar ayuda\n");
    printf("  --help    Mostrar ayuda\n\n");
    printf("Ejemplo:\n");
    printf("  caesar.exe -e 3 mensaje.txt cifrado.txt\n");
}

// 🔹 Función Caesar
char caesar_char(char c, int shift)
{
    if (isalpha(c))
    {
        char base = islower(c) ? 'a' : 'A';
        return (c - base + shift + 26) % 26 + base;
    }
    return c; // no modificar otros caracteres
}

// 🔹 Procesar archivo
void process_file(FILE *in, FILE *out, int shift)
{
    char c;
    while ((c = fgetc(in)) != EOF)
    {
        fputc(caesar_char(c, shift), out);
    }
}

// 🔹 Main
int main(int argc, char *argv[])
{
    if (argc < 2 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
    {
        print_help();
        return 0;
    }

    if (argc != 5)
    {
        printf("Error: argumentos incorrectos\n\n");
        print_help();
        return 1;
    }

    int encrypt = 0;
    int decrypt = 0;

    if (strcmp(argv[1], "-e") == 0)
        encrypt = 1;
    else if (strcmp(argv[1], "-d") == 0)
        decrypt = 1;
    else
    {
        printf("Error: opción inválida\n\n");
        print_help();
        return 1;
    }

    int shift = atoi(argv[2]);
    if (decrypt)
        shift = -shift;

    FILE *input = fopen(argv[3], "r");
    if (!input)
    {
        printf("Error: no se pudo abrir archivo de entrada\n");
        return 1;
    }

    FILE *output = fopen(argv[4], "w");
    if (!output)
    {
        printf("Error: no se pudo crear archivo de salida\n");
        fclose(input);
        return 1;
    }

    process_file(input, output, shift);

    fclose(input);
    fclose(output);

    printf("Proceso completado.\n");
    return 0;
}