/*!
 * \file librarytest.cpp
 * Contains the implementation of the test::LibraryTest class.
 */

#include "librarytest.h"

#include <vector>
using std::vector;

#include <map>
using std::map;

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

        int itemCount = library.getItems().size();
        CPPUNIT_ASSERT_EQUAL(8, itemCount);

        for (size_t i = 0; i < itemCount; i++) 
        {
            Item& item = library[i];
            
            if (typeid(item) == typeid(VHS))
            {
                CPPUNIT_ASSERT_EQUAL(2, item.getRentalCharge());
            }
            else if (typeid(item) == typeid(DVD))
            {
                CPPUNIT_ASSERT_EQUAL(3, item.getRentalCharge());
            }
        }
    }

    void LibraryTest::testRentItems()
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

        // Rent two items from the library
        library[2].setRentedByCustomerId(1);
        library[3].setRentedByCustomerId(2);
        CPPUNIT_ASSERT(library[2].isRented());
        CPPUNIT_ASSERT(library[3].isRented());
        CPPUNIT_ASSERT_EQUAL(library[2].getCustomerId(), 1);
        CPPUNIT_ASSERT_EQUAL(library[3].getCustomerId(), 2);

        std::map<int, Item> nowAvailable;
        library.getAvailableItems(nowAvailable);
        CPPUNIT_ASSERT_EQUAL(size_t(6), nowAvailable.size());
        
        // Rent items in the past, check that they have a higher cost
        Date threeDaysAgo = Date() - 3;
        Date eightDaysAgo = Date() - 8;
        library[4].setRentedByCustomerId(3, threeDaysAgo);
        library[7].setRentedByCustomerId(4, eightDaysAgo);
        CPPUNIT_ASSERT(library[4].isRented());
        CPPUNIT_ASSERT(library[7].isRented());
        CPPUNIT_ASSERT_EQUAL(library[4].getCustomerId(), 3);
        CPPUNIT_ASSERT_EQUAL(library[7].getCustomerId(), 4);
        CPPUNIT_ASSERT(library[4].isLate());
        CPPUNIT_ASSERT(library[7].isLate());
        
        // Now check the costs
        Item& item = library[2];
        CPPUNIT_ASSERT_EQUAL(item.getRentalCharge(), 3);
        item = library[3];
        CPPUNIT_ASSERT_EQUAL(item.getRentalCharge(), 3);
        item = library[4];
        CPPUNIT_ASSERT_EQUAL(item.getRentalCharge(), (int)(3 + item.getLateFee() * ((Date() - item.getDueDate()))));
        item = library[7];
        CPPUNIT_ASSERT_EQUAL(item.getRentalCharge(), (int)(2 + item.getLateFee() * ((Date() - item.getDueDate()))));
        
        // Now return the items
        library[2].setReturned();
        library[3].setReturned();
        library[4].setReturned();
        library[7].setReturned();
        CPPUNIT_ASSERT(!library[2].isRented());
        CPPUNIT_ASSERT(!library[3].isRented());
        CPPUNIT_ASSERT(!library[4].isRented());
        CPPUNIT_ASSERT(!library[7].isRented());
    }
}
