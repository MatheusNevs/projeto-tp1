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
 * nome, data, hora de início, duração, preço e avaliação. Permite a manipulação e recuperação
 * dessas informações.
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
    /**
     * @brief Construtor da classe `Activity`.
     * 
     * Inicializa uma atividade com os atributos fornecidos.
     * 
     * @param code Código da atividade.
     * @param name Nome da atividade.
     * @param date Data da atividade.
     * @param time Hora de início da atividade.
     * @param duration Duração da atividade.
     * @param price Preço da atividade.
     * @param rating Avaliação da atividade.
     */
    Activity(const Code &code, const Name &name, const Date &date, const Duration &time, const Duration &duration, const Money &price, const Rating &rating);

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
