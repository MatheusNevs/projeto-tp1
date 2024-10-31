#include "password.hpp"

/**
 * @brief Método responsável por validar a senha de acordo com os seguintes requisitos:
 *        - Deve conter exatamente 5 dígitos numéricos (0-9).
 *        - Não pode conter dígitos duplicados.
 *        - Não pode estar em ordem consecutiva crescente (ex: 12345).
 *        - Não pode estar em ordem consecutiva decrescente (ex: 54321).
 *
 * @param value A string que representa a senha a ser validada.
 *
 * @throw invalid_argument Lança uma exceção se a senha não cumprir os requisitos.
 */
bool Password::validate(std::string value)
{
    // Verifica se a senha tem exatamente 5 dígitos
    if (value.length() != 5)
    {
        return false;
    }

    // Verifica se todos os caracteres são dígitos
    for (char c : value)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }

    // Verifica se há dígitos duplicados
    std::set<char> digitosUnicos(value.begin(), value.end());
    if (digitosUnicos.size() != 5)
    {
        return false;
    }

    // Verifica se a senha está em ordem consecutiva crescente
    bool isCrescente = true;
    for (size_t i = 1; i < value.size(); ++i)
    {
        if (value[i] != value[i - 1] + 1)
        {
            isCrescente = false;
            break;
        }
    }
    if (isCrescente)
    {
        return false;
    }

    // Verifica se a senha está em ordem consecutiva decrescente
    bool isDecrescente = true;
    for (size_t i = 1; i < value.size(); ++i)
    {
        if (value[i] != value[i - 1] - 1)
        {
            isDecrescente = false;
            break;
        }
    }
    if (isDecrescente)
    {
        return false;

        return true;
    }
}
