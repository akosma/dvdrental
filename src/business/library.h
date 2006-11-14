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
    
	virtual const string getClassName( ) const;

	void addNewDVD(const std::string&);
    void addNewVHS(const std::string&);

private:
    void addNewItem(Item& item);

private:
    vector<Item> _items;
};

#endif
