#include "duration.hpp"

/**
 * @brief Valida se o valor fornecido para a duração está no intervalo permitido.
 *
 * Este método verifica se o valor da duração está entre 0 e 360.
 * 
 * @param duration O valor da duração a ser validado.
 * @return true se o valor estiver entre 0 e 360, false caso contrário.
 */
bool Duration::validate(int duration) {
    if (duration < 0 || duration > 360) {
        return false;
    }
    return true;
}

/**
 * @brief Define o valor da duração, se for válido.
 *
 * Este método utiliza a função de validação para verificar se o valor
 * fornecido está no intervalo permitido antes de atribuí-lo à variável duration.
 * 
 * @param duration O valor a ser atribuído.
 * @return true se o valor foi atribuído corretamente, false se ele for inválido.
 */
bool Duration::setDuration(int duration) {
    if (!validate(duration)) {
        return false;
    }
    this->duration = duration;
    return true;
}
