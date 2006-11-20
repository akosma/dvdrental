/*!
 *  Group 2 DVDRental Project
 *
 *  This file contains the Customer class which represents an entity that
 *  can hire recordings
 */

#include "customer.h"

const std::string Customer::FILE_NAME = "customers.dat";

Customer::Customer()
: _id        (0)
, _firstName ()
, _lastName  ()
, _address   ()
, _phone     ()
{
}

Customer::Customer(int id)
: _id        (id)
, _firstName ()
, _lastName  ()
, _address   ()
, _phone     ()
{
}

Customer::~Customer()
{
}

Customer::Customer(const Customer& rhs)
: _id (rhs._id)
{
    setFirstName(rhs._firstName);
    setLastName(rhs._lastName);
    setAddress(rhs._address);
    setPhone(rhs._phone);
}

Customer& Customer::operator=(const Customer& rhs)
{
    _id = rhs._id;
    setFirstName(rhs._firstName);
    setLastName(rhs._lastName);
    setAddress(rhs._address);
    setPhone(rhs._phone);
    return *this;
}

int Customer::getId() const
{
    return _id;
}

const std::string Customer::getLastName() const
{
    return _lastName;
}

const std::string Customer::getFirstName() const
{
    return _firstName;
}

const std::string Customer::getAddress() const
{
    return _address;
}

const std::string Customer::getPhone() const
{
    return _phone;
}

void Customer::setLastName(const std::string& lastName)
{
    setStringField(lastName, _lastName);
}

void Customer::setFirstName(const std::string& firstName)
{
    setStringField(firstName, _firstName);
}

void Customer::setAddress(const std::string& address)
{
    setStringField(address, _address);
}

void Customer::setPhone(const std::string& phone)
{
    setStringField(phone, _phone);
}
