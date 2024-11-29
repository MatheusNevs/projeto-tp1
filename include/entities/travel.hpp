#include "../domains/code.hpp"
#include "../domains/name.hpp"
#include "../domains/date.hpp"
#include "../domains/money.hpp"
#include "../domains/rating.hpp"
#include "./entity.hpp"

/**
 * @class Travel
 * @brief Representa uma viagem, incluindo informações de destino, data de início, data de término e custo.
 *
 * A classe `Travel` encapsula atributos relacionados a uma viagem, incluindo código,
 * nome, data de início, data de término e custo total da viagem.
 */
class Travel : public Entity
{
private:
    Code code;       ///< Código da viagem.
    Name name;       ///< Nome da viagem.
    Date startDate;  ///< Data de início da viagem.
    Date endDate;    ///< Data de término da viagem.
    Money totalCost; ///< Custo total da viagem.
    Rating rating;   ///< Avaliação da viagem.

public:
    /**
     * @brief Construtor da classe `Travel`.
     *
     * Inicializa a viagem com os atributos fornecidos.
     *
     * @param code Código da viagem.
     * @param name Nome da viagem.
     * @param startDate Data de início da viagem.
     * @param endDate Data de término da viagem.
     * @param totalCost Custo total da viagem.
     * @param rating Avaliação da viagem.
     */
    Travel(const Code &code, const Name &name, const Date &startDate, const Date &endDate, const Money &totalCost, const Rating &rating);

    /**
     * @brief Define um valor para uma propriedade da viagem.
     *
     * A propriedade pode ser qualquer um dos atributos da viagem.
     *
     * @param propertyName Nome da propriedade a ser modificada.
     * @param value Novo valor a ser atribuído à propriedade.
     * @throw invalid_argument Caso a propriedade não exista.
     */
    void set(const Domain &value) override;

    /**
     * @brief Retorna o valor de uma propriedade da viagem.
     *
     * A propriedade pode ser qualquer um dos atributos da viagem.
     *
     * @param propertyName Nome da propriedade a ser recuperada.
     * @return const Domain& Valor da propriedade.
     * @throw invalid_argument Caso a propriedade não exista.
     */
    const Domain &get(const string propertyName) const override;
};
