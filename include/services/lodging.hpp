#ifndef LODGING_SERVICE_H
#define LODGING_SERVICE_H

#include "./model.hpp"
#include "../interfaces/services.hpp"

class LodgingModel : public LodgingServiceInterface, public Model
{
public:
  void create(Code &userCode, Code &lodgingDestinationCode, Lodging &newLodging) override;
  vector<Lodging> read(Code &userCode) override;
  void update(Code &userCode, Code &lodgingCode, Lodging &updatedLodging) override;
  void remove(Code &userCode, Code &lodgingCode) override;
  ~LodgingModel() override {}
};

#endif // LODGING_SERVICE_H