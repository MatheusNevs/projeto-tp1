#include "money.hpp"

/**
 * @brief Valida um valor monetário, verificando se está dentro do intervalo aceitável.
 *
 * @param value Uma string representando o valor monetário que deve ser validado.
 * @return Retorna `true` se o valor for válido (entre 0 e 200.000), e `false` caso contrário.
 */

bool Money::validate(string value)
{
    float quantity = stof(value);
    if (quantity < 0 || quantity > 200000)
    {
        return false;
    }
    return true;
};
