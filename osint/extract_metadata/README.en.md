# Extract Metadata (EXIF/GPS) Python Script

## Description
This Python script extracts metadata from images (EXIF), including camera information and GPS coordinates if available.  
It automatically generates a Google Maps link to locate the photo.

Ideal for educational purposes, digital forensics, and learning about image metadata.

---

## Requirements
- Python 3.x
- Pillow library

Install Pillow with:

pip install Pillow

---

## Usage

python extract_metadata.py image.jpg

- `image.jpg` → path to the image file you want to analyze.

---

## Example Output

File: image.jpg

Camera: Canon EOS 80D
Date: 2023:03:12 15:42:10

GPS:
Latitude: -34.9011
Longitude: -56.1645

Google Maps:
https://maps.google.com/?q=-34.9011,-56.1645

---

## Main Features

- Extracts camera information (`Model`) and original date (`DateTimeOriginal`).
- Extracts GPS information (`GPSLatitude` and `GPSLongitude`).
- Converts coordinates from DMS (degrees, minutes, seconds) to decimal format.
- Automatically generates a Google Maps link.
- Modular: can be used as a standalone script or imported into other Python programs.

---

## Warning
- Works only with images that contain EXIF metadata.
- Respect privacy and legal boundaries when analyzing others' photos.

---

## Author

**DardoSec**  
Teacher – Computer Science – Cybersecurity – Educational Robotics  
