#include "Health.h"

Health* Health::clone() const
{
    return new Health(*this);
}

float Health::getHealth()
{
  return _health;
}
