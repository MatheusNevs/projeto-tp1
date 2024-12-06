#ifndef ACTIVITY_ENTITY_INTERFACE_H
#define ACTIVITY_ENTITY_INTERFACE_H

#include "../domains/code.hpp"
#include "../domains/name.hpp"
#include "../domains/date.hpp"
#include "../domains/duration.hpp"
#include "../domains/money.hpp"
#include "../domains/rating.hpp"
#include "./entity.hpp"
#include "../domains/time.hpp"

/**
 * @class Activity
 * @brief Representa uma entidade `Activity` composta por um código,
 * nome, data, horário, duração, preço e avaliação.
 *
 * A classe `Activity` encapsula informações sobre uma Atividade, como código,
 * nome, data, horário, duração, preço e avaliação. Permite a manipulação e retorno
 * dessas informações através dos métodos `get` e `set`.
 */
class Activity : public Entity
{
private:
    Code code;         ///< Código da atividade.
    Name name;         ///< Nome da atividade.
    Date date;         ///< Data da atividade.
    Time time;         ///< Hora de início da atividade.
    Duration duration; ///< Duração da atividade.
    Money price;       ///< Preço da atividade.
    Rating rating;     ///< Avaliação da atividade.

public:
    /**
     * @brief Construtor da classe `Activity`.
     *
     * Inicializa uma atividade com os atributos código,
     * nome, data, horário, duração, preço e avaliação.
     *
     * @param code Código da atividade.
     * @param name Nome da atividade.
     * @param date Data da atividade.
     * @param time Hora de início da atividade.
     * @param duration Duração da atividade.
     * @param price Preço da atividade.
     * @param rating Avaliação da atividade.
     */
    Activity(const Code &code, const Name &name, const Date &date, const Time &time, const Duration &duration, const Money &price, const Rating &rating);

    /**
     * @brief Define um domínio para uma determinada propriedade da atividade.
     *
     * A propriedade pode ser um código, nome, data, horário, duração, preço ou avaliação.
     *
     * @param domain Dominio a ser atribuido a sua respectiva propriedade
     * @param propertyName Nome da propriedade a qual dominínio será associado
     * @throw invalid_argument Caso a propriedade não exista.
     */
    void set(const Domain &domain, string propertyName) override;

    /**
     * @brief Retorna o domínio de uma propriedade da atividade.
     *
     * A propriedade pode ser um código, nome, data, horário, duração, preço ou avaliação.
     *
     * @param propertyName Nome da propriedade a ser retornada.
     * @return const Domain& referência à propriedade retornada.
     * @throw invalid_argument Caso a propriedade não exista.
     */
    const Domain &get(const string propertyName) const override;
};

#endif // ACTIVITY_ENTITY_INTERFACE_H
