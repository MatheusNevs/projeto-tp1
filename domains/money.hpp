#ifndef MONEY_INTERFACE_H
#define MONEY_INTERFACE_H

#include "domain.hpp"
using namespace std;

class Money : public Domain
{
private:
    float value;

    float moneyMax = 200000.00;

    float moneyMin = 0.00;

    bool validate(float);

public:
    bool setValue(float);

    float getValue() const;
};

inline float Money::getValue() const
{
    return value;
}

#endif // DOMAIN_INTERFACE_H