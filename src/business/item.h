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
    //! Contructor - sets title of recording
    Item(const std::string&);
    virtual ~Item();
    //! Copy constructor
    Item(const Item&);

    //! Assignment overload
    Item& operator=(const Item&);

    //! Access functions - these are overriden in the DVD and VHS classes
    virtual const int getRentalPeriod() const;
    virtual const int getRentalCharge() const;
    virtual const int getLateFee() const;
	virtual const string getClassName( ) const;

    //! Access functions
    const int  getId() const;
    const std::string& getTitle() const;

    //! Mutators
    void setId(const int);
    void setTitle(const std::string&);
    void setRented(const bool);

    //! Returns true if recording is rented out
    const bool isRented() const;

private:
    int         _id;        //! Unique id for this recording
    std::string _title;     //! Recording title
    bool        _rented;    //! true if rented out
};
#endif
