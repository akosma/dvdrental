#include "persist.h"
#include <cstdlib>
#include <string> // program uses C++ standard string class
#include <iostream>
#include <fstream> // file stream         
using namespace std;

// private memeber function prototypes. 

bool _saveCustomer(BaseClass *); 
bool _saveItem(BaseClass *); 
bool _saveRental(BaseClass *); 

//-------------------------------------


Persist::Persist (BaseClass * Base)
	{
	_base = Base; 
	}

bool Persist::save()
	{
	if (_base->getClassName() == "Customer")
		return (_saveCustomer(_base)); 
	
	if (_base->getClassName() == "Item")
		return (_saveItem(_base)); 
	
	if (_base->getClassName() == "Rental")
		return (_saveRental(_base)); 
	}

bool _saveCustomer(Customer * _customer)
	{
	int id = _customer->getId(); 
    string lastName = _customer->getLastName( );
    string firstName =_customer->getFirstName( );
    string Address = _customer->getAddress( );
    string Phone = _customer->getPhone( );

	ofstream outCustomer( "customer.dat", ios::out );
	if ( !outCustomer )
		return 0; // throw exception. 

	return (outCustomer << id << " " <<lastName << " " << firstName << " " << Address << " " << Phone << endl);
	}

bool _saveItem(Item * _item)
	{
	int itemId = _item->getId(); 
	string title = _item->getTitle();
	bool isRented = _item->isRented(); 
	
	ofstream outItem( "intem.dat", ios::out );
	if ( !outItem )
		return 0; // throw exception. 

	return (outItem << itemId << " " << title << " " << isRented << endl);
	}


bool _saveRental(Rental * _rental)
	{
	int custId = _rental->getCustomerId();
	Date dueDate = _rental->getDueDate(); 
	Date rentalDate = _rental->getRentalDate();

	ofstream outRental( "rental.dat", ios::out );
	if ( !outRental )
		return 0; // throw exception. 

	return (outRental << custId << " " << dueDate << " " << rentalDate << endl);
	
	}

// Load functions prototypes. 
bool _loadCustomer(); 
bool _loadItem(); 
bool _loadRental(); 
//--------------------------

bool Persist::load (string ClassName)
	{
	if (ClassName == "Customer")
		return _loadCustomer(); 
			
	if (ClassName == "Item")
		return _loadItem(); 

	if (ClassName == "Rental")
		return _loadRental(); 
	}

bool _loadCustomer(Customer * _customer)
	{
	ifstream inCustomer( "customer.dat", ios::in );
	if ( !inCustomer )
		return 0; // throw exception. 
	
	int id; 
	string lastName; 
    string firstName;
    string Address;
    string Phone; 
	
	inCustomer >> id >> lastName >> firstName >> Address >> Phone;
	}