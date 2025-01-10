#include "../entities/account.hpp"
#include "../entities/travel.hpp"
#include "../entities/destination.hpp"
#include "../entities/activity.hpp"
#include "../entities/lodging.hpp"

class ISAutenticacao
{
public:
  virtual bool authenticate(Account account) = 0;
};

class ISTravel
{
public:
  virtual void create(Travel travel) = 0;
  virtual Travel read(int id) = 0;
  virtual void update(Travel travel) = 0;
  virtual void remove(int id) = 0;
};

class ISDestination
{
public:
  virtual void create(Destination destination) = 0;
  virtual Destination read(int id) = 0;
  virtual void update(Destination destination) = 0;
  virtual void remove(int id) = 0;
};

class ISActivity
{
public:
  virtual void create(Activity activity) = 0;
  virtual Activity read(int id) = 0;
  virtual void update(Activity activity) = 0;
  virtual void remove(int id) = 0;
};

class ISLodging
{
public:
  virtual void create(Lodging lodging) = 0;
  virtual Lodging read(int id) = 0;
  virtual void update(Lodging lodging) = 0;
  virtual void remove(int id) = 0;
};
