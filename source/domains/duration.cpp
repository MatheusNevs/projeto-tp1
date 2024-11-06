#include "duration.hpp"

/**
 * @brief Valida o valor da duração fornecido como string.
 *
 * Este método converte o valor de duração de string para inteiro
 * e verifica se está dentro do intervalo permitido (0 a 360).
 *
 * @param value O valor da duração a ser validado, como uma string.
 * @return True se o valor da duração for válido (entre 0 e 360), false caso contrário.
 */
bool Duration::validate(string value)
{
    int duration = stoi(value);
    if (duration < minDuration || duration > maxDuration)
    {
        return false;
    }
    return true;
}
