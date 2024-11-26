#include "../../include/entities/activity.hpp"

void Activity::setCode(const Code &code)
{
  this->code = code;
}

Code Activity::getCode() const
{
  return code;
}

void Activity::setName(const Name &name)
{
  this->name = name;
}

Name Activity::getName() const
{
  return name;
}

void Activity::setDate(const Date &date)
{
  this->date = date;
}

Date Activity::getDate() const
{
  return date;
}

void Activity::setTime(const Duration &time)
{
  this->time = time;
}

Duration Activity::getTime() const
{
  return time;
}

void Activity::setDuration(const Duration &duration)
{
  this->duration = duration;
}

Duration Activity::getDuration() const
{
  return duration;
}

void Activity::setPrice(const Money &price)
{
  this->price = price;
}

Money Activity::getPrice() const
{
  return price;
}

void Activity::setRating(const Rating &rating)
{
  this->rating = rating;
}

Rating Activity::getRating() const
{
  return rating;
}
