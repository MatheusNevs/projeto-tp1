#include "code.hpp"
#include "name.hpp"
#include "rating.hpp"
#include "date.hpp"

using namespace std;
class Destination {
    private:
        Code code;
        Name name;
        Date arrival;
        Date departure;
        Rating rating;

    public:
        void setCode(const Code&);
        Code getCode() const;

        void setName(const Name&);
        Name getName() const;

        void setArrival(const Date&);
        Date getArrival() const;

        void setDeparture(const Date&);
        Date getDeparture() const;

        void setRating(const Rating&);
        Rating getRating() const;

};