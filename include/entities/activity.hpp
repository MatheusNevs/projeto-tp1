#include "../domains/code.hpp"
#include "../domains/name.hpp"
#include "../domains/date.hpp"
#include "../domains/duration.hpp"
#include "../domains/money.hpp"
#include "../domains/rating.hpp"

class Activity
{
private:
  Code code;
  Name name;
  Date date;
  Duration time;
  Duration duration;
  Money price;
  Rating rating;

public:
  void setCode(const Code &);
  Code getCode() const;

  void setName(const Name &);
  Name getName() const;

  void setDate(const Date &);
  Date getDate() const;

  void setTime(const Duration &);
  Duration getTime() const;

  void setDuration(const Duration &);
  Duration getDuration() const;

  void setPrice(const Money &);
  Money getPrice() const;

  void setRating(const Rating &);
  Rating getRating() const;
};
