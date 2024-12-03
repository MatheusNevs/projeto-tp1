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
    // Cria testes individuais para a entidade Activity, 2 para cada atributo
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

  return 0;
}
