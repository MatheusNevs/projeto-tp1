#ifndef DESTINATION_VIEW_INTERFACE_H
#define DESTINATION_VIEW_INTERFACE_H

#include "../interfaces/presentation.hpp"
#include "../interfaces/services.hpp"

class DestinationView : public PresentationInterface
{
private:
  DestinationServiceInterface *destinationService;

public:
  DestinationView(Code &userCode) : PresentationInterface(userCode) {};
  void setDestinationService(DestinationServiceInterface *destinationService)
  {
    this->destinationService = destinationService;
  };
  void execute(Code &userCode) override;

  void create();
  void update();
  void read();
  void remove();
  ~DestinationView() override
  {
    delete destinationService;
  };
};

#endif // DESTINATION_VIEW_INTERFACE_H