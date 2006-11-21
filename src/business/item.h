/*!
 *  Group 2 DVDRental Project
 *
 *  Declarartion for the Item class. This is the base class for the DVD
 *  and VHS classes. 
 */

#ifndef ITEM_H
#define ITEM_H

#include <string>
using std::string;

#include <map>
using std::map;

#ifndef BASECLASS_H
#include "baseclass.h"
#endif

class Item : public BaseClass
{
public:
    //! Contructor - sets title of recording
    Item();
    Item(const int, const int, const std::string&, const int, const int, const int);
    virtual ~Item();
    //! Copy constructor
    Item(const Item&);

    //! Assignment overload
    Item& operator=(const Item&);

    //! Access functions - these are overriden in the DVD and VHS classes
    const int getRentalPeriod() const;
    const int getRentalCharge() const;
    const int getLateFee() const;
    
    const int getItemKind() const;

    //! Access functions
    const int  getId() const;
    const std::string getTitle() const;

    void setTitle(const std::string&);

private:
    int  _id;            //! Unique id for this recording
    char _title[40];         //! Recording title
    int  _rentalPeriod;
    int  _rentalCharge;
    int  _lateFee;
    int  _kind;
};

typedef std::map<int, Item> Items;

#endif
