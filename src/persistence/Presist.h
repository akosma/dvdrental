/*header file for the Presist object. 
This object is responsible for presisting and retrieving all the application data to and from files. 
it references the baseClass.h */

#ifndef Presist
#define Presist
#include "baseclass.h"

enum Mode
	{
	load = 1,
	save = 2
	}

class Presist
  {
  public:
    Presist(BaseClass);                // gets the BaseClass without a file open mode.  
    Presist(BaseClass, Mode);          // gets the BaseClass and the mode of operation to be done with it. 
  public:
    ~Presist(void);                    // destructor ensures the file has been closed. 
  private:
    string className;                  //holds the type of the object being presisted. 
  };

#endif