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

#ifndef DATE_H
#include "date.h"
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

    //! Access functions
    const int getRentalPeriod() const;
    const int getRentalCharge() const;
    const int getLateFee() const;
    const int  getId() const;
    const std::string getTitle() const;
    const int getItemKind() const;
    const std::string getItemKindString() const;
    const int getCustomerId() const;
    const Date& getDueDate() const;

    void setTitle(const std::string&);
    
    void setRentedByCustomerId(const int);
    const bool isRented() const;
    void setReturned();
    const bool isLate() const;

private:
    int  _id;                //! Unique id for this recording
    char _title[40];         //! Recording title
    int  _rentalPeriod;
    int  _rentalCharge;
    int  _lateFee;
    int  _kind;
    bool _rented;
    int  _customerId;
    Date _rentalDate;
    Date _dueDate;
};

typedef std::map<int, Item> Items;

#endif
