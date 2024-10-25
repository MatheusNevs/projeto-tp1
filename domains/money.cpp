#include "money.hpp"
using namespace std;

bool Money::validate(float value)
{
    if (value < 0 || value > 200000)
    {
        return false;
    }
    return true;
}

bool Money::setValue(float value)
{
    if (validate(value) == true)
    {
        this->value = value;
        return true;
    }
    return false;
}