/*!
 *  Group 2 DVDRental Project
 *
 *
 */

#ifndef RentalH
#define RentalH

#include "date.h"
#include "baseclass.h"

class Rental
{
public:
    Rental( );
    ~Rental( );

    int  getCustomerId( ) const;
    Date getRentalDate( ) const;
    Date getDueDate( ) const;
	virtual const string getClassName( ) const;
    
    void setCustomerId( int customerId );
    void setRentalDate( const Date &rentalDate );
    void setDueDate( const Date &dueDate );

private:
    int  _customerId;
    Date _rentalDate;
    Date _dueDate;
};

#endif
