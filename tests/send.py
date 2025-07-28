import serial
import time
from PIL import Image

# Config
PORT = 'COM6'  # change to your Arduino port
BAUD = 115200
IMG_PATH = 'mikey.jpg'  # must be 160x80 pixels

# Open serial port
ser = serial.Serial(PORT, BAUD, timeout=2)

# Wait for Arduino ready
while True:
    if ser.in_waiting:
        line = ser.readline().decode().strip()
        if line == "READY":
            break

# Load image
img = Image.open(IMG_PATH).convert("RGB")
width, height = img.size
pixels = img.load()

# Send each pixel
start_time=time.time()
for y in range(height):
    for x in range(width):
        r, g, b = pixels[x, y]
        packet = bytes([x, y, r, g, b])
        ser.write(packet)

        # Wait for OK
        while True:
            if ser.in_waiting:
                ack = ser.readline().decode().strip()
                if ack == "OK":
                    break
end_time=time.time()-start_time


print(f"Image sent. Total time: {end_time:.3f} s")
ser.close()
