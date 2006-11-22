/*!
 * \file datetest.h
 * Contains the implementation of the DateTest class.
 */

#include "datetest.h"

#include <ctime> // For time manipulation options

#include <sstream>
using std::stringstream;

#ifndef DATE_H_
#include "../business/date.h"
#endif

/*!
 * \namespace tests
 * This namespace holds the classes that derive from CppUnit::TestFixture
 */
namespace tests
{
    /*!
     * Constructor.
     */
    DateTest::DateTest()
    {
    }
    
    /*!
     * Virtual destructor.
     */
    DateTest::~DateTest()
    {
    }
    
    /*!
     * Called by CppUnit before each test.
     */
    void DateTest::setUp()
    {
    }
    
    /*!
     * Called by CppUnit after each test.
     */
    void DateTest::tearDown()
    {
    }
    
    /*!
     * Tests the creation of a date with today's values.
     */
    void DateTest::testToday()
    {
        // basic time manipulation taken from
        // http://www.informit.com/guides/content.asp?g=cplusplus&seqNum=65&rl=1
        std::time_t curr;
        std::tm local;
        time(&curr);
        local = *(std::localtime(&curr));
        
        // get today's information
        int todayYear = local.tm_year + 1900;
        int todayMonth = local.tm_mon + 1;
        int todayDay = local.tm_mday;
    
        // Build a string with today's date using the ISO format
        std::stringstream todayString;
        todayString << todayYear;
        todayString << "-";
        if (todayMonth < 10)
        {
            todayString << "0";
        }
        todayString << todayMonth;
        todayString << "-";
        if (todayDay < 10)
        {
            todayString << "0";
        }
        todayString << todayDay;
        
        // Without parameters, the constructor returns today's date
        Date today;
        CPPUNIT_ASSERT(today.isValid());
        CPPUNIT_ASSERT(today.getDay() == todayDay);
        CPPUNIT_ASSERT(today.getMonth() == todayMonth);
        CPPUNIT_ASSERT(today.getYear() == todayYear);
        CPPUNIT_ASSERT_EQUAL(todayString.str(), today.getStandardString());
        
        // With parameters, with today's information
        Date today2(todayYear, todayMonth, todayDay);
        CPPUNIT_ASSERT(today2.isValid());
        CPPUNIT_ASSERT_EQUAL(todayDay, today2.getDay());
        CPPUNIT_ASSERT_EQUAL(todayMonth, today2.getMonth());
        CPPUNIT_ASSERT_EQUAL(todayYear, today2.getYear());
        CPPUNIT_ASSERT_EQUAL(todayString.str(), today2.getStandardString());
    
        // All should be equal to each other
        CPPUNIT_ASSERT(today == today2);
        CPPUNIT_ASSERT(today2 == today);
    }
    
    /*!
     * Tests the creation of invalid dates.
     */
    void DateTest::testInvalidDate()
    {
        // Years out of bounds
        Date invalid1(1234, 9, 4);
        Date invalid2(28974, 9, 4);
        
        // Wrong month numbers
        Date invalid3(1973, 899, 4);
        
        // Wrong day numbers
        Date invalid4(1973, 9, 423);
    
        // A valid date
        Date valid(1973, 9, 4);
        
        // February in leap and non-leap years
        Date leap(2000, 2, 29);
        Date nonLeap(1999, 2, 29);
        
        CPPUNIT_ASSERT(!invalid1.isValid());
        CPPUNIT_ASSERT(!invalid2.isValid());
        CPPUNIT_ASSERT(invalid3.isValid());
        CPPUNIT_ASSERT_EQUAL(invalid3.getMonth(), 1);
        CPPUNIT_ASSERT(invalid4.isValid());
        CPPUNIT_ASSERT_EQUAL(invalid4.getDay(), 1);
        CPPUNIT_ASSERT(valid.isValid());
        CPPUNIT_ASSERT(leap.isValid());
        CPPUNIT_ASSERT(nonLeap.isValid());
        CPPUNIT_ASSERT_EQUAL(nonLeap.getDay(), 1);
    }
    
    /*!
     * Tests the comparison operators defined in the business::Date class.
     */
    void DateTest::testComparisons()
    {
        // Bigger by some years
        Date date1(1954, 10, 10);
        Date date2(2087, 3, 3);
        
        CPPUNIT_ASSERT(date1.isValid());
        CPPUNIT_ASSERT(date2.isValid());
        CPPUNIT_ASSERT(date1 < date2);
        CPPUNIT_ASSERT(date2 > date1);
        CPPUNIT_ASSERT(date1 <= date2);
        CPPUNIT_ASSERT(date2 >= date1);
        
        // Bigger by some months
        Date date3(1937, 2, 10);
        Date date4(1937, 12, 1);
        
        CPPUNIT_ASSERT(date3.isValid());
        CPPUNIT_ASSERT(date4.isValid());
        CPPUNIT_ASSERT(date3 < date4);
        CPPUNIT_ASSERT(date4 > date3);
        CPPUNIT_ASSERT(date3 <= date4);
        CPPUNIT_ASSERT(date4 >= date3);
        
        // Bigger by some days
        Date date5(1999, 1, 2);
        Date date6(1999, 1, 3);
    
        CPPUNIT_ASSERT(date5.isValid());
        CPPUNIT_ASSERT(date6.isValid());
        CPPUNIT_ASSERT(date5 < date6);
        CPPUNIT_ASSERT(date6 > date5);
        CPPUNIT_ASSERT(date5 <= date6);
        CPPUNIT_ASSERT(date6 >= date5);
    }
    
    /*!
     * Tests the equality operator and the copy constructor.
     */
    void DateTest::testEquality()
    {
        Date date1(1999, 9, 9);
        
        // Use the copy constructor here
        Date date2(date1);
        
        CPPUNIT_ASSERT(date1.isValid());
        CPPUNIT_ASSERT(date2.isValid());
        CPPUNIT_ASSERT(date1 == date2);
        CPPUNIT_ASSERT(date1 >= date2);
        CPPUNIT_ASSERT(date1 <= date2);
        
        // Different by only the year
        Date date3(2000, 9, 9);
        
        CPPUNIT_ASSERT(date3.isValid());
        CPPUNIT_ASSERT(date1 != date3);
        CPPUNIT_ASSERT(date2 != date3);
        CPPUNIT_ASSERT(date3 != date1);
        CPPUNIT_ASSERT(date3 != date2);
    
        // Different by only the month
        Date date4(1999, 10, 9);
        
        CPPUNIT_ASSERT(date4.isValid());
        CPPUNIT_ASSERT(date1 != date4);
        CPPUNIT_ASSERT(date2 != date4);
        CPPUNIT_ASSERT(date4 != date1);
        CPPUNIT_ASSERT(date4 != date2);
    
        // Different by only the day
        Date date5(1999, 9, 10);
        
        CPPUNIT_ASSERT(date5.isValid());
        CPPUNIT_ASSERT(date1 != date5);
        CPPUNIT_ASSERT(date2 != date5);
        CPPUNIT_ASSERT(date5 != date1);
        CPPUNIT_ASSERT(date5 != date2);
    }
    
    /*!
     * Tests the business::Date::isLeapYear() method.
     */
    void DateTest::testLeapYear()
    {
        Date date1(1999, 9, 9);
        Date date2(2000, 9, 9);
        Date date3(1900, 3, 5);
        
        CPPUNIT_ASSERT(date1.isValid());
        CPPUNIT_ASSERT(date2.isValid());
        CPPUNIT_ASSERT(date3.isValid());
        
        CPPUNIT_ASSERT(!date1.isLeapYear());
        CPPUNIT_ASSERT(date2.isLeapYear());
        CPPUNIT_ASSERT(!date3.isLeapYear());
    }
    
    /*!
     * Tests the business::Date::getWeekday() method.
     */
    void DateTest::testWeekday()
    {
        // A famous date
        Date date(1973, 9, 4);
        CPPUNIT_ASSERT(date.isValid());
        CPPUNIT_ASSERT(date.getWeekday() == "Tuesday");
        
        // Today's weekday taken from
        // http://www.cplusplus.com/ref/ctime/mktime.html
        time_t rawtime;
        struct tm* timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        mktime(timeinfo);
        
        std::string weekday[] = { "Sunday", "Monday", "Tuesday", "Wednesday",
                           "Thursday", "Friday", "Saturday"};
                           
        Date today;
        CPPUNIT_ASSERT(today.isValid());    
        CPPUNIT_ASSERT(today.getWeekday() == weekday[timeinfo->tm_wday]);
    }
}
