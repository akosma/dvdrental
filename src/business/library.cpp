/*!
 *  Group 2 DVDRental Project
 *
 *
 */

#include "library.h"

#include <map>
using std::map;

#ifndef DVD_H
#include "dvd.h"
#endif

#ifndef VHS_H
#include "vhs.h"
#endif

#ifndef ITEM_H
#include "item.h"
#endif

const std::string Library::FILE_NAME = "library.dat";

Library::Library()
: _items (Items())
{
}

Library::~Library()
{
}

void Library::getAvailableItems(Items& availableItems)
{
    Items::reverse_iterator iterator;
    int count = _items.size();
    for(iterator = _items.rbegin(); iterator != _items.rend(); ++iterator)
    {
        Item& item = iterator->second;
        if (!item.isRented())
        {
            availableItems[item.getId()] = item;
        }
    }
}

Item& Library::operator[](const int id)
{
    return _items[id];
}

Item& Library::getItem(const int id)
{
    return _items[id];
}

Items& Library::getItems()
{
    return _items;
}

const int Library::addNewItem(Item& item)
{
    int id = item.getId();
    _items[id] = item;
    return id;
}

const int Library::addNewDVD(const std::string& title)
{
    const int id = getMaximumItemId() + 1;
    DVD dvd(id, title);
    return addNewItem(dvd);
}

const int Library::addNewVHS(const std::string& title)
{
    const int id = getMaximumItemId() + 1;
    VHS vhs(id, title);
    return addNewItem(vhs);
}

const bool Library::erase(const int id)
{
    Item& item = _items[id];
    bool result = false;
    if (!item.isRented())
    {
        result = true;
        _items.erase(id);
    }
    return result;
}

const int Library::getMaximumItemId()
{
    int result = -1;
    Items::reverse_iterator iterator;
    for(iterator = _items.rbegin(); iterator != _items.rend(); iterator++)
    {
        Item& item = (*iterator).second;
        int currentId = item.getId();
        if (result < currentId)
        {
            result = currentId;
        }
    }
    return result;
}
