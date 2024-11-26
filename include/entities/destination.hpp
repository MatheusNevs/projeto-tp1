#include "../domains/code.hpp"
#include "../domains/name.hpp"
#include "../domains/rating.hpp"
#include "../domains/date.hpp"

using namespace std;
/**
 * @class Destination
 * @brief Representa um destino com informações de chegada, partida e avaliação.
 * 
 * A classe `Destination` encapsula atributos como código, nome, datas de chegada 
 * e partida, e uma avaliação do destino.
 */
class Destination
{
private:
    Code code; ///< Código do destino.
    Name name; ///< Nome do destino.
    Date arrival; ///< Data de chegada.
    Date departure; ///< Data de partida.
    Rating rating; ///< Avaliação do destino.

public:
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
