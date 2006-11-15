/*!
 *  Group 2 DVDRental Project
 *
 *  Declaration for the library class. This contains a vector of all the
 *  items that can be rented out.
 */

#ifndef LibraryH
#define LibraryH

#include <vector>
using namespace std;

#include "item.h"
#include "baseclass.h"

class Library
{
public:
    Library();
    ~Library();

    Item& operator[](const int id);
    Item& getItem(const int);

    //! getAvailableItems fills the passed in vector with items that are available for rental
    const int getAvailableItems(vector<Item>&) const;

    //! Used for persistence
	virtual const string getClassName( ) const;

    //! Add a new DVD title to the library
	void addNewDVD(const std::string&);

    //! Add a new VHS title to the library
    void addNewVHS(const std::string&);

private:
    //! Helper used by addNewDVD and addNewVHS
    void addNewItem(Item& item);

private:
    //! Vector of records in the library
    vector<Item> _items;
};

#endif
