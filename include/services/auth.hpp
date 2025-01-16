#ifndef AUTH_MODEL_INTERFACE_H
#define AUTH_MODEL_INTERFACE_H

#include "./model.hpp"
#include "../interfaces/services.hpp"

class AuthModel : public AuthServiceInterface, public Model
{
public:
  bool autenticate(Code userCode, Password userPassword);
  void create(Code userCode, Password userPassword);
};

#endif // AUTH_MODEL_INTERFACE_H