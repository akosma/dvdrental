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
    VHS(const std::string&);
    virtual ~VHS();

    virtual const int getRentalPeriod() const;
    virtual const int getRentalCharge() const;
    virtual const int getLateFee() const;
};

#endif

