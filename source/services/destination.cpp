#include "../../include/services/destination.hpp"

void DestinationModel::create(Code &userCode, Code &destinationTravelCode, Destination &newDestination)
{
  // Verify if the travel code belongs to the same account as the user
  sqlCommand = "SELECT accountCode FROM travel WHERE code = '" + destinationTravelCode.getValue() + "';";
  results.clear();
  this->execute();

  if (results.empty() || results[0]["accountCode"] != userCode.getValue())
  {
    throw invalid_argument("Viagem inexistente ou pertencente a outra conta");
  }

  string accountCode = userCode.getValue();
  string travelCode = destinationTravelCode.getValue();
  string destinationCode = newDestination.get("code").getValue();
  string destinationName = newDestination.get("name").getValue();
  string arrival = newDestination.get("arrival").getValue();
  string departure = newDestination.get("departure").getValue();
  string destinationRating = newDestination.get("rating").getValue();

  sqlCommand = "INSERT INTO destination (code, name, arrival, departure, rating, travelCode) VALUES ('" + destinationCode + "', '" + destinationName + "', '" + arrival + "', '" + departure + "', '" + destinationRating + "', '" + travelCode + "');";
  results.clear();
  this->execute();

  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na criação do destino");
  }
}

void DestinationModel::update(Code &userCode, Code &destinationCode, Destination &updatedDestination)
{
  sqlCommand = "SELECT travelCode FROM destination WHERE code = '" + destinationCode.getValue() + "';";
  results.clear();
  this->execute();

  sqlCommand = "SELECT accountCode FROM travel WHERE code = '" + results[0]["travelCode"] + "';";
  results.clear();
  this->execute();

  if (results.empty() || results[0]["accountCode"] != userCode.getValue())
  {
    throw invalid_argument("Destino inexistente ou pertencente a outra conta");
  }

  string destinationName = updatedDestination.get("name").getValue();
  string arrival = updatedDestination.get("arrival").getValue();
  string departure = updatedDestination.get("departure").getValue();
  string destinationRating = updatedDestination.get("rating").getValue();

  sqlCommand = "UPDATE destination SET name = '" + destinationName + "', arrival = '" + arrival + "', departure = '" + departure + "', rating = '" + destinationRating + "' WHERE code = '" + destinationCode.getValue() + "';";
  results.clear();
  this->execute();

  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na atualização do destino");
  }
}

void DestinationModel::remove(Code &userCode, Code &destinationCode)
{
  sqlCommand = "SELECT travelCode FROM destination WHERE code = '" + destinationCode.getValue() + "';";
  results.clear();
  this->execute();

  sqlCommand = "SELECT accountCode FROM travel WHERE code = '" + results[0]["travelCode"] + "';";
  results.clear();
  this->execute();

  if (results.empty() || results[0]["accountCode"] != userCode.getValue())
  {
    throw invalid_argument("Destino inexistente ou pertencente a outra conta");
  }

  sqlCommand = "DELETE FROM destination WHERE code = '" + destinationCode.getValue() + "';";
  results.clear();
  this->execute();
  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na remoção do destino");
  }
}

vector<Destination> DestinationModel::read(Code &userCode)
{
  sqlCommand = "SELECT d.* FROM destination d INNER JOIN travel t ON d.travelCode = t.code WHERE t.accountCode = '" + userCode.getValue() + "';";
  results.clear();
  this->execute();

  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na leitura dos destinos");
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