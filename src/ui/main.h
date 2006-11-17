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

#undef Main_STYLE
#define Main_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX

class Main : public wxFrame
{
    private:
        DECLARE_EVENT_TABLE();

    public:
        Main(wxWindow *parent,
             wxWindowID id = 1,
             const wxString &title = wxT("DVD Rental"),
             const wxPoint& pos = wxDefaultPosition,
             const wxSize& size = wxDefaultSize,
             long style = Main_STYLE);
        virtual ~Main();

        void firstNameFieldEnter(wxCommandEvent& event);
        void lastNameFieldEnter(wxCommandEvent& event);
        void itemTitleFieldEnter(wxCommandEvent& event);
        void phoneNumberFieldEnter(wxCommandEvent& event);

        void saveCustomerButtonClick(wxCommandEvent& event);
        void itemSaveButtonClick(wxCommandEvent& event);
        void itemCancelButtonClick(wxCommandEvent& event);
        void cancelCustomerEditionClick(wxCommandEvent& event);
        void createRentalButtonClick(wxCommandEvent& event);
        void cancelNewRentalButtonClick(wxCommandEvent& event);
        void editItemButtonClick(wxCommandEvent& event);
        void lateRentalsButtonClick(wxCommandEvent& event);
        void editCustomerButtonClick(wxCommandEvent& event);

        void customersListSelected(wxListEvent& event);
        void itemsListSelected(wxListEvent& event);
        void rentalsListSelected(wxListEvent& event);
        void newRentalCustomerListSelected(wxListEvent& event);
        void newRentalItemListSelected(wxListEvent& event);

        void itemKindChoiceSelected(wxCommandEvent& event );

    private:
        wxBoxSizer *mainSizer;
        wxBoxSizer *notebookSizer;
        wxBoxSizer *customersPageSizer;
        wxBoxSizer *innerCustomersPageSizer;
        wxBoxSizer *itemsPageSizer;
        wxBoxSizer *rentalsPageSizer;
        wxBoxSizer *newRentalPageSizer;
        wxBoxSizer *innerNewRentalPageSizer;
        wxBoxSizer *buttonsNewRentalPageSizer;
        wxBoxSizer *innerItemsPageSizer;

        wxButton *lateRentalsButton;
        wxButton *editItemButton;
        wxButton *editCustomerButton;
        wxButton *cancelNewRentalButton;
        wxButton *returnRentalButton;
        wxButton *createRentalButton;
        wxButton *itemSaveButton;
        wxButton *itemCancelButton;
        wxButton *cancelCustomerEdition;
        wxButton *saveCustomerButton;

        wxStaticText *availableLabel;
        wxStaticText *availabilityLabel;
        wxStaticText *rentalReview;
        wxStaticText *rentalSummary;
        wxStaticText *reviewCreateLabel;
        wxStaticText *selectItemLabel;
        wxStaticText *selectCustomerLabel;
        wxStaticText *itemKindLabel;
        wxStaticText *phoneNumberLabel;
        wxStaticText *itemTitleLabel;
        wxStaticText *lastNameLabel;
        wxStaticText *firstNameLabel;

        wxListCtrl *rentalsList;
        wxListCtrl *newRentalItemList;
        wxListCtrl *newRentalCustomerList;
        wxListCtrl *itemsList;
        wxListCtrl *customersList;

        wxChoice *itemKindChoice;

        wxTextCtrl *itemTitleField;
        wxTextCtrl *phoneNumberField;
        wxTextCtrl *lastNameField;
        wxTextCtrl *firstNameField;

        wxPanel *itemsNotebookPage;
        wxPanel *customersNotebookPage;
        wxPanel *newRentalNotebookPage;
        wxPanel *rentalsNotebookPage;
        wxNotebook *notebook;

        wxPanel *mainPanel;

        wxStatusBar *statusBar;
        wxMenuBar *menuBar;

    private:

        enum
        {
            ID_LATERENTALSBUTTON = 1075,
            ID_EDITITEMBUTTON = 1074,
            ID_EDITCUSTOMERBUTTON = 1073,
            ID_AVAILABLELABEL = 1072,
            ID_AVAILABILITYLABEL = 1071,
            ID_CANCELNEWRENTALBUTTON = 1070,
            ID_RETURNRENTALBUTTON = 1069,
            ID_RENTALREVIEW = 1068,
            ID_RENTALSLIST = 1066,
            ID_RENTALSUMMARY = 1062,
            ID_REVIEWCREATELABEL = 1061,
            ID_CREATERENTALBUTTON = 1060,
            ID_NEWRENTALITEMLIST = 1059,
            ID_SELECTITEMLABEL = 1058,
            ID_NEWRENTALCUSTOMERLIST = 1057,
            ID_SELECTCUSTOMERLABEL = 1056,
            ID_MNU_FILE_1013 = 1013,
            ID_MNU_EDIT_1033 = 1033,
            ID_MNU_CUSTOMER_1014 = 1014,
            ID_MNU_ADDCUSTOMER_1019 = 1019,
            ID_MNU_EDITCUSTOMER_1022 = 1022,
            ID_MNU_DELETECUSTOMER_1023 = 1023,
            ID_MNU_ITEM_1015 = 1015,
            ID_MNU_ADDITEM_1027 = 1027,
            ID_MNU_EDITITEM_1028 = 1028,
            ID_MNU_DELETEITEM_1030 = 1030,
            ID_MNU_RENTAL_1016 = 1016,
            ID_MNU_CREATERENTAL_1025 = 1025,
            ID_MNU_SEELATERENTALS_1026 = 1026,
            ID_MNU_HELP_1017 = 1017,

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
            ID_CANCELCUSTOMEREDITION = 1045,
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
            ID_STATUSBAR = 1004
        };

    private:
        void OnClose(wxCloseEvent& event);
        void CreateGUIControls();
        void CreateMenuBar();
};

#endif
