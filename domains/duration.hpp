#ifndef DURATION_HPP_INCLUDED
#define DURATION_HPP_INCLUDED

#include "domain.hpp"

/**
 * @class Duration
 * @brief Representa uma duração no intervalo de 0 a 360.
 */
class Duration : public Domain {
    private:
        int duration; /**< Armazena o valor da duração. */

        /**
         * @brief Valida o valor da duração.
         * @param duration O valor a ser validado.
         * @return true se estiver no intervalo permitido, false caso contrário.
         */
        bool validate(int);

    public:
        /**
         * @brief Define o valor da duração, se válido.
         * @param duration O valor a ser atribuído.
         * @return true se atribuído corretamente, false se inválido.
         */
        bool setDuration(int);

        /**
         * @brief Retorna o valor atual da duração.
         * @return O valor da duração.
         */
        int getDuration() const;
};
inline int Duration::getDuration() const {
    return duration;
}

#endif // DURATION_HPP_INCLUDED
