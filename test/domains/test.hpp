#ifndef TEST_HPP 
#define TEST_HPP 

#include "../../include/domains/domain.hpp"

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
private:
  std::string validValue;   ///< Valor válido para testar o domínio.
  std::string invalidValue; ///< Valor inválido para testar o domínio.
  Domain *domain;           ///< Ponteiro para o domínio a ser testado.
  bool success;             ///< Indica se o teste foi bem-sucedido.

public:
  /**
   * Construtor da classe UnitTest.
   * 
   * @param validValue Valor válido para testar o domínio.
   * @param invalidValue Valor inválido para testar o domínio.
   * @param domain Ponteiro para o domínio a ser testado.
   */
  UnitTest(const std::string &validValue, const std::string &invalidValue, Domain *domain);

  /**
   * Executa o teste de unidade, testando o setValue e getValue com os valores válidos e inválidos.
   */
  void test();

  /**
   * Retorna o resultado do teste, indicando se foi bem-sucedido.
   * 
   * @return true se o teste foi bem-sucedido, false caso contrário.
   */
  bool getSuccess() const;

  /**
   * Retorna uma descrição do teste, incluindo o nome do domínio e os valores testados.
   * 
   * @return Descrição do teste.
   */
  std::string getDescription() const;
};

// Classe que representa um grupo de testes de unidade, contendo vários testes de unidade
// e a lógica para executar esses testes, mostrando os resultados e mensagens de falha, se houver.
class GroupTest
{
private:
  std::string name;                ///< Nome do grupo de testes.
  std::vector<UnitTest> tests;      ///< Lista de testes de unidade a serem executados.

public:
  /**
   * Construtor da classe GroupTest.
   * 
   * @param name Nome do grupo de testes.
   * @param tests Lista de testes de unidade a serem executados no grupo.
   */
  GroupTest(const std::string &name, const std::vector<UnitTest> &tests);

  /**
   * Executa todos os testes de unidade do grupo e exibe os resultados no terminal.
   * Se algum teste falhar, a mensagem de falha será mostrada.
   */
  void runTests();
};


#endif
