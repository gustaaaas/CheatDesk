import re
import win32com.client
import pytesseract
pytesseract.pytesseract.tesseract_cmd = r"C:\Program Files\Tesseract-OCR\tesseract.exe"
from PIL import Image
import numpy as np
import cv2
from pdf2image import convert_from_path
from pytesseract import Output

pdf_path = "somewhere"#will need to change

pages = convert_from_path(pdf_path, dpi=300)
img = np.array(pages[0].convert("L"))
_, thresh = cv2.threshold(img, 180, 255, cv2.THRESH_BINARY_INV)

known_roles = [
#Add something 
#
#
#
]

data = pytesseract.image_to_data(Image.fromarray(img), output_type=Output.DICT)

found_roles = []
for i, word in enumerate(data["text"]):
    if word in known_roles:
        x, y, w, h = data["left"][i], data["top"][i], data["width"][i], data["height"][i]
        box_x, box_y, box_w, box_h = x + w + 10, y, 40, h
        cropped_box = thresh[box_y:box_y+box_h, box_x:box_x+box_w]
        non_zero_pixels = cv2.countNonZero(cropped_box)
        if non_zero_pixels > 100:
            found_roles.append(word)

print("Paste the ticket description below (press Ctrl+Z when done):")

try:
    raw_input = ""
    while True:
        line = input()
        raw_input += line + "\n"
except EOFError:
    pass

email_match = re.search(r'[\w\.-]+@[\w\.-]+', raw_input)
#
#
name_match = re.search(r'Full Name:\s*([^\n\r]+)', raw_input)
#
#
#

email = email_match.group() if email_match else "!!!Cant find email!!!"
#
#
name = name_match.group(1).strip() if name_match else "!!!Cant find Name!!!"
#
#

outlook = win32com.client.Dispatch("Outlook.Application")
mail = outlook.CreateItem(0)

mail.To = "example@example.com"
mail.Subject = "Roles"

formatted_roles = "\n".join([f"•    {role}" for role in found_roles])

mail.Body = f"""Hello,

Could you please grant the following roles:
{formatted_roles}

1. Some system
#
3. Full Name: {name}
#
5. E-Mail: {email}
#

Thank you.
"""

mail.Display()
