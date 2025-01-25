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
   * @brief Consulta o custo de uma viagem.
   * @param travelCode O código da viagem.
   */
  void consultCost(Code travelCode);

  /**
   * @brief Lista destinos para uma determinada viagem.
   * @param travelCode O código da viagem.
   */
  void listDestinations(Code travelCode);

  /**
   * @brief Consulta um destino específico.
   */
  void consultDestination();

  /**
   * @brief Lista hospedagens para um determinado destino.
   * @param destinationCode O código do destino.
   */
  void listLodgings(Code destinationCode);

  /**
   * @brief Lista atividades para um determinado destino.
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
   * @brief Executa as operações da visualização de viagens.
   * @param userCode O código do usuário.
   */
  void execute(Code &userCode) override;

  /**
   * @brief Cria uma nova entrada de viagem.
   */
  void create();

  /**
   * @brief Atualiza uma entrada de viagem existente.
   */
  void update();

  /**
   * @brief Remove uma entrada de viagem.
   */
  void remove();

  /**
   * @brief Lista todas as entradas de viagem.
   */
  void listAll();

  /**
   * @brief Consulta uma entrada de viagem específica.
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