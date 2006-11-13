/*!
 *  Group 2 DVDRental Project
 *
 *
 */

#include "rental.h"

Rental::Rental( )
{

}

Rental::~Rental( )
{

}

int  Rental::getCustomerId( ) const
{
    return _customerId;
}

Date Rental::getRentalDate( ) const
{
    return _rentalDate;
}

Date Rental::getDueDate( ) const
{
    return _dueDate;
}

void Rental::setCustomerId( int customerId )
{
    _customerId = customerId;
}

void Rental::setRentalDate( const Date &rentalDate )
{
    _rentalDate = rentalDate;
}

void Rental::setDueDate( const Date &dueDate )
{
    _dueDate = dueDate;
}

string Rental::getClassName( )
{
	return "rental.txt";
}
