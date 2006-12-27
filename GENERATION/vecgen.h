#ifndef VECGEN_H
#define VECGEN_H

struct vecgen {
  unsigned int dim;
  const char *type;
  const char *abbrev;
};

int gen(struct vecgen *);

#endif
