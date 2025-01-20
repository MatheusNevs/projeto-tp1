#include "../include/builder.hpp"

void Builder::build(Controller *controller)
{
  AuthModel *authService = new AuthModel();
  TravelModel *travelService = new TravelModel();
  DestinationModel *destinationService = new DestinationModel();

  AuthView *authView = new AuthView(controller->userCode);
  TravelView *travelView = new TravelView(controller->userCode);
  DestinationView *destinationView = new DestinationView(controller->userCode);

  authView->setAuthService(authService);
  travelView->setTravelService(travelService);
  destinationView->setDestinationService(destinationService);

  controller->setAuthView(authView);
  controller->setTravelView(travelView);
  controller->setDestinationView(destinationView);
}
