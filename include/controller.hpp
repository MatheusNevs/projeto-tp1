#ifndef CONTROLLER_INTERFACE_H
#define CONTROLLER_INTERFACE_H

#include "./views/auth.hpp"
#include "./views/travel.hpp"
#include "./views/destination.hpp"
#include "./views/lodging.hpp"
#include "./views/activity.hpp"

/**
 * @class Controller
 * @brief Classe responsável por gerenciar as views e executar a lógica principal do programa.
 */
class Controller
{
private:
  AuthView *authView;               ///< Ponteiro para a view de autenticação.
  TravelView *travelView;           ///< Ponteiro para a view de viagens.
  DestinationView *destinationView; ///< Ponteiro para a view de destinos.
  LodgingView *lodgingView;         ///< Ponteiro para a view de hospedagem.
  ActivityView *activityView;       ///< Ponteiro para a view de atividades.

public:
  Code userCode = Code("000000"); ///< Código do usuário padrão.
  ~Controller();                  ///< Destrutor da classe Controller.

  /**
   * @brief Define a view de autenticação.
   * @param authView Ponteiro para a view de autenticação.
   */
  void setAuthView(AuthView *&authView);

  /**
   * @brief Define a view de viagens.
   * @param travelView Ponteiro para a view de viagens.
   */
  void setTravelView(TravelView *&travelView);

  /**
   * @brief Define a view de destinos.
   * @param destinationView Ponteiro para a view de destinos.
   */
  void setDestinationView(DestinationView *&destinationView);

  /**
   * @brief Define a view de hospedagem.
   * @param lodgingView Ponteiro para a view de hospedagem.
   */
  void setLodgingView(LodgingView *&lodgingView);

  /**
   * @brief Define a view de atividades.
   * @param activityView Ponteiro para a view de atividades.
   */
  void setActivityView(ActivityView *&activityView);

  /**
   * @brief Executa a lógica principal do programa.
   */
  void execute();
};

#endif // CONTROLLER_INTERFACE_H