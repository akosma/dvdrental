@echo off

rem This file builds the DVD Rental application using Microsoft developer tools.
rem
rem Requirements:
rem
rem - Microsoft Visual Studio .NET 2003 or 2005
rem - wxWidgets 2.6.3
rem - CppUnit 1.12.0

nmake /f .\dvdrental.nmake clean
nmake /f .\tests.nmake clean

nmake /f .\dvdrental.nmake cfg=debug
nmake /f .\dvdrental.nmake cfg=release
nmake /f .\tests.nmake cfg=debug
nmake /f .\tests.nmake cfg=release

copy C:\cppunit-1.12.0\lib\cppunitd_dll.dll .\Tests_Debug
copy C:\cppunit-1.12.0\lib\cppunit_dll.dll .\Tests_Release
