#pragma once
#include "vec.h"

namespace raytrac {

  struct Ray {
    Vec3 org, dir;
    Ray(const Vec3& org, const Vec3& dir) : org(org), dir(dir) {}
  };

};

