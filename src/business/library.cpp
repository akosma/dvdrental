/*!
 *  Group 2 DVDRental Project
 *
 *
 */

#include "library.h"

#ifndef DVD_H
#include "dvd.h"
#endif

#ifndef VHS_H
#include "vhs.h"
#endif

const std::string Library::FILE_NAME = "library.dat";

Library::Library()
: _items (vector<Item>())
{
}

Library::~Library()
{
}

const int Library::getAvailableItems(vector<Item>& availableItems) const
{
    for ( vector<Item>::size_type i = 0; i < _items.size(); i++ )
    {
        Item item = _items[i];

        if (!item.isRented())
        {
            availableItems.push_back(item);
        }
    }

    return availableItems.size();
}

Item& Library::operator[](const int id)
{
    return _items[id];
}

Item& Library::getItem(const int id)
{
    return _items[id];
}

void Library::addNewItem(Item& item)
{
    item.setId(_items.size());
    _items.push_back(item);
}

void Library::addNewDVD(const std::string& title)
{
    DVD dvd(title);
    addNewItem(dvd);
}

void Library::addNewVHS(const std::string& title)
{
    VHS vhs(title);
    addNewItem(vhs);
}
