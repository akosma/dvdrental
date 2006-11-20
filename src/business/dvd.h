/*!
 *  Group 2 DVDRental Project
 *
 *  Declaration for the DVD class.
 */

#ifndef DVD_H
#define DVD_H

#ifndef ITEM_H
#include "item.h"
#endif

#ifndef BASECLASS_H
#include "baseclass.h"
#endif

class DVD : public Item
{
public:
    DVD(const std::string&);
    virtual ~DVD();

    //! Overridden accessors that return values for VHS recordings
    virtual const int getRentalPeriod() const;
    virtual const int getRentalCharge() const;
    virtual const int getLateFee() const;

    //! Clas name used for persistence
	const virtual string getClassName( ) const; 
};

#endif
