#include "../domains/code.hpp"
#include "../domains/name.hpp"
#include "../domains/date.hpp"
#include "../domains/duration.hpp"
#include "../domains/money.hpp"
#include "../domains/rating.hpp"

/**
 * @class Activity
 * @brief Representa uma atividade com atributos específicos.
 * 
 * A classe `Activity` encapsula informações sobre uma atividade, como código,
 * nome, data, duração, preço e avaliação.
 */
class Activity
{
private:
    Code code; ///< Código da atividade.
    Name name; ///< Nome da atividade.
    Date date; ///< Data da atividade.
    Duration time; ///< Hora de início da atividade.
    Duration duration; ///< Duração da atividade.
    Money price; ///< Preço da atividade.
    Rating rating; ///< Avaliação da atividade.

public:
    // Métodos getter e setter para cada atributo.

    void setCode(const Code &code);
    Code getCode() const;

    void setName(const Name &name);
    Name getName() const;

    void setDate(const Date &date);
    Date getDate() const;

    void setTime(const Duration &time);
    Duration getTime() const;

    void setDuration(const Duration &duration);
    Duration getDuration() const;

    void setPrice(const Money &price);
    Money getPrice() const;

    void setRating(const Rating &rating);
    Rating getRating() const;
};
