#ifndef ISOPAD_H
#define ISOPAD_H

#include "quantum.h"

#define LAYOUT( \
      k00, k01, k02, \
      k10, k11, k12 \
) \
{ \
    { k00, k01, k02 }, \
    { k10, k11, k12 } \
}

#endif
