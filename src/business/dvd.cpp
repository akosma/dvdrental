/*!
 *  Group 2 DVDRental Project
 *
 *
 */

#include "dvd.h"

const int DVD::ITEM_KIND = 1;

DVD::DVD(const int id, const std::string& title)
: Item(ITEM_KIND, id, title, 2, 3, 2)
{
}

DVD::~DVD()
{
}
