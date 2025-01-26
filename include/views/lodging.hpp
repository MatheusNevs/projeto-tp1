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
   * @brief Executa a operação de acordo com o código do usuário.
   * @param userCode Código do usuário.
   */
  void execute(Code &userCode);

  /**
   * @brief Cria uma nova hospedagem.
   */
  void create();

  /**
   * @brief Atualiza uma hospedagem existente.
   */
  void update();

  /**
   * @brief Remove uma hospedagem.
   */
  void remove();

  /**
   * @brief Lê os dados de uma hospedagem.
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