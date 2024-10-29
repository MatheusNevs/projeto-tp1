#include "money.hpp"
using namespace std;

/**
 * @class Money
 * @brief Classe que representa operações monetárias, como validação de valores.
 */
class Money
{
public:
    /**
     * @brief Valida um valor monetário, verificando se está dentro do intervalo aceitável.
     *
     * @param value Uma string representando o valor monetário que deve ser validado.
     * @return Retorna `true` se o valor for válido (entre 0 e 200.000), e `false` caso contrário.
     * @exception std::invalid_argument Lança uma exceção se a string não for convertível para float.
     * @exception std::out_of_range Lança uma exceção se o valor estiver fora do intervalo de float.
     */
    bool validate(string value);
};

bool Money::validate(string value)
{
    float quantity = stof(value);
    if (quantity < 0 || quantity > 200000)
    {
        return false;
    }
    return true;
};
