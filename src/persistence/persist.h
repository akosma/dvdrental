/*header file for the Persist object. 
This object is responsible for presisting and retrieving all the application data to and from files. 
it references the baseClass.h */

#ifndef PERSIST_H
#define PERSIST_H
#include "baseclass.h"
#include "customer.h"
#include "item.h"
#include "rental.h"


class Persist
	{
  public:
    Persist(BaseClass *); // gets the BaseClass without a file open mode.  
    bool load(BaseClass *); // Saves the class to the relevent file. 

  private:
	BaseClass * _base; 
  };

#endif
