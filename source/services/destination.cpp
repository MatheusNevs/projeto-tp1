#include "../../include/services/destination.hpp"

void DestinationModel::create(Code &userCode, Destination &newDestination)
{
  string accountCode = userCode.getValue();
  string destinationCode = newDestination.get("code").getValue();
  string destinationName = newDestination.get("name").getValue();
  string startDate = newDestination.get("startDate").getValue();
  string endDate = newDestination.get("endDate").getValue();
  string destinationRating = newDestination.get("rating").getValue();

  sqlCommand = "INSERT INTO destination (code, name, startDate, endDate, rating, accountCode) VALUES ('" + destinationCode + "', '" + destinationName + "', '" + startDate + "', '" + endDate + "', '" + destinationRating + "', '" + accountCode + "');";
  results.clear();
  this->execute();

  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na criação do destino");
  }
}

void DestinationModel::update(Code &userCode, Code &destinationCode, Destination &updatedDestination)
{
  sqlCommand = "SELECT accountCode FROM destination WHERE code = '" + destinationCode.getValue() + "';";
  results.clear();
  this->execute();

  if (results.empty() || results[0]["accountCode"] != userCode.getValue())
  {
    throw invalid_argument("Destino inexistente ou pertencente a outra conta");
  }

  string destinationName = updatedDestination.get("name").getValue();
  string startDate = updatedDestination.get("startDate").getValue();
  string endDate = updatedDestination.get("endDate").getValue();
  string destinationRating = updatedDestination.get("rating").getValue();

  sqlCommand = "UPDATE destination SET name = '" + destinationName + "', startDate = '" + startDate + "', endDate = '" + endDate + "', rating = '" + destinationRating + "' WHERE code = '" + destinationCode.getValue() + "';";
  results.clear();
  this->execute();

  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na atualização do destino");
  }
}

void DestinationModel::remove(Code &userCode, Code &destinationCode)
{
  sqlCommand = "SELECT accountCode FROM destination WHERE code = '" + destinationCode.getValue() + "';";
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
  sqlCommand = "SELECT * FROM destination WHERE accountCode = '" + userCode.getValue() + "';";
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
    Date startDate = Date(results[i]["startDate"]);
    Date endDate = Date(results[i]["endDate"]);
    Rating rating = Rating(results[i]["rating"]);
    Destination destination = Destination(code, name, startDate, endDate, rating);
    destinations.push_back(destination);
  }
  return destinations;
}