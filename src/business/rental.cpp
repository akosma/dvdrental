/*!
 *  Group 2 DVDRental Project
 *
 *
 */

#include "rental.h"

const std::string Rental::FILE_NAME = "rentals.dat";

Rental::Rental()
: _customerId (-1)
, _itemId     (-1)
, _rentalDate (Date())
, _dueDate    (Date())
{
}

Rental::Rental(const int customerId, 
               const int itemId, 
               const Date& dueDate)
: _customerId (customerId)
, _itemId     (itemId)
, _rentalDate (Date())
, _dueDate    (dueDate)
{

}

Rental::Rental(const Rental& rhs)
: _customerId (rhs._customerId)
, _itemId     (rhs._itemId)
, _rentalDate (rhs._rentalDate)
, _dueDate    (rhs._dueDate)
{
}

Rental& Rental::operator=(const Rental& rhs)
{
    _customerId = rhs._customerId;
    _itemId = rhs._itemId;
    _rentalDate = rhs._rentalDate;
    _dueDate = rhs._dueDate;
}

Rental::~Rental( )
{
}

const int Rental::getItemId() const
{
    return _itemId;
}

const int Rental::getCustomerId( ) const
{
    return _customerId;
}

const Date& Rental::getRentalDate( ) const
{
    return _rentalDate;
}

const Date& Rental::getDueDate( ) const
{
    return _dueDate;
}

const bool Rental::isLate() const
{
    return false;
}
