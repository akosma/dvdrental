/*!
 *  Group 2 DVDRental Project
 *
 *
 */
#ifndef RENTAL_H
#define RENTAL_H

#include <map>
using std::map;

#ifndef DATE_H
#include "date.h"
#endif

#ifndef BASECLASS_H
#include "baseclass.h"
#endif

class Rental : public BaseClass
{
public:
    Rental();
    Rental(const int, const int, const Date&);
    Rental(const Rental&);
    virtual ~Rental();
    Rental& operator=(const Rental&);

    //! Accessors
    const int  getCustomerId() const;
    const int  getItemId() const;
    const Date& getRentalDate() const;
    const Date& getDueDate() const;
    const bool isLate() const;

public:
    static const std::string FILE_NAME;
    
private:
    int  _customerId;   //! Links this rental to a customer
    int  _itemId;       //! Links this rental to an item
    Date _rentalDate;   //! Date rental was taked out
    Date _dueDate;      //! Date recording due to be returned
};

typedef std::map<int, Rental> Rentals;

#endif
