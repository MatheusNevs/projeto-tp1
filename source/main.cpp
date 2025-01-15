#include "../include/services/model.hpp"
#include "../include/services/travel.hpp"

int main()
{
  Model model = Model();
  model.createTables();

  TravelModel travelModel = TravelModel();
  travelModel.create(Code("123456"), Travel(Code("123567"), Name("joao"), Rating("0")));
  return 0;
}