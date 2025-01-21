#include "../../include/services/activity.hpp"

void ActivityModel::create(Code &userCode, Code &activityDestinationCode, Activity &newActivity)
{
  sqlCommand = "SELECT travelCode FROM destination WHERE code = '" + activityDestinationCode.getValue() + "';";
  results.clear();
  this->execute();

  sqlCommand = "SELECT accountCode FROM travel WHERE code = '" + results[0]["travelCode"] + "';";
  results.clear();
  this->execute();

  if (results.empty() || results[0]["accountCode"] != userCode.getValue())
  {
    throw invalid_argument("Destino inexistente ou pertencente a outra conta");
  }

  string activityCode = newActivity.get("code").getValue();
  string activityName = newActivity.get("name").getValue();
  string activityDate = newActivity.get("date").getValue();
  string activityTime = newActivity.get("time").getValue();
  string activityDuration = newActivity.get("duration").getValue();
  string activityPrice = newActivity.get("price").getValue();
  string activityRating = newActivity.get("rating").getValue();

  sqlCommand = "INSERT INTO activity (code, name, date, time, duration, price, rating, destinationCode) VALUES ('" + activityCode + "', '" + activityName + "', '" + activityDate + "', '" + activityTime + "', '" + activityDuration + "', '" + activityPrice + "', '" + activityRating + "', '" + activityDestinationCode.getValue() + "');";
  results.clear();
  this->execute();

  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na criação da atividade");
  }
}

void ActivityModel::update(Code &userCode, Code &activityCode, Activity &updatedActivity)
{
  sqlCommand = "SELECT destinationCode FROM activity WHERE code = '" + activityCode.getValue() + "';";
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
    throw invalid_argument("Atividade inexistente ou pertencente a outra conta");
  }

  string activityName = updatedActivity.get("name").getValue();
  string activityDate = updatedActivity.get("date").getValue();
  string activityTime = updatedActivity.get("time").getValue();
  string activityDuration = updatedActivity.get("duration").getValue();
  string activityPrice = updatedActivity.get("price").getValue();
  string activityRating = updatedActivity.get("rating").getValue();

  sqlCommand = "UPDATE activity SET name = '" + activityName + "', date = '" + activityDate + "', time = '" + activityTime + "', duration = '" + activityDuration + "', price = '" + activityPrice + "', rating = '" + activityRating + "' WHERE code = '" + activityCode.getValue() + "';";
  results.clear();
  this->execute();

  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na atualização da atividade");
  }
}

void ActivityModel::remove(Code &userCode, Code &activityCode)
{
  sqlCommand = "SELECT destinationCode FROM activity WHERE code = '" + activityCode.getValue() + "';";
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
    throw invalid_argument("Atividade inexistente ou pertencente a outra conta");
  }

  sqlCommand = "DELETE FROM activity WHERE code = '" + activityCode.getValue() + "';";
  results.clear();
  this->execute();

  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na remoção da atividade");
  }
}

vector<Activity> ActivityModel::read(Code &userCode)
{
  sqlCommand = "SELECT a.* FROM activity a INNER JOIN destination d ON a.destinationCode = d.code INNER JOIN travel t ON d.travelCode = t.code WHERE t.accountCode = '" + userCode.getValue() + "';";
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