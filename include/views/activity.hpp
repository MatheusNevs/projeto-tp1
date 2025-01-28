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
   * @brief Executa a apresentação de interface visual para manipulação de informações relacionadas a atividades
   *
   * @param userCode Código do usuário logado que será usado para manipular as informações relacionadas a atividades.
   */
  void execute(Code &userCode);

  /**
   * @brief Interação com usuário para criação de nova atividade.
   */
  void create();

  /**
   * @brief Interação com o usuário para atualização de uma atividade existente.
   */
  void update();

  /**
   * @brief Interação com o usuário para remoção de uma atividade.
   */
  void remove();

  /**
   * @brief Interação com o usuário para leitura de todas suas atividades.
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