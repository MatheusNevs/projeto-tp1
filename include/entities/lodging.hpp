#ifndef LODGING_HPP
#define LODGING_HPP

#include "../domains/code.hpp"
#include "../domains/name.hpp"
#include "../domains/money.hpp"
#include "../domains/rating.hpp"

/**
 * @class Lodging
 * @brief Representa uma hospedagem com informações de código, nome, diária e avaliação.
 *
 * A classe `Lodging` encapsula atributos relacionados a uma hospedagem.
 */
class Lodging
{
private:
    Code code;       ///< Código da hospedagem.
    Name name;       ///< Nome da hospedagem.
    Money dailyRate; ///< Valor da diária da hospedagem.
    Rating rating;   ///< Avaliação da hospedagem.

public:
    /**
     * @brief Construtor da classe `Lodging`.
     *
     * Inicializa a hospedagem com os atributos fornecidos.
     *
     * @param code Código da hospedagem.
     * @param name Nome da hospedagem.
     * @param dailyRate Valor da diária.
     * @param rating Avaliação da hospedagem.
     */
    Lodging(const Code &code, const Name &name, const Money &dailyRate, const Rating &rating);

    // Métodos getter e setter para cada atributo.

    Code getCode() const;
    void setCode(const Code &code);

    Name getName() const;
    void setName(const Name &name);

    Money getDailyRate() const;
    void setDailyRate(const Money &dailyRate);

    Rating getRating() const;
    void setRating(const Rating &rating);
};

#endif
