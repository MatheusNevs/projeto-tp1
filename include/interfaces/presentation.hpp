#ifndef PRESENTATION_INTERFACE_H
#define PRESENTATION_INTERFACE_H

#include "../domains/code.hpp"

/**
 * @class PresentationInterface
 * @brief Interface abstrata para a apresentação de código.
 *
 * Esta classe fornece uma interface para a apresentação de código,
 * exigindo que as classes derivadas implementem o método execute.
 */
class PresentationInterface
{
protected:
  Code &userCode; //< Código do usuário logado

public:
  PresentationInterface(Code &userCode) : userCode(userCode) {}

  /** @brief Método Execute.
   *
   * Método abstrato responsável pela execução da camada de apresentação
   * pela controladora, recebendo o código do usuário para mostrar informações
   * referente ao mesmo.
   *
   * @param userCode código do usuário.
   * @throw invalid_argument
   */
  virtual void execute(Code &userCode) = 0;
  virtual ~PresentationInterface() {};
};

#endif // PRESENTATION_INTERFACE_H