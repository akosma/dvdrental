/*!
 *  Group 2 DVDRental Project
 *
 *
 */

#include "vhs.h"

const int VHS::ITEM_KIND = 0;

VHS::VHS(const int id, const std::string& title)
: Item(ITEM_KIND, id, title, 7, 2, 1)
{
}

VHS::~VHS()
{
}
