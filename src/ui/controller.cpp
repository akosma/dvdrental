#include "controller.h"

#ifndef PERSIST_H
#include "../persistence/persist.h"
#endif

#ifndef CUSTOMER_H
#include "../business/customer.h"
#endif

#ifndef LIBRARY_H
#include "../business/library.h"
#endif

#ifndef ITEM_H
#include "../business/item.h"
#endif

#ifndef VHS_H
#include "../business/vhs.h"
#endif

#ifndef DVD_H
#include "../business/dvd.h"
#endif

Controller::Controller()
: _library        (Library())
, _customers      (0)
, _currentCustomer(0)
, _currentItem    (0)
, _currentRentalId(-1)
{
    loadCustomers();
    loadLibrary();
}

Controller::~Controller()
{
    delete _customers;
    
    // Do not delete _currentCustomer! It is owned by _customers.
    // See Controller::loadCustomer below for details.
    // The same applies to _currentItem!
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
        wxString number;
        number << currentCustomer.getId();
        wxString name;
        name << currentCustomer.getFirstName().c_str();
        name << " ";
        name << currentCustomer.getLastName().c_str();
        wxString phone;
        phone << currentCustomer.getPhone().c_str();
        wxListItem item;
        item.SetText(number);
        long id = (long)currentCustomer.getId();
        item.SetData(id);
        list->InsertItem(item);
        int itemId = item.GetId();
        list->SetItem(itemId, 1, name);
        if (list->GetColumnCount() > 2)
        {
            list->SetItem(itemId, 2, phone);
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

const bool Controller::deleteCurrentCustomer()
{
    bool ok = true;
    if (NULL != _currentCustomer)
    {
        int id = _currentCustomer->getId();

        // Check that the customer does not have rented items!
        Items::reverse_iterator iterator;
        Items& items = _library.getItems();
        for(iterator = items.rbegin(); iterator != items.rend(); iterator++)
        {
            Item& curItem = iterator->second;
            if (curItem.isRented() && curItem.getCustomerId() == id)
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            _currentCustomer = NULL;
            _customers->erase(id);
            saveCustomers();
        }
    }
    return ok;
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
        
        // Beware! Heavy pointer manipulation here!
        // First assign the new customer to the std::map (this makes a copy)
        (*_customers)[id] = *_currentCustomer;
        
        // Then, point the current customer to the one we want
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

void Controller::loadLibrary()
{
    Persist::loadItems(_library.getItems());
}

void Controller::saveLibrary()
{
    Persist::saveItems(_library.getItems());
}

void Controller::fillItemsList(wxListCtrl* list)
{
    list->DeleteAllItems();
    Items::reverse_iterator iterator;
    Items& items = _library.getItems();
    for(iterator = items.rbegin(); iterator != items.rend(); iterator++)
    {
        Item& curItem = iterator->second;
        wxListItem item;
        if (curItem.isRented())
        {
            item.SetTextColour(wxColour(128,0,0));
            if (curItem.isLate())
            {
                item.SetBackgroundColour(wxColour(255, 255, 0));
            }
        }
        else
        {
            item.SetTextColour(wxColour(0,128,0));
        }
        wxString number;
        number << curItem.getId();
        wxString title;
        title << curItem.getTitle().c_str();
        item.SetText(number);
        long id = (long)curItem.getId();
        item.SetData(id);
        list->InsertItem(item);
        int itemId = item.GetId();
        list->SetItem(itemId, 1, title);
        wxString kind;
        kind << curItem.getItemKindString().c_str();
        list->SetItem(itemId, 2, kind);
    }
}

void Controller::fillRentalsList(wxListCtrl* list)
{
    list->DeleteAllItems();
    Items::reverse_iterator iterator;
    Items& items = _library.getItems();
    for(iterator = items.rbegin(); iterator != items.rend(); iterator++)
    {
        Item& curItem = iterator->second;
        wxListItem item;
        if (!curItem.isRented())
        {
            continue;
        }
        wxString number;
        number << curItem.getId();
        wxString title;
        title << curItem.getTitle().c_str();
        wxString kind;
        kind << curItem.getItemKindString().c_str();
        wxString customer;
        customer << (*_customers)[curItem.getCustomerId()].getFirstName().c_str();
        customer << " ";
        customer << (*_customers)[curItem.getCustomerId()].getLastName().c_str();
        wxString date;
        date << curItem.getDueDate().getStandardString().c_str();
        wxString cost;
        cost << curItem.getRentalCharge();

        item.SetText(number);
        long id = (long)curItem.getId();
        item.SetData(id);
        list->InsertItem(item);
        int itemId = item.GetId();

        list->SetItem(itemId, 1, kind);
        list->SetItem(itemId, 2, cost);
        list->SetItem(itemId, 3, title);
        list->SetItem(itemId, 4, customer);
        list->SetItem(itemId, 5, date);
    }
}

void Controller::fillAvailableItemsList(wxListCtrl* list)
{
    list->DeleteAllItems();
    Items::reverse_iterator iterator;
    Items& items = _library.getItems();
    for(iterator = items.rbegin(); iterator != items.rend(); iterator++)
    {
        Item& curItem = iterator->second;
        wxListItem item;
        if (curItem.isRented())
        {
            continue;
        }
        wxString number;
        number << curItem.getId();
        wxString title;
        title << curItem.getTitle().c_str();
        item.SetText(number);
        long id = (long)curItem.getId();
        item.SetData(id);
        list->InsertItem(item);
        int itemId = item.GetId();
        list->SetItem(itemId, 1, title);
        wxString kind;
        kind << curItem.getItemKindString().c_str();
        list->SetItem(itemId, 2, kind);
    }
}

void Controller::loadItem(int id)
{
    // This field points towards one item owned by the Library...
    // That's why you should not delete _currentItem in the destructor!
    _currentItem = &(_library[id]);
}

const wxString Controller::getCurrentItemTitle() const
{
    wxString result;
    if (NULL == _currentItem)
    {
        result << "";
    }
    else
    {
        result << _currentItem->getTitle().c_str();
    }
    return result;
}

const int Controller::getCurrentItemKind() const
{
    int result = -1;
    if (NULL != _currentItem)
    {
        result = _currentItem->getItemKind();
    }
    return result;
}

const bool Controller::deleteCurrentItem()
{
    bool ok = false;
    if (NULL != _currentItem)
    {
        int id = _currentItem->getId();
        _currentItem = NULL;
        ok = _library.erase(id);
        if (ok)
        {
            saveLibrary();
        }
    }
    return ok;
}

void Controller::prepareForNewItem()
{
    _currentItem = NULL;
}

void Controller::saveItem(wxString& title, int kind)
{
    if (NULL == _currentItem)
    {
        int id = -1;
        switch (kind)
        {
            case 0:
                id = _library.addNewVHS(title.c_str());
                break;
                
            case 1:
                id = _library.addNewDVD(title.c_str());
                break;
            
            default:
                break;
        }
        if (-1 != id)
        {
            _currentItem = &(_library[id]);
        }
    }
    else
    {
        _currentItem->setTitle(title.c_str());
    }
    saveLibrary();
}

const Availability Controller::getCurrentItemAvailability() const
{
    Availability result;
    if (NULL == _currentItem)
    {
        result = UNKNOWN;
    }
    else
    {
        if (_currentItem->isRented())
        {
            result = NOT_AVAILABLE;
        }
        else
        {
            result = AVAILABLE;
        }
    }
    return result;
}

const bool Controller::createRental(wxListCtrl* customers, wxListCtrl* items)
{
    bool result = false;
    if (customers->GetSelectedItemCount() == 1 && items->GetSelectedItemCount() >= 1)
    {
        int customer = -1;
        for (int i = 0; i < customers->GetItemCount(); i++)
        {
            int state = customers->GetItemState(i, wxLIST_STATE_SELECTED);
            if (state == wxLIST_STATE_SELECTED)
            {
                customer = customers->GetItemData(i);
                break;
            }
        }
        
        for (int j = 0; j < items->GetItemCount(); j++)
        {
            int state = items->GetItemState(j, wxLIST_STATE_SELECTED);
            if (state == wxLIST_STATE_SELECTED)
            {
                int item = items->GetItemData(j);
                _library[item].setRentedByCustomerId(customer);
            }
        }
        result = true;
    }
    saveLibrary();
    return result;
}

void Controller::setCurrentRental(int itemId)
{
    _currentRentalId = itemId;
}

const wxString Controller::returnCurrentRental()
{
    wxString receipt;
    Item& item = _library[_currentRentalId];
    if (item.isLate())
    {
        receipt << "Item returned late! Applicable fee: ";
        receipt << item.getLateFee();
    }
    else
    {
        receipt << "Item returned in time; no additional fees!";
    }
    item.setReturned();
    saveLibrary();
    return receipt;
}
