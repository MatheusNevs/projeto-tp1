#ifndef SERVICES_INTERFACE_H
#define SERVICES_INTERFACE_H

#include "../interfaces/presentation.hpp"
#include "../domains/code.hpp"
#include "../domains/name.hpp"
#include "../domains/rating.hpp"
#include "../domains/password.hpp"
#include "../entities/travel.hpp"
#include "../entities/destination.hpp"
#include "../entities/lodging.hpp"
#include "../entities/activity.hpp"

/**
 * @class TravelServiceInterface
 * @brief Interface para serviços relacionados a viagens.
 *
 * Esta interface define as operações que podem ser realizadas em dados relacionados a viagens.
 */
class TravelServiceInterface
{
public:
  /**
   * @brief Cria uma nova entrada de viagem.
   *
   * @param userCode O código do usuário que está criando a viagem.
   * @param newTravel O objeto de viagem a ser criado.
   */
  virtual void create(Code &userCode, Travel &newTravel) = 0;

  /**
   * @brief Atualiza uma entrada de viagem existente.
   *
   * @param userCode O código do usuário que está atualizando a viagem.
   * @param travelCode O código da viagem a ser atualizada.
   * @param updatedTravel O objeto de viagem atualizado.
   */
  virtual void update(Code &usercode, Code &travelCode, Travel &updatedTravel) = 0;

  /**
   * @brief Remove uma entrada de viagem existente.
   *
   * @param userCode O código do usuário que está removendo a viagem.
   * @param travelCode O código da viagem a ser removida.
   */
  virtual void remove(Code &userCode, Code &travelCode) = 0;

  /**
   * @brief Lê todas as entradas de viagem de um usuário.
   *
   * @param userCode O código do usuário cujas viagens serão lidas.
   * @return Um vetor de objetos de viagem.
   */
  virtual vector<Travel> readAll(Code &userCode) = 0;

  /**
   * @brief Consulta o custo de uma viagem específica.
   *
   * @param userCode O código do usuário que está consultando o custo.
   * @param travelCode O código da viagem cujo custo será consultado.
   * @return O custo da viagem.
   */
  virtual int consultCost(Code &userCode, Code &travelCode) = 0;

  /**
   * @brief Lista todos os destinos de uma viagem específica.
   *
   * @param userCode O código do usuário que está listando os destinos.
   * @param travelCode O código da viagem cujos destinos serão listados.
   * @return Um vetor de objetos de destino.
   */
  virtual vector<Destination> listDestinations(Code &userCode, Code &travelCode) = 0;

  /**
   * @brief Consulta um destino específico.
   *
   * @param userCode O código do usuário que está consultando o destino.
   * @param destinationCode O código do destino a ser consultado.
   * @return O objeto de destino.
   */
  virtual Destination consultDestination(Code &userCode, Code &destinationCode) = 0;

  /**
   * @brief Lista todas as hospedagens de um destino específico.
   *
   * @param userCode O código do usuário que está listando as hospedagens.
   * @param destinationCode O código do destino cujas hospedagens serão listadas.
   * @return Um vetor de objetos de hospedagem.
   */
  virtual vector<Lodging> listLodgings(Code &userCode, Code &destinationCode) = 0;

  /**
   * @brief Lista todas as atividades de um destino específico.
   *
   * @param userCode O código do usuário que está listando as atividades.
   * @param destinationCode O código do destino cujas atividades serão listadas.
   * @return Um vetor de objetos de atividade.
   */
  virtual vector<Activity> listActivities(Code &userCode, Code &destinationCode) = 0;

  /**
   * @brief Destrutor virtual para a interface.
   */
  virtual ~TravelServiceInterface() {};
};

/**
 * @brief Interface para operações de serviço de autenticação
 *
 * Esta interface define o contrato para operações relacionadas à autenticação,
 * como autenticação e criação de usuário.
 */
class AuthServiceInterface
{
public:
  /**
   * @brief Autentica um usuário com as credenciais fornecidas
   *
   * @param userCode O código de identificação do usuário
   * @param userPassword A senha do usuário
   * @return true Se a autenticação for bem-sucedida
   * @return false Se a autenticação falhar
   */
  virtual bool autenticate(Code &userCode, Password &userPassword) = 0;

  /**
   * @brief Cria um novo usuário com as credenciais fornecidas
   *
   * @param userCode O código para o novo usuário
   * @param userPassword A senha para o novo usuário
   */
  virtual void create(Code &userCode, Password &userPassword) = 0;

  /**
   * @brief Destrutor virtual para limpeza adequada da herança
   */
  virtual ~AuthServiceInterface() {};
};
;

/**
 * @class DestinationServiceInterface
 * @brief Interface para serviços relacionados a destinos.
 *
 * Esta interface define as operações que podem ser realizadas em dados relacionados a destinos.
 */
class DestinationServiceInterface
{
public:
  /**
   * @brief Cria um novo destino.
   *
   * @param userCode O código do usuário que está criando o destino.
   * @param destinationTravelCode O código da viagem associada ao destino.
   * @param destination O objeto de destino a ser criado.
   */
  virtual void create(Code &userCode, Code &destinationTravelCode, Destination &destination) = 0;

  /**
   * @brief Lê todos os destinos de um usuário.
   *
   * @param userCode O código do usuário cujos destinos serão lidos.
   * @return Um vetor de objetos de destino.
   */
  virtual vector<Destination> read(Code &userCode) = 0;

  /**
   * @brief Atualiza um destino existente.
   *
   * @param userCode O código do usuário que está atualizando o destino.
   * @param destinationCode O código do destino a ser atualizado.
   * @param updatedDestination O objeto de destino atualizado.
   */
  virtual void update(Code &userCode, Code &destinationCode, Destination &updatedDestination) = 0;

  /**
   * @brief Remove um destino existente.
   *
   * @param userCode O código do usuário que está removendo o destino.
   * @param destinationCode O código do destino a ser removido.
   */
  virtual void remove(Code &userCode, Code &destinationCode) = 0;

  /**
   * @brief Destrutor virtual para a interface.
   */
  virtual ~DestinationServiceInterface() {};
};

/**
 * @class LodgingServiceInterface
 * @brief Interface para serviços relacionados a hospedagens.
 *
 * Esta interface define as operações que podem ser realizadas em dados relacionados a hospedagens.
 */
class LodgingServiceInterface
{
public:
  /**
   * @brief Cria uma nova hospedagem.
   *
   * @param userCode O código do usuário que está criando a hospedagem.
   * @param lodgingDestinationCode O código do destino associado à hospedagem.
   * @param newLodging O objeto de hospedagem a ser criado.
   */
  virtual void create(Code &userCode, Code &lodgingDestinationCode, Lodging &newLodging) = 0;

  /**
   * @brief Lê todas as hospedagens de um usuário.
   *
   * @param userCode O código do usuário cujas hospedagens serão lidas.
   * @return Um vetor de objetos de hospedagem.
   */
  virtual vector<Lodging> read(Code &userCode) = 0;

  /**
   * @brief Atualiza uma hospedagem existente.
   *
   * @param userCode O código do usuário que está atualizando a hospedagem.
   * @param lodgingCode O código da hospedagem a ser atualizada.
   * @param updatedLodging O objeto de hospedagem atualizado.
   */
  virtual void update(Code &userCode, Code &lodgingCode, Lodging &updatedLodging) = 0;

  /**
   * @brief Remove uma hospedagem existente.
   *
   * @param userCode O código do usuário que está removendo a hospedagem.
   * @param lodgingCode O código da hospedagem a ser removida.
   */
  virtual void remove(Code &userCode, Code &lodgingCode) = 0;

  /**
   * @brief Destrutor virtual para a interface.
   */
  virtual ~LodgingServiceInterface() {};
};

/**
 * @class ActivityServiceInterface
 * @brief Interface para serviços relacionados a atividades.
 *
 * Esta interface define as operações que podem ser realizadas em dados relacionados a atividades.
 */
class ActivityServiceInterface
{
public:
  /**
   * @brief Cria uma nova atividade.
   *
   * @param userCode O código do usuário que está criando a atividade.
   * @param activityDestinationCode O código do destino associado à atividade.
   * @param newActivity O objeto de atividade a ser criado.
   */
  virtual void create(Code &userCode, Code &activityDestinationCode, Activity &newActivity) = 0;

  /**
   * @brief Lê todas as atividades de um usuário.
   *
   * @param userCode O código do usuário cujas atividades serão lidas.
   * @return Um vetor de objetos de atividade.
   */
  virtual vector<Activity> read(Code &userCode) = 0;

  /**
   * @brief Atualiza uma atividade existente.
   *
   * @param userCode O código do usuário que está atualizando a atividade.
   * @param activityCode O código da atividade a ser atualizada.
   * @param updatedActivity O objeto de atividade atualizado.
   */
  virtual void update(Code &userCode, Code &activityCode, Activity &updatedActivity) = 0;

  /**
   * @brief Remove uma atividade existente.
   *
   * @param userCode O código do usuário que está removendo a atividade.
   * @param activityCode O código da atividade a ser removida.
   */
  virtual void remove(Code &userCode, Code &activityCode) = 0;

  /**
   * @brief Destrutor virtual para a interface.
   */
  virtual ~ActivityServiceInterface() {};
};

#endif // SERVICES_INTERFACE_H
