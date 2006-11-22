/*!
 * \file librarytest.h
 * Contains the interface of the test::LibraryTest class.
 */

#ifndef LIBRARYTEST_H_
#define LIBRARYTEST_H_

#include <cppunit/extensions/HelperMacros.h>

/*!
 * \namespace tests
 * This namespace holds the classes that derive from 
 * CppUnit::TestFixture, containing unit tests for the DVD Rental
 * application.
 */
namespace tests
{
    /*!
     * \class LibraryTest
     * Tests the business::DataAccessLayer class.
     */
    class LibraryTest : public CppUnit::TestFixture
    {
        CPPUNIT_TEST_SUITE(tests::LibraryTest);
        CPPUNIT_TEST(testCreateLibrary);
        CPPUNIT_TEST(testRentItems);
        CPPUNIT_TEST_SUITE_END();
    
    public:
    
        /*!
         * Constructor.
         */
        LibraryTest();

        /*!
         * Virtual destructor.
         */
        virtual ~LibraryTest();
    
        /*!
         * Called by CppUnit before each test.
         */
        void setUp();

        /*!
         * Called by CppUnit after each test.
         */
        void tearDown();
        
        /*!
         * Tests the automatic creation of a library.
         */
        void testCreateLibrary();
        
        void testRentItems();
    };
}

CPPUNIT_TEST_SUITE_REGISTRATION(tests::LibraryTest);

#endif /*LIBRARYTEST_H_*/
