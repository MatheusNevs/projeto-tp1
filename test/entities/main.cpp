#include "./entityTest.hpp"
#include "../test.hpp"
#include "../../include/domains/code.hpp"
#include "../../include/domains/password.hpp"
#include "../../include/entities/account.hpp"

int main()
{
  try
  {
    // Cria testes individuais
    Account *testAccount1 = new Account(Code("123123"), Password("15243"));
    EntityUnitTest *test1 = new EntityUnitTest("code", new Code("123456"), testAccount1);
    Account *testAccount2 = new Account(Code("123123"), Password("15243"));
    EntityUnitTest *test2 = new EntityUnitTest("code", new Code("626364"), testAccount2);
    Account *testAccount3 = new Account(Code("123123"), Password("15243"));
    EntityUnitTest *test3 = new EntityUnitTest("code", new Code("121314"), testAccount3);

    // Cria um grupo de testes com os testes vinculados diretamente
    GroupTest group("Testes da Entidade Account ", {test1, test2, test3});

    // Executa os testes
    group.runTests();
  }
  catch (exception &e)
  {
    cout << e.what() << endl;
  }

  return 0;
}
