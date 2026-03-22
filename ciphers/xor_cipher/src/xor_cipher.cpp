#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_help() {
    printf("XOR Cipher Tool\n");
    printf("==================\n\n");
    printf("Uso:\n");
    printf("  xor_cipher.exe -e <key> <input.txt> <output.txt>   # Cifrar\n");
    printf("  xor_cipher.exe -d <key> <input.txt> <output.txt>   # Descifrar\n");
    printf("Opciones:\n");
    printf("  -h        Mostrar ayuda\n");
    printf("  --help    Mostrar ayuda\n\n");
    printf("Ejemplo:\n");
    printf("  xor_cipher.exe -e K mensaje.txt cifrado.txt\n");
}

int main(int argc, char* argv[]) {
    if (argc != 5 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        show_help();
        return 0;
    }

    char mode = argv[1][1];
    char key = argv[2][0];
    char* input_file = argv[3];
    char* output_file = argv[4];

    FILE* fin = fopen(input_file, "rb");
    if (!fin) {
        perror("Error al abrir el archivo de entrada");
        return 1;
    }

    FILE* fout = fopen(output_file, "wb");
    if (!fout) {
        perror("Error al abrir el archivo de salida");
        fclose(fin);
        return 1;
    }

    int c;
    while ((c = fgetc(fin)) != EOF) {
        fputc(c ^ key, fout);
    }

    fclose(fin);
    fclose(fout);

    if (mode == 'e')
        printf("Cifrado completado.\n");
    else
        printf("Descifrado completado.\n");

    return 0;
}