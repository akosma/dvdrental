@echo off

REM This deployment script depends on the 7-zip command line utility
REM http://www.7-zip.org/
REM It also depends on the sqlite3.exe command-line application in your PATH

REM Change these variables to your preferred location
SET ZIP=C:\7-zip\7za.exe
SET ZIP_FILE=..\..\bin\DVDRental-1.0-win-bin.zip

REM =======================================

REM Generate documentation using Doxygen
cd ..
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

cd DVDRental_Release
DELETE %ZIP_FILE%
%ZIP% a -tzip %ZIP_FILE% DVDRental.exe

cd ..\Tests_Release
%ZIP% a -tzip %ZIP_FILE% tests.exe
%ZIP% a -tzip %ZIP_FILE% cppunit_dll.dll

REM =======================================

REM Execute unit tests
echo y | tests.exe
cd ..

REM =======================================

REM Do some cleanup
rmdir /Q /S DVDRental_Debug
rmdir /Q /S DVDRental_Release
rmdir /Q /S Tests_Debug
rmdir /Q /S Tests_Release

cd ..\deploy
