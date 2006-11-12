/*!
 *  Group 2 DVDRental Project
 *
 *  Declaration for the DVD class.
 */

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
