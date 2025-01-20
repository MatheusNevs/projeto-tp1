#ifndef DESTINATION_MODEL_HPP
#define DESTINATION_MODEL_HPP

#include "model.hpp"
#include "../interfaces/services.hpp"

class DestinationModel : public DestinationServiceInterface, public Model
{
public:
  void create(Code &userCode, Destination &newDestination) override;
  void update(Code &userCode, Code &destinationCode, Destination &updatedDestination) override;
  void remove(Code &userCode, Code &destinationCode) override;
  vector<Destination> read(Code &userCode) override;
  ~DestinationModel() override {};
};

#endif // DESTINATION_MODEL_HPP
