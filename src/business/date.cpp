// Exercise 9.8
// Keith Miller
// 19 October 2006

// Member function definitions for class Date

#include <iostream>
#include <ctime>     // for time manipulation functions

#include <sstream>
using std::stringstream;

using std::cout;
using std::endl;

#include "date.h"

// default constructor
Date::Date( )
: year       (0)
, month      (0)
, day        (0)
, julianDate (0)
{
    // basic time manipulation taken from
    // http://www.informit.com/guides/content.asp?g=cplusplus&seqNum=65&rl=1
    std::time_t curr;
    std::tm local;
    time(&curr);
    local = *(std::localtime(&curr));

    // now build the proper instance
    year = local.tm_year + 1900;
    month = local.tm_mon + 1;
    day = local.tm_mday;

    convertToJulianDate();
}

Date::Date(const Date& rhs)
: year       (rhs.year)
, month      (rhs.month)
, day        (rhs.day)
, julianDate (rhs.julianDate)
{
}

Date& Date::operator=(const Date& rhs)
{
    year = rhs.year;
    month = rhs.month;
    day = rhs.day;
    julianDate = rhs.julianDate;
    return *this;
}

Date::Date( int d, int m, int y ) :
    year( y )
{
    // Test month in range. If invalid set it to 1 and output a message
    if ( ( m >= 1 ) && ( m <= 12 ) ) {
        month = m;      // Set the month as given
    }
    else {
        month = 1;      // Month invalid, default to 1

        cout << "Month must be in the range 1 to 12. Given " << m << endl;
    }

    // Test day in range. If invalid set it to 1 and output a message
    if ( d < 1 ) {
        cout << "Day must be greater than 0" << endl;
    }
    else {
        if ( d <= daysInMonth() ) {
            day = d;    // Set the day as given
        }
        else {
            day = 1;    // Day invalid, default to 1
            cout << "Day " << d << " too large for month " << month <<
                " year " << year << endl;
        }
    }
    convertToJulianDate();
}

// Output date as d/m/y
void Date::print()
{
    cout << day << '/' << month << '/' << year;
}

// Increment the date by one day, incrementing month and year when necessary
void Date::nextDay()
{
    ++julianDate;
    convertFromJulianDate();
}

// Add number of days to the date
void Date::addDays(long days)
{
    julianDate += days;
    convertFromJulianDate();
}

const long Date::getJulianDate() const
{
    return julianDate;
}

// Return true if current year is a leap year
// The year is a leap year if
//   it is divisible by 4 and is not divisible by 100
//   or, it is divisible by 400
bool Date::isLeapYear()
{
    if ( year % 4 != 0 ) {
        return false;
    }
    else {
        if ( year % 100 != 0 ) {
            return true;
        }
        else {
            if ( year % 400 != 0 ) {
                return false;
            }
            else {
                return true;
            }
        }
    }
}

// This function returns the number of days in the current month,
// taking into account leap years
int  Date::daysInMonth()
{
    const short monthDays[ 2 ][ 12 ] =
        { { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
          { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
        };

    return monthDays[ isLeapYear() ? 1 : 0 ][ month - 1 ];
}


/*!
 * Equality operator.
 *
 * \param rhs The instance to copy from.
 *
 * \return A boolean.
 */
const bool Date::operator==(const Date& rhs) const
{
    bool result = (year == rhs.year);
    result = result && (month == rhs.month);
    result = result && (day == rhs.day);
    return result;
}

/*!
 * Inequality operator.
 *
 * \param rhs The instance to copy from.
 *
 * \return A boolean.
 */
const bool Date::operator!=(const Date& rhs) const
{
    bool result = !(*this  == rhs);
    return result;
}

/*!
 * Less-than operator.
 *
 * \param rhs The instance to copy from.
 *
 * \return A boolean.
 */
const bool Date::operator<(const Date& rhs) const
{
    bool smaller = false;
    if (year < rhs.year)
    {
        smaller = true;
    }
    else
    {
        if (year > rhs.year)
        {
            smaller = false;
        }
        else
        {
            // Both years are equal: compare months
            if (month < rhs.month)
            {
                smaller = true;
            }
            else
            {
                if (month > rhs.month)
                {
                    smaller = false;
                }
                else
                {
                    // Both years and months are equal:
                    // compare days
                    if (day < rhs.day)
                    {
                        smaller = true;
                    }
                    else
                    {
                        smaller = false;
                    }
                }
            }
        }
    }
    return smaller;
}

/*!
 * Bigger-than operator.
 *
 * \param rhs The instance to copy from.
 *
 * \return A boolean.
 */
const bool Date::operator>(const Date& rhs) const
{
    bool result = !(*this < rhs) && !(*this == rhs);
    return result;
}

/*!
 * Less-or-equal-than operator.
 *
 * \param rhs The instance to copy from.
 *
 * \return A boolean.
 */
const bool Date::operator<=(const Date& rhs) const
{
    bool result = (*this < rhs) || (*this == rhs);
    return result;
}

/*!
 * Bigger-or-equal-than operator.
 *
 * \param rhs The instance to copy from.
 *
 * \return A boolean.
 */
const bool Date::operator>=(const Date& rhs) const
{
    bool result = (*this > rhs) || (*this == rhs);
    return result;
}

Date& Date::operator+(const long days)
{
    addDays(days);
    return *this;
}

Date& Date::operator-(const long days)
{
    addDays(-days);
    return *this;
}

const long Date::operator-(const Date& rhs)
{
    return julianDate - rhs.julianDate;
}

/*!
 * Returns an ISO 8601 standard string, representing the
 * current instance.
 *
 * \return A string.
 */
const std::string Date::getStandardString() const
{
    // ISO 8601 standard ("YYYY-MM-DD") described here:
    // http://www.cl.cam.ac.uk/~mgk25/iso-time.html
    std::stringstream ss;
    ss << year;
    ss << "-";

    if (month < 10)
    {
        ss << "0";
    }
    ss << month;
    ss << "-";

    if (day < 10)
    {
        ss << "0";
    }
    ss << day;

    return ss.str();
}

// Code for this method borrowed from
// http://www.silverglass.org/code/Date.html
void Date::convertToJulianDate()
{
    long lmonth = (long) month,
    long lday = (long) day;
    long lyear = (long) year;

    // Adjust BC years
    if ( lyear < 0 )
    {
        lyear++;
    }

    julianDate = lday - 32075L +
        1461L * ( lyear + 4800L + ( lmonth - 14L ) / 12L ) / 4L +
        367L * ( lmonth - 2L - ( lmonth - 14L ) / 12L * 12L ) / 12L -
        3L * ( ( lyear + 4900L + ( lmonth - 14L ) / 12L ) / 100L ) / 4L;
}

// Code for this method borrowed from
// http://www.silverglass.org/code/Date.html
void Date::convertFromJulianDate()
{
    long t1, t2, yr, mo;

    t1 = julianDate + 68569L;
    t2 = 4L * t1 / 146097L;
    t1 = t1 - ( 146097L * t2 + 3L ) / 4L;
    yr = 4000L * ( t1 + 1L ) / 1461001L;
    t1 = t1 - 1461L * yr / 4L + 31L;
    mo = 80L * t1 / 2447L;
    day = (int) ( t1 - 2447L * mo / 80L );
    t1 = mo / 11L;
    month = (int) ( mo + 2L - 12L * t1 );
    year = (int) ( 100L * ( t2 - 49L ) + yr + t1 );

    // Correct for BC years
    if ( year <= 0 )
    {
        year -= 1;
    }
}