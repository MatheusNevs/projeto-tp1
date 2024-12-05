// Classe implementada pelo aluno com matrícula 231013672

#ifndef ENTITY_INTERFACE_H
#define ENTITY_INTERFACE_H

#include "../domains/domain.hpp"

/**
 * @class Entity
 * @brief Representa uma classe entidade abstrata `Entity` para as entidades se construirem sobre.
 *
 * A classe `Entity` não possui propriedades próprias, as entidades
 * respectivas que implementarão as propriedades. Possui métodos abstratos
 * 'set' e 'get' que irão ser usados pelas entidades, cada uma com sua própria
 * implementação.
 */
class Entity
{
private:
public:
  /** @brief Destrutor virtual
   *
   * Destrutor virtual para garantir que a destruição de objetos derivados
   * seja tratada corretamente.
   */
  virtual ~Entity() = default;

  /**
   * @brief Define um valor para uma propriedade da entidade.
   *
   * A propriedade pode ser qualquer das propriedades da entidade.
   *
   * @param domain Dominio a ser atribuido a sua respectiva propriedade
   * @param propertyName Nome da propriedade a qual dominínio será associado
   * @throw invalid_argument Caso a propriedade não exista.
   */
  virtual void set(const Domain &domain, string propertyName) = 0;

  /** @brief Método Get
   *
   * Método responsável por retornar referência de determinada propriedade da entidade.
   *
   * @param propertyName nome da propriedade que será retornada.
   *
   * @return Domain& referência da propriedade retornada.
   */
  virtual const Domain &get(const string propertyname) const = 0;
};

#endif // ENTITY_INTERFACE_H
