import re
import win32com.client
print("Paste the ticket description below (press Ctrl+Z when done for output):")
outlook = win32com.client.Dispatch("Outlook.Application")

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

email = email_match.group() if email_match else "!!!Cant find email!!!"
#
#
name = name_match.group() if name_match else "!!!Cant find Name!!!"
#
#


mail = outlook.CreateItem(0)
mail.To = "example@example.com"  #Change on your needs
mail.Subject = "Subject"#Mail subject
mail.Body = ""#Your structure
mail.Display()
