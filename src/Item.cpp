#include "Item.h"

Item::Item( )
{

}

Item::~Item( )
{

}

bool Item::isRented( ) const
{
    return _rented;
}

void Item::setRented( bool rented )
{
    _rented = rented;
}
