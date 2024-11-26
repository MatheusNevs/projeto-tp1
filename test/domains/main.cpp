#include "./test.hpp"
#include "../../include/domains/code.hpp"

int main()
{
  try
  {
    // Cria testes individuais
    UnitTest test1("123459", "1000000000000", new Code("123456"));
    UnitTest test2("654QWE8", "12345%", new Code("123456"));
    UnitTest test3("123qwe8", "ASDas@", new Code("123456"));

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
