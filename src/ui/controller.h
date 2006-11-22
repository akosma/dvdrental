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

enum Availability
{
    UNKNOWN = -1,
    NOT_AVAILABLE = 0,
    AVAILABLE = 1
};

class Controller
{
public:
    Controller();
    virtual ~Controller();

    void loadCustomers();
    void saveCustomers();
    void fillCustomersList(wxListCtrl* list);
    void loadCustomer(int id);
    const wxString getCurrentCustomerFirstName() const;
    const wxString getCurrentCustomerLastName() const;
    const wxString getCurrentCustomerAddress() const;
    const wxString getCurrentCustomerPhoneNumber() const;
    const bool deleteCurrentCustomer();
    void prepareForNewCustomer();
    void saveCustomer(wxString&, wxString&, wxString&, wxString&);
    
    void loadLibrary();
    void saveLibrary();
    void fillItemsList(wxListCtrl* list);
    void fillAvailableItemsList(wxListCtrl* list);
    void loadItem(int id);
    const wxString getCurrentItemTitle() const;
    const int getCurrentItemKind() const;
    const Availability getCurrentItemAvailability() const;
    const bool deleteCurrentItem();
    void prepareForNewItem();
    void saveItem(wxString& title, int kind);
    
    void fillRentalsList(wxListCtrl* list);
    const bool createRental(wxListCtrl*, wxListCtrl*);
    void setCurrentRental(int);
    const wxString returnCurrentRental();
    
private:
    int getMaximumCustomerId();

private:
    Library    _library;
    Customers* _customers;
    Customer*  _currentCustomer;
    Item*      _currentItem;
    int        _currentRentalId;
};

#endif
