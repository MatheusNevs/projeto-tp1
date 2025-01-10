#include "services.hpp"

class IAAuthPresentation
{
private:
  ISAutenticacao *service;

public:
  virtual void setService(ISAutenticacao *service)
  {
    this->service = service;
  }

  virtual void present() = 0;
};

class IATravelPresentation
{
private:
  ISTravel *service;

public:
  virtual void setService(ISTravel *service)
  {
    this->service = service;
  }

  virtual void present() = 0;
};

class IADestinationPresentation
{
private:
  ISDestination *service;

public:
  virtual void setService(ISDestination *service)
  {
    this->service = service;
  }

  virtual void present() = 0;
};

class IAActivityPresentation
{
private:
  ISActivity *service;

public:
  virtual void setService(ISActivity *service)
  {
    this->service = service;
  }

  virtual void present() = 0;
};

class IALodgingPresentation
{
private:
  ISLodging *service;

public:
  virtual void setService(ISLodging *service)
  {
    this->service = service;
  }

  virtual void present() = 0;
};
