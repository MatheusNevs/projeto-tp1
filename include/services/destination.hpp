#ifndef DESTINATION_MODEL_HPP
#define DESTINATION_MODEL_HPP

#include "model.hpp"
#include "../interfaces/services.hpp"

/**
 * @class DestinationModel
 * @brief Classe responsável pela gestão de destinos de viagem.
 *
 * A classe DestinationModel implementa a interface DestinationServiceInterface e herda da classe Model.
 */
class DestinationModel : public DestinationServiceInterface, public Model
{
public:
  /**
   * @brief Cria um novo destino de viagem.
   *
   * @param userCode Código do usuário.
   * @param destinationTravelCode Código da viagem do destino.
   * @param newDestination Novo destino a ser criado.
   */
  void create(Code &userCode, Code &destinationTravelCode, Destination &newDestination) override;

  /**
   * @brief Atualiza um destino de viagem existente.
   *
   * @param userCode Código do usuário.
   * @param destinationCode Código do destino a ser atualizado.
   * @param updatedDestination Destino atualizado.
   */
  void update(Code &userCode, Code &destinationCode, Destination &updatedDestination) override;

  /**
   * @brief Remove um destino de viagem.
   *
   * @param userCode Código do usuário.
   * @param destinationCode Código do destino a ser removido.
   */
  void remove(Code &userCode, Code &destinationCode) override;

  /**
   * @brief Lê todos os destinos de viagem de um usuário.
   *
   * @param userCode Código do usuário.
   * @return Vetor de destinos do usuário.
   */
  vector<Destination> read(Code &userCode) override;

  /**
   * @brief Destrutor da classe DestinationModel.
   */
  ~DestinationModel() override {};
};

#endif // DESTINATION_MODEL_HPP
