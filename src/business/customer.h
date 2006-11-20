/*!
 *  Group 2 DVDRental Project
 *
 *  This file declares the Customer class which represents an entity that
 *  can hire recordings
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <map>
using std::map;

#include <string>
using std::string;

#ifndef BASECLASS_H
#include "baseclass.h"
#endif

class Customer : public BaseClass
{
public:
    Customer();
    Customer(int id);
    virtual ~Customer();
    Customer(const Customer&);
    Customer& operator=(const Customer&);

    //! Accessors
    int    getId() const;
    const std::string getLastName() const;
    const std::string getFirstName() const;
    const std::string getAddress() const;
    const std::string getPhone() const;

    //! Mutators
    void setLastName(const std::string& lastName);
    void setFirstName(const std::string& firstName);
    void setAddress(const std::string& address);
    void setPhone(const std::string& phone);

public:
    static const std::string FILE_NAME;
    
private:
    int  _id;             //! Unique ID for this customer
    char _lastName[40];       //! Cusomer last name
    char _firstName[40];      //! Customer first name
    char _address[40];        //! Customer address
    char _phone[40];          //! Customer phone
};

typedef std::map<int, Customer> Customers;

#endif
