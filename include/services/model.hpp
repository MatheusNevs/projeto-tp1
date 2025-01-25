#ifndef MODEL_INTERFACE_H
#define MODEL_INTERFACE_H

#include <sqlite3.h>
#include <bits/stdc++.h>
using namespace std;

/**
 * @class Model
 * @brief Classe base para a interação com o banco de dados SQLite.
 *
 * A classe Model fornece métodos para criar tabelas e executar comandos SQL.
 */
class Model
{
private:
    sqlite3 *db;

    /**
     * @brief Cria a tabela de contas no banco de dados.
     */
    void createAccountTable();

    /**
     * @brief Cria a tabela de viagens no banco de dados.
     */
    void createTravelTable();

    /**
     * @brief Cria a tabela de destinos no banco de dados.
     */
    void createDestinationTable();

    /**
     * @brief Cria a tabela de atividades no banco de dados.
     */
    void createActivityTable();

    /**
     * @brief Cria a tabela de hospedagens no banco de dados.
     */
    void createLodgingTable();

    /**
     * @brief Callback para processar os resultados das consultas SQL.
     *
     * @param notUsed Parâmetro não utilizado.
     * @param argc Número de colunas no resultado.
     * @param argv Valores das colunas.
     * @param azColName Nomes das colunas.
     * @return 0 se bem-sucedido.
     */
    static int callback(void *notUsed, int argc, char **argv, char **azColName);

protected:
    int status;
    static vector<map<string, string>> results;
    string sqlCommand;

public:
    /**
     * @brief Cria todas as tabelas necessárias no banco de dados.
     */
    void createTables();

    /**
     * @brief Executa o comando SQL armazenado em sqlCommand.
     */
    void execute();

    /**
     * @brief Construtor da classe Model.
     */
    Model();

    /**
     * @brief Destrutor da classe Model.
     */
    virtual ~Model();
};

#endif // MODEL_INTERFACE_H