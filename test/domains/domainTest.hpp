#include "../../include/domains/domain.hpp"
#include "../test.hpp"

/**
 * @class DomainUnitTest
 * @brief Representa uma classe de unidade de teste específico para domínios.
 *
 * A classe `DomainUnitTest` herda diretamente de `UnitTest` usando sua interface
 * e implementado propriedades e formas de test próprios.
 */
class DomainUnitTest : public UnitTest
{
private:
  Domain *domain;      ///< Ponteiro para o domínio a ser testado.
  string validValue;   ///< Valor válido para teste do validate.
  string invalidValue; ///< Valor inválido para teste do validate.

public:
  /**
   * Construtor da classe DomainUnitTest.
   *
   * @param validValue Valor válido para testar o domínio.
   * @param invalidValue Valor inválido para testar o domínio.
   * @param domain Ponteiro para o domínio a ser testado.
   */
  DomainUnitTest(const string &validValue, const string &invalidValue, Domain *domain)
  {
    this->invalidValue = invalidValue;
    this->validValue = validValue;
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
