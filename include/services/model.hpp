#ifndef MODEL_INTERFACE_H
#define MODEL_INTERFACE_H

#include "../../lib/db/sqlite3.h"
#include <bits/stdc++.h>
using namespace std;

class Model
{
private:
    sqlite3 *db;
    char *mensagem;

    void createAccountTable();
    void createTravelTable();
    void createDestinationTable();
    void createActivityTable();
    void createLodgingTable();
    static int callback(void *notUsed, int argc, char **argv, char **azColName);

protected:
    int status;
    static vector<map<string, string>> results;
    string sqlCommand;

public:
    void createTables();
    void execute();
    Model();
    virtual ~Model();
};

#endif // MODEL_INTERFACE_H