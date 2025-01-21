#ifndef LODGING_VIEW_HPP
#define LODGING_VIEW_HPP

#include "../interfaces/presentation.hpp"
#include "../services/lodging.hpp"

class LodgingView : public PresentationInterface
{
private:
  LodgingModel *lodgingService;

public:
  LodgingView(Code &userCode) : PresentationInterface(userCode) {};
  void setLodgingService(LodgingModel *lodgingService)
  {
    this->lodgingService = lodgingService;
  };
  void execute(Code &userCode);
  void create();
  void update();
  void remove();
  void read();
  ~LodgingView() override
  {
    delete lodgingService;
  }
};

#endif // LODGING_VIEW_HPP