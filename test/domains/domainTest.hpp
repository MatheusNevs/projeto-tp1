#include "../../include/domains/domain.hpp"
#include "../test.hpp"

class DomainUnitTest : public UnitTest
{
private:
  Domain *domain; ///< Ponteiro para o domínio a ser testado.

public:
  /**
   * Construtor da classe UnitTest.
   *
   * @param validValue Valor válido para testar o domínio.
   * @param invalidValue Valor inválido para testar o domínio.
   * @param domain Ponteiro para o domínio a ser testado.
   */
  DomainUnitTest(const string &validValue, const string &invalidValue, Domain *domain) : UnitTest(validValue, invalidValue)
  {
    this->domain = domain;
  };

  /**
   * Executa o teste de unidade, testando o setValue e getValue com os valores válidos e inválidos.
   */
  void test() override;

  /**
   * Retorna uma descrição do teste, incluindo o nome do domínio e os valores testados.
   *
   * @return Descrição do teste.
   */
  string getDescription() const override;
};
