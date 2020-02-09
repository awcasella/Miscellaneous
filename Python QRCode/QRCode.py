import io
import pyqrcode
from base64 import b64encode
import matplotlib.pyplot as plt
import sys

def generate_qr(data):
	"""Generates a QR Code from a string passed to the function and prints it on the terminal."""
	img = pyqrcode.create(data)
	buffers = io.BytesIO()
	img.png(buffers, scale=8)
	encoded = b64encode(buffers.getvalue()).decode("ascii")
	print("QR code generation successful.")
	print(img.terminal(quiet_zone=1))
	img.png('code.png', scale=6, module_color=[0, 0, 0, 128], background=[0xff, 0xff, 0xcc])
	#img.show()
	return "data:image/png;base64, " + encoded

if __name__ == '__main__':
	qrcode = generate_qr(sys.argv[1])
