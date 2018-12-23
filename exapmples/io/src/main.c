#include "io.h"

int
main (int argc, char *argv[])
{
  file_t fp = io.fopen ("README.md", io.mode.read);
  char buf[1024];
  while (io.fgets (buf, 1024, fp))
    io.printf ("%s", buf);
  io.fclose (fp);
  return 0;
}
