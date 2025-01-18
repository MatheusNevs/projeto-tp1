#include "../include/builder.hpp"
#include "../include/services/auth.hpp"
#include "../include/views/auth.hpp"

#include "../include/services/travel.hpp"
#include "../include/views/travel.hpp"

// #include "../include/services/destination.hpp"
// #include "../include/views/destination.hpp"

// #include "../include/services/lodging.hpp"
// #include "../include/views/lodging.hpp"

// #include "../include/services/activity.hpp"
// #include "../include/views/activity.hpp"

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
