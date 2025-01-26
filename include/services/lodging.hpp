#ifndef LODGING_SERVICE_H
#define LODGING_SERVICE_H

#include "./model.hpp"
#include "../interfaces/services.hpp"

/**
 * @class LodgingModel
 * @brief Classe responsável pela gestão de hospedagens.
 *
 * A classe LodgingModel implementa a interface LodgingServiceInterface e herda da classe Model.
 */
class LodgingModel : public LodgingServiceInterface, public Model
{
public:
  /**
   * @brief Cria uma nova hospedagem.
   *
   * @param userCode Código do usuário.
   * @param lodgingDestinationCode Código do destino da hospedagem.
   * @param newLodging Nova hospedagem a ser criada.
   */
  void create(Code &userCode, Code &lodgingDestinationCode, Lodging &newLodging) override;

  /**
   * @brief Lê todas as hospedagens de um usuário.
   *
   * @param userCode Código do usuário.
   * @return Vetor de hospedagens do usuário.
   */
  vector<Lodging> read(Code &userCode) override;

  /**
   * @brief Atualiza uma hospedagem existente.
   *
   * @param userCode Código do usuário.
   * @param lodgingCode Código da hospedagem a ser atualizada.
   * @param updatedLodging Hospedagem atualizada.
   */
  void update(Code &userCode, Code &lodgingCode, Lodging &updatedLodging) override;

  /**
   * @brief Remove uma hospedagem.
   *
   * @param userCode Código do usuário.
   * @param lodgingCode Código da hospedagem a ser removida.
   */
  void remove(Code &userCode, Code &lodgingCode) override;

  /**
   * @brief Destrutor da classe LodgingModel.
   */
  ~LodgingModel() override {}
};

#endif // LODGING_SERVICE_H