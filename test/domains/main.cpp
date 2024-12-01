#include "./domainTest.hpp"
#include "../test.hpp"
#include "../../include/domains/code.hpp"

int main()
{
  try
  {
    // Cria testes individuais
    DomainUnitTest *test1 = new DomainUnitTest("123459", "1000000000000", new Code("123456"));
    DomainUnitTest *test2 = new DomainUnitTest("654QWE8", "12345%", new Code("123456"));
    DomainUnitTest *test3 = new DomainUnitTest("123qwe8", "ASDas@", new Code("123456"));

    // Cria um grupo de testes com os testes vinculados diretamente
    GroupTest group("Testes do Domínio Code", {test1, test2, test3});

    // Executa os testes
    group.runTests();
  }
  catch (exception &e)
  {
    cout << e.what() << endl;
  }

  return 0;
}
