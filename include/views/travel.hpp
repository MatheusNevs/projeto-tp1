#include "../interfaces/presentation.hpp"
#include "../interfaces/services.hpp"
#include "../domains/code.hpp"
#include "../domains/name.hpp"
#include "../domains/rating.hpp"

class TravelView : PresentationInterface
{
private:
  TravelServiceInterface *travelService;
  Code userCode;

public:
  void setTravelService(TravelServiceInterface *travelService)
  {
    this->travelService = travelService;
  }
  void execute(Code userCode) override;

  void create();
  void update();
  void remove();
  void listAll();
  void consultTravel();
};