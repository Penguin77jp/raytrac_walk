#pragma once

#include "vec.h"
#include "constant.h"

namespace raytrac {

  struct Hitpoint {
    double distance;
    Vec3 normal;
    Vec3 position;

    Hitpoint() : distance(kINF), normal(), position() {}
  };

  struct Intersection {
    Hitpoint hitpoint;
    int object_id;

    Intersection() : object_id(-1) {}
  };

};

