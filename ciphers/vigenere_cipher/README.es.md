# Vigenere Cipher Tool

## Descripción

Esta herramienta permite cifrar y descifrar archivos de texto usando el cifrado Vigenère.
Es una herramienta educativa para CTFs y aprendizaje de criptografía básica.

## Funcionamiento:

- Entrada: archivo .txt
- Salida: archivo .txt
- Clave: palabra o frase ASCII
- Cifrado y descifrado usan la misma operación con la misma clave.
- Mayúsculas y minúsculas se conservan.
- Los caracteres no alfabéticos permanecen igual.
- Muestra ayuda si se ejecuta sin parámetros o con -h / --help.

---

# Uso:

## Cifrar

vigenere_cipher.exe -e <key> <input.txt> <output.txt>   

## Descifrar

vigenere_cipher.exe -d <key> <input.txt> <output.txt>   

## Ejemplos:

vigenere_cipher.exe -e hola sample_input.txt output.txt
vigenere_cipher.exe -d hola output.txt original.txt

---

# Notas:

- La clave se repite cíclicamente a lo largo del texto.
- Ideal para experimentar con CTFs y aprender cómo Vigenère combina clave y texto.
- Funciona con todas las letras ASCII; números, espacios y símbolos permanecen sin cambios.

# Archivos incluidos:

- vigenere_cipher.exe → ejecutable del programa
- sample_input.txt → archivo de prueba (estofa de poesía)
- README_es.md → documentación en español
- README_en.md → documentación en inglés

# Autor

D. García, docente de informática.
