#ifndef VHSH
#define VHSH

#include "Item.h"

class VHS : public Item
{
public:
    virtual int  getRentalPeriod( ) const;
    virtual int  getRentalCharge( ) const;
    virtual int  getLateFee( ) const;
};

#endif

