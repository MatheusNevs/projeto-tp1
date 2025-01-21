#include "../include/builder.hpp"

void Builder::build(Controller *controller)
{
  AuthModel *authService = new AuthModel();
  TravelModel *travelService = new TravelModel();
  DestinationModel *destinationService = new DestinationModel();
  LodgingModel *lodgingService = new LodgingModel();
  // ActivityModel *activityService = new ActivityModel();

  AuthView *authView = new AuthView(controller->userCode);
  TravelView *travelView = new TravelView(controller->userCode);
  DestinationView *destinationView = new DestinationView(controller->userCode);
  LodgingView *lodgingView = new LodgingView(controller->userCode);
  // ActivityView *activityView = new ActivityView(controller->userCode);

  authView->setAuthService(authService);
  travelView->setTravelService(travelService);
  destinationView->setDestinationService(destinationService);
  lodgingView->setLodgingService(lodgingService);
  // activityView->setDestinationService(activityService);

  controller->setAuthView(authView);
  controller->setTravelView(travelView);
  controller->setDestinationView(destinationView);
  controller->setLodgingView(lodgingView);
  // controller->setActivityView(activityView);
}
