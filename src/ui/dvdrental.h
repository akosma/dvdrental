/*!
 * \file dvdrental.h
 * Contains the interface of the ui::DvdRental class.
 */

#ifndef DVDRENTAL_H_
#define DVDRENTAL_H_

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include <wx/listctrl.h>

//#ifndef CONTROLLER_H_
//#include "controller.h"
//#endif

/*!
 * \namespace ui
 * Contains the classes that depend on the wxWidgets framework,
 * providing the GUI of the DVD Rental application.
 */
namespace ui
{
    /*!
     * \class DvdRental
     * Represents the main window of the application. It is
     * launched by the ui::Main class upon application launch
     * and uses a ui::Controller instance to delegate all 
     * persistence tasks.
     */
    class DvdRental : public wxFrame
    {
    public:
        DvdRental(const wxString& title);
        
        // event handlers (these functions should _not_ be virtual)
        void OnFileQuitMenu(wxCommandEvent& event);
        void OnHelpAboutMenu(wxCommandEvent& event);

        void OnPersonNew(wxCommandEvent& event);
        void OnPersonEdit(wxCommandEvent& event);
        void OnPersonDelete(wxCommandEvent& event);
        void OnPersonDeleteAll(wxCommandEvent& event);
        void OnPersonSelect(wxListEvent& event);
        void OnDateSelect(wxListEvent& event);
        void OnShowTodayEvents(wxCommandEvent& event);
        void OnSave(wxCommandEvent& event);
        void OnDeleteDate(wxCommandEvent& event);
        void OnFirstNameEnter(wxCommandEvent& event);
        void OnAddDate(wxCommandEvent& event);
        void OnEditDate(wxCommandEvent& event);
        
    private:

        void CreateNotebook();
        void CreateMenu();
        void CreatePeopleList();
        void CreateDatesList();
        void CreatePanel();
        void CreateButtons();

    private:
        wxListCtrl*     _customersList;
        wxListCtrl*     _itemsList;
        wxListCtrl*     _rentalsList;
//        Controller      _controller;

        DECLARE_EVENT_TABLE()
    };

    // IDs for the controls and the menu commands
    enum
    {
        // menu items
        ID_FILEQUITMENU = wxID_EXIT,
        ID_NOTEBOOK,
        ID_CUSTOMERSPANEL,
        ID_CUSTOMERSLIST,
        ID_ITEMSPANEL,
        ID_RENTALSPANEL,
        
        // it is important for the id corresponding to the "About" command to have
        // this standard value as otherwise it won't be handled properly under Mac
        // (where it is special and put into the "Apple" menu)
        ID_HELPABOUTMENU = wxID_ABOUT
    };
}

#endif /*DVDRENTAL_H_*/
