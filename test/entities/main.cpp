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
    Account *testAccount = new Account(Code("123123"), Password("15243"));
    EntityUnitTest *test1 = new EntityUnitTest("code", new Code("123456"), testAccount);
    EntityUnitTest *test2 = new EntityUnitTest("code", new Code("626364"), testAccount);
    EntityUnitTest *test3 = new EntityUnitTest("code", new Code("121314"), testAccount);

    // Cria um grupo de testes com os testes vinculados diretamente
    GroupTest group("Testes do Domínio ", {test1, test2, test3});

    // Executa os testes
    group.runTests();
  }
  catch (exception &e)
  {
    cout << e.what() << endl;
  }

  return 0;
}
