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
: year  (0)
, month (0)
, day   (0)
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
}

Date::Date(const Date& rhs)
: year  (rhs.year)
, month (rhs.month)
, day   (rhs.day)
{
}

Date& Date::operator=(const Date& rhs)
{
    year = rhs.year;
    month = rhs.month;
    day = rhs.day;
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
}

// Output date as d/m/y
void Date::print()
{
    cout << day << '/' << month << '/' << year;
}

// Increment the date by one day, incrementing month and year when necessary
void Date::nextDay()
{
    if ( day == daysInMonth() ) {
    // We are on the last day of the month, go to next month
        day = 1;

        if ( month == 12) {
        // We have reached the last month of the year, go to next year
            month = 1;
            ++year;
        }
        else {
        // Not end of year so just increment the month
            ++month;
        }
    }
    else {
    // Not end of month so just increment the day
        ++day;
    }
}

// Add number of days to the date
// For the DVDRental project we will only be adding 2 or 7 days to the date so we will use
// a simple loop.
void Date::addDays( int days )
{
    while ( days-- > 0 )
        nextDay( );
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
