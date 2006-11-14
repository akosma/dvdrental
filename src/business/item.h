/*!
 *  Group 2 DVDRental Project
 *
 *  Declarartion for the Item class. This is the base class for the DVD
 *  and VHS classes. 
 */

#ifndef ItemH
#define ItemH

#include <string>
using std::string;

#include "baseclass.h"

class Item
{
public:
    Item(const std::string&);
    virtual ~Item();
    Item(const Item&);
    Item& operator=(const Item&);

    virtual const int getRentalPeriod() const;
    virtual const int getRentalCharge() const;
    virtual const int getLateFee() const;
	virtual const string getClassName( ) const; 

    const int  getId() const;
    const std::string& getTitle() const;

    void setId(const int);
    void setTitle(const std::string&);

    const bool isRented() const;

    void setRented(const bool);

private:
    int         _id;
    std::string _title;
    bool        _rented;
};
#endif
