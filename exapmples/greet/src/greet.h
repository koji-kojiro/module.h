#pragma once
#include "module.h"

module (greet)
{
  void (*hello) (const char *);
};
