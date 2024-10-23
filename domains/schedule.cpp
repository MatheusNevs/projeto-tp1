#include "schedule.hpp"

bool Schedule::validate(string value)
{
  int dividePos = value.find(":");
  if (!dividePos)
    return false;

  string hourString = value.substr(0, dividePos);
  string minutesString = value.substr(dividePos + 1, -1);

  if (hourString.length() != 2 || minutesString.length() != 2)
    return false;

  int hour = stoi(hourString);
  int minutes = stoi(minutesString);

  if (hour < 0 || hour > hourMax || minutes < 0 || minutes > minutesMax)
    return false;

  return true;
}