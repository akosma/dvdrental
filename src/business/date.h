// Exercise 9.8
// Keith Miller
// 19 October 2006

#ifndef DateH
#define DateH

// Class Date definition
class Date
{
public:
    Date( );     // default constructor
    Date( int d, int m , int y );

    void print();       // Print date in d/m/y format

    void nextDay();     // Increment to nect day

private:
    int     month;      // Date values
    int     day;
    int     year;

    bool isLeapYear();  // Returns true if a leap year
    int  daysInMonth(); // Returns the number of days in the month
}; // end class Date

#endif
