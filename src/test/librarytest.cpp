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
        library.addNewDVD("Brief Encounters of the Third Kind");
        library.addNewDVD("Fellowship of the Ring");
        library.addNewDVD("The Two Towers");
        library.addNewDVD("Return of the King");
        library.addNewDVD("Cronicles of Narnia");
        library.addNewVHS("Thomas the Tank Engine");
        library.addNewVHS("Apollo 13");
        library.addNewVHS("Total Recall");

        vector<Item> availableItems;

        int itemCount = library.getAvailableItems(availableItems);

        CPPUNIT_ASSERT_EQUAL(8, itemCount);

        for (size_t i = 0; i < availableItems.size(); i++) 
        {
            Item item = availableItems[i];
            
            if (typeid(item) == typeid(VHS))
            {
                CPPUNIT_ASSERT_EQUAL(2, item.getRentalCharge());
            }
            else if (typeid(item) == typeid(DVD))
            {
                CPPUNIT_ASSERT_EQUAL(3, item.getRentalCharge());
            }
        }

        // Rent two items from the library
        library[2].setRented(true);
        library[3].setRented(true);
        vector<Item> nowAvailable;
        library.getAvailableItems(nowAvailable);

        CPPUNIT_ASSERT_EQUAL(size_t(6), nowAvailable.size());
    }
}
