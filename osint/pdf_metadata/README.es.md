# Analizador de Metadatos de PDF (Herramienta OSINT)

## Descripción

Esta es una herramienta simple en **Python orientada a OSINT** que permite analizar archivos PDF para extraer:

* Metadatos relevantes
* Texto oculto o embebido
* Posibles coordenadas geográficas
* Palabras sospechosas (a partir de una lista personalizable)

Está pensada para **uso educativo**, entrenamiento en ciberseguridad y análisis forense básico.

---

## Características

* Extrae campos importantes de metadatos:

  * Autor
  * Creador
  * Productor
  * Fecha de creación y modificación
  * Título, asunto, palabras clave

* Detecta:

  * Palabras sospechosas (configurables)
  * Coordenadas geográficas (mediante expresiones regulares)

* Extrae todo el texto del PDF

* Soporta:

  * Listas externas de palabras (`wordlist`)
  * Salida completa de metadatos (`--full`)

---

## Requisitos

* Python 3.x
* PyPDF2

Instalación de dependencias:

```bash
pip install PyPDF2
```

---

## Estructura del proyecto

```
pdf_metadata/
│
├── pdf_metadata.py
├── suspicious.txt
├── README.es.md
└── sample.pdf
```

---

## Uso

### Uso básico

```bash
python pdf_metadata.py archivo.pdf
```

### Mostrar todos los metadatos

```bash
python pdf_metadata.py archivo.pdf --full
```

### Usar una lista personalizada

```bash
python pdf_metadata.py archivo.pdf --wordlist mi_lista.txt
```

### Mostrar ayuda

```bash
python pdf_metadata.py --help
```

---

## Ejemplo de salida

```
[RELEVANT METADATA]

Producer: Skia/PDF m148 Google Docs Renderer
Title: Agenda laboral

[POTENTIAL CLUES]

Suspicious keywords found:
- key

[FULL METADATA]

/Title: Agenda laboral
/Producer: Skia/PDF m148 Google Docs Renderer
```

---

## Formato de la wordlist

El archivo de palabras sospechosas debe tener una palabra por línea:

```
password
secret
token
api_key
key
credential
flag
```

---

## Notas

* La extracción de texto puede no funcionar correctamente en PDFs escaneados (imágenes).
* La detección de palabras es simple (no usa contexto ni análisis semántico).
* La detección de coordenadas puede generar falsos positivos.

---

## Uso educativo

Esta herramienta es ideal para:

* Laboratorios de ciberseguridad
* Ejercicios de OSINT
* Enseñanza de herramientas CLI en Python
* Introducción al análisis forense digital

---

## Mejoras futuras

* Detección avanzada con expresiones regulares
* Mostrar contexto donde aparecen las palabras
* Sistema de puntuación de riesgo (bajo / medio / alto)
* Procesamiento por lotes (múltiples PDFs)
* Salida en formato JSON
* Colores en terminal

---

## Licencia

Proyecto de código abierto orientado a uso educativo.

---

## Autor

D. García. Docente de informática.

