#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

void print_help() {
    cout << "Vigenere Cipher Tool" << endl;
    cout << "===================" << endl;
    cout << endl;
    cout << "Uso:" << endl;
    cout << "  vigenere_cipher.exe -e <key> <input.txt> <output.txt>   # Cifrar" << endl;
    cout << "  vigenere_cipher.exe -d <key> <input.txt> <output.txt>   # Descifrar" << endl;
    cout << endl;
    cout << "Opciones:" << endl;
    cout << "  -h, --help     Mostrar ayuda" << endl;
    cout << endl;
    cout << "Ejemplo:" << endl;
    cout << "  vigenere_cipher.exe -e KEY sample_input.txt output.txt" << endl;
    cout << "  vigenere_cipher.exe -d KEY output.txt original.txt" << endl;
}

char shift_char(char c, char k, bool encrypt) {
    if (!isalpha(c))
        return c;

    char base = isupper(c) ? 'A' : 'a';
    int offset = toupper(k) - 'A';
    if (!encrypt)
        offset = 26 - offset;  // Invertir para descifrar
    return (c - base + offset) % 26 + base;
}

int main(int argc, char* argv[]) {
    if (argc < 2 || string(argv[1]) == "-h" || string(argv[1]) == "--help") {
        print_help();
        return 0;
    }

    if (argc != 5) {
        cout << "Error: parámetros incorrectos." << endl;
        print_help();
        return 1;
    }

    string mode = argv[1];
    string key = argv[2];
    string input_file = argv[3];
    string output_file = argv[4];

    if (key.empty()) {
        cout << "Error: la clave no puede estar vacía." << endl;
        return 1;
    }

    ifstream fin(input_file, ios::in);
    if (!fin) {
        cout << "Error: no se pudo abrir " << input_file << endl;
        return 1;
    }

    ofstream fout(output_file, ios::out);
    if (!fout) {
        cout << "Error: no se pudo abrir " << output_file << endl;
        return 1;
    }

    string line;
    size_t key_len = key.length();
    size_t key_index = 0;
    bool encrypt = (mode == "-e");

    while (getline(fin, line)) {
        for (char c : line) {
            char out_char = shift_char(c, key[key_index % key_len], encrypt);
            fout << out_char;
            if (isalpha(c))
                key_index++;
        }
        fout << endl;
    }

    fin.close();
    fout.close();

    cout << "Proceso completado." << endl;
    return 0;
}