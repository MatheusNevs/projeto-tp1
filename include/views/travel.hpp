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
  void create(Code travelCode, Name name);
  void update(Code travelCode, Name name, Rating rating);
  void remove(Code travelCode);
  void listAll();
  void consultTravel(Code travelCode);

public:
  void setTravelService(TravelServiceInterface *travelService)
  {
    travelService = travelService;
  }
  void execute(Code userCode) override;
};