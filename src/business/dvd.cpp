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

const string DVD::getClassName( ) const
{
	return "dvd.txt";
}

