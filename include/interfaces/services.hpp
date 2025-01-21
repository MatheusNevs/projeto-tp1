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

class TravelServiceInterface
{
public:
  virtual void create(Code &userCode, Travel &newTravel) = 0;
  virtual void update(Code &usercode, Code &travelCode, Travel &updatedTravel) = 0;
  virtual void remove(Code &userCode, Code &travelCode) = 0;
  virtual vector<Travel> readAll(Code &userCode) = 0;
  virtual int consultCost(Code &userCode, Code &travelCode) = 0;
  virtual vector<Destination> listDestinations(Code &userCode, Code &travelCode) = 0;
  virtual Destination consultDestination(Code &userCode, Code &destinationCode) = 0;
  virtual vector<Lodging> listLodgings(Code &userCode, Code &destinationCode) = 0;
  virtual vector<Activity> listActivities(Code &userCode, Code &destinationCode) = 0;
  virtual ~TravelServiceInterface() {};
};

class AuthServiceInterface
{
public:
  virtual bool autenticate(Code &userCode, Password &userPassword) = 0;
  virtual void create(Code &userCode, Password &userPassword) = 0;
  virtual ~AuthServiceInterface() {};
};

class DestinationServiceInterface
{
public:
  virtual void create(Code &userCode, Code &destinationTravelCode, Destination &destination) = 0;
  virtual vector<Destination> read(Code &userCode) = 0;
  virtual void update(Code &userCode, Code &destinationCode, Destination &updatedDestination) = 0;
  virtual void remove(Code &userCode, Code &destinationCode) = 0;
  virtual ~DestinationServiceInterface() {};
};

class LodgingServiceInterface
{
public:
  virtual void create(Code &userCode, Code &lodgingDestinationCode, Lodging &newLodging) = 0;
  virtual vector<Lodging> read(Code &userCode) = 0;
  virtual void update(Code &userCode, Code &lodgingCode, Lodging &updatedLodging) = 0;
  virtual void remove(Code &userCode, Code &lodgingCode) = 0;
  virtual ~LodgingServiceInterface() {};
};

class ActivityServiceInterface
{
public:
  virtual void create(Code &userCode, Code &activityDestinationCode, Activity &newActivity) = 0;
  virtual vector<Activity> read(Code &userCode) = 0;
  virtual void update(Code &userCode, Code &activityCode, Activity &updatedActivity) = 0;
  virtual void remove(Code &userCode, Code &activityCode) = 0;
  virtual ~ActivityServiceInterface() {};
};

#endif // SERVICES_INTERFACE_H
