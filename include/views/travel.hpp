#ifndef TRAVEL_VIEW_INTERFACE_H
#define TRAVEL_VIEW_INTERFACE_H

#include "../interfaces/presentation.hpp"
#include "../interfaces/services.hpp"
#include "../domains/code.hpp"
#include "../domains/name.hpp"
#include "../domains/rating.hpp"

class TravelView : public PresentationInterface
{
private:
  TravelServiceInterface *travelService;
  void consultCost(Code travelCode);
  void listDestinations(Code travelCode);
  void consultDestination();
  void listLodgings(Code destinationCode);
  void listActivities(Code destinationCode);

public:
  TravelView(Code *&userCode) : PresentationInterface(userCode) {};
  void setTravelService(TravelServiceInterface *travelService)
  {
    this->travelService = travelService;
  };
  void execute(Code *&userCode) override;

  void create();
  void update();
  void remove();
  void listAll();
  void consultTravel();
};

#endif // TRAVEL_VIEW_INTERFACE_H