/*!
 * \mainpage DVDRental Application
 *
 * \author Ahmed Madkour, Keith Miller, Adrian Kosmaczewski
 * \date November 22nd, 2006
 *
 * \image html icon.jpg
 *
 * The video library Video Fun lends videos and DVDs. They have contracted you
 * to develop a system to automate their business. The system will record details
 * about the customers who use the library, the materials that are available to
 * be lent, and record which customer currently has what materials on loan.
 *
 * \section main_index Index
 *
 * More information about DVDRental can be found in the following pages:
 *
 * \li \subpage pageIntro "Introduction"
 * \li \subpage pageScreenshots "Screenshots"
 * \li \subpage pageTools "External Tools"
 * \li \subpage pageReferences "References"
 *
 */

#include "dvdrental.h"
#include "main.h"

IMPLEMENT_APP(DvdRental)

bool DvdRental::OnInit()
{
    Main* frame = new Main(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}

int DvdRental::OnExit()
{
	return 0;
}

/*!
 * \page pageIntro Introduction
 * The details that are stored for a customer are their first and last name,
 * their address, their phone number and their membership number. The details
 * that are stored for a video and a DVD are their title and serial number.
 * Videos can be rented for a period of one week and the rental charge is two
 * Euros. If a video is returned late an additional late fee is payable of one
 * Euro per day late. DVDs can be rented for a period of two days and the rental
 * charge is three Euros. If a DVD is returned late an additional late fee is
 * payable of two Euros per day late.
 *
 * The program needs to provide the functionality to allow new customers to be
 * added to the system. To allow new videos or DVDs to be added to the system.
 * To allow a video or DVD to be recorded as rented to a customer (the user
 * would enter the customer’s membership number, the item’s serial number and
 * the date of rental). When an item is rented a receipt should be output to
 * the screen that states the name of the item, the length of rental time and
 * the cost of rental. To record the return of a video or DVD the user would
 * enter the serial number for the item and the date of return. If a returned
 * item is late an invoice should be output to the screen that states the name
 * and address of the customer, the name of the item and the late fee.
 *
 * For simplicity the program does not have to cater for deleting or editing
 * customer details or video or DVD details. Also for simplicity the program
 * does not have to store or load the customer or video or DVD data from files.
 * (Bonus marks will be allocated to students who do implement the functionality
 * of being able to load and save the program data to and from a file. To
 * implement this functionality it is easiest if there is a separate file for
 * each type of data: customer, video and DVD.) For testing purposes an initial
 * set of customers and videos and DVDs can be hard coded into the system.
 * New customers, videos and DVDs should be able to be added to the system as
 * it is running.
 */


/*!
 * \page pageScreenshots Screenshots
 *
 * \section screen_winxp Windows XP Professional SP2
 *
 * \image html windows.png
 *
 * \section screen_finder Mac OS X "Tiger" 10.4.8
 *
 * \image html finder.png
 *
 * \section screen_items Item Management
 *
 * \image html items.png
 *
 * \section screen_create_rental Creating a New Rental
 *
 * \image html createrental.png
 *
 * \section screen_customers Customer Management
 *
 * \image html customers.png
 *
 * \section screen_rentals Rental Management
 *
 * \image html rentals.png
 *
 * \section screen_environment The Application on the Mac Desktop
 *
 * \image html environment.png
 *
 */

/*!
 * \page pageTools External Tools
 *
 * DVDRental was built using a myriad of external tools, most of them
 * available for free in the form of open-source projects. The idea behind
 * DVDRental is to be made of a C++ code as portable as possible.
 *
 * This page describes the tools used to create DVDRental.
 *
 * \li \ref tools_repository
 * \li \ref tools_os
 * \li \ref tools_design
 * \li \ref tools_compilers
 * \li \ref tools_ides
 * \li \ref tools_testing
 * \li \ref tools_others
 *
 * \section tools_repository Google Code Repository
 *
 * The source code for DVDRental is stored in a Google Code repository:
 * http://code.google.com/p/dvdrental/
 *
 * The latest snapshot of the code can be retrieved using any subversion client
 * using the following command:
 *
 * svn checkout http://dvdrental.googlecode.com/svn/trunk/ dvdrental
 *
 * \section tools_os Operating Systems
 *
 * DVDRental was successfully built and tested on the following operating systems:
 *
 * \li Windows XP Professional Edition SP2
 * \li Mac OS X 10.4.7 "Tiger" (PowerPC)
 *
 * \section tools_design Design Tools
 *
 * \li The UML diagrams included in the documentation were created using
 * the community edition of Visual Paradigm for UML 5.3
 * (http://www.visual-paradigm.com/product/vpuml/)
 *
 * \section tools_compilers Compilers
 *
 * The source code has been successfully built using the following compilers:
 *
 * \li gcc version 4.0.1 (Apple Computer, Inc. build 5363) (Mac OS X 10.4.8 "Tiger")
 * \li Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3077 for 80x86
 * (Windows XP)
 *
 * \section tools_ides Integrated Development Environments and Build Tools
 *
 * The application can be opened using these IDEs:
 *
 * \li Apple Xcode 2.4 (Mac OS X 10.4 only): open the "DVDRental.xcodeproj" file.
 * \li Visual Studio .NET 2003 (Windows only): open the "DVDRental.vcproj" file.
 * \li Borland C++ Builder 2006 (http://www.borland.com/us/products/cbuilder/index.html):
 * open the "DVDRental.bdsproj" file.
 *
 * Besides these IDEs, the application can be built from the command line
 * thanks to makefiles:
 *
 * \li Microsoft NMAKE utility
 * (http://msdn2.microsoft.com/en-us/library/dd9y37ha.aspx)
 *
 * \section tools_testing Open Source Tools
 *
 * The following open source, cross-platform tools were used to
 * create DVDRental and the current documentation:
 *
 * \li CppUnit 1.12 (http://cppunit.sourceforge.net/), directly downloadable
 * from http://prdownloads.sourceforge.net/cppunit/cppunit-1.12.0.tar.gz
 * \li wxWidgets 2.6.3 (http://www.wxwidgets.org/), directly downloadable from
 * http://prdownloads.sourceforge.net/wxwindows/wxWidgets-2.6.3.tar.bz2
 * \li Doxygen 1.4.7 (http://www.doxygen.org/)
 * \li Subversion 1.4 (http://subversion.tigris.org)
 *
 * \section tools_others Other Tools
 *
 * \li Microsoft HTML Help Workshop 3.0
 * (http://www.microsoft.com/downloads/details.aspx?familyid=00535334-c8a6-452f-9aa0-d597d16580cc&displaylang=en)
 * \li Crimson Editor (http://www.crimsoneditor.com/)
 * \li GnoCHM (http://gnochm.sourceforge.net/), CHM file viewer for the GNOME desktop
 * \li Chmox (http://chmox.sourceforge.net/), CHM file viewer for Mac OS X
 * \li The Windows ZIP files were generated with 7-zip (http://www.7-zip.org/)
 * \li Microsoft VBScript (http://msdn.microsoft.com/scripting) was used to
 * create the SQL file containing random dates.
 *
 */

/*!
 * \page pageReferences References
 *
 * This page lists the external references of information used during
 * the development of the application.
 *
 * \section ref_books Books
 *
 * \li Date validation algorithm adapted from Deitel's "C++ How To Program,
 * Fifth Edition"
 * ISBN 0-13-185757-6, page 537
 * \li "Effective C++, Third Edition" by Scott Meyers (Addison Wesley,
 * ISBN 0-321-33487-6)
 * \li "C++ Cookbook", by Ryan Stephens, Christopher Diggins, Jonathan Turkanis and
 * Jeff Cogswell (O'Reilly, ISBN 0-596-00761-2)
 * \li "Cross-Platform GUI Programming with wxWidgets", by Julian Smart,
 * Kevin Hock and Stefan Csomor (Prentice Hall, ISBN 0-131-47381-6)
 *
 * \section ref_web References on the Web
 *
 * \li wxWidgets documentation (http://wxwidgets.org/docs/)
 * \li CppUnit documentation (http://cppunit.sourceforge.net/doc/lastest/index.html)
 * \li The ISO 8601 standard ("YYYY-MM-DD") is described here
 * http://www.cl.cam.ac.uk/~mgk25/iso-time.html
 * \li Basic date manipulation algorithms adapted from
 * http://www.informit.com/guides/content.asp?g=cplusplus&seqNum=65&rl=1
 * \li The application icon was taken from
 * http://www.pef.org/stopworkplaceviolence/images/dvd-icon.jpg
 * \li The Julian Date algorithms are taken from
 * http://www.silverglass.org/code/Date.html
 *
 */

/*!
 * \page pageDocumentation Documentation
 *
 * To generate the documentation, make sure that Doxygen 1.4.7 or later
 * (http://www.stack.nl/~dimitri/doxygen/) and dot (http://www.graphviz.org/) are
 * installed; type "doxygen" in the folder where the file "Doxyfile" is located.
 *
 * For Windows, the Doxyfile also assumes that the HTML Compiler (used to generate
 * this CHM file) is located in "C:\Program Files\HTML Help Workshop\hhc.exe".
 * CHM files can be viewed in the Macintosh using Chmox (http://chmox.sourceforge.net/)
 * and in Linux using GnoCHM (http://gnochm.sourceforge.net/)
 *
 */
