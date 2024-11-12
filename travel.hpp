#include "name.hpp"
#include "rating.hpp"
#include "code.hpp"

using namespace std;

class Travel
{
private:
    Code code;
    Name name;
    Rating rating;

public:
    Travel(const Code &code, Name &name, Rating &rating);

    Code getCode() const;
    void setCode(const Code &);

    Name getName() const;
    void setName(const Name &);

    Rating getRating() const;
    void setRating(const Rating &);
};

inline Code Travel::getCode() const
{
    return code;
}

inline void Code Travel::setCode(const Code &code)
{
    this->code = code;
}

inline Name Travel::getName() const
{
    return name;
}

inline Name Travel::setName(const Name &name)
{
    this->name = name;
}

inline Rating Travel::getRating() const
{
    return rating;
}

inline Rating Travel::setRating(const Rating &rating)
{
    this->rating = rating;
}