#ifndef ItemH
#define ItemH

#include <string>
using std::string;

class Item
{
public:
    Item( );
    ~Item( );

    virtual int getRentalPeriod( ) const = 0;
    virtual int getRentalCharge( ) const = 0;
    virtual int getLateFee( ) const = 0;
    
    bool isRented( ) const;

    void setRented( bool rented );
    
private:
    int    _id;
    string _title;
    bool   _rented;
};
#endif
