/*!
 * \file main.h
 * Contains the interface of the ui::Main class.
 */

#ifndef MAIN_H_
#define MAIN_H_

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

/*!
 * \namespace ui
 * Contains the classes that depend on the wxWidgets framework,
 * providing the GUI of the DVD Rental application.
 */
namespace ui
{
    /*!
     * \class Main
     * This class is the core of the GUI; it contains the entry 
     * point of the application.
     */
    class Main : public wxApp
    {
    public:
        virtual bool OnInit();
        int OnExit();
    };
}

DECLARE_APP(ui::Main)

#endif /*MAIN_H_*/
