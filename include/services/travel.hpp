#ifndef TRAVEL_MODEL_INTERFACE_H
#define TRAVEL_MODEL_INTERFACE_H

#include "./model.hpp"
#include "../interfaces/services.hpp"

/**
 * @class TravelModel
 * @brief Implementação do serviço relacionado a viagens.
 *
 * Esta classe herda da classe Model para se comunicar com o banco de dados e
 * implementa a interface de serviço de viagem, TravelServiceInterface,
 * disponibilizando métodos para manipulação de informações de viagens
 * em um banco de dados persistente.
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
   * @param userCode Código do usuário que está atualizando a viagem para verificar se tem permissão sobre a mesma.
   * @param travelCode Código da viagem a ser atualizada.
   * @param updatedTravel Viagem atualizada.
   */
  void update(Code &userCode, Code &travelCode, Travel &updatedTravel) override;

  /**
   * @brief Remove uma viagem.
   *
   * @param userCode Código do usuário que está removendo a viagem para verificar se tem permissão sobre a mesma.
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
   * @param userCode Código do usuário que está consultando custo da viagem para verificar se tem permissão sobre a mesma.
   * @param travelCode Código da viagem.
   * @return Custo da viagem.
   */
  int consultCost(Code &userCode, Code &travelCode) override;

  /**
   * @brief Lista os destinos de uma viagem.
   *
   * @param userCode Código do usuário que está consultando os destinos da viagem para verificar se tem permissão sobre a mesma.
   * @param travelCode Código da viagem.
   * @return Vetor de destinos da viagem.
   */
  vector<Destination> listDestinations(Code &userCode, Code &travelCode) override;

  /**
   * @brief Consulta um destino específico de uma viagem.
   *
   * @param userCode Código do usuário que está consultando destino de viagem para verificar se tem permissão sobre a mesma.
   * @param destinationCode Código do destino.
   * @return Destino consultado.
   */
  Destination consultDestination(Code &userCode, Code &destinationCode) override;

  /**
   * @brief Lista as hospedagens de um destino.
   *
   * @param userCode Código do usuário que está listando hospedagens de destino para verificar se tem permissão sobre o mesmo.
   * @param destinationCode Código do destino.
   * @return Vetor de hospedagens do destino.
   */
  vector<Lodging> listLodgings(Code &userCode, Code &destinationCode) override;

  /**
   * @brief Lista as atividades de um destino.
   *
   * @param userCode Código do usuário que está listando atividades de destino para verificar se tem permissão sobre o mesmo.
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