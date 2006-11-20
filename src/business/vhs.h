/*!
 *  Group 2 DVDRental Project
 *
 *  Declaration for the VHS class
 */

#ifndef VHS_H
#define VHS_H

#ifndef ITEM_H
#include "item.h"
#endif

class VHS : public Item
{
public:
    VHS(const std::string&);
    virtual ~VHS();

    //! Overridden accessors that return values for VHS recordings
    virtual const int getRentalPeriod() const;
    virtual const int getRentalCharge() const;
    virtual const int getLateFee() const;
};

#endif
