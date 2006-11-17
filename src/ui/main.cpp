//---------------------------------------------------------------------------
//
// Name:        main.cpp
// Author:      ako
// Created:     11/14/2006 12:14:42 PM
// Description: Main class implementation
//
//---------------------------------------------------------------------------

#include "main.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// Main
//----------------------------------------------------------------------------
BEGIN_EVENT_TABLE(Main,wxFrame)
    EVT_CLOSE(Main::OnClose)

    EVT_BUTTON(ID_LATERENTALSBUTTON,Main::lateRentalsButtonClick)
    EVT_BUTTON(ID_EDITITEMBUTTON,Main::editItemButtonClick)
    EVT_BUTTON(ID_EDITCUSTOMERBUTTON,Main::editCustomerButtonClick)
    EVT_BUTTON(ID_CANCELNEWRENTALBUTTON,Main::cancelNewRentalButtonClick)
    EVT_BUTTON(ID_CREATERENTALBUTTON,Main::createRentalButtonClick)
    EVT_BUTTON(ID_ITEMSAVEBUTTON,Main::itemSaveButtonClick)
    EVT_BUTTON(ID_ITEMCANCELBUTTON,Main::itemCancelButtonClick)
    EVT_BUTTON(ID_CANCELCUSTOMEREDITION,Main::cancelCustomerEditionClick)
    EVT_BUTTON(ID_SAVECUSTOMERBUTTON,Main::saveCustomerButtonClick)

    EVT_CHOICE(ID_ITEMKINDCHOICE,Main::itemKindChoiceSelected)

    EVT_TEXT_ENTER(ID_ITEMTITLEFIELD,Main::itemTitleFieldEnter)
    EVT_TEXT_ENTER(ID_LASTNAMEFIELD,Main::lastNameFieldEnter)
    EVT_TEXT_ENTER(ID_FIRSTNAMEFIELD,Main::firstNameFieldEnter)
    EVT_TEXT_ENTER(ID_PHONENUMBERFIELD,Main::phoneNumberFieldEnter)

    EVT_LIST_ITEM_SELECTED(ID_ITEMSLIST,Main::itemsListSelected)
    EVT_LIST_ITEM_SELECTED(ID_RENTALSLIST,Main::rentalsListSelected)
    EVT_LIST_ITEM_SELECTED(ID_NEWRENTALITEMLIST,Main::newRentalItemListSelected)
    EVT_LIST_ITEM_SELECTED(ID_NEWRENTALCUSTOMERLIST,Main::newRentalCustomerListSelected)
    EVT_LIST_ITEM_SELECTED(ID_CUSTOMERSLIST,Main::customersListSelected)
END_EVENT_TABLE()

Main::Main(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
    CreateMenuBar();
    CreateGUIControls();
}

Main::~Main()
{
}

void Main::CreateMenuBar()
{
    menuBar = new wxMenuBar();
    wxMenu *ID_MNU_FILE_1013_Mnu_Obj = new wxMenu(0);
    ID_MNU_FILE_1013_Mnu_Obj->Append(wxID_EXIT, wxT("Quit"), wxT(""), wxITEM_NORMAL);
    menuBar->Append(ID_MNU_FILE_1013_Mnu_Obj, wxT("File"));

    wxMenu *ID_MNU_EDIT_1033_Mnu_Obj = new wxMenu(0);
    ID_MNU_EDIT_1033_Mnu_Obj->Append(wxID_CUT, wxT("Cut"), wxT(""), wxITEM_NORMAL);
    ID_MNU_EDIT_1033_Mnu_Obj->Append(wxID_COPY, wxT("Copy"), wxT(""), wxITEM_NORMAL);
    ID_MNU_EDIT_1033_Mnu_Obj->Append(wxID_PASTE, wxT("Paste"), wxT(""), wxITEM_NORMAL);
    menuBar->Append(ID_MNU_EDIT_1033_Mnu_Obj, wxT("Edit"));

    wxMenu *ID_MNU_CUSTOMER_1014_Mnu_Obj = new wxMenu(0);
    ID_MNU_CUSTOMER_1014_Mnu_Obj->Append(ID_MNU_ADDCUSTOMER_1019, wxT("Add Customer"), wxT(""), wxITEM_NORMAL);
    ID_MNU_CUSTOMER_1014_Mnu_Obj->Append(ID_MNU_EDITCUSTOMER_1022, wxT("Edit Customer"), wxT(""), wxITEM_NORMAL);
    ID_MNU_CUSTOMER_1014_Mnu_Obj->Append(ID_MNU_DELETECUSTOMER_1023, wxT("Delete Customer"), wxT(""), wxITEM_NORMAL);
    menuBar->Append(ID_MNU_CUSTOMER_1014_Mnu_Obj, wxT("Customer"));

    wxMenu *ID_MNU_ITEM_1015_Mnu_Obj = new wxMenu(0);
    ID_MNU_ITEM_1015_Mnu_Obj->Append(ID_MNU_ADDITEM_1027, wxT("Add Item"), wxT(""), wxITEM_NORMAL);
    ID_MNU_ITEM_1015_Mnu_Obj->Append(ID_MNU_EDITITEM_1028, wxT("Edit Item"), wxT(""), wxITEM_NORMAL);
    ID_MNU_ITEM_1015_Mnu_Obj->Append(ID_MNU_DELETEITEM_1030, wxT("Delete Item"), wxT(""), wxITEM_NORMAL);
    menuBar->Append(ID_MNU_ITEM_1015_Mnu_Obj, wxT("Item"));

    wxMenu *ID_MNU_RENTAL_1016_Mnu_Obj = new wxMenu(0);
    ID_MNU_RENTAL_1016_Mnu_Obj->Append(ID_MNU_CREATERENTAL_1025, wxT("Create Rental"), wxT(""), wxITEM_NORMAL);
    ID_MNU_RENTAL_1016_Mnu_Obj->Append(ID_MNU_SEELATERENTALS_1026, wxT("See Late Rentals"), wxT(""), wxITEM_NORMAL);
    menuBar->Append(ID_MNU_RENTAL_1016_Mnu_Obj, wxT("Rental"));

    wxMenu *ID_MNU_HELP_1017_Mnu_Obj = new wxMenu(0);
    ID_MNU_HELP_1017_Mnu_Obj->Append(wxID_ABOUT, wxT("About..."), wxT(""), wxITEM_NORMAL);
    menuBar->Append(ID_MNU_HELP_1017_Mnu_Obj, wxT("Help"));
    SetMenuBar(menuBar);
}

void Main::CreateGUIControls()
{
    // Global window set up
    mainSizer = new wxBoxSizer(wxHORIZONTAL);
    this->SetSizer(mainSizer);
    this->SetAutoLayout(true);

    statusBar = new wxStatusBar(this, ID_STATUSBAR);

    // This "mainPanel" is used to provide a common background to the window
    // similar to the background of a dialog box
    mainPanel = new wxPanel(this, ID_MAINPANEL, wxPoint(0,0), wxSize(592,454));
    mainSizer->Add(mainPanel, 1, wxEXPAND | wxALL, 0);

    notebookSizer = new wxBoxSizer(wxHORIZONTAL);
    mainPanel->SetSizer(notebookSizer);
    mainPanel->SetAutoLayout(true);

    notebook = new wxNotebook(mainPanel, ID_NOTEBOOK, wxPoint(8,7),wxSize(574,439));
    notebookSizer->Add(notebook, 1, wxEXPAND | wxALL, 5);

    // Rentals Tab

    rentalsPageSizer = new wxBoxSizer(wxHORIZONTAL);
    rentalsNotebookPage = new wxPanel(notebook, ID_RENTALSNOTEBOOKPAGE, wxPoint(4,24), wxSize(566,411));
    notebook->AddPage(rentalsNotebookPage, wxT("Rentals"));
    rentalsNotebookPage->SetSizer(rentalsPageSizer);
    rentalsNotebookPage->SetAutoLayout(true);

    rentalsList = new wxListCtrl(rentalsNotebookPage, ID_RENTALSLIST, wxPoint(5,8), wxSize(168,395), wxLC_REPORT);
    rentalsPageSizer->Add(rentalsList, 1, wxEXPAND | wxALL, 5);
    innerNewRentalPageSizer = new wxBoxSizer(wxVERTICAL);
    rentalsPageSizer->Add(innerNewRentalPageSizer, 1, wxEXPAND | wxALL, 5);

    rentalReview = new wxStaticText(rentalsNotebookPage, ID_RENTALREVIEW, wxT(""), wxPoint(188,9), wxDefaultSize, 0, wxT("rentalReview"));
    innerNewRentalPageSizer->Add(rentalReview, 1, wxEXPAND | wxALL, 5);

    buttonsNewRentalPageSizer = new wxBoxSizer(wxHORIZONTAL);
    innerNewRentalPageSizer->Add(buttonsNewRentalPageSizer, 0, wxALIGN_RIGHT | wxALL, 5);

    returnRentalButton = new wxButton(rentalsNotebookPage, ID_RETURNRENTALBUTTON, wxT("Returned"), wxPoint(478,379), wxSize(75,25), 0, wxDefaultValidator, wxT("returnRentalButton"));
    buttonsNewRentalPageSizer->Add(returnRentalButton, 0, wxALIGN_RIGHT | wxALL, 5);

    lateRentalsButton = new wxButton(rentalsNotebookPage, ID_LATERENTALSBUTTON, wxT("See Late Rentals"), wxPoint(298,379), wxSize(165,25), 0, wxDefaultValidator, wxT("lateRentalsButton"));
    buttonsNewRentalPageSizer->Add(lateRentalsButton, 0, wxALIGN_RIGHT | wxALL, 5);

    // Customers Tab

    customersPageSizer = new wxBoxSizer(wxHORIZONTAL);
    customersNotebookPage = new wxPanel(notebook, ID_CUSTOMERSNOTEBOOKPAGE, wxPoint(4,24), wxSize(566,411));
    notebook->AddPage(customersNotebookPage, wxT("Customers"));
    customersNotebookPage->SetSizer(customersPageSizer);
    customersNotebookPage->SetAutoLayout(true);

    customersList = new wxListCtrl(customersNotebookPage, ID_CUSTOMERSLIST, wxPoint(5,8), wxSize(168,395), wxLC_REPORT);
    customersPageSizer->Add(customersList, 1, wxEXPAND | wxALL, 5);
    innerCustomersPageSizer = new wxBoxSizer(wxVERTICAL);
    customersPageSizer->Add(innerCustomersPageSizer, 1, wxEXPAND | wxALL, 5);

    firstNameLabel = new wxStaticText(customersNotebookPage, ID_FIRSTNAMELABEL, wxT("First Name"), wxPoint(198,21), wxDefaultSize, 0, wxT("firstNameLabel"));
    innerCustomersPageSizer->Add(firstNameLabel, 0, wxALIGN_LEFT | wxALL, 5);
    firstNameField = new wxTextCtrl(customersNotebookPage, ID_FIRSTNAMEFIELD, wxT(""), wxPoint(298,19), wxSize(231,21), 0, wxDefaultValidator, wxT("firstNameField"));
    innerCustomersPageSizer->Add(firstNameField, 0, wxALIGN_RIGHT | wxALL, 5);

    lastNameLabel = new wxStaticText(customersNotebookPage, ID_LASTNAMELABEL, wxT("Last Name"), wxPoint(198,59), wxDefaultSize, 0, wxT("lastNameLabel"));
    innerCustomersPageSizer->Add(lastNameLabel, 0, wxALIGN_LEFT | wxALL, 5);
    lastNameField = new wxTextCtrl(customersNotebookPage, ID_LASTNAMEFIELD, wxT(""), wxPoint(298,57), wxSize(231,21), 0, wxDefaultValidator, wxT("lastNameField"));
    innerCustomersPageSizer->Add(lastNameField, 0, wxALIGN_RIGHT | wxALL, 5);

    phoneNumberLabel = new wxStaticText(customersNotebookPage, ID_PHONENUMBERLABEL, wxT("Phone Number"), wxPoint(198,99), wxDefaultSize, 0, wxT("phoneNumberLabel"));
    innerCustomersPageSizer->Add(phoneNumberLabel, 0, wxALIGN_LEFT | wxALL, 5);
    phoneNumberField = new wxTextCtrl(customersNotebookPage, ID_PHONENUMBERFIELD, wxT(""), wxPoint(298,97), wxSize(231,21), 0, wxDefaultValidator, wxT("phoneNumberField"));
    innerCustomersPageSizer->Add(phoneNumberField, 0, wxALIGN_RIGHT | wxALL, 5);

    editCustomerButton = new wxButton(customersNotebookPage, ID_EDITCUSTOMERBUTTON, wxT("Edit"), wxPoint(298,379), wxSize(75,25), 0, wxDefaultValidator, wxT("editCustomerButton"));
    innerCustomersPageSizer->Add(editCustomerButton, 0, wxALIGN_RIGHT | wxALL, 5);
    saveCustomerButton = new wxButton(customersNotebookPage, ID_SAVECUSTOMERBUTTON, wxT("Save"), wxPoint(388,379), wxSize(75,25), 0, wxDefaultValidator, wxT("saveCustomerButton"));
    innerCustomersPageSizer->Add(saveCustomerButton, 0, wxALIGN_RIGHT | wxALL, 5);
    cancelCustomerEdition = new wxButton(customersNotebookPage, ID_CANCELCUSTOMEREDITION, wxT("Cancel"), wxPoint(478,379), wxSize(75,25), 0, wxDefaultValidator, wxT("cancelCustomerEdition"));
    innerCustomersPageSizer->Add(cancelCustomerEdition, 0, wxALIGN_RIGHT | wxALL, 5);

    // Items Tab

    itemsNotebookPage = new wxPanel(notebook, ID_ITEMSNOTEBOOKPAGE, wxPoint(4,24), wxSize(566,411));
    notebook->AddPage(itemsNotebookPage, wxT("Items"));

    itemsList = new wxListCtrl(itemsNotebookPage, ID_ITEMSLIST, wxPoint(5,8), wxSize(168,395), wxLC_REPORT);

    itemTitleLabel = new wxStaticText(itemsNotebookPage, ID_ITEMTITLELABEL, wxT("Title"), wxPoint(198,21), wxDefaultSize, 0, wxT("itemTitleLabel"));
    itemKindLabel = new wxStaticText(itemsNotebookPage, ID_KINDLABEL, wxT("Kind"), wxPoint(198,59), wxDefaultSize, 0, wxT("itemKindLabel"));
    availabilityLabel = new wxStaticText(itemsNotebookPage, ID_AVAILABILITYLABEL, wxT("Availability"), wxPoint(198,99), wxDefaultSize, 0, wxT("availabilityLabel"));

    itemTitleField = new wxTextCtrl(itemsNotebookPage, ID_ITEMTITLEFIELD, wxT(""), wxPoint(298,19), wxSize(231,21), 0, wxDefaultValidator, wxT("itemTitleField"));

    wxArrayString arrayStringFor_itemKindChoice;
    arrayStringFor_itemKindChoice.Add(wxT("VHS"));
    arrayStringFor_itemKindChoice.Add(wxT("DVD"));
    itemKindChoice = new wxChoice(itemsNotebookPage, ID_ITEMKINDCHOICE, wxPoint(298,57), wxSize(115,21), arrayStringFor_itemKindChoice, 0, wxDefaultValidator, wxT("itemKindChoice"));
    itemKindChoice->SetSelection(-1);

    availableLabel = new wxStaticText(itemsNotebookPage, ID_AVAILABLELABEL, wxT("Available"), wxPoint(298,99), wxDefaultSize, 0, wxT("availableLabel"));
    availableLabel->SetForegroundColour(wxColour(0,128,0));
    availableLabel->SetFont(wxFont(14, wxSWISS, wxNORMAL,wxBOLD, FALSE));

    itemCancelButton = new wxButton(itemsNotebookPage, ID_ITEMCANCELBUTTON, wxT("Cancel"), wxPoint(478,379), wxSize(75,25), 0, wxDefaultValidator, wxT("itemCancelButton"));
    itemSaveButton = new wxButton(itemsNotebookPage, ID_ITEMSAVEBUTTON, wxT("Save"), wxPoint(388,379), wxSize(75,25), 0, wxDefaultValidator, wxT("itemSaveButton"));
    editItemButton = new wxButton(itemsNotebookPage, ID_EDITITEMBUTTON, wxT("Edit"), wxPoint(298,379), wxSize(75,25), 0, wxDefaultValidator, wxT("editItemButton"));

    // Create New Rental Tab

    newRentalNotebookPage = new wxPanel(notebook, ID_NEWRENTALNOTEBOOKPAGE, wxPoint(4,24), wxSize(566,411));
    notebook->AddPage(newRentalNotebookPage, wxT("Create New Rental"));

    selectCustomerLabel = new wxStaticText(newRentalNotebookPage, ID_SELECTCUSTOMERLABEL, wxT("1) Select a Customer"), wxPoint(8,9), wxDefaultSize, 0, wxT("selectCustomerLabel"));
    selectItemLabel = new wxStaticText(newRentalNotebookPage, ID_SELECTITEMLABEL, wxT("2) Select one or more Items"), wxPoint(198,9), wxDefaultSize, 0, wxT("selectItemLabel"));
    reviewCreateLabel = new wxStaticText(newRentalNotebookPage, ID_REVIEWCREATELABEL, wxT("3) Review and Create"), wxPoint(388,9), wxDefaultSize, 0, wxT("reviewCreateLabel"));

    newRentalCustomerList = new wxListCtrl(newRentalNotebookPage, ID_NEWRENTALCUSTOMERLIST, wxPoint(8,29), wxSize(160,370), wxLC_REPORT);
    newRentalItemList = new wxListCtrl(newRentalNotebookPage, ID_NEWRENTALITEMLIST, wxPoint(198,29), wxSize(160,370), wxLC_REPORT);

    rentalSummary = new wxStaticText(newRentalNotebookPage, ID_RENTALSUMMARY, wxT(""), wxPoint(388,29), wxDefaultSize, 0, wxT("rentalSummary"));

    createRentalButton = new wxButton(newRentalNotebookPage, ID_CREATERENTALBUTTON, wxT("Create Rental"), wxPoint(388,349), wxSize(165,25), 0, wxDefaultValidator, wxT("createRentalButton"));
    cancelNewRentalButton = new wxButton(newRentalNotebookPage, ID_CANCELNEWRENTALBUTTON, wxT("Cancel"), wxPoint(388,379), wxSize(165,25), 0, wxDefaultValidator, wxT("cancelNewRentalButton"));

    SetStatusBar(statusBar);
    SetTitle(wxT("DVD Rental"));
    SetIcon(wxNullIcon);
    SetSize(8,8,600,515);
    Center();

    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);
}

void Main::OnClose(wxCloseEvent& event)
{
    Destroy();
}

/*
 * firstNameFieldEnter
 */
void Main::firstNameFieldEnter(wxCommandEvent& event)
{
    // insert your code here
}

/*
 * lastNameFieldEnter
 */
void Main::lastNameFieldEnter(wxCommandEvent& event)
{
    // insert your code here
}

/*
 * saveCustomerButtonClick
 */
void Main::saveCustomerButtonClick(wxCommandEvent& event)
{
    // insert your code here
}

/*
 * itemSaveButtonClick
 */
void Main::itemSaveButtonClick(wxCommandEvent& event)
{
    // insert your code here
}

/*
 * itemCancelButtonClick
 */
void Main::itemCancelButtonClick(wxCommandEvent& event)
{
    // insert your code here
}

/*
 * itemTitleFieldEnter
 */
void Main::itemTitleFieldEnter(wxCommandEvent& event)
{
    // insert your code here
}

/*
 * itemKindChoiceSelected
 */
void Main::itemKindChoiceSelected(wxCommandEvent& event )
{
    // insert your code here
}

/*
 * phoneNumberFieldEnter
 */
void Main::phoneNumberFieldEnter(wxCommandEvent& event)
{
    // insert your code here
}

/*
 * cancelCustomerEditionClick
 */
void Main::cancelCustomerEditionClick(wxCommandEvent& event)
{
    // insert your code here
}


/*
 * customersListSelected
 */
void Main::customersListSelected(wxListEvent& event)
{
    // insert your code here
}

/*
 * itemsListSelected
 */
void Main::itemsListSelected(wxListEvent& event)
{
    // insert your code here
}

/*
 * rentalsListSelected
 */
void Main::rentalsListSelected(wxListEvent& event)
{
    // insert your code here
}

/*
 * editCustomerButtonClick
 */
void Main::editCustomerButtonClick(wxCommandEvent& event)
{
    // insert your code here
}

/*
 * newRentalCustomerListSelected
 */
void Main::newRentalCustomerListSelected(wxListEvent& event)
{
    // insert your code here
}

/*
 * newRentalItemListSelected
 */
void Main::newRentalItemListSelected(wxListEvent& event)
{
    // insert your code here
}

/*
 * createRentalButtonClick
 */
void Main::createRentalButtonClick(wxCommandEvent& event)
{
    // insert your code here
}

/*
 * cancelNewRentalButtonClick
 */
void Main::cancelNewRentalButtonClick(wxCommandEvent& event)
{
    // insert your code here
}

/*
 * editItemButtonClick
 */
void Main::editItemButtonClick(wxCommandEvent& event)
{
    // insert your code here
}

/*
 * lateRentalsButtonClick
 */
void Main::lateRentalsButtonClick(wxCommandEvent& event)
{
    // insert your code here
}
