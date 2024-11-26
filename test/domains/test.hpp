#include "../../include/domains/domain.hpp"

// Definições de cores ANSI para saída colorida
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

// Classe que recebe um domínio genérico, um valor válido para
// este domínio e um valor inválido. Testa o setValue do dominio
// recebido com valores validos e invalidos, esperando erro para
// o valor invalido. Verifica se, caso não dê erro, o getValue
// do domínio retorne o valor setado.
class UnitTest
{
private:
  std::string validValue;
  std::string invalidValue;
  Domain *domain;
  bool success;

public:
  UnitTest(const std::string &validValue, const std::string &invalidValue, Domain *domain);
  void test();
  bool getSuccess() const;
  std::string getDescription() const;
};

// Classe que receberá um nome e N UnitTest's que irá rodar os
// testes dos respectivos testes de unidade mostrando no terminal
// os resultados e, em caso de falha de teste, a mensagem da falha.
class GroupTest
{
private:
  std::string name;
  std::vector<UnitTest> tests;

public:
  GroupTest(const std::string &name, const std::vector<UnitTest> &tests);
  void runTests();
};
