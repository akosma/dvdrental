#include "controller.h"

#ifndef PERSIST_H
#include "../persistence/persist.h"
#endif

Controller::Controller()
: _library        (Library())
, _customers      (0)
, _rentals        (0)
, _currentCustomer(0)
, _currentItem    (0)
, _currentRental  (0)
{
    loadCustomers();
}

Controller::~Controller()
{
    delete _customers;
    delete _rentals;
    
    // Do not delete _currentCustomer! It is owned by _customers.
    // See Controller::loadCustomer below for details.
}

void Controller::fillRentalsList(wxListCtrl* list)
{
}

void Controller::loadCustomers()
{
    delete _customers;
    _customers = Persist::loadCustomers();
}

void Controller::fillCustomersList(wxListCtrl* list)
{
    Customers::reverse_iterator customerIterator;
    for(customerIterator = _customers->rbegin(); customerIterator != _customers->rend();
            customerIterator++)
    {
        Customer& currentCustomer = customerIterator->second;
        wxString name;
        name << currentCustomer.getFirstName().c_str();
        name << " ";
        name << currentCustomer.getLastName().c_str();
        wxListItem item;
        long id = (long)currentCustomer.getId();
        item.SetText(name);
        item.SetData(id);
        list->InsertItem(item);
    }

//    // Update the status bar text
//    size_t quantity = _people->size();
//    _statusBarText = "";
//    _statusBarText << quantity;
//    if (quantity > 1)
//    {
//        _statusBarText << " people";
//    }
//    else
//    {
//        _statusBarText << " person";
//    }
}

void Controller::loadCustomer(int id)
{
    // This field points towards one item owned by _customers...
    // That's why you should not delete _currentCustomer in the destructor!
    _currentCustomer = &(*_customers)[id];
}

const wxString Controller::getCurrentCustomerFirstName() const
{
    wxString name;
    name << _currentCustomer->getFirstName().c_str();
    return name;
}

const wxString Controller::getCurrentCustomerLastName() const
{
    wxString name;
    name << _currentCustomer->getLastName().c_str();
    return name;
}
