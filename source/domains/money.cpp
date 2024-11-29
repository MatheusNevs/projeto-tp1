#include "../../include/domains/money.hpp"

void Money::validate(string value)
{
    float quantity = stof(value);
    if (quantity < moneyMin || quantity > moneyMax)
    {
        throw invalid_argument("Argumento invalido.");
    }
}
