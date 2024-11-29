#include <bits/stdc++.h>
using namespace std;

// Definições de cores ANSI para saída colorida
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

// Classe que representa um teste de unidade para um domínio específico.
// Esta classe testa o comportamento do método setValue com um valor válido e inválido,
// esperando que o valor inválido cause um erro. Após isso, verifica se o método getValue
// retorna o valor corretamente quando o valor válido é utilizado.
class UnitTest
{
protected:
  string validValue;   ///< Valor válido para testar o domínio.
  string invalidValue; ///< Valor inválido para testar o domínio.
  bool success = true; ///< Indica se o teste foi bem-sucedido.

public:
  /**
   * Executa o teste de unidade, testando o setValue e getValue com os valores válidos e inválidos.
   */
  virtual void test() = 0;

  /**
   * Retorna uma descrição do teste, incluindo o nome do domínio e os valores testados.
   *
   * @return Descrição do teste.
   */
  virtual string getDescription() const = 0;

  /**
   * Retorna o resultado do teste, indicando se foi bem-sucedido.
   *
   * @return true se o teste foi bem-sucedido, false caso contrário.
   */
  bool getSuccess() const
  {
    return this->success;
  };

  UnitTest(string validValue, string invalidValue);
};

// Classe que representa um grupo de testes de unidade, contendo vários testes de unidade
// e a lógica para executar esses testes, mostrando os resultados e mensagens de falha, se houver.
class GroupTest
{
private:
  string name;            ///< Nome do grupo de testes.
  vector<UnitTest> tests; ///< Lista de testes de unidade a serem executados.

public:
  /**
   * Construtor da classe GroupTest.
   *
   * @param name Nome do grupo de testes.
   * @param tests Lista de testes de unidade a serem executados no grupo.
   */
  GroupTest(const string &name, const vector<UnitTest> &tests);

  /**
   * Executa todos os testes de unidade do grupo e exibe os resultados no terminal.
   * Se algum teste falhar, a mensagem de falha será mostrada.
   */
  void runTests();
};