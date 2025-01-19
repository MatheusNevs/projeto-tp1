#ifndef CONTROLLER_INTERFACE_H
#define CONTROLLER_INTERFACE_H

#include "./views/auth.hpp"
#include "./views/travel.hpp"

class Controller
{
private:
  AuthView *authView;
  TravelView *travelView;

public:
  Code userCode = Code("000000");
  ~Controller();
  void setAuthView(AuthView *&authView);
  void setTravelView(TravelView *&travelView);

  void execute();
};
#endif // CONTROLLER_INTERFACE_H