#pragma once
#include "module.h"

/* avoid to include stdio.h */
typedef void * file_t;

module (io)
{
  struct
    {
      struct
        {
          const char *read;
          const char *write;
          const char *append;
          const char *append_extend;
          const char *read_extend;
          const char *write_extend;
          const char *binary_read;
          const char *binary_write;
          const char *binary_append;
          const char *binary_read_extend;
          const char *binary_write_extend;
          const char *binary_append_extend;
        } mode;
      file_t (*open) (const char *, const char *);
      char *(*gets) (char *, int, file_t);
      int (*close) (file_t);
    } file;
  int (*printf) (const char *, ...);   
};
