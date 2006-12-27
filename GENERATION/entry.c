#include <stdlib.h>
#include "vecgen.h"

struct vecgen vg;

int main(int argc, char *argv[])
{
  if (argc < 2) return 111;
  vg.dim = atoi(argv[1]);
  if (!vg.dim) return 112;
  if (argc >= 4) {
    vg.type = argv[2];
    vg.abbrev = argv[3];
  }
  return gen(&vg);
}
