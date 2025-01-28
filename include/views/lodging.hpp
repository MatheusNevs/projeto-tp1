#ifndef LODGING_VIEW_HPP
#define LODGING_VIEW_HPP

#include "../interfaces/presentation.hpp"
#include "../interfaces/services.hpp"

/**
 * @class LodgingView
 * @brief Classe responsável pela apresentação das operações de hospedagem.
 */
class LodgingView : public PresentationInterface
{
private:
  LodgingServiceInterface *lodgingService; ///< Serviço de hospedagem

public:
  /**
   * @brief Construtor da classe LodgingView.
   * @param userCode Código do usuário.
   */
  LodgingView(Code &userCode) : PresentationInterface(userCode) {};

  /**
   * @brief Define o serviço de hospedagem.
   * @param lodgingService Ponteiro para o serviço de hospedagem.
   */
  void setLodgingService(LodgingServiceInterface *lodgingService)
  {
    this->lodgingService = lodgingService;
  };

  /**
   * @brief Executa a apresentação de interface visual para manipulação de informações relacionadas a hospedagens.
   * @param userCode Código do usuário.
   */
  void execute(Code &userCode);

  /**
   * @brief Interação com usuário para criação de uma nova hospedagem.
   */
  void create();

  /**
   * @brief Interação com usuário para atualização de uma hospedagem existente.
   */
  void update();

  /**
   * @brief Interação com usuário para remoção de uma hospedagem.
   */
  void remove();

  /**
   * @brief Interação com usuário para leitura de suas hospedagens.
   */
  void read();

  /**
   * @brief Destrutor da classe LodgingView.
   */
  ~LodgingView() override
  {
    delete lodgingService;
  }
};

#endif // LODGING_VIEW_HPP