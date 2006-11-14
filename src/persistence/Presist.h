/*header file for the Presist object. 
This object is responsible for presisting and retrieving all the application data to and from files. 
it references the baseClass.h */

#ifndef PERSIST_H
#define PERSIST_H
#include "baseclass.h"

enum Mode
	{
	load = 1,
	save = 2
	}

class Persist
  {
  public:
    Persist(BaseClass);                // gets the BaseClass without a file open mode.  
    Persist(BaseClass, Mode);          // gets the BaseClass and the mode of operation to be done with it. 
    ~Persist(void);                    // destructor ensures the file has been closed. 
    BaseClass load(string className);  // public member function to load class. 
	bool save (BaseClass);             // public member function to save class. 

  private:
    string className;                  //holds the type of the object being presisted. 
	bool _save(BaseClass);             // saves the passed base class. 
	BaseClass _load (string className);// loads the ClassName and returns a reference to it. 
  };

#endif