#ifndef DURATION_HPP_INCLUDED
#define DURATION_HPP_INCLUDED

#include "domain.hpp"

/**
 * @class Duration
 * @brief Representa um domínio específico para gerenciar valores de duração.
 *
 * A classe Duration é derivada da classe base Domain.
 * Ela é projetada para lidar e validar valores de duração.
 */
class Duration : public Domain {
    private:
        /**
         * @brief Armazena o valor da duração.
         */
        int duration;

        /**
         * @brief Valida o valor de duração fornecido.
         *
         * Este método é uma sobrecarga do método validate na classe base Domain.
         * Ele verifica se a string fornecida pode ser convertida em um valor de duração válido.
         *
         * @param value O valor da duração a ser validado, como uma string.
         * @return True se o valor for válido, false caso contrário.
         */
        bool validate(string value) override;
    
    public:
        /**
         * @brief Construtor da classe Duration.
         *
         * Este construtor inicializa a classe Duration com o valor fornecido.
         * Ele chama o construtor da classe base Domain para definir o valor inicial.
         *
         * @param value O valor inicial da duração como uma string.
         */
        Duration(string value);
};

/**
 * @brief Implementação do construtor inline da classe Duration.
 *
 * Este construtor chama o construtor da classe base Domain para inicializar
 * o valor de duração fornecido.
 *
 * @param value O valor inicial da duração como uma string.
 */
inline Duration::Duration(string value) : Domain(value) {}

#endif // DURATION_HPP_INCLUDED
