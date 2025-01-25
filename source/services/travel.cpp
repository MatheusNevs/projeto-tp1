#include "../../include/services/travel.hpp"

void TravelModel::create(Code &userCode, Travel &newTravel)
{
  string accountCode = userCode.getValue();
  string travelCode = newTravel.get("code").getValue();
  string travelName = newTravel.get("name").getValue();
  string travelRating = newTravel.get("rating").getValue();
  sqlCommand = "INSERT INTO travel (code, name, rating, accountCode) VALUES ('" + travelCode + "', '" + travelName + "', '" + travelRating + "', '" + accountCode + "');";
  results.clear();
  this->execute();
  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na criação da viagem");
  }
}

void TravelModel::update(Code &userCode, Code &travelCode, Travel &updatedTravel)
{
  sqlCommand = "SELECT accountCode FROM travel WHERE code = '" + travelCode.getValue() + "';";
  results.clear();
  this->execute();

  if (results.empty() || results[0]["accountCode"] != userCode.getValue())
  {
    throw invalid_argument("Viagem inexistente ou pertencente a outra conta");
  }

  string travelName = updatedTravel.get("name").getValue();
  string travelRating = updatedTravel.get("rating").getValue();

  sqlCommand = "UPDATE travel SET name = '" + travelName + "', rating = '" + travelRating + "' WHERE code = '" + travelCode.getValue() + "';";
  results.clear();
  this->execute();
  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na atualização da viagem");
  }
}

void TravelModel::remove(Code &userCode, Code &travelCode)
{
  sqlCommand = "SELECT accountCode FROM travel WHERE code = '" + travelCode.getValue() + "';";
  results.clear();
  this->execute();

  if (results.empty() || results[0]["accountCode"] != userCode.getValue())
  {
    throw invalid_argument("Viagem inexistente ou pertencente a outra conta");
  }

  sqlCommand = "DELETE FROM travel WHERE code = '" + travelCode.getValue() + "';";
  results.clear();
  this->execute();
  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na remoção da viagem");
  }
}

vector<Travel> TravelModel::readAll(Code &userCode)
{
  sqlCommand = "SELECT * FROM travel WHERE accountCode = '" + userCode.getValue() + "';";
  results.clear();
  this->execute();

  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na leitura das viagens");
  }

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

int TravelModel::consultCost(Code &userCode, Code &travelCode)
{
  sqlCommand = "SELECT accountCode FROM travel WHERE code = '" + travelCode.getValue() + "';";
  results.clear();
  this->execute();

  if (results.empty() || results[0]["accountCode"] != userCode.getValue())
  {
    throw invalid_argument("Viagem inexistente ou pertencente a outra conta");
  }

  sqlCommand = "SELECT SUM(price) AS totalActivityCost FROM activity WHERE destinationCode IN (SELECT code FROM destination WHERE travelCode = '" + travelCode.getValue() + "');";
  results.clear();
  this->execute();

  int totalActivityCost = 0;
  if (status == SQLITE_OK && !results.empty() && results[0]["totalActivityCost"] != "NULL")
  {
    totalActivityCost = stoi(results[0]["totalActivityCost"]);
  }

  sqlCommand = "SELECT dailyRate, arrival, departure FROM lodging INNER JOIN destination ON lodging.destinationCode = destination.code WHERE destination.travelCode = '" + travelCode.getValue() + "';";
  results.clear();
  this->execute();

  int totalLodgingCost = 0;
  if (status == SQLITE_OK && !results.empty())
  {
    for (size_t i = 0; i < results.size(); i++)
    {
      int dailyRate = stoi(results[i]["dailyRate"]);
      Date arrival = Date(results[i]["arrival"]);
      Date departure = Date(results[i]["departure"]);
      int days = Date::calculateDateRange(arrival.getValue(), departure.getValue());
      totalLodgingCost += dailyRate * days;
    }
  }

  return totalActivityCost + totalLodgingCost;
}

vector<Destination> TravelModel::listDestinations(Code &userCode, Code &travelCode)
{
  sqlCommand = "SELECT accountCode FROM travel WHERE code = '" + travelCode.getValue() + "';";
  results.clear();
  this->execute();

  if (results.empty() || results[0]["accountCode"] != userCode.getValue())
  {
    throw invalid_argument("Viagem inexistente ou pertencente a outra conta");
  }

  sqlCommand = "SELECT * FROM destination WHERE travelCode = '" + travelCode.getValue() + "';";
  results.clear();
  this->execute();

  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na listagem de destinos");
  }

  vector<Destination> destinations;
  for (size_t i = 0; i < results.size(); i++)
  {
    Code code = Code(results[i]["code"]);
    Name name = Name(results[i]["name"]);
    Date arrival = Date(results[i]["arrival"]);
    Date departure = Date(results[i]["departure"]);
    Rating rating = Rating(results[i]["rating"]);
    Destination destination = Destination(code, name, arrival, departure, rating);
    destinations.push_back(destination);
  }
  return destinations;
}

Destination TravelModel::consultDestination(Code &userCode, Code &destinationCode)
{
  sqlCommand = "SELECT accountCode FROM destination WHERE code = '" + destinationCode.getValue() + "';";
  results.clear();
  this->execute();

  if (results.empty() || results[0]["accountCode"] != userCode.getValue())
  {
    throw invalid_argument("Viagem inexistente ou pertencente a outra conta");
  }

  sqlCommand = "SELECT * FROM destination WHERE code = '" + destinationCode.getValue() + "';";
  results.clear();
  this->execute();

  if (results.empty())
  {
    throw invalid_argument("Destino não encontrado");
  }

  Code code = Code(results[0]["code"]);
  Name name = Name(results[0]["name"]);
  Date arrival = Date(results[0]["arrival"]);
  Date departure = Date(results[0]["departure"]);
  Rating rating = Rating(results[0]["rating"]);
  Destination destination = Destination(code, name, arrival, departure, rating);

  return destination;
}

vector<Lodging> TravelModel::listLodgings(Code &userCode, Code &destinationCode)
{
  sqlCommand = "SELECT travelCode FROM destination WHERE code = '" + destinationCode.getValue() + "';";
  results.clear();
  this->execute();

  sqlCommand = "SELECT accountCode from travel WHERE code = '" + results[0]["travelCode"] + "';";
  results.clear();
  this->execute();

  if (results.empty() || results[0]["accountCode"] != userCode.getValue())
  {
    throw invalid_argument("Informações sobre viagem inexistente ou pertencente a outra conta");
  }

  sqlCommand = "SELECT * FROM lodging WHERE destinationCode = '" + destinationCode.getValue() + "';";
  results.clear();
  this->execute();

  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na leitura das hospedagens");
  }

  vector<Lodging> lodgings;
  for (size_t i = 0; i < results.size(); i++)
  {
    Code code = Code(results[i]["code"]);
    Name name = Name(results[i]["name"]);
    Money dailyRate = Money(results[i]["dailyRate"]);
    Rating rating = Rating(results[i]["rating"]);
    Lodging lodging = Lodging(code, name, dailyRate, rating);
    lodgings.push_back(lodging);
  }
  return lodgings;
}

vector<Activity> TravelModel::listActivities(Code &userCode, Code &destinationCode)
{
  sqlCommand = "SELECT travelCode FROM destination WHERE code = '" + destinationCode.getValue() + "';";
  results.clear();
  this->execute();

  sqlCommand = "SELECT accountCode from travel WHERE code = '" + results[0]["travelCode"] + "';";
  results.clear();
  this->execute();

  if (results.empty() || results[0]["accountCode"] != userCode.getValue())
  {
    throw invalid_argument("Informações sobre viagem inexistente ou pertencente a outra conta");
  }

  sqlCommand = "SELECT * FROM activity WHERE destinationCode = '" + destinationCode.getValue() + "';";
  results.clear();
  this->execute();

  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na leitura das atividades");
  }

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