#include "random.h"

namespace raytrac {

  // Xor-Shiftによる乱数ジェネレータ
  unsigned int XorShift::next(void) {
    const unsigned int t = seed_[0] ^ (seed_[0] << 11);
    seed_[0] = seed_[1];
    seed_[1] = seed_[2];
    seed_[2] = seed_[3];
    return seed_[3] = (seed_[3] ^ (seed_[3] >> 19)) ^ (t ^ (t >> 8));
  }

  double XorShift::next01(void) {
    return (double)next() / UINT_MAX;
  }

  XorShift::XorShift(const unsigned int initial_seed) {
    unsigned int s = initial_seed;
    for (int i = 1; i <= 4; i++) {
      seed_[i - 1] = s = 1812433253U * (s ^ (s >> 30)) + i;
    }
  }
};


