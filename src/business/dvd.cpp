/*!
 *  Group 2 DVDRental Project
 *
 *
 */

#include "dvd.h"

DVD::DVD(const std::string& title)
: Item(title)
{
}

DVD::~DVD()
{
}

const int DVD::getRentalPeriod( ) const
{
    return 2;
}

const int DVD::getRentalCharge( ) const
{
    return 3;
}

const int DVD::getLateFee( ) const
{
    return 2;
}

string DVD::getClassName( )
{
	return "dvd.txt";
}

