#ifndef DVDH
#define DVDH

#include "item.h"

class DVD : public Item
{
public:
    virtual int  getRentalPeriod( ) const;
    virtual int  getRentalCharge( ) const;
    virtual int  getLateFee( ) const;
};

#endif
