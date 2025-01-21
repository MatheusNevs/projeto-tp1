#ifndef CONTROLLER_INTERFACE_H
#define CONTROLLER_INTERFACE_H

#include "./views/auth.hpp"
#include "./views/travel.hpp"
#include "./views/destination.hpp"
#include "./views/lodging.hpp"

class Controller
{
private:
  AuthView *authView;
  TravelView *travelView;
  DestinationView *destinationView;
  LodgingView *lodgingView;
  // ActivityView *ActivityView;

public:
  Code userCode = Code("000000");
  ~Controller();
  void setAuthView(AuthView *&authView);
  void setTravelView(TravelView *&travelView);
  void setDestinationView(DestinationView *&destinationView);
  void setLodgingView(LodgingView *&lodgingView);
  // void setActivityView(activityView*&activityView);

  void execute();
};
#endif // CONTROLLER_INTERFACE_H