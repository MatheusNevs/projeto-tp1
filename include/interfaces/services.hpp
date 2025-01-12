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
  virtual void create(Code userCode, Code travelCode, Name name) = 0;
  virtual void update(Code travelCode) = 0;
  virtual void remove(Code travelCode) = 0;
  virtual vector<Travel> readAll(Code userCode) = 0;
  virtual int consultCost(Code travelCode) = 0;
  virtual vector<Destination> listDetinations(Code travelCode) = 0;
  virtual Destination consultDestination(Code destinationCode) = 0;
  virtual vector<Lodging> listLodgings(Code destinationCode) = 0;
  virtual vector<Activity> listActivities(Code destinationCode) = 0;
};