#include "controller.h"

#ifndef PERSIST_H
#include "../persistence/persist.h"
#endif

#ifndef CUSTOMER_H
#include "../business/customer.h"
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

void Controller::saveCustomers()
{
    Persist::saveCustomers(*_customers);
}

void Controller::fillCustomersList(wxListCtrl* list)
{
    list->DeleteAllItems();
    Customers::reverse_iterator customerIterator;
    for(customerIterator = _customers->rbegin(); customerIterator != _customers->rend();
            customerIterator++)
    {
        Customer& currentCustomer = customerIterator->second;
        wxString name;
        name << currentCustomer.getFirstName().c_str();
        name << " ";
        name << currentCustomer.getLastName().c_str();
        wxString phone;
        phone << currentCustomer.getPhone().c_str();
        wxListItem item;
        item.SetText(name);
        long id = (long)currentCustomer.getId();
        item.SetData(id);
        list->InsertItem(item);
        if (list->GetColumnCount() > 1)
        {
            int itemId = item.GetId();
            list->SetItem(itemId, 1, phone);
        }
    }
}

void Controller::loadCustomer(int id)
{
    // This field points towards one item owned by _customers...
    // That's why you should not delete _currentCustomer in the destructor!
    _currentCustomer = &(*_customers)[id];
}

const wxString Controller::getCurrentCustomerFirstName() const
{
    wxString result;
    if (NULL == _currentCustomer)
    {
        result << "";
    }
    else
    {
        result << _currentCustomer->getFirstName().c_str();
    }
    return result;
}

const wxString Controller::getCurrentCustomerLastName() const
{
    wxString result;
    if (NULL == _currentCustomer)
    {
        result << "";
    }
    else
    {
        result << _currentCustomer->getLastName().c_str();
    }
    return result;
}

const wxString Controller::getCurrentCustomerPhoneNumber() const
{
    wxString result;
    if (NULL == _currentCustomer)
    {
        result << "";
    }
    else
    {
        result << _currentCustomer->getPhone().c_str();
    }
    return result;
}

const wxString Controller::getCurrentCustomerAddress() const
{
    wxString result;
    if (NULL == _currentCustomer)
    {
        result << "";
    }
    else
    {
        result << _currentCustomer->getAddress().c_str();
    }
    return result;
}

void Controller::deleteCurrentCustomer()
{
    if (NULL != _currentCustomer)
    {
        int id = _currentCustomer->getId();
        _currentCustomer = NULL;
        _customers->erase(id);
        saveCustomers();
    }
}

void Controller::prepareForNewCustomer()
{
    _currentCustomer = NULL;
}

void Controller::saveCustomer(wxString& firstName, wxString& lastName, wxString& address, wxString& phone)
{
    if (NULL == _currentCustomer)
    {
        int id = getMaximumCustomerId() + 1;
        _currentCustomer = new Customer(id);
        (*_customers)[id] = *_currentCustomer;
        _currentCustomer = &(*_customers)[id];
    }
    _currentCustomer->setFirstName(firstName.c_str());
    _currentCustomer->setLastName(lastName.c_str());
    _currentCustomer->setAddress(address.c_str());
    _currentCustomer->setPhone(phone.c_str());
    saveCustomers();
}

int Controller::getMaximumCustomerId()
{
    int result = 0;
    Customers::reverse_iterator customerIterator;
    for(customerIterator = _customers->rbegin(); customerIterator != _customers->rend();
            customerIterator++)
    {
        Customer& currentCustomer = customerIterator->second;
        int currentId = currentCustomer.getId();
        if (result < currentId)
        {
            result = currentId;
        }
    }
    return result;
}
