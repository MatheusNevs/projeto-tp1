#include "../../include/domains/money.hpp"

/**
 * @brief Valida um valor monetário, verificando se está dentro do intervalo aceitável.
 *
 * @param value Uma string representando o valor monetário que deve ser validado.
 * @return Retorna `true` se o valor for válido (entre 0 e 200.000), e `false` caso contrário.
 */

void Money::validate(string value)
{
    float quantity = stof(value);
    if (quantity < moneyMin || quantity > moneyMax)
    {
        throw invalid_argument("Argumento invalido.");
    }
}
