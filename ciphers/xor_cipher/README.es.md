# XOR Cipher Tool

## Descripción

Esta herramienta permite cifrar y descifrar archivos de texto usando el cifrado XOR.
Es una herramienta educativa para CTFs y aprendizaje de criptografía básica.

## Funcionamiento:

- Entrada: archivo .txt
- Salida: archivo .txt
- Clave: un solo carácter (ASCII)
- Cifrado y descifrado usan la misma operación XOR, con la misma clave.
- Muestra ayuda si se ejecuta sin parámetros o con -h / --help.

---

## Uso:

xor_cipher.exe -e <key> <input.txt> <output.txt>   # Cifrar
xor_cipher.exe -d <key> <input.txt> <output.txt>   # Descifrar

## Ejemplos:

xor_cipher.exe -e K sample_input.txt output.txt
xor_cipher.exe -d K output.txt original.txt

## Notas:

- La clave es sensible a mayúsculas/minúsculas (K ≠ k).
- Funciona con todas las letras, números, espacios y símbolos ASCII.
- Ideal para experimentar con CTFs y aprender cómo XOR transforma los datos.

## Archivos incluidos:

- xor_cipher.exe  → ejecutable del programa
- sample_input.txt → archivo de prueba (estrofa de poesía)
- README_es.md → esta documentación en español
- README_en.md → documentación en inglés

## Autor

D. García, docente de informática.
