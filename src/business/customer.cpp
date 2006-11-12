/*!
 *  Group 2 DVDRental Project
 *
 *  This file contains the Customer class which represents an entity that
 *  can hire recordings
 */

#include "customer.h"

Customer::Customer( )
{

}

Customer::~Customer( )
{

}

int Customer::getId( ) const
{
    return _id;
}

string Customer::getLastName( ) const
{
    return _lastName;
}

string Customer::getFirstName( ) const
{
    return _firstName;
}

string Customer::getAddress( ) const
{
    return _address;
}

string Customer::getPhone( ) const
{
    return _phone;
}

void Customer::setId( int id )
{
    _id = id;
}

void Customer::setLastName( const string &lastName )
{
    _lastName = lastName;
}

void Customer::setFirstName( const string &firstName )
{
    _firstName = firstName;
}

void Customer::setAddress( const string &address ) 
{
    _address = address;
}

void Customer::setPhone( const string &phone ) 
{
    _phone = phone;
}

