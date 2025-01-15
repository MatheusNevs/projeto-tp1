#include "../../include/services/travel.hpp"

void TravelModel::create(Code userCode, Travel newTravel)
{
  string accountCode = userCode.getValue();
  string travelCode = newTravel.get("code").getValue();
  string travelName = newTravel.get("name").getValue();
  string travelRating = newTravel.get("rating").getValue();
  sqlCommand = "INSERT INTO travel (code, name, rating, accountCode) VALUES ('" + travelCode + "', '" + travelName + "', '" + travelRating + "', '" + accountCode + "');";
  results.clear();
  this->execute();
}

void TravelModel::update(Code userCode, Code travelCode, Travel updatedTravel)
{
  sqlCommand = "SELECT accountCode FROM travel WHERE code = '" + travelCode.getValue() + "';";
  results.clear();
  this->execute();

  if (results.empty() || results[0]["accountCode"] != userCode.getValue())
  {
    status = SQLITE_AUTH;
    return;
  }

  string travelName = updatedTravel.get("name").getValue();
  string travelRating = updatedTravel.get("rating").getValue();

  sqlCommand = "UPDATE travel SET name = '" + travelName + "', rating = '" + travelRating + "' WHERE code = '" + travelCode.getValue() + "';";
  results.clear();
  this->execute();
}

void TravelModel::remove(Code userCode, Code travelCode)
{
  sqlCommand = "SELECT accountCode FROM travel WHERE code = '" + travelCode.getValue() + "';";
  results.clear();
  this->execute();

  if (results.empty() || results[0]["accountCode"] != userCode.getValue())
  {
    status = SQLITE_AUTH;
    return;
  }

  sqlCommand = "DELETE FROM travel WHERE code = '" + travelCode.getValue() + "';";
  results.clear();
  this->execute();
}

vector<Travel> TravelModel::readAll(Code userCode)
{
  sqlCommand = "SELECT * FROM travel WHERE accountCode = '" + userCode.getValue() + "';";
  results.clear();
  this->execute();

  vector<Travel> travels;
  for (size_t i = 0; i < results.size(); i++)
  {
    Code code = Code(results[i]["code"]);
    Name name = Name(results[i]["name"]);
    Rating rating = Rating(results[i]["rating"]);
    Travel travel = Travel(code, name, rating);
    travels.push_back(travel);
  }
  return travels;
}

int TravelModel::consultCost(Code userCode, Code travelCode)
{
  sqlCommand = "SELECT accountCode FROM travel WHERE code = '" + travelCode.getValue() + "';";
  results.clear();
  this->execute();

  if (results.empty() || results[0]["accountCode"] != userCode.getValue())
  {
    status = SQLITE_AUTH;
    return 0;
  }

  sqlCommand = "SELECT SUM(money) FROM (SELECT money FROM activity WHERE destinationCode IN (SELECT code FROM destination WHERE travelCode = '" + travelCode.getValue() + "') UNION ALL SELECT money FROM lodging WHERE destinationCode IN (SELECT code FROM destination WHERE travelCode = '" + travelCode.getValue() + "'));";
  results.clear();
  this->execute();

  if (results.empty() || results[0]["SUM(money)"].empty())
  {
    return 0;
  }

  return stoi(results[0]["SUM(money)"]);
}

vector<Destination> TravelModel::listDestinations(Code userCode, Code travelCode)
{
  sqlCommand = "SELECT accountCode FROM travel WHERE code = '" + travelCode.getValue() + "';";
  results.clear();
  this->execute();

  if (results.empty() || results[0]["accountCode"] != userCode.getValue())
  {
    status = SQLITE_AUTH;
    return {};
  }

  sqlCommand = "SELECT * FROM destination WHERE travelCode = '" + travelCode.getValue() + "';";
  results.clear();
  this->execute();

  vector<Destination> destinations;
  for (size_t i = 0; i < results.size(); i++)
  {
    Code code = Code(results[i]["code"]);
    Name name = Name(results[i]["name"]);
    Date startDate = Date(results[i]["startDate"]);
    Date endDate = Date(results[i]["endDate"]);
    Rating rating = Rating(results[i]["rating"]);
    Destination destination = Destination(code, name, startDate, endDate, rating);
    destinations.push_back(destination);
  }
  return destinations;
}

Destination TravelModel::consultDestination(Code userCode, Code destinationCode)
{
  sqlCommand = "SELECT accountCode FROM destination WHERE code = '" + destinationCode.getValue() + "';";
  results.clear();
  this->execute();

  if (results.empty() || results[0]["accountCode"] != userCode.getValue())
  {
    status = SQLITE_AUTH;
    return Destination(Code("123456"), Name("Joao"), Date("01-01-01"), Date("01-01-01"), Rating("0"));
  }

  sqlCommand = "SELECT * FROM destination WHERE code = '" + destinationCode.getValue() + "';";
  results.clear();
  this->execute();

  if (results.empty())
  {
    return Destination(Code("123456"), Name("Joao"), Date("01-01-01"), Date("01-01-01"), Rating("0"));
  }

  Code code = Code(results[0]["code"]);
  Name name = Name(results[0]["name"]);
  Date startDate = Date(results[0]["startDate"]);
  Date endDate = Date(results[0]["endDate"]);
  Rating rating = Rating(results[0]["rating"]);
  Destination destination = Destination(code, name, startDate, endDate, rating);

  return destination;
}

vector<Lodging> TravelModel::listLodgings(Code userCode, Code destinationCode)
{
  sqlCommand = "SELECT accountCode FROM destination WHERE code = '" + destinationCode.getValue() + "';";
  results.clear();
  this->execute();

  if (results.empty() || results[0]["accountCode"] != userCode.getValue())
  {
    status = SQLITE_AUTH;
    return {};
  }

  sqlCommand = "SELECT * FROM lodging WHERE destinationCode = '" + destinationCode.getValue() + "';";
  results.clear();
  this->execute();

  vector<Lodging> lodgings;
  for (size_t i = 0; i < results.size(); i++)
  {
    Code code = Code(results[i]["code"]);
    Name name = Name(results[i]["name"]);
    Money dailyRate = Money(results[i]["money"]);
    Rating rating = Rating(results[i]["rating"]);
    Lodging lodging = Lodging(code, name, dailyRate, rating);
    lodgings.push_back(lodging);
  }
  return lodgings;
}

vector<Activity> TravelModel::listActivities(Code userCode, Code destinationCode)
{
  sqlCommand = "SELECT accountCode FROM destination WHERE code = '" + destinationCode.getValue() + "';";
  results.clear();
  this->execute();

  if (results.empty() || results[0]["accountCode"] != userCode.getValue())
  {
    status = SQLITE_AUTH;
    return {};
  }

  sqlCommand = "SELECT * FROM activity WHERE destinationCode = '" + destinationCode.getValue() + "';";
  results.clear();
  this->execute();

  vector<Activity> activities;
  for (size_t i = 0; i < results.size(); i++)
  {
    Code code = Code(results[i]["code"]);
    Name name = Name(results[i]["name"]);
    Date date = Date(results[i]["date"]);
    Time time = Time(results[i]["time"]);
    Duration duration = Duration(results[i]["duration"]);
    Money price = Money(results[i]["price"]);
    Rating rating = Rating(results[i]["rating"]);
    Activity activity = Activity(code, name, date, time, duration, price, rating);
    activities.push_back(activity);
  }
  return activities;
}