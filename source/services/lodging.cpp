#include "../../include/services/lodging.hpp"

void LodgingModel::create(Code &userCode, Code &lodgingDestinationCode, Lodging &newLodging)
{
  sqlCommand = "SELECT travelCode FROM destination WHERE code = '" + lodgingDestinationCode.getValue() + "';";
  results.clear();
  this->execute();

  sqlCommand = "SELECT accountCode FROM travel WHERE code = '" + results[0]["travelCode"] + "';";
  results.clear();
  this->execute();

  if (results.empty() || results[0]["accountCode"] != userCode.getValue())
  {
    throw invalid_argument("Destino inexistente ou pertencente a outra conta");
  }

  string lodgingCode = newLodging.get("code").getValue();
  string lodgingName = newLodging.get("name").getValue();
  string dailyRate = newLodging.get("dailyRate").getValue();
  string lodgingRating = newLodging.get("rating").getValue();

  sqlCommand = "INSERT INTO lodging (code, name, dailyRate, rating, destinationCode) VALUES ('" + lodgingCode + "', '" + lodgingName + "', '" + dailyRate + "', '" + lodgingRating + "', '" + lodgingDestinationCode.getValue() + "');";
  results.clear();
  this->execute();

  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na criação da hospedagem");
  }
}

void LodgingModel::update(Code &userCode, Code &lodgingCode, Lodging &updatedLodging)
{
  sqlCommand = "SELECT destinationCode FROM lodging WHERE code = '" + lodgingCode.getValue() + "';";
  results.clear();
  this->execute();

  sqlCommand = "SELECT travelCode FROM destination WHERE code = '" + results[0]["destinationCode"] + "';";
  results.clear();
  this->execute();

  sqlCommand = "SELECT accountCode FROM travel WHERE code = '" + results[0]["travelCode"] + "';";
  results.clear();
  this->execute();

  if (results.empty() || results[0]["accountCode"] != userCode.getValue())
  {
    throw invalid_argument("Hospedagem inexistente ou pertencente a outra conta");
  }

  string lodgingName = updatedLodging.get("name").getValue();
  string dailyRate = updatedLodging.get("dailyRate").getValue();
  string lodgingRating = updatedLodging.get("rating").getValue();

  sqlCommand = "UPDATE lodging SET name = '" + lodgingName + "', dailyRate = '" + dailyRate + "', rating = '" + lodgingRating + "' WHERE code = '" + lodgingCode.getValue() + "';";
  results.clear();
  this->execute();

  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na atualização da hospedagem");
  }
}

void LodgingModel::remove(Code &userCode, Code &lodgingCode)
{
  sqlCommand = "SELECT destinationCode FROM lodging WHERE code = '" + lodgingCode.getValue() + "';";
  results.clear();
  this->execute();

  sqlCommand = "SELECT travelCode FROM destination WHERE code = '" + results[0]["destinationCode"] + "';";
  results.clear();
  this->execute();

  sqlCommand = "SELECT accountCode FROM travel WHERE code = '" + results[0]["travelCode"] + "';";
  results.clear();
  this->execute();

  if (results.empty() || results[0]["accountCode"] != userCode.getValue())
  {
    throw invalid_argument("Hospedagem inexistente ou pertencente a outra conta");
  }

  sqlCommand = "DELETE FROM lodging WHERE code = '" + lodgingCode.getValue() + "';";
  results.clear();
  this->execute();

  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na remoção da hospedagem");
  }
}

vector<Lodging> LodgingModel::read(Code &userCode)
{
  sqlCommand = "SELECT l.* FROM lodging l INNER JOIN destination d ON l.destinationCode = d.code INNER JOIN travel t ON d.travelCode = t.code WHERE t.accountCode = '" + userCode.getValue() + "';";
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