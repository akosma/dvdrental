/*!
 * \file librarytest.cpp
 * Contains the implementation of the test::LibraryTest class.
 */

#include "librarytest.h"

#include <vector>
using std::vector;

#include <typeinfo>

#include "../business/library.h"
#include "../business/dvd.h"
#include "../business/vhs.h"

/*!
 * \namespace tests
 * This namespace holds the classes that derive from 
 * CppUnit::TestFixture, containing unit tests for the DVD Rental
 * application.
 */
namespace tests
{
    /*!
     * Constructor.
     */
    LibraryTest::LibraryTest()
    {
    }
    
    /*!
     * Virtual destructor.
     */
    LibraryTest::~LibraryTest()
    {
    }
    
    /*!
     * Called by CppUnit before each test.
     */
    void LibraryTest::setUp()
    {
    }
    
    /*!
     * Called by CppUnit after each test.
     */
    void LibraryTest::tearDown()
    {
    }
    
    /*!
     * Tests the automatic creation of a library.
     */
    void LibraryTest::testCreateLibrary()
    {
        Library library;
        Item *item;

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
        
        CPPUNIT_ASSERT_EQUAL(itemCount, 8);

        for (int i = 0; i < availableItems.size( ); i++) 
        {
            Item *item = availableItems[ i ];
            
            if (typeid(item) == typeid(VHS))
            {
                CPPUNIT_ASSERT_EQUAL(item->getRentalCharge(), 2);
            }
            else if (typeid(item) == typeid(DVD))
            {
                CPPUNIT_ASSERT_EQUAL(item->getRentalCharge(), 3);
            }
        }

        // Rent two items from the library
        availableItems[ 2 ]->setRented( true );
        availableItems[ 3 ]->setRented( true );
        vector<Item *> nowAvailable;
        library.getAvailableItems( nowAvailable );

        CPPUNIT_ASSERT_EQUAL(nowAvailable.size(), size_t(6));
    }
}
