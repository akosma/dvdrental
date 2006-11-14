/*!
 *  Group 2 DVDRental Project
 *
 *
 */

#include "vhs.h"

VHS::VHS(const std::string& title)
: Item(title)
{
}

VHS::~VHS()
{
}

const int VHS::getRentalPeriod( ) const
{
    return 7;
}

const int VHS::getRentalCharge( ) const
{
    return 2;
}

const int VHS::getLateFee( ) const
{
    return 1;
}

const string VHS::getClassName( ) const
{
	return "vhs.txt";
}
