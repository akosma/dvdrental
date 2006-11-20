/*!
 *  Group 2 DVDRental Project
 *
 *  Base class for all business classes. This abstract class contsins the pure virtual 
 *  function getClassName that is used to specify the file name during the serialization process.
 */

#ifndef BASECLASS_H
#define BASECLASS_H

#include <string>
using namespace std;

class BaseClass
{
protected:
    void setStringField(const std::string&, char*);
};

#endif

