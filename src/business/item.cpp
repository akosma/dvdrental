#include <cassert>

#include "item.h"

Item::Item( ) :
    _id( -1 ),
    _title( "" ),
    _rented( false )
{

}

Item::~Item( )
{

}

int Item::getId( ) const
{
    return _id;
}

char *Item::getTitle( ) const
{
    return _title;
}

void Item::setId( int id )
{
    _id = id;
}

void Item::setTitle( char *title )
{
    _title = title;
}

int Item::getRentalPeriod( ) const
{
    assert( false );
    return 0;
}

int Item::getRentalCharge( ) const
{
    assert( false );
    return 0;
}

int Item::getLateFee( ) const
{
    assert( false );
    return 0;
}


bool Item::isRented( ) const
{
    return _rented;
}

void Item::setRented( bool rented )
{
    _rented = rented;
}
