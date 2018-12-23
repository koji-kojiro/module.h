#include <stdio.h>
#include "greet.h"

static void
hello (const char *name)
{
  printf ("Hello, %s.\n", name);
}

constructor
__init_math (void)
{
  greet.hello = hello;
}
