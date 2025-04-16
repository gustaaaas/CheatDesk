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
region_match = re.search(r'\(([^()]*\/[^()]*)\)', raw_input)
if not region_match:
    region_match = re.search(r'for\s+([A-Za-z\s]+/[A-Za-z\s]+)', raw_input, re.IGNORECASE)

#Testing
'''
print("\nTest Matches:")
print("Email Match:      ", email_match.group() if email_match else "X Not found")
#
#
print("Name Match:       ", name_match.group() if name_match else "X Not found")
#
'''

email = email_match.group() if email_match else "unknown@example.com"
#
#
name = name_match.group() if name_match else "unknown"
#
region = region_match.group(1).strip() if region_match else "Unknown Region"

#Testing
#Printing the states as you configure it.
