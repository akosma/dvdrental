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

#include "baseclass.h"
#include "date.h"

class Item : public BaseClass
{
public:
    //! Contructor - sets title of recording
    Item(const std::string&);
    virtual ~Item();
    //! Copy constructor
    Item(const Item&);

    //! Assignment overload
    Item& operator=(const Item&);

    //! Function used to mark an item as being rented out.
    //! CustomerId identifies the customer, and rentalDate is the
    //! date of the rental. Returns true if rental successful.
    bool rentItem( int customerId, Date &rentalDate );

    // Return rented item
    void returnItem( );

    //! Access functions - these are overriden in the DVD and VHS classes
    virtual const int getRentalPeriod() const;
    virtual const int getRentalCharge() const;
    virtual const int getLateFee() const;

    //! Access functions
    const int  getId() const;
    const std::string getTitle() const;
    int  getCustomerId( ) const;
    Date getRentalDate( ) const;
    Date getDueDate( ) const;

    //! Mutators
    void setId(const int);
    void setTitle(const std::string&);

    //! Returns true if recording is rented out
    const bool isRented() const;

private:
    int  _id;            //! Unique id for this recording
    char _title[40];         //! Recording title
    bool _rented;        //! true if rented out
    int  _customerId;    //! Links this rental to a customer
    Date _rentalDate;    //! Date rental was taked out
    Date _dueDate;       //! Date recording due to be returned
};
#endif
