#include "./domainTest.hpp"
#include "../test.hpp"
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
    DomainUnitTest *test1 = new DomainUnitTest("123459", "1000000000000", new Code("123456"));
    DomainUnitTest *test2 = new DomainUnitTest("654QWE", "12345%", new Code("123456"));
    DomainUnitTest *test3 = new DomainUnitTest("193qwe", "ASDas@", new Code("123456"));

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
    DomainUnitTest *test1 = new DomainUnitTest("12-02-05", "1000-022-55", new Date("01-01-01"));
    DomainUnitTest *test2 = new DomainUnitTest("29-02-04", "12/05/09", new Date("01-01-01"));
    DomainUnitTest *test3 = new DomainUnitTest("31-12-99", "0123456789", new Date("01-01-01"));

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
    DomainUnitTest *test1 = new DomainUnitTest("05", "1000", new Duration("0"));
    DomainUnitTest *test2 = new DomainUnitTest("100", "aabbcc", new Duration("0"));
    DomainUnitTest *test3 = new DomainUnitTest("360", "12a", new Duration("0"));

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
    DomainUnitTest *test1 = new DomainUnitTest("200.000,00", "-5.00", new Money("0.00"));
    DomainUnitTest *test2 = new DomainUnitTest("100.50", "aabbcc", new Money("0.00"));
    DomainUnitTest *test3 = new DomainUnitTest("3600.99", "120.588", new Money("0.00"));

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
    DomainUnitTest *test1 = new DomainUnitTest("aaaaa", "trintaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", new Name("Joao"));
    DomainUnitTest *test2 = new DomainUnitTest("Fernando", "sadfffffffffffffffffffffffffffffffffff", new Name("Joao"));
    DomainUnitTest *test3 = new DomainUnitTest("3¨%$@nnn", "120.5888888888888888888888888888888888", new Name("Joao"));

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
    DomainUnitTest *test1 = new DomainUnitTest("98562", "99586", new Password("02468"));
    DomainUnitTest *test2 = new DomainUnitTest("97681", "34567", new Password("02468"));
    DomainUnitTest *test3 = new DomainUnitTest("79461", "85a97", new Password("02468"));

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
    DomainUnitTest *test1 = new DomainUnitTest("1", "6", new Rating("0"));
    DomainUnitTest *test2 = new DomainUnitTest("3", "-5", new Rating("0"));
    DomainUnitTest *test3 = new DomainUnitTest("5", "A", new Rating("0"));

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
    DomainUnitTest *test1 = new DomainUnitTest("10:40", "1410", new Time("00:00"));
    DomainUnitTest *test2 = new DomainUnitTest("23:59", "-14:05", new Time("00:00"));
    DomainUnitTest *test3 = new DomainUnitTest("12:11", "1A:50", new Time("00:00"));
    DomainUnitTest *test4 = new DomainUnitTest("03:02", "05:60", new Time("00:00"));

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
