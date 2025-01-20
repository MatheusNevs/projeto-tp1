#include "../../include/services/model.hpp"
#include <sys/stat.h>
#include <sys/types.h>

vector<map<string, string>> Model::results;

Model::Model()
{
  int error = 0;

  struct stat info;
  if (stat("./db", &info) != 0 || !(info.st_mode & S_IFDIR))
  {
    mkdir("./db", 0777);
  }

  error = sqlite3_open("./db/dev.db", &db);

  if (error)
  {
    cout << "DB Open Error: " << sqlite3_errmsg(db) << endl;
  }
}

void Model::createAccountTable()
{
  sqlCommand = "CREATE TABLE IF NOT EXISTS account("
               "code VARCHAR(6) PRIMARY KEY,"
               "password VARCHAR(5) NOT NULL);";
  this->execute();
}

void Model::createTravelTable()
{
  sqlCommand = "CREATE TABLE IF NOT EXISTS travel("
               "code VARCHAR(6) PRIMARY KEY,"
               "name VARCHAR(30) NOT NULL,"
               "rating INTEGER(1) CHECK(rating >= 0 AND rating <= 5),"
               "accountCode VARCHAR(6),"
               "FOREIGN KEY(accountCode) REFERENCES account(code));";
  this->execute();
}

void Model::createDestinationTable()
{
  sqlCommand = "CREATE TABLE IF NOT EXISTS destination("
               "code VARCHAR(6) PRIMARY KEY,"
               "name VARCHAR(30) NOT NULL,"
               "arrival VARCHAR(8) NOT NULL,"
               "departure VARCHAR(8) NOT NULL,"
               "rating INTEGER(1) CHECK(rating >= 0 AND rating <= 5),"
               "travelCode VARCHAR(6),"
               "FOREIGN KEY(travelCode) REFERENCES travel(code));";
  this->execute();
}

void Model::createActivityTable()
{
  sqlCommand = "CREATE TABLE IF NOT EXISTS activity("
               "code VARCHAR(6) PRIMARY KEY,"
               "name VARCHAR(30) NOT NULL,"
               "date VARCHAR(8) NOT NULL,"
               "time VARCHAR(5) NOT NULL,"
               "duration INTEGER CHECK(duration >= 0 AND duration <= 360),"
               "price INTEGER CHECK(price >= 0 AND price <= 200000),"
               "rating INTEGER(1) CHECK(rating >= 0 AND rating <= 5),"
               "destinationCode VARCHAR(6),"
               "FOREIGN KEY(destinationCode) REFERENCES destination(code));";
  this->execute();
}

void Model::createLodgingTable()
{
  sqlCommand = "CREATE TABLE IF NOT EXISTS lodging("
               "code VARCHAR(6) PRIMARY KEY,"
               "name VARCHAR(30) NOT NULL,"
               "dailyRate INTEGER CHECK(dailyRate >= 0 AND dailyRate <= 200000),"
               "rating INTEGER(1) CHECK(rating >= 0 AND rating <= 5),"
               "destinationCode VARCHAR(6),"
               "FOREIGN KEY(destinationCode) REFERENCES destination(code));";
  this->execute();
}

void Model::createTables()
{
  createAccountTable();
  createTravelTable();
  createDestinationTable();
  createActivityTable();
  createLodgingTable();
}

Model::~Model()
{
  sqlite3_close(db);
  db = nullptr;
}

void Model::execute()
{
  status = sqlite3_exec(db, sqlCommand.c_str(), callback, nullptr, nullptr);
}

int Model::callback(void *data, int argc, char **argv, char **azColName)
{
  map<string, string> row;
  for (int i = 0; i < argc; i++)
  {
    row[azColName[i]] = argv[i] ? argv[i] : "NULL";
  }
  results.push_back(row);
  return 0;
}
