#include "../../include/domains/name.hpp"


/**
 * @brief Verifica se o nome fornecido é válido.
 *
 * Este método verifica se o comprimento do nome está dentro dos limites aceitáveis.
 * Para ser válido, o nome deve ter entre 1 e 30 caracteres.
 *
 * @param name Nome que será verificado.
 * @return true se o nome é válido (não vazio e com até 30 caracteres), false caso contrário.
 */
void Name::validate(string name)
{
    if (name.length() > 30 || name.empty())
    {
        throw invalid_argument("Argumento invalido.");
    }
}
