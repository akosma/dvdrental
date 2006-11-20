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

void Persist::createDummyCustomerFile()
{
    // File not found, create dummy file
    Customers customers;
    Customer customer1(0);
    customer1.setFirstName("Robert");
    customer1.setLastName("Smith");
    Customer customer2(1);
    customer2.setFirstName("John");
    customer2.setLastName("Davis");
    customers[0] = customer1;
    customers[1] = customer2;
    saveCustomers(customers);
}
