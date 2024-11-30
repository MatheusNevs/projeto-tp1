#include "./test.hpp"
#include "../../include/domains/code.hpp"
#include "../../include/domains/date.hpp"
#include "../../include/domains/duration.hpp"
#include "../../include/domains/money.hpp"
#include "../../include/domains/name.hpp"
#include "../../include/domains/password.hpp"
#include "../../include/domains/rating.hpp"
#include "../../include/domains/time.hpp"

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

  // Testes do Duration
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

  // Testes do money
  try
  {
    // Cria testes individuais
    UnitTest test1("200.000,00", "-5.00", new Money("0.00"));
    UnitTest test2("100.50", "aabbcc", new Money("0.00"));
    UnitTest test3("3600.99", "120.588", new Money("0.00"));

    // Cria um grupo de testes com os testes vinculados diretamente
    GroupTest group("Testes do Domínio Dinheiro", {test1, test2, test3});

    // Executa os testes
    group.runTests();
  }
  catch (exception &e)
  {
    cout << e.what() << endl;
  }

  // Testes do Name
  try
  {
    // Cria testes individuais
    UnitTest test1("aaaaa", "trintaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", new Name("Joao"));
    UnitTest test2("Fernando", "sadfffffffffffffffffffffffffffffffffff", new Name("Joao"));
    UnitTest test3("3¨%$@nnn", "120.5888888888888888888888888888888888", new Name("Joao"));

    // Cria um grupo de testes com os testes vinculados diretamente
    GroupTest group("Testes do Domínio Nome", {test1, test2, test3});

    // Executa os testes
    group.runTests();
  }
  catch (exception &e)
  {
    cout << e.what() << endl;
  }

  // Testes do Password
  try
  {
    // Cria testes individuais
    UnitTest test1("98562", "99586", new Password("02468"));
    UnitTest test2("97681", "34567", new Password("02468"));
    UnitTest test3("79461", "85a97", new Password("02468"));

    // Cria um grupo de testes com os testes vinculados diretamente
    GroupTest group("Testes do Domínio Senha", {test1, test2, test3});

    // Executa os testes
    group.runTests();
  }
  catch (exception &e)
  {
    cout << e.what() << endl;
  }

  // Testes do Rating
  try
  {
    // Cria testes individuais
    UnitTest test1("1", "6", new Rating("0"));
    UnitTest test2("3", "-5", new Rating("0"));
    UnitTest test3("5", "A", new Rating("0"));

    // Cria um grupo de testes com os testes vinculados diretamente
    GroupTest group("Testes do Domínio Avaliação", {test1, test2, test3});

    // Executa os testes
    group.runTests();
  }
  catch (exception &e)
  {
    cout << e.what() << endl;
  }

  // Testes do Time
  try
  {
    // Cria testes individuais
    UnitTest test1("10:40", "1410", new Time("00:00"));
    UnitTest test2("23:59", "-14:05", new Time("00:00"));
    UnitTest test3("12:11", "1A:50", new Time("00:00"));
    UnitTest test4("03:02", "05:60", new Time("00:00"));

    // Cria um grupo de testes com os testes vinculados diretamente
    GroupTest group("Testes do Domínio Horário", {test1, test2, test3, test4});

    // Executa os testes
    group.runTests();
  }
  catch (exception &e)
  {
    cout << e.what() << endl;
  }

  return 0;
}
