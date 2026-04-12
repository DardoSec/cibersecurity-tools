import re
import argparse
from PyPDF2 import PdfReader

IMPORTANT_FIELDS = [
    "/Author",
    "/Creator",
    "/Producer",
    "/CreationDate",
    "/ModDate",
    "/Title",
    "/Subject",
    "/Keywords"
]

def load_wordlist(path):
    try:
        with open(path, "r", encoding="utf-8") as f:
            return [line.strip().lower() for line in f if line.strip()]
    except FileNotFoundError:
        print(f"[!] Wordlist not found: {path}")
        print("[!] Using default wordlist")
        return ["password", "flag", "secret", "key"]

def extract_metadata(pdf_path):
    reader = PdfReader(pdf_path)
    return reader.metadata

def filter_metadata(metadata):
    filtered = {}
    for key in IMPORTANT_FIELDS:
        if key in metadata and metadata[key]:
            filtered[key.replace("/", "")] = metadata[key]
    return filtered

def extract_text(pdf_path):
    reader = PdfReader(pdf_path)
    text = ""
    for page in reader.pages:
        try:
            text += page.extract_text() or ""
        except:
            pass
    return text

def find_coordinates(text):
    pattern = r"[-+]?\d{1,2}\.\d+[, ]\s*[-+]?\d{1,3}\.\d+"
    return re.findall(pattern, text)

def find_suspicious(text, keywords):
    findings = []
    text = text.lower()
    for word in keywords:
        if word in text:
            findings.append(word)
    return findings

def write_output(file, metadata, coords, suspicious, full_metadata=None):
    with open(file, "w", encoding="utf-8") as f:
        f.write("[RELEVANT METADATA]\n\n")

        for k, v in metadata.items():
            f.write(f"{k}: {v}\n")

        f.write("\n[POTENTIAL CLUES]\n\n")

        if coords:
            f.write("Detected coordinates:\n")
            for c in coords:
                f.write(f"- {c}\n")

        if suspicious:
            f.write("\nSuspicious keywords found:\n")
            for s in suspicious:
                f.write(f"- {s}\n")

        if full_metadata:
            f.write("\n[FULL METADATA]\n\n")
            for k, v in full_metadata.items():
                f.write(f"{k}: {v}\n")

def main():
    parser = argparse.ArgumentParser(
        description="PDF metadata and content analyzer (basic OSINT tool)"
    )

    parser.add_argument(
        "pdf",
        help="Path to the PDF file to analyze"
    )

    parser.add_argument(
        "--full",
        action="store_true",
        help="Show full metadata"
    )

    parser.add_argument(
        "--wordlist",
        default="suspicious.txt",
        help="Suspicious keywords file (default: suspicious.txt)"
    )

    args = parser.parse_args()

    pdf_path = args.pdf
    full_mode = args.full
    wordlist_path = args.wordlist

    keywords = load_wordlist(wordlist_path)

    metadata = extract_metadata(pdf_path)
    filtered = filter_metadata(metadata)

    text = extract_text(pdf_path)
    coords = find_coordinates(text)
    suspicious = find_suspicious(text, keywords)

    output_file = "output_pdf.txt"

    write_output(
        output_file,
        filtered,
        coords,
        suspicious,
        metadata if full_mode else None
    )

    print(f"[✔] Analysis completed. Check {output_file}")

if __name__ == "__main__":
    main()