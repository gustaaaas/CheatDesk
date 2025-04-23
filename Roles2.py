import re
import win32com.client
import pytesseract
pytesseract.pytesseract.tesseract_cmd = r"PATH TO - tesseract.exe"

from PIL import Image
import numpy as np
import cv2
from pdf2image import convert_from_path
from pytesseract import Output

pdf_path = "##"
pages = convert_from_path(pdf_path, dpi=300)
img = np.array(pages[0].convert("L"))
_, thresh = cv2.threshold(img, 180, 255, cv2.THRESH_BINARY_INV)

known_roles = [
#
#
#
#
]

data = pytesseract.image_to_data(Image.fromarray(img), output_type=Output.DICT)

anchor_index = None
anchor_x = None
anchor_y = None
anchor_h = None

for i, word in enumerate(data["text"]):
    if word in known_roles:
        anchor_index = known_roles.index(word)
        anchor_x = data["left"][i] + data["width"][i] + 10
        anchor_y = data["top"][i]
        anchor_h = data["height"][i]
        break

found_roles = []
if anchor_index is not None:
    for offset in [-2, -1, 0, 1, 2]:
        idx = anchor_index + offset
        if 0 <= idx < len(known_roles):
            box_y = anchor_y + offset * (anchor_h + 10)
            box_x = anchor_x
            box_w, box_h = 40, 30
            cropped_box = thresh[box_y:box_y+box_h, box_x:box_x+box_w]
            if cropped_box.shape[0] > 0 and cropped_box.shape[1] > 0:
                if cv2.countNonZero(cropped_box) > 300:
                    found_roles.append(known_roles[idx])
else:
    print("No anchor role detected.")

print("Paste the # description below (press Ctrl+Z when done):")
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

formatted_roles = "\n".join([f"•    {role}" for role in found_roles]) if found_roles else "•    (No roles detected)"

outlook = win32com.client.Dispatch("Outlook.Application")
mail = outlook.CreateItem(0)

mail.To = "example@example.com"
mail.Subject = "###"

mail.Body = f"""Hello,

#
{formatted_roles}

#
#
3. Full Name: {name}
#
5. E-Mail: {email}
#

Thank you.
"""

mail.Display()
