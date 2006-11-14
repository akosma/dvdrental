/*!
 *  Group 2 DVDRental Project
 *
 *
 */

#include <cassert>

#include "item.h"

Item::Item(const std::string& title) 
: _id     (-1)
, _title  (title)
, _rented (false)
{
}

Item::~Item()
{
}

Item::Item(const Item& rhs)
: _id     (rhs._id)
, _title  (rhs._title)
, _rented (rhs._rented)
{
}

Item& Item::operator=(const Item& rhs)
{
    _id     = rhs._id;
    _title  = rhs._title;
    _rented = rhs._rented;
    return *this;
}

const int Item::getId() const
{
    return _id;
}

const std::string& Item::getTitle() const
{
    return _title;
}

void Item::setId(const int id)
{
    _id = id;
}

void Item::setTitle(const std::string& title)
{
    _title = title;
}

const int Item::getRentalPeriod() const
{
    assert( false );
    return 0;
}

const int Item::getRentalCharge() const
{
    assert( false );
    return 0;
}

const int Item::getLateFee() const
{
    assert( false );
    return 0;
}

const string Item::getClassName() const
{
    return "Item";
}

const bool Item::isRented() const
{
    return _rented;
}

void Item::setRented(const bool rented)
{
    _rented = rented;
}
