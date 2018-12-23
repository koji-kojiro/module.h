#include <stdio.h>
#include <stdarg.h>
#include "io.h"

static file_t 
_fopen (const char * filename, const char * mode)
{
  return (file_t *) fopen (filename, mode);
}

static char *
_fgets (char * s, int n, file_t stream)
{
  return fgets (s, n, stream);
}

static int
_fclose (file_t stream)
{
  return fclose (stream);
}

static int
_printf (const char *format, ...)
{
  va_list ap;
  va_start (ap, format);
  int ret = vprintf (format, ap);
  va_end (ap);
  return ret;
}

constructor
__init_math (void)
{
  io.mode.read = "r";
  io.mode.write = "w";
  io.mode.append = "a";
  io.mode.read_extend = "r+";
  io.mode.write_extend = "w+";
  io.mode.append_extend = "a+";
  io.mode.binary_read = "rb"; 
  io.mode.binary_write = "wb";
  io.mode.binary_append = "ab";
  io.mode.binary_read_extend = "r+b";
  io.mode.binary_write_extend = "w+b";
  io.mode.binary_append_extend = "a+b";

  io.fopen = _fopen;
  io.fgets = _fgets;
  io.fclose = _fclose;
  io.printf = _printf;
}
