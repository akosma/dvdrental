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
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(Main,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(Main::OnClose)
	EVT_BUTTON(ID_LATERENTALSBUTTON,Main::lateRentalsButtonClick)
	EVT_BUTTON(ID_EDITITEMBUTTON,Main::editItemButtonClick)
	EVT_BUTTON(ID_EDITCUSTOMERBUTTON,Main::editCustomerButtonClick)
	EVT_BUTTON(ID_CANCELNEWRENTAL,Main::cancelNewRentalClick)
	
	EVT_LIST_ITEM_SELECTED(ID_RENTALSLIST,Main::rentalsListSelected)
	EVT_BUTTON(ID_CREATERENTALBUTTON,Main::createRentalButtonClick)
	
	EVT_LIST_ITEM_SELECTED(ID_NEWRENTALITEMLIST,Main::newRentalItemListSelected)
	
	EVT_LIST_ITEM_SELECTED(ID_NEWRENTALCUSTOMERLIST,Main::newRentalCustomerListSelected)
	EVT_BUTTON(ID_ITEMSAVEBUTTON,Main::itemSaveButtonClick)
	EVT_BUTTON(ID_ITEMCANCELBUTTON,Main::itemCancelButtonClick)
	EVT_CHOICE(ID_ITEMKINDCHOICE,Main::itemKindChoiceSelected)
	EVT_TEXT_ENTER(ID_ITEMTITLEFIELD,Main::itemTitleFieldEnter)
	
	EVT_LIST_ITEM_SELECTED(ID_ITEMSLIST,Main::itemsListSelected)
	EVT_TEXT_ENTER(ID_PHONENUMBERFIELD,Main::phoneNumberFieldEnter)
	EVT_BUTTON(ID_CANCELCUSTOMEREDITION,Main::cancelCustomerEditionClick)
	EVT_BUTTON(ID_SAVECUSTOMERBUTTON,Main::saveCustomerButtonClick)
	EVT_TEXT_ENTER(ID_LASTNAMEFIELD,Main::lastNameFieldEnter)
	EVT_TEXT_ENTER(ID_FIRSTNAMEFIELD,Main::firstNameFieldEnter)
	
	EVT_LIST_ITEM_SELECTED(ID_CUSTOMERSLIST,Main::customersListSelected)
END_EVENT_TABLE()
////Event Table End

Main::Main(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

Main::~Main()
{
}

void Main::CreateGUIControls()
{
	//Do not add custom code here
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	statusBar = new wxStatusBar(this, ID_STATUSBAR);

	mainPanel = new wxPanel(this, ID_MAINPANEL, wxPoint(0,0), wxSize(592,454));

	notebook = new wxNotebook(mainPanel, ID_NOTEBOOK, wxPoint(8,7),wxSize(574,439));

	rentalsNotebookPage = new wxPanel(notebook, ID_RENTALSNOTEBOOKPAGE, wxPoint(4,24), wxSize(566,411));
	notebook->AddPage(rentalsNotebookPage, wxT("Rentals"));

	newRentalNotebookPage = new wxPanel(notebook, ID_NEWRENTALNOTEBOOKPAGE, wxPoint(4,24), wxSize(566,411));
	notebook->AddPage(newRentalNotebookPage, wxT("Create New Rental"));

	customersNotebookPage = new wxPanel(notebook, ID_CUSTOMERSNOTEBOOKPAGE, wxPoint(4,24), wxSize(566,411));
	notebook->AddPage(customersNotebookPage, wxT("Customers"));

	customersList = new wxListCtrl(customersNotebookPage, ID_CUSTOMERSLIST, wxPoint(5,8), wxSize(168,395), wxLC_REPORT);

	firstNameLabel = new wxStaticText(customersNotebookPage, ID_FIRSTNAMELABEL, wxT("First Name"), wxPoint(198,21), wxDefaultSize, 0, wxT("firstNameLabel"));

	lastNameLabel = new wxStaticText(customersNotebookPage, ID_LASTNAMELABEL, wxT("Last Name"), wxPoint(198,59), wxDefaultSize, 0, wxT("lastNameLabel"));

	firstNameField = new wxTextCtrl(customersNotebookPage, ID_FIRSTNAMEFIELD, wxT(""), wxPoint(298,19), wxSize(231,21), 0, wxDefaultValidator, wxT("firstNameField"));

	lastNameField = new wxTextCtrl(customersNotebookPage, ID_LASTNAMEFIELD, wxT(""), wxPoint(298,57), wxSize(231,21), 0, wxDefaultValidator, wxT("lastNameField"));

	saveCustomerButton = new wxButton(customersNotebookPage, ID_SAVECUSTOMERBUTTON, wxT("Save"), wxPoint(388,379), wxSize(75,25), 0, wxDefaultValidator, wxT("saveCustomerButton"));

	cancelCustomerEdition = new wxButton(customersNotebookPage, ID_CANCELCUSTOMEREDITION, wxT("Cancel"), wxPoint(478,379), wxSize(75,25), 0, wxDefaultValidator, wxT("cancelCustomerEdition"));

	phoneNumberLabel = new wxStaticText(customersNotebookPage, ID_PHONENUMBERLABEL, wxT("Phone Number"), wxPoint(198,99), wxDefaultSize, 0, wxT("phoneNumberLabel"));

	phoneNumberField = new wxTextCtrl(customersNotebookPage, ID_PHONENUMBERFIELD, wxT(""), wxPoint(298,97), wxSize(231,21), 0, wxDefaultValidator, wxT("phoneNumberField"));

	itemsNotebookPage = new wxPanel(notebook, ID_ITEMSNOTEBOOKPAGE, wxPoint(4,24), wxSize(566,411));
	notebook->AddPage(itemsNotebookPage, wxT("Items"));

	itemsList = new wxListCtrl(itemsNotebookPage, ID_ITEMSLIST, wxPoint(5,8), wxSize(168,395), wxLC_REPORT);

	itemTitleLabel = new wxStaticText(itemsNotebookPage, ID_ITEMTITLELABEL, wxT("Title"), wxPoint(198,21), wxDefaultSize, 0, wxT("itemTitleLabel"));

	itemTitleField = new wxTextCtrl(itemsNotebookPage, ID_ITEMTITLEFIELD, wxT(""), wxPoint(298,19), wxSize(231,21), 0, wxDefaultValidator, wxT("itemTitleField"));

	itemKindLabel = new wxStaticText(itemsNotebookPage, ID_KINDLABEL, wxT("Kind"), wxPoint(198,59), wxDefaultSize, 0, wxT("itemKindLabel"));

	wxArrayString arrayStringFor_itemKindChoice;
	arrayStringFor_itemKindChoice.Add(wxT("(none)"));
	arrayStringFor_itemKindChoice.Add(wxT("VHS"));
	arrayStringFor_itemKindChoice.Add(wxT("DVD"));
	itemKindChoice = new wxChoice(itemsNotebookPage, ID_ITEMKINDCHOICE, wxPoint(298,57), wxSize(115,21), arrayStringFor_itemKindChoice, 0, wxDefaultValidator, wxT("itemKindChoice"));
	itemKindChoice->SetSelection(-1);

	itemCancelButton = new wxButton(itemsNotebookPage, ID_ITEMCANCELBUTTON, wxT("Cancel"), wxPoint(478,379), wxSize(75,25), 0, wxDefaultValidator, wxT("itemCancelButton"));

	itemSaveButton = new wxButton(itemsNotebookPage, ID_ITEMSAVEBUTTON, wxT("Save"), wxPoint(388,379), wxSize(75,25), 0, wxDefaultValidator, wxT("itemSaveButton"));

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

	selectCustomerLabel = new wxStaticText(newRentalNotebookPage, ID_SELECTCUSTOMERLABEL, wxT("1) Select a Customer"), wxPoint(8,9), wxDefaultSize, 0, wxT("selectCustomerLabel"));

	newRentalCustomerList = new wxListCtrl(newRentalNotebookPage, ID_NEWRENTALCUSTOMERLIST, wxPoint(8,29), wxSize(160,370), wxLC_REPORT);

	selectItemLabel = new wxStaticText(newRentalNotebookPage, ID_SELECTITEMLABEL, wxT("2) Select one or more Items"), wxPoint(198,9), wxDefaultSize, 0, wxT("selectItemLabel"));

	newRentalItemList = new wxListCtrl(newRentalNotebookPage, ID_NEWRENTALITEMLIST, wxPoint(198,29), wxSize(160,370), wxLC_REPORT);

	createRentalButton = new wxButton(newRentalNotebookPage, ID_CREATERENTALBUTTON, wxT("Create Rental"), wxPoint(388,349), wxSize(165,25), 0, wxDefaultValidator, wxT("createRentalButton"));

	reviewCreateLabel = new wxStaticText(newRentalNotebookPage, ID_REVIEWCREATELABEL, wxT("3) Review and Create"), wxPoint(388,9), wxDefaultSize, 0, wxT("reviewCreateLabel"));

	rentalSummary = new wxStaticText(newRentalNotebookPage, ID_RENTALSUMMARY, wxT(""), wxPoint(388,29), wxDefaultSize, 0, wxT("rentalSummary"));

	rentalsList = new wxListCtrl(rentalsNotebookPage, ID_RENTALSLIST, wxPoint(5,8), wxSize(168,395), wxLC_REPORT);

	rentalReview = new wxStaticText(rentalsNotebookPage, ID_RENTALREVIEW, wxT(""), wxPoint(188,9), wxDefaultSize, 0, wxT("rentalReview"));

	returnRentalButton = new wxButton(rentalsNotebookPage, ID_RETURNRENTALBUTTON, wxT("Returned"), wxPoint(478,379), wxSize(75,25), 0, wxDefaultValidator, wxT("returnRentalButton"));

	cancelNewRental = new wxButton(newRentalNotebookPage, ID_CANCELNEWRENTAL, wxT("Cancel"), wxPoint(388,379), wxSize(165,25), 0, wxDefaultValidator, wxT("cancelNewRental"));

	availabilityLabel = new wxStaticText(itemsNotebookPage, ID_AVAILABILITYLABEL, wxT("Availability"), wxPoint(198,99), wxDefaultSize, 0, wxT("availabilityLabel"));

	availableLabel = new wxStaticText(itemsNotebookPage, ID_AVAILABLELABEL, wxT("Available"), wxPoint(298,99), wxDefaultSize, 0, wxT("availableLabel"));
	availableLabel->SetForegroundColour(wxColour(0,128,0));
	availableLabel->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxBOLD, FALSE));

	editCustomerButton = new wxButton(customersNotebookPage, ID_EDITCUSTOMERBUTTON, wxT("Edit"), wxPoint(298,379), wxSize(75,25), 0, wxDefaultValidator, wxT("editCustomerButton"));

	editItemButton = new wxButton(itemsNotebookPage, ID_EDITITEMBUTTON, wxT("Edit"), wxPoint(298,379), wxSize(75,25), 0, wxDefaultValidator, wxT("editItemButton"));

	lateRentalsButton = new wxButton(rentalsNotebookPage, ID_LATERENTALSBUTTON, wxT("See Late Rentals"), wxPoint(298,379), wxSize(165,25), 0, wxDefaultValidator, wxT("lateRentalsButton"));

	SetStatusBar(statusBar);
	SetTitle(wxT("DVD Rental"));
	SetIcon(wxNullIcon);
	SetSize(8,8,600,500);
	Center();
	
	////GUI Items Creation End
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
 * cancelNewRentalClick
 */
void Main::cancelNewRentalClick(wxCommandEvent& event)
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
