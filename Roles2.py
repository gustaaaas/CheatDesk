import re
import win32com.client
import time
import numpy as np
import sys

banned_keywords = ['Name''something something']
print("Paste the ticket description below (press Ctrl+Z when done):")
try:
    raw_input = ""
    while True:
        line = input()
        raw_input += line + "\n"
except EOFError:
    pass
import time
import sys

print("Loading", end="", flush=True)
for _ in range(3):
    time.sleep(1)
    print(".", end="", flush=True)
print()


email_match = re.search(r'[\w\.-]+@[\w\.-]+', raw_input)
#
#
possible_names = re.findall(r'\b([A-Z][a-z]{2,})\s+([A-Z][a-z]{2,})\b', raw_input)
#
#
#
#
filtered_names = [
    f"{first} {last}" for first, last in possible_names
    if first not in banned_keywords and last not in banned_keywords
]
email = email_match.group() if email_match else "!!!Cant find email!!!"
#
#
name = filtered_names[0] if filtered_names else "!!!Cant find Name!!!"
#
#


outlook = win32com.client.Dispatch("Outlook.Application")
mail = outlook.CreateItem(0)

mail.To = "Send.To...."
mail.Cc="Who.Should.See...."
mail.Subject = "Subject"

mail.Body = f"""Hello,

Could you please grant the following roles to the following users:

#
#
#
#

1. Some software system
#
3. Full Name: {name}
#
5. E-Mail: {email}
#

Thank you.
"""

mail.Display()
