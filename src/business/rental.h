/*!
 *  Group 2 DVDRental Project
 *
 *
 */

#include <map>
using std::map;

#ifndef RENTAL_H
#define RENTAL_H

#ifndef DATE_H
#include "date.h"
#endif

#ifndef BASECLASS_H
#include "baseclass.h"
#endif

class Rental : public BaseClass
{
public:
    Rental( );
    ~Rental( );

    //! Accessors
    int  getCustomerId( ) const;
    Date getRentalDate( ) const;
    Date getDueDate( ) const;

    //! Mutators
    void setCustomerId( int customerId );
    void setRentalDate( const Date &rentalDate );
    void setDueDate( const Date &dueDate );

public:
    static const std::string FILE_NAME;
    
private:
    int  _customerId;   //! Links this rental to a customer
    Date _rentalDate;   //! Date rental was taked out
    Date _dueDate;      //! Date recording due to be returned
};

typedef std::map<int, Rental> Rentals;

#endif
