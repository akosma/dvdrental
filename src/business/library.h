/*!
 *  Group 2 DVDRental Project
 *
 *  Declaration for the library class. This contains a vector of all the
 *  items that can be rented out.
 */

#ifndef LibraryH
#define LibraryH

#include <vector>
using namespace std;

#include "item.h"

class Library
{
public:
    Library( );
    ~Library( );

//! getAvailableItems fills the passed in vector with items that are available for rental
    int getAvailableItems( vector<Item *> &availableItems ) const;
    
    Item *newDVD( );
    Item *newVHS( ); 

private:
    Item *newItem( Item *item );

    vector<Item *> _items;
};

#endif
