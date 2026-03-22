# Caesar Cipher - Command Line Tool

## Description

This tool implements the **Caesar cipher**, a classic letter substitution cipher.  
It allows you to encrypt and decrypt text files (.txt) from the Windows command line.

Only **letters A–Z and a–z** are processed; all other characters (numbers, symbols, spaces) remain unchanged.  
It does not handle accented letters or special Unicode characters.

---

## Usage

# Encrypt

caesar.exe -e <shift> <input_file.txt> <output_file.txt>  

# Decrypt

caesar.exe -d <shift> <input_file.txt> <output_file.txt>  

# Show help

caesar.exe -h | --help                                    

### Examples

Encrypt with shift 3:

caesar.exe -e 3 message.txt encrypted.txt

Decrypt with shift 3:

caesar.exe -d 3 encrypted.txt decrypted.txt

---

## Compilation

With GCC / MinGW:

gcc caesar.c -o caesar.exe

With Visual Studio:

- Create a console project
- Add caesar.c
- Compile in Release/Debug

---

## Educational Notes

- Ideal for educational CTFs and basic cryptography exercises.  
- Demonstrates how simple substitution ciphers work.  
- Great for practicing brute force and pattern analysis.

---

## Author / Reference

Educational cybersecurity project.