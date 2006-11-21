/*!
 *  Group 2 DVDRental Project
 *
 *  Declaration for the DVD class.
 */

#ifndef DVD_H
#define DVD_H

#ifndef ITEM_H
#include "item.h"
#endif

#ifndef BASECLASS_H
#include "baseclass.h"
#endif

class DVD : public Item
{
public:
    DVD(const int, const std::string&);
    virtual ~DVD();
    
private:
    static const int ITEM_KIND;
};

#endif
