import re
import webbrowser

print("Paste the ticket description below (press Ctrl+Z when done for output):")

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
if not region_match:
    region_match = re.search(r'for\s+([A-Za-z\s]+/[A-Za-z\s]+)', raw_input, re.IGNORECASE)
    

email = email_match.group() if email_match else "Unknown email"
#
#
name = name_match.group() if name_match else "Not found Name"
#
#
