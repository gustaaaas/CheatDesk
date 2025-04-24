import re
from colorama import init, Fore, Style
init(autoreset=True)
print("Paste the ticket description below (press Ctrl+Z when done for output):")

banned_keywords = ['Name']
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
possible_names = re.findall(r'\b([A-Z][a-z]{2,})\s+([A-Z][a-z]{2,})\b', raw_input)
#
#
#
#
filtered_names = [
    f"{first} {last}" for first, last in possible_names
    if first not in banned_keywords and last not in banned_keywords
]
email = email_match.group() if email_match else Fore.RED + "!!!Cant find email!!!" + Style.RESET_ALL
#
#
name = filtered_names[0] if filtered_names else Fore.RED+"!!!Cant find Name!!!"+Style.RESET_ALL
#
#


print("==========================================================================================\n\n")
print(f"\n\nPlease grant the following users (new users for {}) to #:\n")
print(f"{:<15} {:<10} {email:<28} {}\n\n\n\n")
print("==========================================================================================\n\n")