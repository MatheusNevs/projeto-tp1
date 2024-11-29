#include "../domains/code.hpp"
#include "../domains/name.hpp"
#include "../domains/date.hpp"
#include "../domains/rating.hpp"
#include "./entity.hpp"

/**
 * @class Destination
 * @brief Representa um destino com informações detalhadas.
 *
 * A classe `Destination` encapsula atributos como código, nome, datas de chegada
 * e partida, e uma avaliação do destino. Permite a manipulação e recuperação
 * dessas informações.
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
     * Inicializa um destino com os atributos fornecidos.
     *
     * @param code Código do destino.
     * @param name Nome do destino.
     * @param arrival Data de chegada ao destino.
     * @param departure Data de partida do destino.
     * @param rating Avaliação do destino.
     */
    Destination(const Code &code, const Name &name, const Date &arrival, const Date &departure, const Rating &rating);

    /**
     * @brief Define um valor para uma propriedade do destino.
     *
     * A propriedade pode ser qualquer um dos atributos do destino.
     *
     * @param propertyName Nome da propriedade a ser modificada.
     * @param value Novo valor a ser atribuído à propriedade.
     * @throw invalid_argument Caso a propriedade não exista.
     */
    void set(const Domain &value) override;

    /**
     * @brief Retorna o valor de uma propriedade do destino.
     *
     * A propriedade pode ser qualquer um dos atributos do destino.
     *
     * @param propertyName Nome da propriedade a ser recuperada.
     * @return const string& Valor da propriedade.
     * @throw invalid_argument Caso a propriedade não exista.
     */
    const Domain &get(const string propertyName);
};
