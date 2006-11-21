// Exercise 9.8
// Keith Miller
// 19 October 2006

#ifndef DATE_H
#define DATE_H

// Class Date definition
class Date
{
public:
    Date( );     // default constructor
    Date( int d, int m , int y );
    Date(const Date&);
    Date& operator=(const Date&);

    void print();               // Print date in d/m/y format

    void nextDay();             // Increment to next day
    void addDays( int days );   // Add number of days to the date

    /*!
     * Equality operator.
     * 
     * \param rhs The instance to copy from.
     * 
     * \return A boolean.
     */
    const bool operator==(const Date& rhs) const;

    /*!
     * Inequality operator.
     * 
     * \param rhs The instance to copy from.
     * 
     * \return A boolean.
     */
    const bool operator!=(const Date& rhs) const;

    /*!
     * Less-than operator.
     * 
     * \param rhs The instance to copy from.
     * 
     * \return A boolean.
     */
    const bool operator<(const Date& rhs) const;

    /*!
     * Less-or-equal-than operator.
     * 
     * \param rhs The instance to copy from.
     * 
     * \return A boolean.
     */
    const bool operator<=(const Date& rhs) const;

    /*!
     * Bigger-than operator.
     * 
     * \param rhs The instance to copy from.
     * 
     * \return A boolean.
     */
    const bool operator>(const Date& rhs) const;

    /*!
     * Bigger-or-equal-than operator.
     * 
     * \param rhs The instance to copy from.
     * 
     * \return A boolean.
     */
    const bool operator>=(const Date& rhs) const;
    
    /*!
     * Returns an ISO 8601 standard string, representing the 
     * current instance.
     * 
     * \return A string.
     */
    const std::string getStandardString() const;

private:
    int     month;              // Date values
    int     day;
    int     year;

    bool isLeapYear();          // Returns true if a leap year
    int  daysInMonth();         // Returns the number of days in the month
}; // end class Date

#endif
