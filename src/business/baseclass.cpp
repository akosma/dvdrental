#include "baseclass.h"

BaseClass::BaseClass()
{
}

BaseClass::~BaseClass()
{
}

void BaseClass::setStringField(const std::string& input, char* field)
{
    const char *value = input.data();
    int length = input.size();
    length = (length < 40 ? length : 39);
    strncpy(field, value, length);
    field[length] = '\0'; // append null character
}
