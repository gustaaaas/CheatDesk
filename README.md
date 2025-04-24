# CheatDesk
---
CheatDesk is a streamlined role management assistant designed to simplify role request processing within IT systems. Built using Python and C, it automates the generation of standardized Outlook emails and parses user input or documents (PDFs) to identify key ticket information. 
---


Keep in mind, a big portion of code had to be hiden for confidentiality reasons, all parts that were deleted are marked as #. You will need to replace those parts with your logic if you would want to run this.
----
## Features

-  **Auto-Filled Email Creation**: Generates formatted Outlook emails requesting access roles for users.
-  **Smart Ticket Parsing**: Extracts:
  - Full name
  - Email
  - (Keep in mind I had to delete a lot of parsings because of confidentiality reasons)
-  **PDF Role Detection (Optional)**: Uses OCR (Tesseract) to detect checked roles from attached scanned forms (planned for v2).
-  **ASCII UI**: Slick retro-style terminal UI with keyboard-based menu.
-  **Color-Coded Output**: Uses ANSI escape codes (via Colorama in Python or raw escape codes in C) for clean, readable interface.
-  **Failsafes**: Flags missing ticket info with red-highlighted warnings.

---

## Technologies

- **Python** — Core logic, string parsing, OCR.
- **C (CheatDesk Menu)** — Custom CLI menu and UI rendering.
- **Tesseract OCR** — Extracts text and box data from scanned PDFs.(V2)
- **PDF2Image & OpenCV** — Image preprocessing for PDF parsing.(V2)
- **Colorama (Python)** — Terminal color support.
- **Win32com** — Sends Outlook emails automatically.

---



## Future Plans (v2+)
```bash
 Multiple user detection from a single ticket.

 Logs saving for detecting multiple types of the same request before the actuall request.

 Role approval audit logging.

 NLP-based ticket parsing.

 Auto-updater for the app.

 A request feature.

 GUI version (Electron or Tkinter).
