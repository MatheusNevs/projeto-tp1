#include "../include/services/model.hpp"
#include "../include/builder.hpp"
#include "../include/controller.hpp"

#include "../include/services/travel.hpp"
#include "../include/views/travel.hpp"

#include "../include/services/auth.hpp"
#include "../include/views/auth.hpp"

int main()
{
  Model model = Model();
  model.createTables();

  Builder builder;
  Controller controller;

  builder.build(&controller);
  controller.execute();

  return 0;
}