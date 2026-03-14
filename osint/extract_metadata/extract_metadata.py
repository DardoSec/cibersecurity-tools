from PIL import Image
from PIL.ExifTags import TAGS, GPSTAGS
import sys


def get_exif_data(image):
    exif_data = {}
    info = image._getexif()

    if info:
        for tag, value in info.items():
            decoded = TAGS.get(tag, tag)
            exif_data[decoded] = value

    return exif_data


def get_gps_info(exif_data):
    gps_info = {}

    if "GPSInfo" in exif_data:
        for key in exif_data["GPSInfo"]:
            decoded = GPSTAGS.get(key, key)
            gps_info[decoded] = exif_data["GPSInfo"][key]

    return gps_info


def convert_to_degrees(value):
    # Pillow devuelve IFDRational, que se puede convertir directamente a float
    d = float(value[0])
    m = float(value[1])
    s = float(value[2])

    return d + (m / 60.0) + (s / 3600.0)


def get_coordinates(gps_info):
    lat = None
    lon = None

    if "GPSLatitude" in gps_info and "GPSLatitudeRef" in gps_info:
        lat = convert_to_degrees(gps_info["GPSLatitude"])
        if gps_info["GPSLatitudeRef"] != "N":
            lat = -lat

    if "GPSLongitude" in gps_info and "GPSLongitudeRef" in gps_info:
        lon = convert_to_degrees(gps_info["GPSLongitude"])
        if gps_info["GPSLongitudeRef"] != "E":
            lon = -lon

    return lat, lon


def main():

    if len(sys.argv) < 2:
        print("Usage: extract_metadata image.jpg")
        return

    filename = sys.argv[1]

    image = Image.open(filename)

    print(f"\nFile: {filename}\n")

    exif_data = get_exif_data(image)

    if "Model" in exif_data:
        print("Camera:", exif_data["Model"])

    if "DateTimeOriginal" in exif_data:
        print("Date:", exif_data["DateTimeOriginal"])

    gps_info = get_gps_info(exif_data)
    lat, lon = get_coordinates(gps_info)

    if lat is not None and lon is not None:
        print("\nGPS:")
        print("Latitude:", lat)
        print("Longitude:", lon)

        print("\nGoogle Maps:")
        print(f"https://maps.google.com/?q={lat},{lon}")


if __name__ == "__main__":
    main()
