# Extract Metadata (EXIF/GPS) Python Script

## Descripción
Este script en Python permite extraer metadata de imágenes (EXIF), incluyendo información de la cámara y coordenadas GPS si están presentes.  
Genera automáticamente un enlace a Google Maps para ubicar la foto.

Ideal para fines educativos, OSINT, análisis forense de imágenes y aprendizaje de Python.

---

## Requisitos
- Python 3.x
- Librería Pillow

Instalación de Pillow:

```bash
pip install Pillow
```

## Uso

```bash
python extract_metadata.py imagen.jpg
```

## Ejemplo de salida

```bash
File: imagen.jpg

Camera: Canon EOS 80D
Date: 2023:03:12 15:42:10

GPS:
Latitude: -34.9011
Longitude: -56.1645

Google Maps:
https://maps.google.com/?q=-34.9011,-56.1645
```

## Advertencia

- Solo funciona con imágenes que contengan metadata EXIF.
- Respetar la privacidad y la legalidad al analizar fotos ajenas.

## Autor

**DardoSec**  
Teacher – Computer Science – Cybersecurity – Educational Robotics  
