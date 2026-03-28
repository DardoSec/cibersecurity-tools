Vigenere Cipher Tool

This tool allows you to encrypt and decrypt text files using the Vigenère cipher.
It is an educational tool for CTFs and learning basic cryptography.

How it works:

- Input: .txt file
- Output: .txt file
- Key: ASCII word or phrase
- Encryption and decryption use the same operation with the same key.
- Uppercase and lowercase letters are preserved.
- Non-alphabetic characters remain unchanged.
- Shows help if run without parameters or with -h / --help.

Usage:

# Encrypt

vigenere_cipher.exe -e <key> <input.txt> <output.txt>   

# Decrypt

vigenere_cipher.exe -d <key> <input.txt> <output.txt>   

Example:

vigenere_cipher.exe -e hola sample_input.txt output.txt
vigenere_cipher.exe -d hola output.txt original.txt

Notes:

- The key repeats cyclically over the text.
- Ideal for experimenting in CTFs and learning how Vigenère combines key and text.
- Works with all ASCII letters; numbers, spaces, and symbols remain unchanged.

Included files:

- vigenere_cipher.exe → program executable
- sample_input.txt → test input file (poem stanza)
- README_es.txt → Spanish documentation
- README_en.txt → English documentation
