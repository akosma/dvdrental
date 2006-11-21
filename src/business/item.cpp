/*!
 *  Group 2 DVDRental Project
 *
 *
 */

#include <cassert>

#include "item.h"

Item::Item()
: _id           (0)
, _rentalPeriod (0)
, _rentalCharge (0)
, _lateFee      (0)
, _kind         (-1)
, _rented       (false)
, _customerId   (-1)
, _rentalDate   (Date())
, _dueDate      (Date())
{
}

Item::Item(const int kind,
           const int id, 
           const std::string& title, 
           const int rentalPeriod, 
           const int rentalCharge, 
           const int lateFee)
: _id           (id)
, _rentalPeriod (rentalPeriod)
, _rentalCharge (rentalCharge)
, _lateFee      (lateFee)
, _kind         (kind)
, _rented       (false)
, _customerId   (-1)
, _rentalDate   (Date())
, _dueDate      (Date())
{
    setTitle(title);
}

Item::~Item()
{
}

Item::Item(const Item& rhs)
: _id           (rhs._id)
, _rentalPeriod (rhs._rentalPeriod)
, _rentalCharge (rhs._rentalCharge)
, _lateFee      (rhs._lateFee)
, _kind         (rhs._kind)
, _rented       (rhs._rented)
, _customerId   (rhs._customerId)
, _rentalDate   (rhs._rentalDate)
, _dueDate      (rhs._dueDate)
{
    setTitle(rhs._title);
}

Item& Item::operator=(const Item& rhs)
{
    _id = rhs._id;
    setTitle(rhs._title);
    _rentalPeriod = rhs._rentalPeriod;
    _rentalCharge = rhs._rentalCharge;
    _lateFee = rhs._lateFee;
    _kind = rhs._kind;
    _rented = rhs._rented;
    _customerId = rhs._customerId;
    _rentalDate = rhs._rentalDate;
    _dueDate = rhs._dueDate;
    return *this;
}

void Item::setRentedByCustomerId(const int customerId)
{
    // Only rent out if not already rented
    if (!_rented) 
    {
        _customerId = customerId;   // Customer who has the item rented out
        _rentalDate = Date();   // Date it was rented = today

        // Set up the date that it is due back. This is done by adding the rental period
        // from the derived class (DVD or VHS) to the rentalDate
        _dueDate = Date();
        _dueDate.addDays(_rentalPeriod);

        // Finally mark the item as being rented out.
        _rented = true;
    }
}

const int Item::getId() const
{
    return _id;
}

const std::string Item::getTitle() const
{
    return _title;
}

void Item::setTitle(const std::string& title)
{
    setStringField(title, _title);
}

const int Item::getRentalPeriod() const
{
    return _rentalPeriod;
}

const int Item::getRentalCharge() const
{
    return _rentalCharge;
}

const int Item::getLateFee() const
{
    return _lateFee;
}

const int Item::getItemKind() const
{
    return _kind;
}

const std::string Item::getItemKindString() const
{
    std::string result;
    switch (_kind)
    {
        case 0:
            result = "VHS";
            break;
            
        case 1:
            result = "DVD";
            break;
            
        default:
            result = "?";
            break;
    }
    return result;
}

void Item::setReturned()
{
    _rented = false;
}

const bool Item::isLate() const
{
    Date today;
    return _dueDate <= today;
}

const bool Item::isRented() const
{
    return _rented;
}

const int Item::getCustomerId() const
{
    return _customerId;
}

const Date& Item::getDueDate() const
{
    return _dueDate;
}
