#ifndef TRAVEL_HPP
#define TRAVEL_HPP

#include "../domains/code.hpp"
#include "../domains/name.hpp"
#include "../domains/rating.hpp"

/**
 * @class Travel
 * @brief Representa uma viagem com informações básicas.
 *
 * A classe `Travel` encapsula os atributos de uma viagem, incluindo código, nome e avaliação.
 */
class Travel
{
private:
    Code code;     ///< Código da viagem.
    Name name;     ///< Nome da viagem.
    Rating rating; ///< Avaliação da viagem.

public:
    /**
     * @brief Construtor da classe `Travel`.
     *
     * Inicializa a viagem com os atributos fornecidos.
     *
     * @param code Código da viagem.
     * @param name Nome da viagem.
     * @param rating Avaliação da viagem.
     */
    Travel(const Code &code, Name &name, Rating &rating);

    // Métodos getter e setter para cada atributo.

    Code getCode() const;
    void setCode(const Code &code);

    Name getName() const;
    void setName(const Name &name);

    Rating getRating() const;
    void setRating(const Rating &rating);
};

#endif
