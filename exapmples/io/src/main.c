#include "io.h"

int
main (int argc, char *argv[])
{
  file_t fp = io.file.open ("README.md", io.file.mode.read);
  char buf[1024];
  while (io.file.gets (buf, 1024, fp))
    io.printf ("%s", buf);
  io.file.close (fp);
  return 0;
}
