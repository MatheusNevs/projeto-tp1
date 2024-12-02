#include "../../include/entities/entity.hpp"
#include "../test.hpp"

/**
 * @class EntityUnitTest
 * @brief Representa uma classe de unidade de teste específico para entidades.
 *
 * A classe `EntityUnitTest` herda diretamente de `UnitTest` usando sua interface
 * e implementado propriedades e formas de test próprios.
 */
class EntityUnitTest : public UnitTest
{
private:
  Entity *entity;                ///< Ponteiro para entidade a ser testada
  Domain *domainTest;            //< Ponteiro para dominio a ser associado à entidade para teste
  string propertyName;           //< Nome da propriedade a qual domínio está associado
  void destroyEntityUnitTest();  //< Método para destruir unidade em teste

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
