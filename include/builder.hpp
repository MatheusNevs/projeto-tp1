#ifndef BUILDER_INTERFACE_H
#define BUILDER_INTERFACE_H

#include "./views/auth.hpp"
#include "./views/travel.hpp"
#include "./controller.hpp"

class Builder
{
public:
  void build(Controller *controller);
};

#endif // BUILDER_INTERFACE_H