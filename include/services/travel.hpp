#ifndef TRAVEL_MODEL_INTERFACE_H
#define TRAVEL_MODEL_INTERFACE_H

#include "./model.hpp"
#include "../interfaces/services.hpp"

class TravelModel : public TravelServiceInterface, public Model
{
public:
  void create(Code userCode, Travel newTravel) override;
  void update(Code userCode, Code travelCode, Travel updatedTravel) override;
  void remove(Code userCode, Code travelCode) override;
  vector<Travel> readAll(Code userCode) override;
  int consultCost(Code userCode, Code travelCode) override;
  vector<Destination> listDestinations(Code userCode, Code travelCode) override;
  Destination consultDestination(Code userCode, Code destinationCode) override;
  vector<Lodging> listLodgings(Code userCode, Code destinationCode) override;
  vector<Activity> listActivities(Code userCode, Code destinationCode) override;
};

#endif // TRAVEL_MODEL_INTERFACE_H