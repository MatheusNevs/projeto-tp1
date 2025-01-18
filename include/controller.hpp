#ifndef CONTROLLER_INTERFACE_H
#define CONTROLLER_INTERFACE_H

#include "./interfaces/presentation.hpp"

class Controller
{
private:
  PresentationInterface *authView;
  PresentationInterface *travelView;
  PresentationInterface *destinationView;
  PresentationInterface *lodgingView;
  PresentationInterface *activityView;

public:
  Code *userCode;
  void setAuthView(PresentationInterface *authView);
  void setTravelView(PresentationInterface *travelView);
  void setDestinationView(PresentationInterface *destinationView);
  void setLodgingView(PresentationInterface *lodgingView);
  void setActivityView(PresentationInterface *activityView);

  void execute();
};
#endif // CONTROLLER_INTERFACE_H