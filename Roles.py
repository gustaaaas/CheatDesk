import re
from colorama import init, Fore, Style
init(autoreset=True)
print("Paste the description below (press Ctrl+Z when done for output):")

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
#

email = email_match.group() if email_match else Fore.RED + "!!!Cant find email!!!" + Style.RESET_ALL
#
#
name = name_match.group(1).strip() if name_match else Fore.RED + "!!!Cant find name!!!" + Style.RESET_ALL
#
#


print(f"Please grant the following # (new users for #) ##\n")
print(f"# # {email:<28} #")
