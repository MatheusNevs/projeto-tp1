#include "code.hpp"
#include "name.hpp"
#include "money.hpp"
#include "rating.hpp"

using namespace std;

class Lodging
{
private:
    Code code;
    Name name;
    Money dailyRate;
    Rating rating;

public:
    // Construtor
    Lodging(const Code &code, const Name &name, const Money &dailyRate, const Rating &rating);

    // Metodos get e set para cada atributo
    Code getCode() const;
    void setCode(const Code&);

    Name getName() const;
    void setName(const Name&);

    Money getDailyRate() const;
    void setDailyRate(const Money&);

    Rating getRating() const;
    void setRating(const Rating&);
};