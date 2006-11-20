/*!
 *  Group 2 DVDRental Project
 *
 *  Declaration for the library class. This contains a vector of all the
 *  items that can be rented out.
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
using namespace std;

#ifndef ITEM_H
#include "item.h"
#endif

#ifndef BASECLASS_H
#include "baseclass.h"
#endif

class Library : public BaseClass
{
public:
    Library();
    ~Library();

    Item& operator[](const int id);
    Item& getItem(const int);

    //! getAvailableItems fills the passed in vector with items that are available for rental
    const int getAvailableItems(vector<Item>&) const;

    //! Add a new DVD title to the library
	void addNewDVD(const std::string&);

    //! Add a new VHS title to the library
    void addNewVHS(const std::string&);

public:
    static const std::string FILE_NAME;

private:
    //! Helper used by addNewDVD and addNewVHS
    void addNewItem(Item& item);

private:
    //! Vector of records in the library
    vector<Item> _items;
};

#endif
