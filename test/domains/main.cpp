#include "./test.hpp"
#include "../../include/domains/code.hpp"
#include "../../include/domains/date.hpp"
#include "../../include/domains/duration.hpp"
#include "../../include/domains/money.hpp"
#include "../../include/domains/name.hpp"
#include "../../include/domains/password.hpp"
#include "../../include/domains/rating.hpp"
#include "../../include/domains/schedule.hpp"

int main()
{

  // Testes do Code
  try
  {
    // Cria testes individuais
    UnitTest test1("123459", "1000000000000", new Code("123456"));
    UnitTest test2("654QWE", "12345%", new Code("123456"));
    UnitTest test3("193qwe", "ASDas@", new Code("123456"));

    // Cria um grupo de testes com os testes vinculados diretamente
    GroupTest group("Testes do Domínio Código", {test1, test2, test3});

    // Executa os testes
    group.runTests();
  }
  catch (exception &e)
  {
    cout << e.what() << endl;
  }

  // Testes do date
  try
  {
    // Cria testes individuais
    UnitTest test1("12-02-05", "1000-022-55", new Date("01-01-01"));
    UnitTest test2("29-02-04", "12/05/09", new Date("01-01-01"));
    UnitTest test3("31-12-99", "0123456789", new Date("01-01-01"));

    // Cria um grupo de testes com os testes vinculados diretamente
    GroupTest group("Testes do Domínio Data", {test1, test2, test3});

    // Executa os testes
    group.runTests();
  }
  catch (exception &e)
  {
    cout << e.what() << endl;
  }

  // Testes do duration
  try
  {
    // Cria testes individuais
    UnitTest test1("05", "1000", new Duration("0"));
    UnitTest test2("100", "aabbcc", new Duration("0"));
    UnitTest test3("360", "12a", new Duration("0"));

    // Cria um grupo de testes com os testes vinculados diretamente
    GroupTest group("Testes do Domínio Duração", {test1, test2, test3});

    // Executa os testes
    group.runTests();
  }
  catch (exception &e)
  {
    cout << e.what() << endl;
  }

  return 0;
}
