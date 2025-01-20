#ifndef CONTROLLER_INTERFACE_H
#define CONTROLLER_INTERFACE_H

#include "./views/auth.hpp"
#include "./views/travel.hpp"
#include "./views/destination.hpp"

class Controller
{
private:
  AuthView *authView;
  TravelView *travelView;
  DestinationView *destinationView;

public:
  Code userCode = Code("000000");
  ~Controller();
  void setAuthView(AuthView *&authView);
  void setTravelView(TravelView *&travelView);
  void setDestinationView(DestinationView *&destinationView);

  void execute();
};
#endif // CONTROLLER_INTERFACE_H