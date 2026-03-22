# Cifrado César - Herramienta de Línea de Comandos

## Descripción

Esta herramienta implementa el **cifrado César**, un cifrado clásico de sustitución de letras.  
Permite cifrar y descifrar archivos de texto (.txt) desde la línea de comandos en Windows.

Solo procesa **letras A–Z y a–z**; todos los demás caracteres (números, símbolos, espacios) se mantienen igual.  
No maneja caracteres con tildes ni caracteres especiales Unicode.

---

## Uso

# Cifrar

caesar.exe -e <shift> <archivo_entrada.txt> <archivo_salida.txt>  

# Descifrar

caesar.exe -d <shift> <archivo_entrada.txt> <archivo_salida.txt>  

# Mostrar ayuda

caesar.exe -h | --help                                           

### Ejemplos

Cifrar con desplazamiento 3:

caesar.exe -e 3 mensaje.txt cifrado.txt

Descifrar con desplazamiento 3:

caesar.exe -d 3 cifrado.txt mensaje_descifrado.txt

---

## Compilación

Con GCC / MinGW:

gcc caesar.c -o caesar.exe

Con Visual Studio:

- Crear un proyecto de consola
- Agregar caesar.c
- Compilar en Release/Debug

---

## Notas pedagógicas

- Ideal para CTFs educativos y prácticas de criptografía básica.  
- Muestra cómo funcionan los cifrados de sustitución simples.  
- Perfecto para trabajar con fuerza bruta y análisis de patrones.

---

## Autor / Referencia

Proyecto educativo de ciberseguridad.