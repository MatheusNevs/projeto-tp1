#ifndef DESTINATION_ENTITY_INTERFACE_H
#define DESTINATION_ENTITY_INTERFACE_H

#include "../domains/code.hpp"
#include "../domains/name.hpp"
#include "../domains/date.hpp"
#include "../domains/rating.hpp"
#include "./entity.hpp"

/**
 * @class Destination
 * @brief Representa uma entidade `Destination` composta por um código,
 * nome, data de chegada, data de partida e avaliação.
 *
 * A classe `Destination` encapsula atributos como código, nome, datas de chegada
 * e partida, e uma avaliação do destino. Permite a manipulação e recuperação
 * dessas informações através dos métodos `get` e `set`.
 */
class Destination : public Entity
{
private:
    Code code;      ///< Código do destino.
    Name name;      ///< Nome do destino.
    Date arrival;   ///< Data de chegada ao destino.
    Date departure; ///< Data de partida do destino.
    Rating rating;  ///< Avaliação do destino.

public:
    /**
     * @brief Construtor da classe `Destination`.
     *
     * Inicializa um destino com um código, nome,
     * data de chegada, data de partida e avaliação.
     *
     * @param code Código do destino.
     * @param name Nome do destino.
     * @param arrival Data de chegada ao destino.
     * @param departure Data de partida do destino.
     * @param rating Avaliação do destino.
     */
    Destination(const Code &code, const Name &name, const Date &arrival, const Date &departure, const Rating &rating);

    /**
     * @brief Define um domínio para uma determinada propriedade do destino.
     *
     * A propriedade pode ser o código, nome, data de chegada, data de partida ou avaliação.
     *
     * @param domain Dominio a ser atribuido a sua respectiva propriedade
     * @param propertyName Nome da propriedade a qual dominínio será associado
     * @throw invalid_argument Caso a propriedade não exista.
     */
    void set(const Domain &domain, string propertyName) override;

    /**
     * @brief Retorna o domínio de uma propriedade do destino.
     *
     * A propriedade pode ser código, nome, data de chegada, data
     * de saída ou avaliação.
     *
     * @param propertyName Nome da propriedade a ser retornada.
     * @return const string& Valor da propriedade.
     * @throw invalid_argument Caso a propriedade não exista.
     */
    const Domain &get(const string propertyName) const override;
};

#endif // DESTINATION_ENTITY_INTERFACE_H
