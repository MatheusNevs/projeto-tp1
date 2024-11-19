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