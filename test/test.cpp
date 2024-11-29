#include "./test.hpp"

bool UnitTest::getSuccess() const
{
  return this->success;
}
GroupTest::GroupTest(const string &name, const vector<UnitTest *> &tests)
    : name(name), tests(tests) {}

void GroupTest::runTests()
{
  cout << "Executando testes no grupo: " << name << "\n";

  size_t passedCount = 0; // Contador de testes aprovados

  for (size_t i = 0; i < tests.size(); ++i)
  {
    cout << "\nTeste " << i + 1 << ": " << tests[i]->getDescription() << "\n";
    tests[i]->test();

    if (tests[i]->getSuccess())
    {
      cout << GREEN << "Teste " << i + 1 << " passou.\n"
           << RESET;
      passedCount++;
    }
    else
    {
      cout << RED << "Teste " << i + 1 << " falhou.\n"
           << RESET;
    }
  }

  cout << "\nFim dos testes do grupo: " << name << "\n";

  // Resumo no final
  cout << (passedCount == tests.size() ? GREEN : RED)
       << "Passaram: " << passedCount << " / " << tests.size() << RESET << "\n";
}
