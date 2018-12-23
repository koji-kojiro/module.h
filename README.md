# module.h
## Overview
**module.h** is a header-only library contains an implementation of simple module system for C programming language.
This is quite experimental library. So, use at your own risks.

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
So, the function `__init_foo` is hooked to main function and it initializes the struct `foo`.
It can be said that each modules are singletons.

You can also create sub-modules like this:

```:.c
module (foo)
{
  struct
    {
      void (*baz) (void); 
    } bar;
}
```

The constructor should be:

```:.c
constructor
__init_foo (void)
{
  foo.bar.baz = baz;
}
```

## Limitations
All the functions or the variables belonging to a module are actualy members of a struct named same as the module.
So, macros and types could not be contained in a module.

```:.c
module (foo)
{
  int (*bar) (void); /* works */
  double baz;        /* works */
  typedef qux quux;  /* error */
};
```

## Benefits
`module.h` allows you to avoid a kind of name-conflicting problems.
C basically doesn't have namespaces, so, sometimes some kinf of prefix or suffix rules are taken,
for example, `fprintf` for files and `printf` for stdout.  
`module.h` can avoid this old manner. Please refer examples/io.

## License
moule.h is distributed under [MIT License](LICENSE).

## Author
[TANI Kojiro](https://github.com/koji-kojiro) (kojiro0531@gmail.com)
