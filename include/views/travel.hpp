#include "../interfaces/presentation.hpp"
#include "../interfaces/services.hpp"
#include "../domains/code.hpp"
#include "../domains/name.hpp"
#include "../domains/rating.hpp"

class TravelView : PresentationInterface
{
private:
  TravelServiceInterface *travelService;
  void consultCost(Code travelCode);
  void listDestinations(Code travelCode);
  void consultDestination();
  void listLodgings(Code destinationCode);
  void listActivities(Code destinationCode);

public:
  void setTravelService(TravelServiceInterface *travelService)
  {
    this->travelService = travelService;
  }
  void execute(Code &userCode) override;

  void create();
  void update();
  void remove();
  void listAll();
  void consultTravel();
};