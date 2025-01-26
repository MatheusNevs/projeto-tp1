#ifndef ACTIVITY_VIEW_HPP
#define ACTIVITY_VIEW_HPP

#include "../interfaces/presentation.hpp"
#include "../interfaces/services.hpp"

/**
 * @class ActivityView
 * @brief Classe responsável pela apresentação das atividades.
 *
 * A classe ActivityView implementa a interface PresentationInterface e gerencia a interação com o serviço de atividades.
 */
class ActivityView : public PresentationInterface
{
private:
  ActivityServiceInterface *activityService;

public:
  /**
   * @brief Construtor da classe ActivityView.
   *
   * @param userCode Código do usuário.
   */
  ActivityView(Code &userCode) : PresentationInterface(userCode) {};

  /**
   * @brief Define o serviço de atividades a ser utilizado.
   *
   * @param activityService Ponteiro para o serviço de atividades.
   */
  void setActivityService(ActivityServiceInterface *activityService)
  {
    this->activityService = activityService;
  };

  /**
   * @brief Executa a visualização das atividades para um usuário.
   *
   * @param userCode Código do usuário.
   */
  void execute(Code &userCode);

  /**
   * @brief Cria uma nova atividade.
   */
  void create();

  /**
   * @brief Atualiza uma atividade existente.
   */
  void update();

  /**
   * @brief Remove uma atividade.
   */
  void remove();

  /**
   * @brief Lê todas as atividades de um usuário.
   */
  void read();

  /**
   * @brief Destrutor da classe ActivityView.
   */
  ~ActivityView() override
  {
    delete activityService;
  }
};

#endif // ACTIVITY_VIEW_HPP