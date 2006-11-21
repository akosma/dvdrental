#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include <wx/listctrl.h>

#include <map>
using std::map;

#include <string>
using std::string;

#ifndef CUSTOMER_H
#include "../business/customer.h"
#endif

#ifndef LIBRARY_H
#include "../business/library.h"
#endif

#ifndef RENTAL_H
#include "../business/rental.h"
#endif

class Controller
{
public:
    Controller();
    virtual ~Controller();

    void fillRentalsList(wxListCtrl* list);
    
    void loadCustomers();
    void saveCustomers();
    void fillCustomersList(wxListCtrl* list);
    void loadCustomer(int id);
    const wxString getCurrentCustomerFirstName() const;
    const wxString getCurrentCustomerLastName() const;
    const wxString getCurrentCustomerAddress() const;
    const wxString getCurrentCustomerPhoneNumber() const;
    void deleteCurrentCustomer();
    void prepareForNewCustomer();
    void saveCustomer(wxString& firstName, wxString& lastName, wxString& address, wxString& phone);
    
    void loadLibrary();
    void saveLibrary();
    void fillItemsList(wxListCtrl* list);
    void loadItem(int id);
    const wxString getCurrentItemTitle() const;
    const int getCurrentItemKind() const;
    void deleteCurrentItem();
    void prepareForNewItem();
    void saveItem(wxString& title, int kind);
    
private:
    int getMaximumCustomerId();

private:
    Library    _library;
    Customers* _customers;
    Rentals*   _rentals;
    Customer*  _currentCustomer;
    Item*      _currentItem;
    Rental*    _currentRental;
};

#endif
