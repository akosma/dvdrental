/*!
 *  Group 2 DVDRental Project
 *
 *  This file contains tests for the DVDRental classes
 */

#include <iostream>
#include <vector>
using namespace std;

#include "Library.h"
#include "DVD.h"
#include "VHS.h"

int main( )
{
    Library library;

    Item *item;

    cout << "Setting up library...\n";
    
    item = library.newDVD();
    item->setTitle( "Brief Encounter" );

    item = library.newDVD();
    item->setTitle( "Fellowship of the Ring" );

    item = library.newDVD();
    item->setTitle( "The Two Towers" );

    item = library.newDVD();
    item->setTitle( "Return of the King" );

    item = library.newDVD();
    item->setTitle( "Cronicles of Narnia" );

    item = library.newVHS();
    item->setTitle( "Thomas the Tank Engine" );

    item = library.newVHS();
    item->setTitle( "Apollo 13" );

    item = library.newVHS();
    item->setTitle( "Total Recall" );

    vector<Item *> availableItems;

    int itemCount = library.getAvailableItems( availableItems );

    cout << "Library contains " << itemCount << " recordings:\n";

    for (int i = 0; i < availableItems.size( ); i++) {
        Item *item = availableItems[ i ];

        cout << "  " << item->getTitle( ) << " Rental charge " << item->getRentalCharge( ) << "\n";
    }

    availableItems[ 2 ]->setRented( true );
    availableItems[ 3 ]->setRented( true );

    vector<Item *> nowAvailable;

    library.getAvailableItems( nowAvailable );

    cout << "After renting two records there are " << nowAvailable.size( ) << " left\n";

    return 0;
}
