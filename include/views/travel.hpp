#ifndef TRAVEL_VIEW_INTERFACE_H
#define TRAVEL_VIEW_INTERFACE_H

#include "../interfaces/presentation.hpp"
#include "../interfaces/services.hpp"
#include "../domains/code.hpp"
#include "../domains/name.hpp"
#include "../domains/rating.hpp"

/**
 * @class TravelView
 * @brief Gerencia a lógica de apresentação para operações relacionadas a viagens.
 */
class TravelView : public PresentationInterface
{
private:
  TravelServiceInterface *travelService; ///< Ponteiro para a interface do serviço de viagens.

  /**
   * @brief Interação com usuário para consulta de custo de uma determinada viagem.
   * @param travelCode O código da viagem.
   */
  void consultCost(Code travelCode);

  /**
   * @brief Interação com usuário para leitura de destinos relacionados a uma determinada viagem.
   * @param travelCode O código da viagem.
   */
  void listDestinations(Code travelCode);

  /**
   * @brief Interação com usuário para consulta individual de destino relacionado a viagem.
   */
  void consultDestination();

  /**
   * @brief Interação com usuário para leitura de hospedagens de destino relacionado a viagem.
   * @param destinationCode O código do destino.
   */
  void listLodgings(Code destinationCode);

  /**
   * @brief Interação com usuário para leitura de atividades de destino relacionado a viagem.
   * @param destinationCode O código do destino.
   */
  void listActivities(Code destinationCode);

public:
  /**
   * @brief Construtor da classe TravelView.
   * @param userCode O código do usuário.
   */
  TravelView(Code &userCode) : PresentationInterface(userCode) {};

  /**
   * @brief Define a interface do serviço de viagens.
   * @param travelService Ponteiro para a interface do serviço de viagens.
   */
  void setTravelService(TravelServiceInterface *travelService)
  {
    this->travelService = travelService;
  };

  /**
   * @brief Executa a apresentação de interface visual para manipulação de informações relacionadas a viagens.
   * @param userCode O código do usuário.
   */
  void execute(Code &userCode) override;

  /**
   * @brief Interação com usuário para criação de uma viagem.
   */
  void create();

  /**
   * @brief Interação com usuário para atualização de uma viagem existente.
   */
  void update();

  /**
   * @brief Interação com usuário para remoção de uma viagem.
   */
  void remove();

  /**
   * @brief Interação com usuário para leitura de suas viagens.
   */
  void listAll();

  /**
   * @brief Interação com usuário para consulta individual de viagem, apresentando opções de consulta da mesma.
   */
  void consultTravel();

  /**
   * @brief Destrutor da classe TravelView.
   */
  ~TravelView() override
  {
    delete travelService;
  };
};

#endif // TRAVEL_VIEW_INTERFACE_H