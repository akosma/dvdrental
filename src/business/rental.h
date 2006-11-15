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

    //! Accessors
    int  getCustomerId( ) const;
    Date getRentalDate( ) const;
    Date getDueDate( ) const;

    //! Used for persistence
	virtual const string getClassName( ) const;

    //! Mutators
    void setCustomerId( int customerId );
    void setRentalDate( const Date &rentalDate );
    void setDueDate( const Date &dueDate );

private:
    int  _customerId;   //! Links this rental to a customer
    Date _rentalDate;   //! Date rental was taked out
    Date _dueDate;      //! Date recording due to be returned
};

#endif
