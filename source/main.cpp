#include "../include/services/model.hpp"
#include "../include/services/travel.hpp"
#include "../include/views/travel.hpp"

int main()
{
  Model model = Model();
  model.createTables();

  Code userCode = Code("123456");

  TravelModel *travelModel = new TravelModel();
  TravelView travelView;
  travelView.setTravelService(travelModel);
  travelView.execute(userCode);
  return 0;
}