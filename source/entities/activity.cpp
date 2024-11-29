#include "../../include/entities/activity.hpp"
#include <typeinfo> // Necessário para typeid()

Activity::Activity(const Code &code, const Name &name, const Date &date, const Duration &time, const Duration &duration, const Money &price, const Rating &rating)
    : code(code), name(name), date(date), time(time), duration(duration), price(price), rating(rating) {}

void Activity::set(const Domain &domain)
{
  if (typeid(domain) == typeid(Code))
  {
    this->code = static_cast<const Code &>(domain);
  }
  else if (typeid(domain) == typeid(Name))
  {
    this->name = static_cast<const Name &>(domain);
  }
  else if (typeid(domain) == typeid(Date))
  {
    this->date = static_cast<const Date &>(domain);
  }
  else if (typeid(domain) == typeid(Duration))
  {
    this->time = static_cast<const Duration &>(domain);
    this->duration = static_cast<const Duration &>(domain);
  }
  else if (typeid(domain) == typeid(Money))
  {
    this->price = static_cast<const Money &>(domain);
  }
  else if (typeid(domain) == typeid(Rating))
  {
    this->rating = static_cast<const Rating &>(domain);
  }
  else
  {
    throw invalid_argument("Tipo desconhecido para o domínio fornecido");
  }
}

const Domain &Activity::get(const string propertyName) const
{
  if (propertyName == "code")
  {
    return this->code;
  }
  else if (propertyName == "name")
  {
    return this->name;
  }
  else if (propertyName == "date")
  {
    return this->date;
  }
  else if (propertyName == "time")
  {
    return this->time;
  }
  else if (propertyName == "duration")
  {
    return this->duration;
  }
  else if (propertyName == "price")
  {
    return this->price;
  }
  else if (propertyName == "rating")
  {
    return this->rating;
  }
  else
  {
    throw invalid_argument("Propriedade desconhecida");
  }
}
