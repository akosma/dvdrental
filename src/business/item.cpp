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
{
    setTitle(rhs._title);
}

Item& Item::operator=(const Item& rhs)
{
    _id     = rhs._id;
    setTitle(rhs._title);
    _rentalPeriod = rhs._rentalPeriod;
    _rentalCharge = rhs._rentalCharge;
    _lateFee = rhs._lateFee;
    _kind = rhs._kind;
    return *this;
}

//bool Item::rentItem( int customerId, Date &rentalDate )
//{
//    // Only rent out if not already rented
//    if ( ! _rented ) {
//        _customerId = customerId;   // Customer who has the item rented out
//        _rentalDate = rentalDate;   // Date it was rented
//
//        // Set up the date that it is due back. This is done by adding the rental period
//        // from the derived class (DVD or VHS) to the rentalDate
//        _dueDate    = rentalDate;
//        _dueDate.addDays( getRentalPeriod( ) );
//
//        // Finally mark the item as being rented out.
//        _rented = true;
//
//        return true;    // Retun true to signify sucessful rental
//    }
//    else {
//        return false;   // Return false to signy rental failed
//    }
//}

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
