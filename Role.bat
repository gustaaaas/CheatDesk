@echo off
setlocal enabledelayedexpansion

set lineCount=0
set Line=

echo Please paste the documentation (each line followed by ENTER):

:loop
set /p userInput=

set /a lineCount+=1

if !lineCount! equ 5 (
    set Line=!userInput!
)

if !lineCount! geq 5 goto process

goto loop

:process
set Line=!Line: =!
for /f "tokens=1" %%B in ("!Line!") do set Deparment=%%Bs
for /f "tokens=2" %%C in ("!Line!") do set Email=%%C
for /f "tokens=5" %%F in ("!Line!") do set FirstName=%%F
for /f "tokens=6" %%G in ("!Line!") do set LastName=%%G
for /f "tokens=3" %%D in ("!Line!") do set Qnum=%%D
for /f "tokens=4" %%E in ("!Line!") do set Inc=%%E

echo !Deparment!      !Qnum!     !Email!     !Inc! >>Doc.txt
timeout /t 1
start Doc.txt
pause