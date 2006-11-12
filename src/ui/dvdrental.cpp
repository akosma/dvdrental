/*!
 * \file dvdrental.cpp
 * Contains the implementation of the ui::DvdRental class.
 */

#include "dvdrental.h"

//#ifndef CONTROLLER_H_
//#include "controller.h"
//#endif

BEGIN_EVENT_TABLE(ui::DvdRental, wxFrame)
    EVT_MENU(ui::ID_FILEQUITMENU,             ui::DvdRental::OnFileQuitMenu)
    EVT_MENU(ui::ID_HELPABOUTMENU,            ui::DvdRental::OnHelpAboutMenu)
//    EVT_MENU(ui::FileShowTodayEvents,         ui::DvdRental::OnShowTodayEvents)
//    EVT_MENU(ui::PersonNew,                   ui::DvdRental::OnPersonNew)
//    EVT_MENU(ui::PersonEdit,                  ui::DvdRental::OnPersonEdit)
//    EVT_MENU(ui::PersonDelete,                ui::DvdRental::OnPersonDelete)
//    EVT_MENU(ui::PersonDeleteAll,             ui::DvdRental::OnPersonDeleteAll)
//    EVT_BUTTON(ui::TodayEventsButton,         ui::DvdRental::OnShowTodayEvents)
//    EVT_BUTTON(ui::SaveButton,                ui::DvdRental::OnSave)
//    EVT_BUTTON(ui::EditButton,                ui::DvdRental::OnPersonEdit)
//    EVT_BUTTON(ui::DeleteDateButton,          ui::DvdRental::OnDeleteDate)
//    EVT_BUTTON(ui::AddDateButton,             ui::DvdRental::OnAddDate)
//    EVT_BUTTON(ui::EditDateButton,            ui::DvdRental::OnEditDate)
//    EVT_TEXT_ENTER(ui::LastNameTextCtrl,      ui::DvdRental::OnSave)
//    EVT_TEXT_ENTER(ui::FirstNameTextCtrl,     ui::DvdRental::OnFirstNameEnter)
//    EVT_LIST_ITEM_SELECTED(ui::PeopleListbox, ui::DvdRental::OnPersonSelect)
//    EVT_LIST_ITEM_SELECTED(ui::PeopleDatebox, ui::DvdRental::OnDateSelect)
END_EVENT_TABLE()

/*!
 * \namespace ui
 * Contains the classes that depend on the wxWidgets framework,
 * providing the GUI of the DVD Rental application.
 */
namespace ui
{
    DvdRental::DvdRental(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(600, 500),
                wxDEFAULT_FRAME_STYLE - wxRESIZE_BORDER - wxMAXIMIZE_BOX)
    , _customersList        (0)
    , _itemsList            (0)
    , _rentalsList          (0)
//    , _controller  (Controller())
    {
        CreateNotebook();
        CreateStatusBar();
        CreateMenu();
//        CreatePeopleList();
//        CreateDatesList();
//        CreatePanel();
//        CreateButtons();
//
//        _controller.fillPeopleList(_peopleList);
//        SetStatusText(_controller.getStatusBarText());
    }
    
    void DvdRental::CreateNotebook()
    {
        wxNotebook* notebook = new wxNotebook( this, ID_NOTEBOOK, wxDefaultPosition, wxDefaultSize, wxNB_DEFAULT );

        wxPanel* customersPanel = new wxPanel( notebook, ID_CUSTOMERSPANEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
        wxListCtrl* customersList = new wxListCtrl( customersPanel, ID_CUSTOMERSLIST, wxDefaultPosition, wxSize(100, 200), wxLC_REPORT );
        notebook->AddPage(customersPanel, _("Customers"));

        wxPanel* itemsPanel = new wxPanel( notebook, ID_ITEMSPANEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
        notebook->AddPage(itemsPanel, _("Items"));

        wxPanel* rentalsPanel = new wxPanel( notebook, ID_RENTALSPANEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
        notebook->AddPage(rentalsPanel, _("Rentals"));
    }

    void DvdRental::CreatePanel()
    {
//        _firstName = new wxTextCtrl(_mainPanel, FirstNameTextCtrl, wxT(""),
//    						    wxPoint(180, 10), wxSize(300, 20), wxTE_PROCESS_ENTER);
//        _lastName = new wxTextCtrl(_mainPanel, LastNameTextCtrl, wxT(""),
//    						    wxPoint(180, 50), wxSize(300, 20), wxTE_PROCESS_ENTER);
//
//        _firstName->SetEditable(false);
//        _lastName->SetEditable(false);
    }

    void DvdRental::CreateButtons()
    {
//        _buttonAddDate = new wxButton(_mainPanel, AddDateButton, wxT("Add Date"),
//                                    wxPoint(180, 350), wxSize(80, 25));
//        _buttonEditDate = new wxButton(_mainPanel, EditDateButton, wxT("Edit Date"),
//                                    wxPoint(270, 350), wxSize(80, 25));
//        _buttonDeleteDate = new wxButton(_mainPanel, DeleteDateButton, wxT("Remove"),
//                                    wxPoint(360, 350), wxSize(80, 25));
//        _buttonSave = new wxButton(_mainPanel, SaveButton, wxT("Save"),
//    							    wxPoint(180, 90), wxSize(80, 25));
//        _buttonEdit = new wxButton(_mainPanel, EditButton, wxT("Edit"),
//    							    wxPoint(270, 90), wxSize(80, 25));
//        _buttonShowTodayEvents = new wxButton(_mainPanel,
//                    TodayEventsButton, wxT("Today"),
//                    wxPoint(360, 90), wxSize(80, 25));
//
//        _buttonAddDate->Disable();
//        _buttonEditDate->Disable();
//        _buttonDeleteDate->Disable();
//        _buttonSave->Disable();
//        _buttonEdit->Disable();
    }

    void DvdRental::CreatePeopleList()
    {
//        _peopleList = new wxListCtrl(_mainPanel, PeopleListbox,
//                            wxPoint(15, 10), wxSize(150, 370),
//                            wxLC_REPORT + wxLC_NO_HEADER + wxLC_SINGLE_SEL);
//
//        _peopleList->InsertColumn(0, wxString("People names"),
//    						    wxLIST_FORMAT_LEFT, 125);
    }

    void DvdRental::CreateDatesList()
    {
//        _datesList = new wxListCtrl(_mainPanel, PeopleDatebox,
//                            wxPoint(180, 130), wxSize(300, 200),
//                            wxLC_REPORT + wxLC_SINGLE_SEL);
//        _datesList->InsertColumn(0, wxString("Date"),
//    						    wxLIST_FORMAT_LEFT, 148);
//        _datesList->InsertColumn(1, wxString("Event"),
//    						    wxLIST_FORMAT_LEFT, 148);
    }

    void DvdRental::CreateMenu()
    {
        wxMenu* fileMenu = new wxMenu;
//        wxMenu* personMenu = new wxMenu;
        wxMenu* helpMenu = new wxMenu;
//
//        // the "About" item should be in the help menu
        helpMenu->Append(ID_HELPABOUTMENU, _T("&About...\tF1"), _T("Show about dialog"));
//        fileMenu->Append(FileShowTodayEvents, _T("&Show Today's Events\tCtrl-T"), _T("Show Today's Events"));
        fileMenu->Append(ID_FILEQUITMENU, _T("E&xit\tCtrl-Q"), _T("Quit this program"));
//
//        personMenu->Append(PersonNew, _T("N&ew\tCtrl-N"), _T("Add new person"));
//        personMenu->Append(PersonEdit, _T("E&dit\tCtrl-E"), _T("Edit current person"));
//        personMenu->Append(PersonDelete, _T("D&elete\tCtrl-D"), _T("Delete the current person"));
//        personMenu->Append(PersonDeleteAll, _T("Delete A&ll\tCtrl-A"), _T("Delete all people"));
//
//        // now append the freshly created menu to the menu bar...
        wxMenuBar *menuBar = new wxMenuBar();
        menuBar->Append(fileMenu, _T("&File"));
//        menuBar->Append(personMenu, _T("&Person"));
        menuBar->Append(helpMenu, _T("&Help"));
        SetMenuBar(menuBar);
    }

    void DvdRental::OnFileQuitMenu(wxCommandEvent& WXUNUSED(event))
    {
        Close(true);
    }

    void DvdRental::OnHelpAboutMenu(wxCommandEvent& WXUNUSED(event))
    {
        wxString msg;
        msg.Printf( _T("DVD Rental application, 2006\n")
                    _T("Keith Miller\nAhmed Madkour\nAdrian Kosmaczewski"));

        wxMessageBox(msg, _T("About DVD Rental"), wxOK | wxICON_INFORMATION, this);
    }

    void DvdRental::OnPersonNew(wxCommandEvent& WXUNUSED(event))
    {
//        _firstName->SetValue(wxT(""));
//        _lastName->SetValue(wxT(""));
//        _firstName->SetEditable(true);
//        _lastName->SetEditable(true);
//        _firstName->SetFocus();
//        _buttonSave->Enable();
//        _buttonEdit->Disable();
//        _buttonAddDate->Disable();
//        _buttonDeleteDate->Disable();
//        _datesList->DeleteAllItems();
//        _controller.prepareForNewPerson();
    }

    void DvdRental::OnPersonDelete(wxCommandEvent& WXUNUSED(event))
    {
//        int answer = wxMessageBox("Are you sure?", "Confirm deletion", wxYES_NO);
//        if (answer == wxYES)
//        {
//            _controller.deleteCurrentPerson();
//            _datesList->DeleteAllItems();
//            _peopleList->DeleteAllItems();
//            _controller.fillPeopleList(_peopleList);
//            _buttonSave->Disable();
//            _buttonEdit->Disable();
//            _buttonAddDate->Disable();
//            _buttonDeleteDate->Disable();
//            SetStatusText(_controller.getStatusBarText());
//            _firstName->SetValue(_controller.getCurrentFirstName());
//            _lastName->SetValue(_controller.getCurrentLastName());
//        }
    }

    void DvdRental::OnPersonDeleteAll(wxCommandEvent& event)
    {
//        int answer = wxMessageBox("Are you sure? This cannot be undone.", "Confirm deletion", wxYES_NO);
//        if (answer == wxYES)
//        {
//            _controller.deleteAllPeople();
//
//            _datesList->DeleteAllItems();
//            _peopleList->DeleteAllItems();
//            _controller.fillPeopleList(_peopleList);
//            _buttonSave->Disable();
//            _buttonEdit->Disable();
//            _buttonAddDate->Disable();
//            _buttonDeleteDate->Disable();
//            SetStatusText(_controller.getStatusBarText());
//            _firstName->SetValue(_controller.getCurrentFirstName());
//            _lastName->SetValue(_controller.getCurrentLastName());
//        }
    }

    void DvdRental::OnPersonSelect(wxListEvent& event)
    {
//        int personId = (int)event.GetData();
//        _controller.loadPerson(personId);
//        _firstName->SetEditable(false);
//        _lastName->SetEditable(false);
//        _buttonSave->Disable();
//        _buttonEdit->Enable();
//        _buttonAddDate->Enable();
//        _buttonDeleteDate->Disable();
//        _buttonEditDate->Disable();
//
//        _datesList->DeleteAllItems();
//        _controller.fillDatesList(_datesList);
//        SetStatusText(_controller.getStatusBarText());
//        _firstName->SetValue(_controller.getCurrentFirstName());
//        _lastName->SetValue(_controller.getCurrentLastName());
    }

    void DvdRental::OnDateSelect(wxListEvent& event)
    {
//        int dateId = (int)event.GetData();
//        _controller.loadDate(dateId);
//        _buttonDeleteDate->Enable();
//        _buttonEditDate->Enable();
    }

    void DvdRental::OnShowTodayEvents(wxCommandEvent& event)
    {
//        wxString title;
//        title << "Events for ";
//        title << _controller.getTodayDateString();
//        TodayEventsDialog ted(title, _controller);
//        ted.Centre(wxBOTH);
//        ted.ShowModal();
    }

    void DvdRental::OnSave(wxCommandEvent& event)
    {
//        wxString first = _firstName->GetValue();
//        wxString last = _lastName->GetValue();
//        if (first.Length() == 0 || first.Length() == 0)
//        {
//            wxMessageBox(_T("You must provide the first and the last name."), _T("Error"), wxOK | wxICON_ERROR, this);
//        }
//        else
//        {
//            _controller.savePerson(first, last);
//            _firstName->SetEditable(false);
//            _lastName->SetEditable(false);
//            _buttonSave->Disable();
//            _buttonEdit->Enable();
//            _buttonAddDate->Enable();
//            _peopleList->DeleteAllItems();
//            _controller.fillPeopleList(_peopleList);
//            SetStatusText(_controller.getStatusBarText());
//        }
    }

    void DvdRental::OnPersonEdit(wxCommandEvent& event)
    {
//        if (_controller.isPersonSelected())
//        {
//            _firstName->SetEditable(true);
//            _lastName->SetEditable(true);
//            _firstName->SetFocus();
//            _buttonSave->Enable();
//            _buttonEdit->Disable();
//            _buttonAddDate->Disable();
//            _buttonDeleteDate->Disable();
//            _buttonEditDate->Disable();
//        }
    }

    void DvdRental::OnDeleteDate(wxCommandEvent& event)
    {
//        _controller.deleteCurrentDate();
//        _datesList->DeleteAllItems();
//        _controller.fillDatesList(_datesList);
//        _buttonDeleteDate->Disable();
//        _buttonEditDate->Disable();
    }

    void DvdRental::OnFirstNameEnter(wxCommandEvent& event)
    {
//        _lastName->SetFocus();
    }

    void DvdRental::OnAddDate(wxCommandEvent& event)
    {
//        DateDialog dd(_controller, false);
//        dd.Centre(wxBOTH);
//        if (wxID_OK == dd.ShowModal())
//        {
//            _datesList->DeleteAllItems();
//            _controller.fillDatesList(_datesList);
//        }
    }

    void DvdRental::OnEditDate(wxCommandEvent& event)
    {
//        DateDialog dd(_controller, true);
//        dd.Centre(wxBOTH);
//        if (wxID_OK == dd.ShowModal())
//        {
//            _datesList->DeleteAllItems();
//            _controller.fillDatesList(_datesList);
//        }
    }
}
