# PDF Metadata Analyzer (OSINT Tool)

## Description

This is a simple **Python-based OSINT tool** that analyzes PDF files to extract:

* Relevant metadata
* Hidden or embedded text
* Potential geographic coordinates
* Suspicious keywords (from a customizable wordlist)

It is designed for **educational purposes**, cybersecurity training, and basic forensic analysis.

---

## Features

* Extracts important metadata fields:

  * Author
  * Creator
  * Producer
  * Creation & modification dates
  * Title, Subject, Keywords

* Detects:

  * Suspicious keywords (customizable)
  * Geographic coordinates (regex-based)

* Extracts full PDF text content

* Supports:

  * External wordlists
  * Full metadata output (`--full` flag)

---

## Requirements

* Python 3.x
* PyPDF2

Install dependencies:

```bash
pip install PyPDF2
```

---

## Project Structure

```
pdf_metadata/
│
├── pdf_metadata.py
├── suspicious.txt
├── README.en.md
└── sample.pdf
```

---

## Usage

### Basic usage

```bash
python pdf_metadata.py sample.pdf
```

### Show full metadata

```bash
python pdf_metadata.py sample.pdf --full
```

### Use a custom wordlist

```bash
python pdf_metadata.py file.pdf --wordlist mylist.txt
```

### Show help

```bash
python pdf_metadata.py --help
```

---

## Example Output

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

## Wordlist Format

The wordlist file should contain one keyword per line:

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

## Notes

* PDF text extraction may not work properly on scanned documents (images).
* Keyword detection is based on simple matching (case-insensitive).
* Coordinates detection uses regex and may produce false positives.

---

## Educational Use

This tool is ideal for:

* Cybersecurity training labs
* OSINT exercises
* Teaching CLI tools and Python scripting
* Introductory digital forensics

---

## Future Improvements

* Regex-based advanced keyword detection
* Context extraction (show where keywords appear)
* Risk scoring system (low / medium / high)
* Batch processing (multiple PDFs)
* JSON output support
* Colored terminal output

---

## License

This project is open-source and available for educational use.

---

## Author

D. García. Computer technology teacher.
