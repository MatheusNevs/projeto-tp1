#include "domain.hpp"

class Money : public Domain
{
private:
    static const float moneyMax = 200000.00;

    static const float moneyMin = 0.00;

    bool validate(string) override;

public:
    Money(string value);
};

inline Money::Money(string value) : Domain(value) {}