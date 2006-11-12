@echo off

rem This file builds the BirthdayCard application using Microsoft developer tools.
rem
rem Requirements:
rem
rem - Microsoft Visual Studio .NET 2003 or 2005
rem - SQLite 3.3.8
rem - wxWidgets 2.6.3
rem - CppUnit 1.12.0

nmake /f .\birthdaycard.nmake clean
nmake /f .\unittests.nmake clean

nmake /f .\birthdaycard.nmake cfg=debug
nmake /f .\birthdaycard.nmake cfg=release
nmake /f .\unittests.nmake cfg=debug
nmake /f .\unittests.nmake cfg=release

copy C:\cppunit-1.12.0\lib\cppunitd_dll.dll .\Debug
copy C:\cppunit-1.12.0\lib\cppunit_dll.dll .\Release
