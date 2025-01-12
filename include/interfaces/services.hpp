#ifndef SERVICES_INTERFACE_H
#define SERVICES_INTERFACE_H

#include "../interfaces/presentation.hpp"
#include "../domains/code.hpp"
#include "../domains/name.hpp"
#include "../domains/rating.hpp"
#include "../entities/travel.hpp"
#include "../entities/destination.hpp"
#include "../entities/lodging.hpp"
#include "../entities/activity.hpp"

class TravelServiceInterface
{
public:
  virtual void create(Code userCode, Travel newTravel) = 0;
  virtual void update(Code usercode, Code travelCode, Travel updatedTravel) = 0;
  virtual void remove(Code userCode, Code travelCode) = 0;
  virtual vector<Travel> readAll(Code userCode) = 0;
  virtual int consultCost(Code userCode, Code travelCode) = 0;
  virtual vector<Destination> listDestinations(Code userCode, Code travelCode) = 0;
  virtual Destination consultDestination(Code userCode, Code destinationCode) = 0;
  virtual vector<Lodging> listLodgings(Code userCode, Code destinationCode) = 0;
  virtual vector<Activity> listActivities(Code userCode, Code destinationCode) = 0;
};

#endif // SERVICES_INTERFACE_H