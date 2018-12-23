#include <stdio.h>
#include <stdarg.h>
#include "io.h"

static file_t 
file_open (const char * filename, const char * mode)
{
  return (file_t *) fopen (filename, mode);
}

static char *
file_gets (char * s, int n, file_t stream)
{
  return fgets (s, n, stream);
}

static int
file_close (file_t stream)
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
  io.file.mode.read = "r";
  io.file.mode.write = "w";
  io.file.mode.append = "a";
  io.file.mode.read_extend = "r+";
  io.file.mode.write_extend = "w+";
  io.file.mode.append_extend = "a+";
  io.file.mode.binary_read = "rb"; 
  io.file.mode.binary_write = "wb";
  io.file.mode.binary_append = "ab";
  io.file.mode.binary_read_extend = "r+b";
  io.file.mode.binary_write_extend = "w+b";
  io.file.mode.binary_append_extend = "a+b";

  io.file.open = file_open;
  io.file.gets = file_gets;
  io.file.close = file_close;
  io.printf = _printf;
}
