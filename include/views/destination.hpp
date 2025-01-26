#ifndef DESTINATION_VIEW_INTERFACE_H
#define DESTINATION_VIEW_INTERFACE_H

#include "../interfaces/presentation.hpp"
#include "../interfaces/services.hpp"

/**
 * @class DestinationView
 * @brief Classe responsável pela apresentação das operações de destino.
 */
class DestinationView : public PresentationInterface
{
private:
  DestinationServiceInterface *destinationService;

public:
  /**
   * @brief Construtor da classe DestinationView.
   * @param userCode Código do usuário.
   */
  DestinationView(Code &userCode) : PresentationInterface(userCode) {};

  /**
   * @brief Define o serviço de destino.
   * @param destinationService Ponteiro para a interface do serviço de destino.
   */
  void setDestinationService(DestinationServiceInterface *destinationService)
  {
    this->destinationService = destinationService;
  };

  /**
   * @brief Executa a operação de destino.
   * @param userCode Código do usuário.
   */
  void execute(Code &userCode) override;

  /**
   * @brief Cria um novo destino.
   */
  void create();

  /**
   * @brief Atualiza um destino existente.
   */
  void update();

  /**
   * @brief Lê um destino.
   */
  void read();

  /**
   * @brief Remove um destino.
   */
  void remove();

  /**
   * @brief Destrutor da classe DestinationView.
   */
  ~DestinationView() override
  {
    delete destinationService;
  };
};

#endif // DESTINATION_VIEW_INTERFACE_H