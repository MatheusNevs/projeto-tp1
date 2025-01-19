#include "../include/builder.hpp"

void Builder::build(Controller *controller)
{
  AuthModel *authService = new AuthModel();
  TravelModel *travelService = new TravelModel();

  AuthView *authView = new AuthView(controller->userCode);
  TravelView *travelView = new TravelView(controller->userCode);

  authView->setAuthService(authService);
  travelView->setTravelService(travelService);

  controller->setAuthView(authView);
  controller->setTravelView(travelView);
}
