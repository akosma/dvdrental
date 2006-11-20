/*!
 *  Group 2 DVDRental Project
 *
 *
 */

#include <cassert>

#include "item.h"

Item::Item(const std::string& title) 
: _id     (-1)
, _rented (false)
{
    setTitle(title);
}

Item::~Item()
{
}

Item::Item(const Item& rhs)
: _id     (rhs._id)
, _rented (rhs._rented)
{
    setTitle(rhs._title);
}

Item& Item::operator=(const Item& rhs)
{
    _id     = rhs._id;
    setTitle(rhs._title);
    _rented = rhs._rented;
    return *this;
}

bool Item::rentItem( int customerId, Date &rentalDate )
{
    // Only rent out if not already rented
    if ( ! _rented ) {
        _customerId = customerId;   // Customer who has the item rented out
        _rentalDate = rentalDate;   // Date it was rented

        // Set up the date that it is due back. This is done by adding the rental period
        // from the derived class (DVD or VHS) to the rentalDate
        _dueDate    = rentalDate;
        _dueDate.addDays( getRentalPeriod( ) );

        // Finally mark the item as being rented out.
        _rented = true;

        return true;    // Retun true to signify sucessful rental
    }
    else {
        return false;   // Return false to signy rental failed
    }
}

// Mark item as being returned.
void Item::returnItem( )
{
    _rented     = false;
    _customerId = 0;
}

const int Item::getId() const
{
    return _id;
}

int  Item::getCustomerId( ) const
{
    return _customerId;
}

Date Item::getRentalDate( ) const
{
    return _rentalDate;
}

Date Item::getDueDate( ) const
{
    return _dueDate;
}

const std::string Item::getTitle() const
{
    return _title;
}

void Item::setId(const int id)
{
    _id = id;
}

void Item::setTitle(const std::string& title)
{
    setStringField(title, _title);
}

const int Item::getRentalPeriod() const
{
    assert( false );
    return 0;
}

const int Item::getRentalCharge() const
{
    assert( false );
    return 0;
}

const int Item::getLateFee() const
{
    assert( false );
    return 0;
}

const bool Item::isRented() const
{
    return _rented;
}
