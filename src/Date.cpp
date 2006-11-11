// Exercise 9.8
// Keith Miller
// 19 October 2006

// Member function definitions for class Date

#include <iostream>

using std::cout;
using std::endl;

#include "Date.h"

// default constructor
Date::Date( )
{

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


