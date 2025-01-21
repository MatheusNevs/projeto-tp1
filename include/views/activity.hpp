#ifndef ACTIVITY_VIEW_HPP
#define ACTIVITY_VIEW_HPP

#include "../interfaces/presentation.hpp"
#include "../services/activity.hpp"

class ActivityView : public PresentationInterface
{
private:
  ActivityModel *activityService;

public:
  ActivityView(Code &userCode) : PresentationInterface(userCode) {};
  void setActivityService(ActivityModel *activityService)
  {
    this->activityService = activityService;
  };
  void execute(Code &userCode);
  void create();
  void update();
  void remove();
  void read();
  ~ActivityView() override
  {
    delete activityService;
  }
};

#endif // ACTIVITY_VIEW_HPP