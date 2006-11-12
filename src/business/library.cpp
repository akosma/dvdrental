/*!
 *  Group 2 DVDRental Project
 *
 *
 */

#include "library.h"
#include "dvd.h"
#include "vhs.h"

Library::Library( )
{

}

Library::~Library( )
{

}

int Library::getAvailableItems( vector<Item *> &availableItems ) const
{
    for ( vector<Item>::size_type i = 0; i < _items.size(); i++ ) {
        Item *item = _items[ i ];

        if ( ! item->isRented( ) ) {
            availableItems.push_back( item );
        }
    }

    return availableItems.size();
}

Item *Library::newItem( Item *item )
{
    item->setId( _items.size( ) );

    _items.push_back( item );

    return item;
}

Item *Library::newDVD( )
{
    return newItem( new( DVD ) );
}

Item *Library::newVHS( )
{
    return newItem( new( VHS ) );
}

