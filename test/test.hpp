#ifndef UNIT_TEST_INTERFACE_H
#define UNIT_TEST_INTERFACE_H

#include <bits/stdc++.h>
using namespace std;

// Definições de cores ANSI para saída colorida
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

/**
 * @class UnitTest
 * @brief Representa uma classe abstrata para criação de testes de unidade.
 *
 * A classe `UnitTest` representa uma classe abstrata de testes de unidade tanto para
 * criação para domínios quanto para entidades.
 */
class UnitTest
{
protected:
  bool success = true; ///< Indica se o teste foi bem-sucedido.

public:
  /**
   * Executa o teste de unidade, dependendo da implementação da classe a ser herdada por esta.
   */
  virtual void test() = 0;

  /**
   * Retorna uma descrição do teste, dependendo da implementação da classe a ser herdada por esta.
   *
   * @return Descrição do teste.
   */
  virtual string getDescription() const = 0;

  /**
   * Retorna o resultado do teste, indicando se foi bem-sucedido.
   *
   * @return true se o teste foi bem-sucedido, false caso contrário.
   */
  bool getSuccess() const;
};

/**
 * @class GroupTest
 * @brief Representa uma classe de grupo de testes de unidade.
 *
 * A classe `UnitTest` representa uma classe de grupo de testes de unidade
 * que agrupa vários testes de unidade e proporciona um log dos resultados
 * dos testes após serem executados.
 */
class GroupTest
{
private:
  string name;              ///< Nome do grupo de testes.
  vector<UnitTest *> tests; ///< Lista de testes de unidade a serem executados.

public:
  /**
   * Construtor da classe GroupTest.
   *
   * @param name Nome do grupo de testes.
   * @param tests Lista de testes de unidade a serem executados no grupo.
   */
  GroupTest(const string &name, const vector<UnitTest *> &tests);

  /**
   * Executa todos os testes de unidade do grupo e exibe os resultados no terminal.
   * Se algum teste falhar, a mensagem de falha será mostrada.
   */
  void runTests();
};

#endif // UNIT_TEST_INTERFACE_H