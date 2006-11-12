@echo off

REM This deployment script depends on the 7-zip command line utility
REM http://www.7-zip.org/
REM It also depends on the sqlite3.exe command-line application in your PATH

REM Change these variables to your preferred location
SET ZIP=C:\7-zip\7za.exe
SET ZIP_FILE=..\bin\BirthdayCard-1.0-win-bin.zip

REM =======================================

REM Generate random numbers and create the demo database
cd ../src/sql
cscript date_generator.vbs
sqlite3 BirthdayCard.db < people.sql
sqlite3 BirthdayCard.db < dates.sql
cd ../../
move .\src\sql\BirthdayCard.db .\bin\BirthdayCard.db

REM =======================================

REM Generate documentation using Doxygen
doxygen

REM Erase HTML files, only keep CHM file
cd doc
rmdir /Q /S html

REM =======================================

REM Build the applications
cd ../make
call windows.bat

REM =======================================

REM Create the distributable zip file
DELETE %ZIP_FILE%
cd Release
%ZIP% a -tzip %ZIP_FILE% BirthdayCard.exe
%ZIP% a -tzip %ZIP_FILE% unittests.exe
%ZIP% a -tzip %ZIP_FILE% cppunit_dll.dll
%ZIP% a -tzip %ZIP_FILE% C:\WINDOWS\SYSTEM32\sqlite3.dll
%ZIP% a -tzip %ZIP_FILE% ..\..\bin\BirthdayCard.db

REM =======================================

REM Execute unit tests
unittests.exe

REM =======================================

REM Do some cleanup
cd ..
rmdir /Q /S Debug
rmdir /Q /S Release

cd ..
del bin\BirthdayCard.db

cd deploy
