/*!
 *  Group 2 DVDRental Project
 *
 *
 */

#include <cassert>

#include "item.h"

Item::Item(const std::string& title) 
: _id     (-1)
, _rented (false)
{
    setTitle(title);
}

Item::~Item()
{
}

Item::Item(const Item& rhs)
: _id     (rhs._id)
, _rented (rhs._rented)
{
    setTitle(rhs._title);
}

Item& Item::operator=(const Item& rhs)
{
    _id     = rhs._id;
    setTitle(rhs._title);
    _rented = rhs._rented;
    return *this;
}

const int Item::getId() const
{
    return _id;
}

const std::string Item::getTitle() const
{
    return _title;
}

void Item::setId(const int id)
{
    _id = id;
}

void Item::setTitle(const std::string& title)
{
    setStringField(title, _title);
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

const bool Item::isRented() const
{
    return _rented;
}

void Item::setRented(const bool rented)
{
    _rented = rented;
}
