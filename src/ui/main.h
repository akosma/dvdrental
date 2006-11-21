//---------------------------------------------------------------------------
//
// Name:        main.h
// Author:      ako
// Created:     11/14/2006 12:14:42 PM
// Description: Main class declaration
//
//---------------------------------------------------------------------------

#ifndef __MAIN_h__
#define __MAIN_h__

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
    #include <wx/frame.h>
#else
    #include <wx/wxprec.h>
#endif

#include <wx/menu.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/listctrl.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/gbsizer.h>

#ifndef CONTROLLER_H
#include "controller.h"
#endif

#undef Main_STYLE
#define Main_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX

class Main : public wxFrame
{
    private:
        DECLARE_EVENT_TABLE();

    public:
        Main(wxWindow *parent,
             wxWindowID id = 1,
             const wxString &title = wxT("DVDRental"),
             const wxPoint& pos = wxDefaultPosition,
             const wxSize& size = wxDefaultSize,
             long style = Main_STYLE);
        virtual ~Main();

        void OnFirstNameFieldEnter(wxCommandEvent& event);
        void OnLastNameFieldEnter(wxCommandEvent& event);
        void OnItemTitleFieldEnter(wxCommandEvent& event);
        void OnPhoneNumberFieldEnter(wxCommandEvent& event);
        void OnAddressFieldEnter(wxCommandEvent& event);

        void OnSaveCustomerButtonClick(wxCommandEvent& event);
        void OnItemSaveButtonClick(wxCommandEvent& event);
        void OnItemCancelButtonClick(wxCommandEvent& event);
        void OnCancelCustomerEditionClick(wxCommandEvent& event);
        void OnCreateRentalButtonClick(wxCommandEvent& event);
        void OnEditItemButtonClick(wxCommandEvent& event);
        void OnEditCustomerButtonClick(wxCommandEvent& event);
        void OnRentalsReturnButtonClick(wxCommandEvent& event);

        void OnCustomersListSelected(wxListEvent& event);
        void OnItemsListSelected(wxListEvent& event);
        void OnRentalsListSelected(wxListEvent& event);

        void OnMenuFileExitSelected(wxCommandEvent& event);
        void OnMenuHelpAboutSelected(wxCommandEvent& event);
        void OnMenuAddCustomerSelected(wxCommandEvent& event);
        void OnMenuDeleteCustomerSelected(wxCommandEvent& event);
        void OnMenuAddItemSelected(wxCommandEvent& event);
        void OnMenuDeleteItemSelected(wxCommandEvent& event);

    private:
        Controller controller;
    
        wxBoxSizer* mainSizer;
        wxBoxSizer* notebookSizer;

        wxBoxSizer* customersPageSizer;
        wxBoxSizer* innerCustomersPageSizer;
        wxBoxSizer* buttonsCustomerSizer;

        wxBoxSizer* itemsPageSizer;
        wxBoxSizer* rentalsPageSizer;
        wxBoxSizer* innerRentalsPageSizer;
        wxBoxSizer* newRentalPageSizer;
        wxBoxSizer* buttonsNewRentalPageSizer;
        wxBoxSizer* innerItemsPageSizer;
        wxBoxSizer* buttonsItemSizer;
        wxBoxSizer* newRentalButtonSizer;
        wxBoxSizer* newRentalInnerSizer;

        wxGridBagSizer* newRentalFieldsSizer;
        wxGridBagSizer* customerFieldsSizer;
        wxGridBagSizer* itemFieldsSizer;

        wxButton* editItemButton;
        wxButton* editCustomerButton;
        wxButton* cancelNewRentalButton;
        wxButton* returnRentalButton;
        wxButton* createRentalButton;
        wxButton* itemSaveButton;
        wxButton* itemCancelButton;
        wxButton* cancelCustomerEditionButton;
        wxButton* saveCustomerButton;

        wxStaticText* availableLabel;
        wxStaticText* availabilityLabel;
        wxStaticText* rentalSummary;
        wxStaticText* reviewCreateLabel;
        wxStaticText* selectItemLabel;
        wxStaticText* selectCustomerLabel;
        wxStaticText* itemKindLabel;
        wxStaticText* phoneNumberLabel;
        wxStaticText* itemTitleLabel;
        wxStaticText* lastNameLabel;
        wxStaticText* firstNameLabel;
        wxStaticText* addressLabel;

        wxListCtrl* rentalsList;
        wxListCtrl* newRentalItemList;
        wxListCtrl* newRentalCustomerList;
        wxListCtrl* itemsList;
        wxListCtrl* customersList;

        wxChoice* itemKindChoice;

        wxTextCtrl* itemTitleField;
        wxTextCtrl* phoneNumberField;
        wxTextCtrl* lastNameField;
        wxTextCtrl* firstNameField;
        wxTextCtrl* addressField;

        wxPanel* itemsNotebookPage;
        wxPanel* customersNotebookPage;
        wxPanel* newRentalNotebookPage;
        wxPanel* rentalsNotebookPage;
        wxNotebook* notebook;

        wxPanel* mainPanel;

        wxMenuBar* menuBar;

    private:

        enum
        {
            ID_EDITITEMBUTTON = 1074,
            ID_EDITCUSTOMERBUTTON = 1073,
            ID_AVAILABLELABEL = 1072,
            ID_AVAILABILITYLABEL = 1071,
            ID_RETURNRENTALBUTTON = 1069,
            ID_RENTALSLIST = 1066,
            ID_RENTALSUMMARY = 1062,
            ID_REVIEWCREATELABEL = 1061,
            ID_CREATERENTALBUTTON = 1060,
            ID_NEWRENTALITEMLIST = 1059,
            ID_SELECTITEMLABEL = 1058,
            ID_NEWRENTALCUSTOMERLIST = 1057,
            ID_SELECTCUSTOMERLABEL = 1056,
            ID_MNU_FILE = 1013,
            ID_MNU_EDIT = 1033,
            ID_MNU_CUSTOMER = 1014,
            ID_MNU_ADDCUSTOMER = 1019,
            ID_MNU_DELETECUSTOMER = 1023,
            ID_MNU_ITEM = 1015,
            ID_MNU_ADDITEM = 1027,
            ID_MNU_DELETEITEM = 1030,
            ID_MNU_RENTAL = 1016,
            ID_MNU_CREATERENTAL = 1025,
            ID_MNU_SEELATERENTALS = 1026,
            ID_MNU_HELP = 1017,

            ID_ITEMSAVEBUTTON = 1053,
            ID_ITEMCANCELBUTTON = 1052,
            ID_ITEMKINDCHOICE = 1051,
            ID_KINDLABEL = 1050,
            ID_ITEMTITLEFIELD = 1049,
            ID_ITEMTITLELABEL = 1048,
            ID_ITEMSLIST = 1020,
            ID_ITEMSNOTEBOOKPAGE = 1005,
            ID_PHONENUMBERFIELD = 1047,
            ID_PHONENUMBERLABEL = 1046,
            ID_CANCELCUSTOMEREDITIONBUTTON = 1045,
            ID_SAVECUSTOMERBUTTON = 1044,
            ID_LASTNAMEFIELD = 1043,
            ID_FIRSTNAMEFIELD = 1042,
            ID_LASTNAMELABEL = 1041,
            ID_FIRSTNAMELABEL = 1040,
            ID_CUSTOMERSLIST = 1007,
            ID_CUSTOMERSNOTEBOOKPAGE = 1003,
            ID_NEWRENTALNOTEBOOKPAGE = 1055,
            ID_RENTALSNOTEBOOKPAGE = 1006,
            ID_NOTEBOOK = 1002,
            ID_MAINPANEL = 1005,
            ID_STATUSBAR = 1004,
            ID_ADDRESSLABEL = 1060,
            ID_ADDRESSFIELD = 1061
        };

    private:
        void OnClose(wxCloseEvent& event);
        void CreateGUIControls();
        void CreateGlobalControls();
        void CreateCustomersTab();
        void CreateRentalsTab();
        void CreateItemsTab();
        void CreateNewRentalTab();
        void CreateMenuBar();
        void LoadData();
        void SetAvailabilityLabel(Availability);
};

#endif
