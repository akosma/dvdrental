/*header file for the Persist object. 
This object is responsible for presisting and retrieving all the application data to and from files. 
it references the baseClass.h */

#ifndef PERSIST_H
#define PERSIST_H

#include <map>
using std::map;

#ifndef CUSTOMER_H
#include "../business/customer.h"
#endif

#ifndef ITEM_H
#include "../business/item.h"
#endif

#ifndef RENTAL_H
#include "../business/rental.h"
#endif

#ifndef LIBRARY_H
#include "../business/library.h"
#endif

class Persist
{
public:
    static Customers* loadCustomers();
    static void saveCustomers(Customers&);
    static void loadLibrary(Items&);
    static void saveLibrary(Items&);

private:
    static void createDummyCustomerFile();
    static void createDummyLibraryFile();

private:
    Persist();
};

#endif
