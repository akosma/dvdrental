/*!
 *  Group 2 DVDRental Project
 *
 *  Declaration for the VHS class
 */

#ifndef VHS_H
#define VHS_H

#ifndef ITEM_H
#include "item.h"
#endif

class VHS : public Item
{
public:
    VHS(const int, const std::string&);
    virtual ~VHS();

private:
    static const int ITEM_KIND;
};

#endif
