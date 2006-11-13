/*!
 *  Group 2 DVDRental Project
 *
 *  Declaration for the DVD class.
 */

#ifndef DVDH
#define DVDH

#include "item.h"
#include "baseclass.h"

class DVD : public Item
{
public:
    DVD(const std::string&);
    virtual ~DVD();

    virtual const int getRentalPeriod() const;
    virtual const int getRentalCharge() const;
    virtual const int getLateFee() const;
	virtual string getClassName( ); 
};

#endif
