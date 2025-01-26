#ifndef CONTROLLER_INTERFACE_H
#define CONTROLLER_INTERFACE_H

#include "./interfaces/presentation.hpp"

/**
 * @class Controller
 * @brief Classe responsável por gerenciar as views e executar a lógica principal do programa.
 */
class Controller
{
private:
  PresentationInterface *authView;        ///< Ponteiro para a view de autenticação.
  PresentationInterface *travelView;      ///< Ponteiro para a view de viagens.
  PresentationInterface *destinationView; ///< Ponteiro para a view de destinos.
  PresentationInterface *lodgingView;     ///< Ponteiro para a view de hospedagem.
  PresentationInterface *activityView;    ///< Ponteiro para a view de atividades.

public:
  Code userCode = Code("000000"); ///< Código do usuário padrão.
  ~Controller();                  ///< Destrutor da classe Controller.

  /**
   * @brief Define a view de autenticação.
   * @param authView Ponteiro para a view de autenticação.
   */
  void setAuthView(PresentationInterface *authView);

  /**
   * @brief Define a view de viagens.
   * @param travelView Ponteiro para a view de viagens.
   */
  void setTravelView(PresentationInterface *travelView);

  /**
   * @brief Define a view de destinos.
   * @param destinationView Ponteiro para a view de destinos.
   */
  void setDestinationView(PresentationInterface *destinationView);

  /**
   * @brief Define a view de hospedagem.
   * @param lodgingView Ponteiro para a view de hospedagem.
   */
  void setLodgingView(PresentationInterface *lodgingView);

  /**
   * @brief Define a view de atividades.
   * @param activityView Ponteiro para a view de atividades.
   */
  void setActivityView(PresentationInterface *activityView);

  /**
   * @brief Executa a lógica principal do programa.
   */
  void execute();
};

#endif // CONTROLLER_INTERFACE_H