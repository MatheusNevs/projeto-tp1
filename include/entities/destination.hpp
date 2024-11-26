#include "../domains/code.hpp"
#include "../domains/name.hpp"
#include "../domains/rating.hpp"
#include "../domains/date.hpp"

using namespace std;

/**
 * @class Destination
 * @brief Representa um destino com informações detalhadas.
 * 
 * A classe `Destination` encapsula atributos como código, nome, datas de chegada 
 * e partida, e uma avaliação do destino. Permite a manipulação e recuperação
 * dessas informações.
 */
class Destination
{
private:
    Code code; ///< Código do destino.
    Name name; ///< Nome do destino.
    Date arrival; ///< Data de chegada ao destino.
    Date departure; ///< Data de partida do destino.
    Rating rating; ///< Avaliação do destino.

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

    // Métodos getter e setter para cada atributo.

    void setCode(const Code &code);
    Code getCode() const;

    void setName(const Name &name);
    Name getName() const;

    void setArrival(const Date &arrival);
    Date getArrival() const;

    void setDeparture(const Date &departure);
    Date getDeparture() const;

    void setRating(const Rating &rating);
    Rating getRating() const;
};
