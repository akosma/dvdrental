#ifndef ItemH
#define ItemH

class Item
{
public:
    Item( );
    ~Item( );

    virtual int getRentalPeriod( ) const;
    virtual int getRentalCharge( ) const;
    virtual int getLateFee( ) const;

    int  getId( ) const;
    char *getTitle( ) const;

    void setId( int id );
    void setTitle( char *title );

    bool isRented( ) const;

    void setRented( bool rented );

private:
    int  _id;
    char *_title;
    bool _rented;
};
#endif