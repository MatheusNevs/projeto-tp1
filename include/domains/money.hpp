#include "./domain.hpp"

class Money : public Domain
{
private:
    static const float moneyMax = 200000.00;

    static const float moneyMin = 0.00;

    void validate(string) override;

public:
    Money(string value);
};

inline Money::Money(string value)
{
    this->setValue(value);
}