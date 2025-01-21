#ifndef ACTIVITY_SERVICE_H
#define ACTIVITY_SERVICE_H

#include "./model.hpp"
#include "../interfaces/services.hpp"

class ActivityModel : public ActivityServiceInterface, public Model
{
public:
  void create(Code &userCode, Code &activityDestinationCode, Activity &newActivity) override;
  vector<Activity> read(Code &userCode) override;
  void update(Code &userCode, Code &activityCode, Activity &updatedActivity) override;
  void remove(Code &userCode, Code &activityCode) override;
  ~ActivityModel() override {}
};

#endif // ACTIVITY_SERVICE_H