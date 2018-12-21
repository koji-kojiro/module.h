# module.h
## Overview
**module.h** is a header-obly library contains an implementation of simple module system for C programming language.

## Usage
### Creating a module
A module should consist of a pair of a header file and .c source file. Here is an example below:

#### greet.h

```:.c
#pragma once
#include <module.h>

/* module declaration.
 * `module(name)` is a macro function which generates struct definition and more.
 */
module (greet)
{
  /* function should be declared as a function pointer. */
  void (*hello) (const char *); 
};

```

#### greet.c

```:.c
#include <stdio.h>
#include "greet.h"

/* module members should be static. */
static void
hello (const char *name)
{
  printf ("Hello, %s\n", name);
}

/* you should define a function to initialize module menmbers. 
 * `constructor` is a macro defined in `module.h`.
 */
constructor
__init_greet (void)
{
  greet.hello = hello;
}

```

You can use this `greet` module as follows.

```:.c
#include "greet.h"

int
main (int argc, char *argv[])
{
  greet.hello ("Kojiro");
  return 0;
}
```

## How it works
`module (foo) { ... };` is expanded as follows:

```:.c
constructor __init_foo (void);
struct module_foo foo;
struct module_foo { ... };
```

`constructor` is expanded to `__attribute__((constructor)) void`.
So, the function `__init_foo` is hooked to main function and it initializes the struct foo.

