#ifndef ACTIVITY_SERVICE_H
#define ACTIVITY_SERVICE_H

#include "./model.hpp"
#include "../interfaces/services.hpp"

/**
 * @class ActivityModel
 * @brief Implementação do serviço relacionado a atividades.
 *
 * Esta classe herda da classe Model para se comunicar com o banco de dados e
 * implementa a interface de serviço de atividade, ActivityServiceInterface,
 * disponibilizando métodos para manipulação de informações de atividades
 * em um banco de dados persistente.
 */
class ActivityModel : public ActivityServiceInterface, public Model
{
public:
  /**
   * @brief Cria uma nova atividade.
   *
   * @param userCode O código do usuário que está criando a atividade.
   * @param activityDestinationCode O código do destino associado à atividade.
   * @param newActivity O objeto de atividade a ser criado.
   */
  void create(Code &userCode, Code &activityDestinationCode, Activity &newActivity) override;

  /**
   * @brief Lê todas as atividades de um usuário.
   *
   * @param userCode O código do usuário cujas atividades serão lidas.
   * @return Um vetor de objetos de atividade.
   */
  vector<Activity> read(Code &userCode) override;

  /**
   * @brief Atualiza uma atividade existente.
   *
   * @param userCode O código do usuário que está atualizando a atividade para verificar se tem permissão sobre a mesma.
   * @param activityCode O código da atividade a ser atualizada.
   * @param updatedActivity O objeto de atividade atualizado.
   */
  void update(Code &userCode, Code &activityCode, Activity &updatedActivity) override;

  /**
   * @brief Remove uma atividade existente.
   *
   * @param userCode O código do usuário que está removendo a atividade para verificar se tem permissão sobre a mesma.
   * @param activityCode O código da atividade a ser removida.
   */
  void remove(Code &userCode, Code &activityCode) override;

  /**
   * @brief Destrutor virtual para a classe.
   */
  ~ActivityModel() override {}
};

#endif // ACTIVITY_SERVICE_H