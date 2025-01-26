#ifndef TRAVEL_MODEL_INTERFACE_H
#define TRAVEL_MODEL_INTERFACE_H

#include "./model.hpp"
#include "../interfaces/services.hpp"

/**
 * @class TravelModel
 * @brief Classe responsável pela gestão de viagens.
 *
 * A classe TravelModel implementa a interface TravelServiceInterface e herda da classe Model.
 */
class TravelModel : public TravelServiceInterface, public Model
{
public:
  /**
   * @brief Cria uma nova viagem.
   *
   * @param userCode Código do usuário.
   * @param newTravel Nova viagem a ser criada.
   */
  void create(Code &userCode, Travel &newTravel) override;

  /**
   * @brief Atualiza uma viagem existente.
   *
   * @param userCode Código do usuário.
   * @param travelCode Código da viagem a ser atualizada.
   * @param updatedTravel Viagem atualizada.
   */
  void update(Code &userCode, Code &travelCode, Travel &updatedTravel) override;

  /**
   * @brief Remove uma viagem.
   *
   * @param userCode Código do usuário.
   * @param travelCode Código da viagem a ser removida.
   */
  void remove(Code &userCode, Code &travelCode) override;

  /**
   * @brief Lê todas as viagens de um usuário.
   *
   * @param userCode Código do usuário.
   * @return Vetor de viagens do usuário.
   */
  vector<Travel> readAll(Code &userCode) override;

  /**
   * @brief Consulta o custo de uma viagem.
   *
   * @param userCode Código do usuário.
   * @param travelCode Código da viagem.
   * @return Custo da viagem.
   */
  int consultCost(Code &userCode, Code &travelCode) override;

  /**
   * @brief Lista os destinos de uma viagem.
   *
   * @param userCode Código do usuário.
   * @param travelCode Código da viagem.
   * @return Vetor de destinos da viagem.
   */
  vector<Destination> listDestinations(Code &userCode, Code &travelCode) override;

  /**
   * @brief Consulta um destino específico de uma viagem.
   *
   * @param userCode Código do usuário.
   * @param destinationCode Código do destino.
   * @return Destino consultado.
   */
  Destination consultDestination(Code &userCode, Code &destinationCode) override;

  /**
   * @brief Lista as hospedagens de um destino.
   *
   * @param userCode Código do usuário.
   * @param destinationCode Código do destino.
   * @return Vetor de hospedagens do destino.
   */
  vector<Lodging> listLodgings(Code &userCode, Code &destinationCode) override;

  /**
   * @brief Lista as atividades de um destino.
   *
   * @param userCode Código do usuário.
   * @param destinationCode Código do destino.
   * @return Vetor de atividades do destino.
   */
  vector<Activity> listActivities(Code &userCode, Code &destinationCode) override;

  /**
   * @brief Destrutor da classe TravelModel.
   */
  ~TravelModel() override {};
};

#endif // TRAVEL_MODEL_INTERFACE_H