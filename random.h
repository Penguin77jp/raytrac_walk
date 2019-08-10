#ifndef _RANDOM_H_
#define _RANDOM_H_

#include <climits>

namespace raytrac {

  // Xor-Shiftによる乱数ジェネレータ
  class XorShift {
    unsigned int seed_[4];
  public:
    unsigned int next(void);

    double next01(void);

    XorShift(const unsigned int initial_seed);
  };

  typedef XorShift Random;

};

#endif
