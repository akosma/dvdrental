#include "persist.h"

#include <iostream>
#include <fstream> // file stream         
using namespace std;

#ifndef CUSTOMER_H
#include "customer.h"
#endif

Customers* Persist::loadCustomers()
{
    Customers* customers = new Customers();
    Customer customer;
    const char* fileName = Customer::FILE_NAME.c_str();

    // Test to see if the file exists...
    std::ifstream test(fileName, std::ios::in);
    if (!test)
    {
        createDummyCustomerFile();
    }
    test.close();
    
    std::ifstream file(fileName, std::ios::in);
    file.read(reinterpret_cast<char*>(&customer), sizeof(Customer));
    while (!file.eof())
    {
        (*customers)[customer.getId()] = customer;
        file.read(reinterpret_cast<char*>(&customer), sizeof(Customer));
    }
    file.close();
    
    return customers;
}

void Persist::saveCustomers(Customers& customers)
{
    Customers::iterator iterator;
    const char* fileName = Customer::FILE_NAME.c_str();

    std::ofstream file(fileName, std::ios::out);
    if (!file)
    {
        std::cerr << "Error while opening " << fileName << std::endl;
        exit(EXIT_FAILURE);
    }

    for (iterator = customers.begin(); iterator != customers.end(); ++iterator)
    {
        Customer customer = (*iterator).second;
        file.write(reinterpret_cast<const char*>(&customer), sizeof(Customer));
    }
    file.close();
}

void Persist::loadItems(Items& library)
{
    Item item;
    const char* fileName = Library::FILE_NAME.c_str();

    // Test to see if the file exists...
    std::ifstream test(fileName, std::ios::in);
    if (!test)
    {
        createDummyLibraryFile();
    }
    test.close();
    
    std::ifstream file(fileName, std::ios::in);
    file.read(reinterpret_cast<char*>(&item), sizeof(Item));
    while (!file.eof())
    {
        library[item.getId()] = item;
        file.read(reinterpret_cast<char*>(&item), sizeof(Item));
    }
    file.close();
}

void Persist::saveItems(Items& library)
{
    Items::iterator iterator;
    const char* fileName = Library::FILE_NAME.c_str();

    std::ofstream file(fileName, std::ios::out);
    if (!file)
    {
        std::cerr << "Error while opening " << fileName << std::endl;
        exit(EXIT_FAILURE);
    }

    for (iterator = library.begin(); iterator != library.end(); ++iterator)
    {
        Item item = (*iterator).second;
        file.write(reinterpret_cast<const char*>(&item), sizeof(Item));
    }
    file.close();
}

void Persist::createDummyLibraryFile()
{
    Library library;
    library.addNewDVD("Brief Encounters of the Third Kind");
    library.addNewDVD("Fellowship of the Ring");
    library.addNewDVD("The Two Towers");
    library.addNewDVD("Return of the King");
    library.addNewDVD("Cronicles of Narnia");
    library.addNewVHS("Thomas the Tank Engine");
    library.addNewVHS("Apollo 13");
    library.addNewVHS("Total Recall");
    saveItems(library.getItems());
}

void Persist::createDummyCustomerFile()
{
    // File not found, create dummy file
    Customers customers;
    Customer customer0(0);
    customer0.setFirstName("Robert");
    customer0.setLastName("Smith");
    customer0.setPhone("(123) 456-7890");
    customer0.setAddress("Guadalajara Ave. 234");
    customers[0] = customer0;

    Customer customer1(1);
    customer1.setFirstName("John");
    customer1.setLastName("Davis");
    customer1.setPhone("(987) 654-3210");
    customer1.setAddress("Palm Beach Boulevard 32");
    customers[1] = customer1;

    Customer customer2(2);
    customer2.setFirstName("Pam");
    customer2.setLastName("Johnson");
    customer2.setPhone("(985) 987-1897");
    customer2.setAddress("Chuleta Street East 242");
    customers[2] = customer2;

    Customer customer3(3);
    customer3.setFirstName("Robert");
    customer3.setLastName("Palmer");
    customer3.setPhone("(987) 322-9875");
    customer3.setAddress("Important Valley Street 267");
    customers[3] = customer3;

    Customer customer4(4);
    customer4.setFirstName("Juan");
    customer4.setLastName("Perez");
    customer4.setPhone("(488) 133-3510");
    customer4.setAddress("Antonio Avenue, 325 East");
    customers[4] = customer4;

    Customer customer5(5);
    customer5.setFirstName("Pedro");
    customer5.setLastName("Gonzales");
    customer5.setPhone("(987) 458-9632");
    customer5.setAddress("");
    customers[5] = customer5;

    Customer customer6(6);
    customer6.setFirstName("Jean");
    customer6.setLastName("Delafontaine");
    customer6.setPhone("(558) 987-5463");
    customer6.setAddress("Rue des Moines East, 35");
    customers[6] = customer6;

    saveCustomers(customers);
}
