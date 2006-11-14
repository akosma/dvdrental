/*!
 *  Group 2 DVDRental Project
 *
 *  Base class for all business classes. This abstract class contsins the pure virtual 
 *  function getClassName that is used to specify the file name during the serialization process.
 */

#ifndef BASECLASSH
#define BASECLASSH

#include <string>
using namespace std;


class BaseClass
{
public:
	virtual std::string getClassName( ) = 0; 
};

#endif

