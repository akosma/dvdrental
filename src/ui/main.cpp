//---------------------------------------------------------------------------
//
// Name:        main.cpp
// Author:      ako
// Created:     11/14/2006 12:14:42 PM
// Description: Main class implementation
//
//---------------------------------------------------------------------------

#include "main.h"

BEGIN_EVENT_TABLE(Main,wxFrame)
    EVT_CLOSE(Main::OnClose)

    EVT_BUTTON(ID_LATERENTALSBUTTON,           Main::OnLateRentalsButtonClick)
    EVT_BUTTON(ID_EDITITEMBUTTON,              Main::OnEditItemButtonClick)
    EVT_BUTTON(ID_EDITCUSTOMERBUTTON,          Main::OnEditCustomerButtonClick)
    EVT_BUTTON(ID_CANCELNEWRENTALBUTTON,       Main::OnCancelNewRentalButtonClick)
    EVT_BUTTON(ID_CREATERENTALBUTTON,          Main::OnCreateRentalButtonClick)
    EVT_BUTTON(ID_ITEMSAVEBUTTON,              Main::OnItemSaveButtonClick)
    EVT_BUTTON(ID_ITEMCANCELBUTTON,            Main::OnItemCancelButtonClick)
    EVT_BUTTON(ID_CANCELCUSTOMEREDITIONBUTTON, Main::OnCancelCustomerEditionClick)
    EVT_BUTTON(ID_SAVECUSTOMERBUTTON,          Main::OnSaveCustomerButtonClick)

    EVT_TEXT_ENTER(ID_FIRSTNAMEFIELD,   Main::OnFirstNameFieldEnter)
    EVT_TEXT_ENTER(ID_LASTNAMEFIELD,    Main::OnLastNameFieldEnter)
    EVT_TEXT_ENTER(ID_PHONENUMBERFIELD, Main::OnPhoneNumberFieldEnter)
    EVT_TEXT_ENTER(ID_ADDRESSFIELD,     Main::OnAddressFieldEnter)

    EVT_LIST_ITEM_SELECTED(ID_ITEMSLIST,             Main::OnItemsListSelected)
    EVT_LIST_ITEM_SELECTED(ID_RENTALSLIST,           Main::OnRentalsListSelected)
    EVT_LIST_ITEM_SELECTED(ID_NEWRENTALITEMLIST,     Main::OnNewRentalItemListSelected)
    EVT_LIST_ITEM_SELECTED(ID_NEWRENTALCUSTOMERLIST, Main::OnNewRentalCustomerListSelected)
    EVT_LIST_ITEM_SELECTED(ID_CUSTOMERSLIST,         Main::OnCustomersListSelected)
    
    EVT_MENU(wxID_EXIT,             Main::OnMenuFileExitSelected)
    EVT_MENU(wxID_ABOUT,            Main::OnMenuHelpAboutSelected)
    EVT_MENU(ID_MNU_ADDCUSTOMER,    Main::OnMenuAddCustomerSelected)
    EVT_MENU(ID_MNU_DELETECUSTOMER, Main::OnMenuDeleteCustomerSelected)
    EVT_MENU(ID_MNU_DELETEITEM,     Main::OnMenuDeleteItemSelected)
    EVT_MENU(ID_MNU_ADDITEM,        Main::OnMenuAddItemSelected)
END_EVENT_TABLE()

Main::Main(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame    (parent, id, title, position, size, style)
, controller (Controller())
{
    CreateMenuBar();
    CreateGUIControls();
    LoadData();
}

Main::~Main()
{
}

void Main::CreateMenuBar()
{
    menuBar = new wxMenuBar();
    wxMenu *fileMenu = new wxMenu(0);
    fileMenu->Append(wxID_EXIT, wxT("Quit\tCtrl-Q"), wxT(""), wxITEM_NORMAL);
    menuBar->Append(fileMenu, wxT("File"));

    wxMenu *editMenu = new wxMenu(0);
    editMenu->Append(wxID_CUT, wxT("Cut\tCtrl-X"), wxT(""), wxITEM_NORMAL);
    editMenu->Append(wxID_COPY, wxT("Copy\tCtrl-C"), wxT(""), wxITEM_NORMAL);
    editMenu->Append(wxID_PASTE, wxT("Paste\tCtrl-V"), wxT(""), wxITEM_NORMAL);
    menuBar->Append(editMenu, wxT("Edit"));

    wxMenu *customerMenu = new wxMenu(0);
    customerMenu->Append(ID_MNU_ADDCUSTOMER, wxT("Add Customer\tCtrl-A"), wxT(""), wxITEM_NORMAL);
    customerMenu->Append(ID_MNU_DELETECUSTOMER, wxT("Delete Customer\tCtrl-D"), wxT(""), wxITEM_NORMAL);
    menuBar->Append(customerMenu, wxT("Customer"));

    wxMenu *itemMenu = new wxMenu(0);
    itemMenu->Append(ID_MNU_ADDITEM, wxT("Add Item\tCtrl-I"), wxT(""), wxITEM_NORMAL);
    itemMenu->Append(ID_MNU_DELETEITEM, wxT("Delete Item\tCtrl-Shift-I"), wxT(""), wxITEM_NORMAL);
    menuBar->Append(itemMenu, wxT("Item"));

    wxMenu *rentalMenu = new wxMenu(0);
    rentalMenu->Append(ID_MNU_CREATERENTAL, wxT("Create Rental"), wxT(""), wxITEM_NORMAL);
    rentalMenu->Append(ID_MNU_SEELATERENTALS, wxT("See Late Rentals"), wxT(""), wxITEM_NORMAL);
    menuBar->Append(rentalMenu, wxT("Rental"));

    wxMenu *helpMenu = new wxMenu(0);
    helpMenu->Append(wxID_ABOUT, wxT("About...\tF1"), wxT(""), wxITEM_NORMAL);
    menuBar->Append(helpMenu, wxT("Help"));
    SetMenuBar(menuBar);
}

void Main::CreateGUIControls()
{
    CreateGlobalControls();

    // Create the four tab pages of the notebook
    CreateNewRentalTab();
    CreateRentalsTab();
    CreateCustomersTab();
    CreateItemsTab();

    // Latest touches of style
    SetTitle(wxT("DVDRental"));
    SetIcon(wxNullIcon);
#ifdef WIN32
    // The DVD icon is taken from
    // http://www.pef.org/stopworkplaceviolence/images/dvd-icon.jpg
    SetIcon(wxIcon("IDI_ICON_APP"));
#endif
    SetSize(8,8,600,515);
    Center();

    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);
}

void Main::CreateGlobalControls()
{
    mainSizer = new wxBoxSizer(wxHORIZONTAL);
    this->SetSizer(mainSizer);
    this->SetAutoLayout(true);

    // This "mainPanel" is used to provide a common background to the window
    // similar to the background of a dialog box
    mainPanel = new wxPanel(this, ID_MAINPANEL, wxPoint(0,0), wxSize(592,454));
    mainSizer->Add(mainPanel, 1, wxEXPAND | wxALL, 0);

    notebookSizer = new wxBoxSizer(wxHORIZONTAL);
    mainPanel->SetSizer(notebookSizer);
    mainPanel->SetAutoLayout(true);

    notebook = new wxNotebook(mainPanel, ID_NOTEBOOK, wxPoint(8,7),wxSize(574,439));
    notebookSizer->Add(notebook, 1, wxEXPAND | wxALL, 5);
}

void Main::CreateCustomersTab()
{
    customersPageSizer = new wxBoxSizer(wxHORIZONTAL);
    customersNotebookPage = new wxPanel(notebook, ID_CUSTOMERSNOTEBOOKPAGE, wxPoint(4,24), wxSize(566,411));
    notebook->AddPage(customersNotebookPage, wxT("Customers"));
    customersNotebookPage->SetSizer(customersPageSizer);
    customersNotebookPage->SetAutoLayout(true);

    customersList = new wxListCtrl(customersNotebookPage, ID_CUSTOMERSLIST, wxPoint(5,8), wxSize(168,395), wxLC_REPORT + wxLC_SINGLE_SEL);
    customersList->InsertColumn(0, wxT("#"), wxLIST_FORMAT_LEFT, 30);
    customersList->InsertColumn(1, wxT("Name"), wxLIST_FORMAT_LEFT, 130);
    customersList->InsertColumn(2, wxT("Phone"), wxLIST_FORMAT_LEFT, 130);

    customersPageSizer->Add(customersList, 1, wxEXPAND | wxALL, 5);
    innerCustomersPageSizer = new wxBoxSizer(wxVERTICAL);
    customersPageSizer->Add(innerCustomersPageSizer, 1, wxEXPAND | wxALL, 5);

    customerFieldsSizer = new wxGridBagSizer(10, 10);
    innerCustomersPageSizer->Add(customerFieldsSizer, 1, wxEXPAND | wxALL, 5);

    firstNameLabel = new wxStaticText(customersNotebookPage, ID_FIRSTNAMELABEL, wxT("First Name"), wxPoint(198,21), wxDefaultSize, 0, wxT("firstNameLabel"));
    customerFieldsSizer->Add(firstNameLabel, wxGBPosition(0, 0));
    firstNameField = new wxTextCtrl(customersNotebookPage, ID_FIRSTNAMEFIELD, wxT(""), wxPoint(298,19), wxDefaultSize, wxTE_PROCESS_ENTER);
    customerFieldsSizer->Add(firstNameField, wxGBPosition(0, 1), wxDefaultSpan, wxGROW);

    lastNameLabel = new wxStaticText(customersNotebookPage, ID_LASTNAMELABEL, wxT("Last Name"), wxPoint(198,59), wxDefaultSize, 0, wxT("lastNameLabel"));
    customerFieldsSizer->Add(lastNameLabel, wxGBPosition(1, 0));
    lastNameField = new wxTextCtrl(customersNotebookPage, ID_LASTNAMEFIELD, wxT(""), wxPoint(298,57), wxDefaultSize, wxTE_PROCESS_ENTER);
    customerFieldsSizer->Add(lastNameField, wxGBPosition(1, 1), wxDefaultSpan, wxGROW);

    addressLabel = new wxStaticText(customersNotebookPage, ID_ADDRESSLABEL, wxT("Address"), wxPoint(198,99), wxDefaultSize, 0, wxT("addressLabel"));
    customerFieldsSizer->Add(addressLabel, wxGBPosition(2, 0));
    addressField = new wxTextCtrl(customersNotebookPage, ID_ADDRESSFIELD, wxT(""), wxPoint(298,97), wxDefaultSize, wxTE_PROCESS_ENTER);
    customerFieldsSizer->Add(addressField, wxGBPosition(2, 1), wxDefaultSpan, wxGROW);

    phoneNumberLabel = new wxStaticText(customersNotebookPage, ID_PHONENUMBERLABEL, wxT("Phone Number"), wxPoint(198,99), wxDefaultSize, 0, wxT("phoneNumberLabel"));
    customerFieldsSizer->Add(phoneNumberLabel, wxGBPosition(3, 0));
    phoneNumberField = new wxTextCtrl(customersNotebookPage, ID_PHONENUMBERFIELD, wxT(""), wxPoint(298,97), wxDefaultSize, wxTE_PROCESS_ENTER);
    customerFieldsSizer->Add(phoneNumberField, wxGBPosition(3, 1), wxDefaultSpan, wxGROW);

    customerFieldsSizer->AddGrowableCol(1);

    buttonsCustomerSizer = new wxBoxSizer(wxHORIZONTAL);
    innerCustomersPageSizer->Add(buttonsCustomerSizer, 0, wxALIGN_RIGHT | wxALL, 5);
    
    editCustomerButton = new wxButton(customersNotebookPage, ID_EDITCUSTOMERBUTTON, wxT("Edit"), wxPoint(298,379), wxSize(75,25), 0, wxDefaultValidator, wxT("editCustomerButton"));
    editCustomerButton->Disable();
    buttonsCustomerSizer->Add(editCustomerButton, 0, wxALIGN_RIGHT | wxALL, 5);
    saveCustomerButton = new wxButton(customersNotebookPage, ID_SAVECUSTOMERBUTTON, wxT("Save"), wxPoint(388,379), wxSize(75,25), 0, wxDefaultValidator, wxT("saveCustomerButton"));
    saveCustomerButton->Disable();
    buttonsCustomerSizer->Add(saveCustomerButton, 0, wxALIGN_RIGHT | wxALL, 5);
    cancelCustomerEditionButton = new wxButton(customersNotebookPage, ID_CANCELCUSTOMEREDITIONBUTTON, wxT("Cancel"), wxPoint(478,379), wxSize(75,25), 0, wxDefaultValidator, wxT("cancelCustomerEditionButton"));
    cancelCustomerEditionButton->Disable();
    buttonsCustomerSizer->Add(cancelCustomerEditionButton, 0, wxALIGN_RIGHT | wxALL, 5);
}

void Main::CreateRentalsTab()
{
    rentalsPageSizer = new wxBoxSizer(wxHORIZONTAL);
    rentalsNotebookPage = new wxPanel(notebook, ID_RENTALSNOTEBOOKPAGE, wxPoint(4,24), wxSize(566,411));
    notebook->AddPage(rentalsNotebookPage, wxT("Rentals"));
    rentalsNotebookPage->SetSizer(rentalsPageSizer);
    rentalsNotebookPage->SetAutoLayout(true);

    rentalsList = new wxListCtrl(rentalsNotebookPage, ID_RENTALSLIST, wxPoint(5,8), wxSize(168,395), wxLC_REPORT);
    rentalsPageSizer->Add(rentalsList, 1, wxEXPAND | wxALL, 5);
    innerRentalsPageSizer = new wxBoxSizer(wxVERTICAL);
    rentalsPageSizer->Add(innerRentalsPageSizer, 1, wxEXPAND | wxALL, 5);

    rentalReview = new wxStaticText(rentalsNotebookPage, ID_RENTALREVIEW, wxT(""), wxPoint(188,9), wxDefaultSize, 0, wxT("rentalReview"));
    innerRentalsPageSizer->Add(rentalReview, 1, wxEXPAND | wxALL, 5);

    buttonsNewRentalPageSizer = new wxBoxSizer(wxHORIZONTAL);
    innerRentalsPageSizer->Add(buttonsNewRentalPageSizer, 0, wxALIGN_RIGHT | wxALL, 5);

    returnRentalButton = new wxButton(rentalsNotebookPage, ID_RETURNRENTALBUTTON, wxT("Returned"), wxPoint(478,379), wxSize(75,25), 0, wxDefaultValidator, wxT("returnRentalButton"));
    buttonsNewRentalPageSizer->Add(returnRentalButton, 0, wxALIGN_RIGHT | wxALL, 5);

    lateRentalsButton = new wxButton(rentalsNotebookPage, ID_LATERENTALSBUTTON, wxT("See Late Rentals"), wxPoint(298,379), wxSize(165,25), 0, wxDefaultValidator, wxT("lateRentalsButton"));
    buttonsNewRentalPageSizer->Add(lateRentalsButton, 0, wxALIGN_RIGHT | wxALL, 5);
}

void Main::CreateItemsTab()
{
    itemsPageSizer = new wxBoxSizer(wxHORIZONTAL);
    itemsNotebookPage = new wxPanel(notebook, ID_ITEMSNOTEBOOKPAGE, wxPoint(4,24), wxSize(566,411));
    notebook->AddPage(itemsNotebookPage, wxT("Items"));
    itemsNotebookPage->SetSizer(itemsPageSizer);
    itemsNotebookPage->SetAutoLayout(true);

    itemsList = new wxListCtrl(itemsNotebookPage, ID_ITEMSLIST, wxPoint(5,8), wxSize(168,395), wxLC_REPORT);
    itemsList->InsertColumn(0, wxT("#"), wxLIST_FORMAT_LEFT, 30);
    itemsList->InsertColumn(1, wxT("Title"), wxLIST_FORMAT_LEFT, 210);
    itemsPageSizer->Add(itemsList, 1, wxEXPAND | wxALL, 5);
    innerItemsPageSizer = new wxBoxSizer(wxVERTICAL);
    itemsPageSizer->Add(innerItemsPageSizer, 1, wxEXPAND | wxALL, 5);

    itemFieldsSizer = new wxGridBagSizer(10, 10);
    innerItemsPageSizer->Add(itemFieldsSizer, 1, wxEXPAND | wxALL, 5);

    itemTitleLabel = new wxStaticText(itemsNotebookPage, ID_ITEMTITLELABEL, wxT("Title"), wxPoint(198,21), wxDefaultSize, wxTE_PROCESS_ENTER);
    itemFieldsSizer->Add(itemTitleLabel, wxGBPosition(0, 0));
    itemTitleField = new wxTextCtrl(itemsNotebookPage, ID_ITEMTITLEFIELD, wxT(""), wxPoint(298,19), wxSize(231,21), 0, wxDefaultValidator, wxT("itemTitleField"));
    itemFieldsSizer->Add(itemTitleField, wxGBPosition(0, 1), wxDefaultSpan, wxGROW);

    itemKindLabel = new wxStaticText(itemsNotebookPage, ID_KINDLABEL, wxT("Kind"), wxPoint(198,59), wxDefaultSize, 0, wxT("itemKindLabel"));
    itemFieldsSizer->Add(itemKindLabel, wxGBPosition(1, 0));

    wxArrayString arrayStringFor_itemKindChoice;
    arrayStringFor_itemKindChoice.Add(wxT("VHS"));
    arrayStringFor_itemKindChoice.Add(wxT("DVD"));
    itemKindChoice = new wxChoice(itemsNotebookPage, ID_ITEMKINDCHOICE, wxPoint(298,57), wxSize(115,21), arrayStringFor_itemKindChoice, 0, wxDefaultValidator, wxT("itemKindChoice"));
    itemKindChoice->SetSelection(-1);
    itemFieldsSizer->Add(itemKindChoice, wxGBPosition(1, 1), wxDefaultSpan, wxGROW);

    availabilityLabel = new wxStaticText(itemsNotebookPage, ID_AVAILABILITYLABEL, wxT("Availability"), wxPoint(198,99), wxDefaultSize, 0, wxT("availabilityLabel"));
    itemFieldsSizer->Add(availabilityLabel, wxGBPosition(2, 0));

    availableLabel = new wxStaticText(itemsNotebookPage, ID_AVAILABLELABEL, wxT("Available"), wxPoint(298,99), wxDefaultSize, 0, wxT("availableLabel"));
    availableLabel->SetForegroundColour(wxColour(0,128,0));
    availableLabel->SetFont(wxFont(14, wxSWISS, wxNORMAL,wxBOLD, FALSE));
    itemFieldsSizer->Add(availableLabel, wxGBPosition(2, 1), wxDefaultSpan, wxGROW);

    itemFieldsSizer->AddGrowableCol(1);

    buttonsItemSizer = new wxBoxSizer(wxHORIZONTAL);
    innerItemsPageSizer->Add(buttonsItemSizer, 0, wxALIGN_RIGHT | wxALL, 5);

    editItemButton = new wxButton(itemsNotebookPage, ID_EDITITEMBUTTON, wxT("Edit"), wxPoint(298,379), wxSize(75,25), 0, wxDefaultValidator, wxT("editItemButton"));
    buttonsItemSizer->Add(editItemButton, 0, wxALIGN_RIGHT | wxALL, 5);
    itemSaveButton = new wxButton(itemsNotebookPage, ID_ITEMSAVEBUTTON, wxT("Save"), wxPoint(388,379), wxSize(75,25), 0, wxDefaultValidator, wxT("itemSaveButton"));
    buttonsItemSizer->Add(itemSaveButton, 0, wxALIGN_RIGHT | wxALL, 5);
    itemCancelButton = new wxButton(itemsNotebookPage, ID_ITEMCANCELBUTTON, wxT("Cancel"), wxPoint(478,379), wxSize(75,25), 0, wxDefaultValidator, wxT("itemCancelButton"));
    buttonsItemSizer->Add(itemCancelButton, 0, wxALIGN_RIGHT | wxALL, 5);
}

void Main::CreateNewRentalTab()
{
    newRentalPageSizer = new wxBoxSizer(wxHORIZONTAL);
    newRentalNotebookPage = new wxPanel(notebook, ID_NEWRENTALNOTEBOOKPAGE, wxPoint(4,24), wxSize(566,411));
    notebook->AddPage(newRentalNotebookPage, wxT("Create New Rental"));
    newRentalNotebookPage->SetSizer(newRentalPageSizer);
    newRentalNotebookPage->SetAutoLayout(true);

    newRentalFieldsSizer = new wxGridBagSizer(10, 10);
    newRentalPageSizer->Add(newRentalFieldsSizer, 1, wxEXPAND | wxALL, 5);

    selectCustomerLabel = new wxStaticText(newRentalNotebookPage, ID_SELECTCUSTOMERLABEL, wxT("1) Select a Customer"), wxPoint(8,9), wxDefaultSize, 0, wxT("selectCustomerLabel"));
    newRentalFieldsSizer->Add(selectCustomerLabel, wxGBPosition(0, 0), wxDefaultSpan, wxGROW);
    selectItemLabel = new wxStaticText(newRentalNotebookPage, ID_SELECTITEMLABEL, wxT("2) Select one or more Items"), wxPoint(198,9), wxDefaultSize, 0, wxT("selectItemLabel"));
    newRentalFieldsSizer->Add(selectItemLabel, wxGBPosition(0, 1), wxDefaultSpan, wxGROW);
    reviewCreateLabel = new wxStaticText(newRentalNotebookPage, ID_REVIEWCREATELABEL, wxT("3) Review and Create"), wxPoint(388,9), wxDefaultSize, 0, wxT("reviewCreateLabel"));
    newRentalFieldsSizer->Add(reviewCreateLabel, wxGBPosition(0, 2), wxDefaultSpan, wxGROW);

    newRentalCustomerList = new wxListCtrl(newRentalNotebookPage, ID_NEWRENTALCUSTOMERLIST, wxPoint(8,29), wxSize(160,370), wxLC_REPORT + wxLC_SINGLE_SEL);
    newRentalCustomerList->InsertColumn(0, wxT("#"), wxLIST_FORMAT_LEFT, 30);
    newRentalCustomerList->InsertColumn(1, wxT("Name"), wxLIST_FORMAT_LEFT, 150);
    newRentalFieldsSizer->Add(newRentalCustomerList, wxGBPosition(1, 0), wxDefaultSpan, wxGROW);
    newRentalItemList = new wxListCtrl(newRentalNotebookPage, ID_NEWRENTALITEMLIST, wxPoint(198,29), wxSize(160,370), wxLC_REPORT);
    newRentalItemList->InsertColumn(0, wxT("#"), wxLIST_FORMAT_LEFT, 30);
    newRentalItemList->InsertColumn(1, wxT("Title"), wxLIST_FORMAT_LEFT, 150);
    newRentalFieldsSizer->Add(newRentalItemList, wxGBPosition(1, 1), wxDefaultSpan, wxGROW);

    rentalSummary = new wxStaticText(newRentalNotebookPage, ID_RENTALSUMMARY, wxT(""), wxPoint(388,29), wxDefaultSize, 0, wxT("rentalSummary"));
    newRentalInnerSizer = new wxBoxSizer(wxVERTICAL);
    newRentalInnerSizer->Add(rentalSummary, 1, wxEXPAND | wxALL, 5);
    newRentalFieldsSizer->Add(newRentalInnerSizer, wxGBPosition(1, 2), wxDefaultSpan, wxGROW);
    
    newRentalButtonSizer = new wxBoxSizer(wxHORIZONTAL);
    newRentalInnerSizer->Add(newRentalButtonSizer, 0, wxALIGN_RIGHT | wxALL, 5);

    createRentalButton = new wxButton(newRentalNotebookPage, ID_CREATERENTALBUTTON, wxT("Create"), wxPoint(388,349), wxSize(75,25), 0, wxDefaultValidator, wxT("createRentalButton"));
    newRentalButtonSizer->Add(createRentalButton, 0, wxALIGN_RIGHT | wxALL, 5);
    cancelNewRentalButton = new wxButton(newRentalNotebookPage, ID_CANCELNEWRENTALBUTTON, wxT("Cancel"), wxPoint(388,379), wxSize(75,25), 0, wxDefaultValidator, wxT("cancelNewRentalButton"));
    newRentalButtonSizer->Add(cancelNewRentalButton, 0, wxALIGN_RIGHT | wxALL, 5);

    newRentalFieldsSizer->AddGrowableRow(1);
    newRentalFieldsSizer->AddGrowableCol(0);
    newRentalFieldsSizer->AddGrowableCol(1);
    newRentalFieldsSizer->AddGrowableCol(2);
}

void Main::LoadData()
{
    controller.fillCustomersList(customersList);
    controller.fillCustomersList(newRentalCustomerList);
    controller.fillItemsList(itemsList);
    controller.fillItemsList(newRentalItemList);
}

void Main::OnMenuFileExitSelected(wxCommandEvent& WXUNUSED(event))
{
    int answer = wxMessageBox("Are you sure?", "Exit DVDRental", wxYES_NO);
    if (answer == wxYES)
    {
        Close(true);
    }
}

void Main::OnMenuHelpAboutSelected(wxCommandEvent& WXUNUSED(event))
{
    wxString msg;
    msg.Printf( _T("DVDRental Application, 2006\n\n")
                _T("Ahmed Madkour\nKeith Miller\nAdrian Kosmaczewski"));

    wxMessageBox(msg, _T("About DVDRental"), wxOK | wxICON_INFORMATION, this);
}


void Main::OnClose(wxCloseEvent& event)
{
    Destroy();
}

void Main::OnFirstNameFieldEnter(wxCommandEvent& event)
{
    lastNameField->SetFocus();
}

void Main::OnLastNameFieldEnter(wxCommandEvent& event)
{
    addressField->SetFocus();
}

void Main::OnAddressFieldEnter(wxCommandEvent& event)
{
    phoneNumberField->SetFocus();    
}

void Main::OnPhoneNumberFieldEnter(wxCommandEvent& event)
{
    OnSaveCustomerButtonClick(event);
}

void Main::OnSaveCustomerButtonClick(wxCommandEvent& event)
{
    wxString first = firstNameField->GetValue();
    wxString last = lastNameField->GetValue();
    wxString address = addressField->GetValue();
    wxString phone = phoneNumberField->GetValue();
    if (first.Length() == 0 || first.Length() == 0)
    {
        wxMessageBox(_T("You must provide the first and the last name."), _T("Error"), wxOK | wxICON_ERROR, this);
        firstNameField->SetFocus();
    }
    else
    {
        controller.saveCustomer(first, last, address, phone);
        LoadData();
        saveCustomerButton->Disable();
        editCustomerButton->Enable();
        cancelCustomerEditionButton->Disable();
        firstNameField->SetEditable(false);
        lastNameField->SetEditable(false);
        addressField->SetEditable(false);
        phoneNumberField->SetEditable(false);
    }
}

void Main::OnCancelCustomerEditionClick(wxCommandEvent& event)
{
    saveCustomerButton->Disable();
    editCustomerButton->Enable();
    cancelCustomerEditionButton->Disable();
    firstNameField->SetEditable(false);
    lastNameField->SetEditable(false);
    addressField->SetEditable(false);
    phoneNumberField->SetEditable(false);
    firstNameField->SetValue(controller.getCurrentCustomerFirstName());
    lastNameField->SetValue(controller.getCurrentCustomerLastName());
    addressField->SetValue(controller.getCurrentCustomerAddress());
    phoneNumberField->SetValue(controller.getCurrentCustomerPhoneNumber());
}

void Main::OnCustomersListSelected(wxListEvent& event)
{
    int customerId = (int)event.GetData();
    controller.loadCustomer(customerId);
    firstNameField->SetEditable(false);
    lastNameField->SetEditable(false);
    addressField->SetEditable(false);
    phoneNumberField->SetEditable(false);
    saveCustomerButton->Disable();
    editCustomerButton->Enable();
    cancelCustomerEditionButton->Disable();
    firstNameField->SetValue(controller.getCurrentCustomerFirstName());
    lastNameField->SetValue(controller.getCurrentCustomerLastName());
    addressField->SetValue(controller.getCurrentCustomerAddress());
    phoneNumberField->SetValue(controller.getCurrentCustomerPhoneNumber());
}

void Main::OnEditCustomerButtonClick(wxCommandEvent& event)
{
    saveCustomerButton->Enable();
    editCustomerButton->Disable();
    cancelCustomerEditionButton->Enable();
    firstNameField->SetEditable(true);
    firstNameField->SetFocus();
    lastNameField->SetEditable(true);
    addressField->SetEditable(true);
    phoneNumberField->SetEditable(true);
}

void Main::OnMenuAddCustomerSelected(wxCommandEvent& event)
{
    notebook->SetSelection(2);
    controller.prepareForNewCustomer();
    saveCustomerButton->Enable();
    editCustomerButton->Disable();
    cancelCustomerEditionButton->Enable();
    firstNameField->SetEditable(true);
    firstNameField->SetFocus();
    lastNameField->SetEditable(true);
    addressField->SetEditable(true);
    phoneNumberField->SetEditable(true);
    firstNameField->SetValue("");
    lastNameField->SetValue("");
    addressField->SetValue("");
    phoneNumberField->SetValue("");
}

void Main::OnMenuDeleteCustomerSelected(wxCommandEvent& event)
{
    notebook->SetSelection(2);
    int answer = wxMessageBox("Are you sure?", "Delete current customer", wxYES_NO);
    if (answer == wxYES)
    {
        controller.deleteCurrentCustomer();
        LoadData();
        firstNameField->SetValue("");
        lastNameField->SetValue("");
        addressField->SetValue("");
        phoneNumberField->SetValue("");
    }
}

////////////////////////////////////
//! Item Management methods
////////////////////////////////////

void Main::OnItemsListSelected(wxListEvent& event)
{
    int itemId = (int)event.GetData();
    controller.loadItem(itemId);
    itemTitleField->SetEditable(false);
    itemSaveButton->Disable();
    editItemButton->Enable();
    itemCancelButton->Disable();
    itemTitleField->SetValue(controller.getCurrentItemTitle());
    itemKindChoice->SetSelection(controller.getCurrentItemKind());
}

void Main::OnItemSaveButtonClick(wxCommandEvent& event)
{
    wxString title = itemTitleField->GetValue();
    int kind = itemKindChoice->GetSelection();
    if (title.Length() == 0 || kind == -1)
    {
        wxMessageBox(_T("You must provide both title and kind."), _T("Error"), wxOK | wxICON_ERROR, this);
        itemTitleField->SetFocus();
    }
    else
    {
        controller.saveItem(title, kind);
        LoadData();
        itemTitleField->SetEditable(false);
        itemSaveButton->Disable();
        editItemButton->Enable();
        itemCancelButton->Disable();
        itemTitleField->SetValue(controller.getCurrentItemTitle());
        itemKindChoice->SetSelection(controller.getCurrentItemKind());
    }
}

void Main::OnItemCancelButtonClick(wxCommandEvent& event)
{
    itemTitleField->SetEditable(false);
    itemSaveButton->Disable();
    editItemButton->Enable();
    itemCancelButton->Disable();
    itemTitleField->SetValue(controller.getCurrentItemTitle());
    itemKindChoice->SetSelection(controller.getCurrentItemKind());
}

void Main::OnEditItemButtonClick(wxCommandEvent& event)
{
    itemTitleField->SetEditable(true);
    itemTitleField->SetFocus();
    itemSaveButton->Enable();
    editItemButton->Disable();
    itemCancelButton->Enable();
}

void Main::OnMenuDeleteItemSelected(wxCommandEvent& event)
{
    notebook->SetSelection(3);
    int answer = wxMessageBox("Are you sure?", "Delete current item", wxYES_NO);
    if (answer == wxYES)
    {
        controller.deleteCurrentItem();
        LoadData();
        itemTitleField->SetValue("");
        itemKindChoice->SetSelection(-1);
    }
}

void Main::OnMenuAddItemSelected(wxCommandEvent& event)
{
    notebook->SetSelection(3);
    controller.prepareForNewItem();
    itemTitleField->SetEditable(true);
    itemTitleField->SetFocus();
    itemSaveButton->Enable();
    editItemButton->Disable();
    itemCancelButton->Enable();
    itemTitleField->SetValue("");
    itemKindChoice->SetSelection(-1);
}

/*
 * rentalsListSelected
 */
void Main::OnRentalsListSelected(wxListEvent& event)
{
    // insert your code here
}

/*
 * newRentalCustomerListSelected
 */
void Main::OnNewRentalCustomerListSelected(wxListEvent& event)
{
    // insert your code here
}

/*
 * newRentalItemListSelected
 */
void Main::OnNewRentalItemListSelected(wxListEvent& event)
{
    // insert your code here
}

/*
 * createRentalButtonClick
 */
void Main::OnCreateRentalButtonClick(wxCommandEvent& event)
{
    // insert your code here
}

/*
 * cancelNewRentalButtonClick
 */
void Main::OnCancelNewRentalButtonClick(wxCommandEvent& event)
{
    // insert your code here
}

/*
 * lateRentalsButtonClick
 */
void Main::OnLateRentalsButtonClick(wxCommandEvent& event)
{
    // insert your code here
}
