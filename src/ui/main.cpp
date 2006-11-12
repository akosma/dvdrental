/*!
 * \file main.cpp
 * Contains the implementation of the ui::Main class.
 */

#include "main.h"

#ifndef DVDRENTAL_H_
#include "dvdrental.h"
#endif

IMPLEMENT_APP(ui::Main)

/*!
 * \namespace ui
 * Contains the classes that depend on the wxWidgets framework,
 * providing the GUI of the DVD Rental application.
 */
namespace ui
{
    // 'Main program' equivalent: the program execution "starts" here
    bool Main::OnInit()
    {
        DvdRental* frame = new DvdRental(_T("DVDRental Application"));
        frame->Show(true);

        // success: wxApp::OnRun() will be called which will enter the main message
        // loop and the application will run. If we returned false here, the
        // application would exit immediately.
        return true;
    }

    int Main::OnExit()
    {
      return 0;
    }
}

