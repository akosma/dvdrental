#ifndef RentalH
#define RentalH

#include "Date.h"

class Rental
{
public:
    Rental( );
    ~Rental( );

    int  getCustomerId( ) const;
    Date getRentalDate( ) const;
    Date getDueDate( ) const;
    
    void setCustomerId( int customerId );
    void setRentalDate( const Date &rentalDate );
    void setDueDate( const Date &dueDate );

private:
    int  _customerId;
    Date _rentalDate;
    Date _dueDate;
};

#endif
