/*!
 * \file datetest.h
 * Contains the interface of the test::DateTest class.
 */

#ifndef DATETEST_H_
#define DATETEST_H_

#include <cppunit/extensions/HelperMacros.h>

/*!
 * \namespace tests
 * This namespace holds the classes that derive from 
 * CppUnit::TestFixture, containing unit tests for the BirthdayCard
 * application.
 */
namespace tests
{
    /*!
     * \class DateTest
     * Tests the business::Date class.
     */
    class DateTest : public CppUnit::TestFixture
    {
        CPPUNIT_TEST_SUITE(tests::DateTest);
        CPPUNIT_TEST(testToday);
        CPPUNIT_TEST(testInvalidDate);
        CPPUNIT_TEST(testComparisons);
        CPPUNIT_TEST(testEquality);
        CPPUNIT_TEST(testLeapYear);
        CPPUNIT_TEST(testWeekday);
        CPPUNIT_TEST_SUITE_END();
    
    public:
    
        /*!
         * Constructor.
         */
        DateTest();

        /*!
         * Virtual destructor.
         */
        virtual ~DateTest();
    
        /*!
         * Called by CppUnit before each test.
         */
        void setUp();

        /*!
         * Called by CppUnit after each test.
         */
        void tearDown();
        
        /*!
         * Tests the creation of a date with today's values.
         */
        void testToday();
        
        /*!
         * Tests the creation of invalid dates.
         */
        void testInvalidDate();
        
        /*!
         * Tests the comparison operators defined in the business::Date class.
         */
        void testComparisons();
        
        /*!
         * Tests the equality operator and the copy constructor.
         */
        void testEquality();
        
        /*!
         * Tests the business::Date::isLeapYear() method.
         */
        void testLeapYear();
        
        /*!
         * Tests the business::Date::getWeekday() method.
         */
        void testWeekday();
    };
}

CPPUNIT_TEST_SUITE_REGISTRATION(tests::DateTest);

#endif /*DATETEST_H_*/
