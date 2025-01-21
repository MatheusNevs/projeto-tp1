#ifndef BUILDER_INTERFACE_H
#define BUILDER_INTERFACE_H

#include "./controller.hpp"

#include "../include/services/auth.hpp"
#include "../include/views/auth.hpp"

#include "../include/services/travel.hpp"
#include "../include/views/travel.hpp"

#include "../include/services/destination.hpp"
#include "../include/views/destination.hpp"

#include "../include/services/lodging.hpp"
#include "../include/views/lodging.hpp"

// #include "../include/services/activity.hpp"
// #include "../include/views/activity.hpp"

class Builder
{
public:
  void build(Controller *controller);
};

#endif // BUILDER_INTERFACE_H