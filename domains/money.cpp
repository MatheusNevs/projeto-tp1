#include "money.hpp"
using namespace std;

bool Money::validate(string value)
{
    float quantity = stof(value);
    if (quantity < 0 || quantity > 200000)
    {
        return false;
    }
    return true;
};