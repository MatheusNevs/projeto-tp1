#include "../../include/entities/entity.hpp"
#include "../test.hpp"

/**
 * @class EntityUnitTest
 * @brief Representa uma classe de unidade de teste específico para entidades.
 *
 * A classe `EntityUnitTest` herda diretamente de `UnitTest` usando sua interface
 * e implementado propriedades e uma forma de test próprio, através do recebimento
 * de um dado domínio e o nome da propriedade associada para testar a entidade.
 */
class EntityUnitTest : public UnitTest
{
private:
  Entity *entity;      ///< Ponteiro para entidade a ser testada
  Domain *domainTest;  ///< Ponteiro para dominio a ser associado à entidade para teste
  string propertyName; ///< Nome da propriedade a qual domínio está associado

  /**
   * Método para destrução da entidade criada no teste de unidade
   *
   * @brief Destrutor da entidade do teste de unidade
   *
   */
  void destroyEntityUnitTest()
  {
    delete entity;
  };

public:
  /**
   * @brief Construtor da classe EntityUnitTest.
   *
   * Este construtor inicializa a classe com a entidade a ser testada, o domínio
   * ao qual a entidade está associada, e o nome da propriedade da entidade que
   * será testada.
   *
   * @param propertyName Nome da propriedade associada ao domínio para o teste.
   * @param domain Ponteiro para o domínio associado à entidade.
   * @param entity Ponteiro para a entidade que será testada.
   */
  EntityUnitTest(string propertyName, Domain *domain, Entity *entity)
  {
    this->entity = entity;
    this->domainTest = domain;
    this->propertyName = propertyName;
  };

  /**
   * Executa o teste de unidade, testando o `set` e o `get` da entidade pelo domínio e
   * nome da propriedade recebidos no construtor.
   */
  void test() override;

  /**
   * Retorna uma descrição do teste, incluindo o nome da propriedade e seu novo valor que foram
   * testadas na entidade.
   *
   * @return Descrição do teste.
   */
  string getDescription() const override;
};
