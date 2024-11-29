#ifndef ENTITY_INTERFACE_H
#define ENTITY_INTERFACE_H

#include <bits/stdc++.h>
#include <stdexcept>
#include "../domains/domain.hpp"

using namespace std;

class Entity
{
private:
public:
  /** @brief Método Set.
   *
   * Método responsável pela atribuição do valor a uma determinada
   * propriedade da entidade
   *
   * @param propertyName Nome da propriedade que irá sofrer a alteração
   * @param value string que será validada dentro do domínio da propriedade
   * e então associada à mesma
   * @throw invalid_argument caso não esteja no formato desejado.
   */
  virtual void set(const Domain &domain) = 0;

  /** @brief Método Get
   *
   * Método responsável por retornar o valor
   *
   * @param propertyName nome da propriedade que terá valor retornado
   *
   * @return value
   */
  virtual const Domain &get(const string propertyname) const = 0;
};

#endif // ENTITY_INTERFACE_H
