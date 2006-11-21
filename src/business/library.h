/*!
 *  Group 2 DVDRental Project
 *
 *  Declaration for the library class. This contains a vector of all the
 *  items that can be rented out.
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include <map>
using std::map;

#ifndef ITEM_H
#include "item.h"
#endif

#ifndef BASECLASS_H
#include "baseclass.h"
#endif

#ifndef RENTAL_H
#include "rental.h"
#endif

class Library : public BaseClass
{
public:
    Library();
    ~Library();

    Item& operator[](const int id);
    Item& getItem(const int);
    
    Items& getItems();

    //! getAvailableItems fills the passed in vector with items that are available for rental
//    const int getAvailableItems(Items&) const;

    //! Add a new DVD title to the library
	const int addNewDVD(const std::string&);

    //! Add a new VHS title to the library
    const int addNewVHS(const std::string&);
    
    //! Remove an item from the library
    void erase(const int id);
    
    const Rental createRental(const int, const int) const;

public:
    static const std::string FILE_NAME;

private:
    //! Helper used by addNewDVD and addNewVHS
    const int addNewItem(Item& item);
    const int getMaximumItemId();

private:
    //! Map of records in the library
    Items _items;
};

#endif
