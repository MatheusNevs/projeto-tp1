#include "./entityTest.hpp"
#include "../test.hpp"

#include "../../include/domains/code.hpp"
#include "../../include/domains/password.hpp"
#include "../../include/domains/duration.hpp"
#include "../../include/domains/date.hpp"
#include "../../include/domains/money.hpp"
#include "../../include/domains/name.hpp"
#include "../../include/domains/rating.hpp"
#include "../../include/domains/time.hpp"

#include "../../include/entities/account.hpp"
#include "../../include/entities/activity.hpp"
#include "../../include/entities/destination.hpp"
#include "../../include/entities/lodging.hpp"
#include "../../include/entities/travel.hpp"

int main()
{
  try
  {
    // Cria testes individuais para a entidade Account, 1 para cada atributo
    Account *testAccount1 = new Account(Code("123abc"), Password("15243"));
    EntityUnitTest *test1 = new EntityUnitTest("code", new Code("789CBA"), testAccount1);

    Account *testAccount2 = new Account(Code("123abc"), Password("15243"));
    EntityUnitTest *test2 = new EntityUnitTest("password", new Password("13579"), testAccount2);

    // Cria um grupo de testes com os testes vinculados diretamente
    GroupTest group("Testes da Entidade Account ", {test1, test2});

    // Executa os testes
    group.runTests();
  }
  catch (exception &e)
  {
    cout << e.what() << endl;
  }

  try
  {
    // Cria testes individuais para a entidade Activity, 1 para cada atributo
    Activity *testActivity1 = new Activity(Code("123abc"), Name("Joao"), Date("01-01-01"), Time("10:55"), Duration("100"), Money("50.00"), Rating("1"));
    EntityUnitTest *test1 = new EntityUnitTest("code", new Code("789CBA"), testActivity1);

    Activity *testActivity2 = new Activity(Code("123abc"), Name("Joao"), Date("01-01-01"), Time("10:55"), Duration("100"), Money("50.00"), Rating("1"));
    EntityUnitTest *test2 = new EntityUnitTest("name", new Name("Carlos"), testActivity2);

    Activity *testActivity3 = new Activity(Code("123abc"), Name("Joao"), Date("01-01-01"), Time("10:55"), Duration("100"), Money("50.00"), Rating("1"));
    EntityUnitTest *test3 = new EntityUnitTest("date", new Date("01-02-03"), testActivity3);

    Activity *testActivity4 = new Activity(Code("123abc"), Name("Joao"), Date("01-01-01"), Time("10:55"), Duration("100"), Money("50.00"), Rating("1"));
    EntityUnitTest *test4 = new EntityUnitTest("time", new Time("12:00"), testActivity4);

    Activity *testActivity5 = new Activity(Code("123abc"), Name("Joao"), Date("01-01-01"), Time("10:55"), Duration("100"), Money("50.00"), Rating("1"));
    EntityUnitTest *test5 = new EntityUnitTest("duration", new Duration("200"), testActivity5);

    Activity *testActivity6 = new Activity(Code("123abc"), Name("Joao"), Date("01-01-01"), Time("10:55"), Duration("100"), Money("50.00"), Rating("1"));
    EntityUnitTest *test6 = new EntityUnitTest("price", new Money("2.000,00"), testActivity6);

    Activity *testActivity7 = new Activity(Code("123abc"), Name("Joao"), Date("01-01-01"), Time("10:55"), Duration("100"), Money("50.00"), Rating("1"));
    EntityUnitTest *test7 = new EntityUnitTest("rating", new Rating("5"), testActivity7);

    // Cria um grupo de testes com os testes vinculados diretamente
    GroupTest group("Testes da Entidade Activity ", {test1, test2, test3, test4, test5, test6, test7});

    // Executa os testes
    group.runTests();
  }
  catch (exception &e)
  {
    cout << e.what() << endl;
  }

  try
  {
    // Cria testes individuais para a entidade Destination, 1 para cada atributo
    Destination *testActivity1 = new Destination(Code("123abc"), Name("Joao"), Date("01-01-01"), Date("02-01-01"), Rating("1"));
    EntityUnitTest *test1 = new EntityUnitTest("code", new Code("789CBA"), testActivity1);

    Destination *testActivity2 = new Destination(Code("123abc"), Name("Joao"), Date("01-01-01"), Date("02-01-01"), Rating("1"));
    EntityUnitTest *test2 = new EntityUnitTest("name", new Name("Carlos"), testActivity2);

    Destination *testActivity3 = new Destination(Code("123abc"), Name("Joao"), Date("01-01-01"), Date("02-01-01"), Rating("1"));
    EntityUnitTest *test3 = new EntityUnitTest("arrival", new Date("01-02-03"), testActivity3);

    Destination *testActivity4 = new Destination(Code("123abc"), Name("Joao"), Date("01-01-01"), Date("02-01-01"), Rating("1"));
    EntityUnitTest *test4 = new EntityUnitTest("departure", new Date("05-06-12"), testActivity4);

    Destination *testActivity5 = new Destination(Code("123abc"), Name("Joao"), Date("01-01-01"), Date("02-01-01"), Rating("1"));
    EntityUnitTest *test5 = new EntityUnitTest("rating", new Rating("5"), testActivity5);

    // Cria um grupo de testes com os testes vinculados diretamente
    GroupTest group("Testes da Entidade Destination ", {test1, test2, test3, test4, test5});

    // Executa os testes
    group.runTests();
  }
  catch (exception &e)
  {
    cout << e.what() << endl;
  }

  try
  {
    // Cria testes individuais para a entidade Lodging, 1 para cada atributo
    Lodging *testActivity1 = new Lodging(Code("123abc"), Name("Joao"), Money("50.00"), Rating("1"));
    EntityUnitTest *test1 = new EntityUnitTest("code", new Code("789CBA"), testActivity1);

    Lodging *testActivity2 = new Lodging(Code("123abc"), Name("Joao"), Money("50.00"), Rating("1"));
    EntityUnitTest *test2 = new EntityUnitTest("name", new Name("Carlos"), testActivity2);

    Lodging *testActivity3 = new Lodging(Code("123abc"), Name("Joao"), Money("50.00"), Rating("1"));
    EntityUnitTest *test3 = new EntityUnitTest("dailyRate", new Money("2.000,00"), testActivity3);

    Lodging *testActivity4 = new Lodging(Code("123abc"), Name("Joao"), Money("50.00"), Rating("1"));
    EntityUnitTest *test4 = new EntityUnitTest("rating", new Rating("5"), testActivity4);

    // Cria um grupo de testes com os testes vinculados diretamente
    GroupTest group("Testes da Entidade Lodging ", {test1, test2, test3, test4});

    // Executa os testes
    group.runTests();
  }
  catch (exception &e)
  {
    cout << e.what() << endl;
  }

  try
  {
    // Cria testes individuais para a entidade Travel, 1 para cada atributo
    Travel *testActivity1 = new Travel(Code("123abc"), Name("Joao"), Date("01-01-01"), Date("02-01-01"), Money("50.00"), Rating("1"));
    EntityUnitTest *test1 = new EntityUnitTest("code", new Code("789CBA"), testActivity1);

    Travel *testActivity2 = new Travel(Code("123abc"), Name("Joao"), Date("01-01-01"), Date("02-01-01"), Money("50.00"), Rating("1"));
    EntityUnitTest *test2 = new EntityUnitTest("name", new Name("Carlos"), testActivity2);

    Travel *testActivity3 = new Travel(Code("123abc"), Name("Joao"), Date("01-01-01"), Date("02-01-01"), Money("50.00"), Rating("1"));
    EntityUnitTest *test3 = new EntityUnitTest("startDate", new Date("01-02-03"), testActivity3);

    Travel *testActivity4 = new Travel(Code("123abc"), Name("Joao"), Date("01-01-01"), Date("02-01-01"), Money("50.00"), Rating("1"));
    EntityUnitTest *test4 = new EntityUnitTest("endDate", new Date("05-06-12"), testActivity4);

    Travel *testActivity5 = new Travel(Code("123abc"), Name("Joao"), Date("01-01-01"), Date("02-01-01"), Money("50.00"), Rating("1"));
    EntityUnitTest *test5 = new EntityUnitTest("totalCost", new Money("2.000,00"), testActivity5);

    Travel *testActivity6 = new Travel(Code("123abc"), Name("Joao"), Date("01-01-01"), Date("02-01-01"), Money("50.00"), Rating("1"));
    EntityUnitTest *test6 = new EntityUnitTest("rating", new Rating("5"), testActivity6);

    // Cria um grupo de testes com os testes vinculados diretamente
    GroupTest group("Testes da Entidade Travel ", {test1, test2, test3, test4, test5, test6});

    // Executa os testes
    group.runTests();
  }
  catch (exception &e)
  {
    cout << e.what() << endl;
  }

  return 0;
}
