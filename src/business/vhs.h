/*!
 *  Group 2 DVDRental Project
 *
 *  Declaration for the VHS class
 */

#ifndef VHSH
#define VHSH

#include "item.h"

class VHS : public Item
{
public:
    virtual int  getRentalPeriod( ) const;
    virtual int  getRentalCharge( ) const;
    virtual int  getLateFee( ) const;
};

#endif

