/*!
 *  Group 2 DVDRental Project
 *
 *
 */

#include "vhs.h"

int VHS::getRentalPeriod( ) const
{
    return 7;
}

int VHS::getRentalCharge( ) const
{
    return 2;
}

int VHS::getLateFee( ) const
{
    return 1;
}
