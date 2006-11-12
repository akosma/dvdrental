/*!
 *  Group 2 DVDRental Project
 *
 *  This file declares the Customer class which represents an entity that
 *  can hire recordings
 */

#ifndef CustomerH
#define CustomerH

#include <string>
#include <vector>
using namespace std;

#include "rental.h"

class Customer
{
public:
    Customer( );
    ~Customer( );

    int    getId( ) const;
    string getLastName( ) const;
    string getFirstName( ) const;
    string getAddress( ) const;
    string getPhone( ) const;

    void setId( int id );
    void setLastName( const string &lastName );
    void setFirstName( const string &firstName );
    void setAddress( const string &address );
    void setPhone( const string &phone );

private:
    int    _id;             // Unique ID for this customer
    string _lastName;
    string _firstName;
    string _address;
    string _phone;

//! List of the rentals that this customer has
    vector<Rental *> _rentals;
};

#endif
