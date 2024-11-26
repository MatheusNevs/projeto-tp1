#include "./test.hpp"

/**
 * @brief Construtor da classe UnitTest.
 *
 * Inicializa um teste unitário com valores válidos e inválidos, além de receber
 * um ponteiro para um domínio que será testado.
 *
 * @param validValue Valor esperado como válido pelo domínio.
 * @param invalidValue Valor esperado como inválido pelo domínio.
 * @param domain Ponteiro para o objeto do domínio que será testado.
 */
UnitTest::UnitTest(const string &validValue, const string &invalidValue, Domain *domain)
    : validValue(validValue), invalidValue(invalidValue), domain(domain), success(true) {}

/**
 * @brief Executa os testes unitários para o domínio.
 *
 * Este método realiza dois testes principais:
 * - Verifica se o domínio aceita e salva corretamente o valor válido.
 * - Verifica se o domínio rejeita corretamente o valor inválido.
 *
 * @details
 * - Para o valor válido:
 *   - Chama o método `setValue` do domínio.
 *   - Confirma que o valor armazenado com `getValue` corresponde ao valor válido.
 * - Para o valor inválido:
 *   - Chama o método `setValue` do domínio e espera que ele lance uma exceção.
 *
 * @throws Exceções lançadas por `setValue` são tratadas internamente.
 */
void UnitTest::test()
{
  try
  {
    // Testa com valor válido
    domain->setValue(validValue);
    if (domain->getValue() != validValue)
      cout << RED << "Falha: Valor válido '" << validValue << "' não foi salvo.\n"
           << RESET;
  }
  catch (...)
  {
    success = false;
    cout << RED << "Falha: Valor válido '" << validValue << "' gerou erro.\n"
         << RESET;
  }

  try
  {
    // Testa com valor inválido
    domain->setValue(invalidValue);
    success = false;
    cout << RED << "Falha: Valor inválido '" << invalidValue << "' não gerou erro.\n"
         << RESET;
    if (domain->getValue() == invalidValue)
      cout << RED << "Falha: Valor inválido '" << invalidValue << "' foi salvo.\n"
           << RESET;
  }
  catch (...)
  {
    // Comportamento esperado para valor inválido
  }
}

/**
 * @brief Retorna o status do teste unitário.
 *
 * Indica se o teste unitário foi bem-sucedido, considerando tanto o valor válido
 * quanto o valor inválido.
 *
 * @return `true` se o teste foi bem-sucedido, ou `false` caso contrário.
 */
bool UnitTest::getSuccess() const
{
  return success;
}

/**
 * @brief Retorna uma descrição resumida do teste.
 *
 * A descrição inclui os valores válidos e inválidos testados, útil para identificar
 * o que o teste cobre.
 *
 * @return String com a descrição do teste.
 */
string UnitTest::getDescription() const
{
  return "Testando domínio com valor válido '" + validValue + "' e valor inválido '" + invalidValue + "'.";
}

/**
 * @brief Construtor da classe GroupTest.
 *
 * Inicializa um grupo de testes com um nome e uma lista de testes unitários.
 *
 * @param name Nome do grupo de testes.
 * @param tests Vetor de objetos `UnitTest` que pertencem ao grupo.
 */
GroupTest::GroupTest(const string &name, const vector<UnitTest> &tests)
    : name(name), tests(tests) {}

/**
 * @brief Executa todos os testes do grupo.
 *
 * Este método itera sobre todos os testes unitários do grupo, executando-os um a um,
 * e exibe os resultados individualmente e um resumo final.
 *
 * @details
 * - Para cada teste:
 *   - Exibe a descrição do teste.
 *   - Chama o método `test` do objeto `UnitTest`.
 *   - Exibe se o teste foi bem-sucedido ou falhou.
 * - No final:
 *   - Exibe um resumo com o número de testes aprovados e falhados.
 */
void GroupTest::runTests()
{
  cout << "Executando testes no grupo: " << name << "\n";

  size_t passedCount = 0; // Contador de testes aprovados

  for (size_t i = 0; i < tests.size(); ++i)
  {
    cout << "\nTeste " << i + 1 << ": " << tests[i].getDescription() << "\n";
    tests[i].test();

    if (tests[i].getSuccess())
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
