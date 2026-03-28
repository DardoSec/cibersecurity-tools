# XOR Cipher Tool

## Description

This tool allows you to encrypt and decrypt text files using the XOR cipher.
It is an educational tool for CTFs and learning basic cryptography.

## How it works:

- Input: .txt file
- Output: .txt file
- Key: a single ASCII character
- Encryption and decryption use the same XOR operation with the same key.
- Shows help if run without parameters or with -h / --help.

---

## Usage:

xor_cipher.exe -e <key> <input.txt> <output.txt>   # Encrypt
xor_cipher.exe -d <key> <input.txt> <output.txt>   # Decrypt

## Examples:

xor_cipher.exe -e K sample_input.txt output.txt
xor_cipher.exe -d K output.txt original.txt

## Notes:

- Key is case-sensitive (K ≠ k).
- Works with all ASCII letters, numbers, spaces, and symbols.
- Perfect for experimenting in CTFs and learning how XOR transforms data.

## Included files:

- xor_cipher.exe → program executable
- sample_input.txt → test input file (poem stanza)
- README_es.md → Spanish documentation
- README_en.md → English documentation

## Author

D. García, computer technology teacher.
