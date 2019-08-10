#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <cmath>
#include <iostream>
#include <Siv3D.hpp>
#include "radiance.h"
#include "random.h"
#include "Scene.h"
#include <vector>

namespace raytrac {

  class Render {
  public:
    int width, height;
    int samples;
    int supersamples;
    Scene* sceneData;
    std::vector<Color> image;
    Render(const int width, const int height,const int supersamples, Scene* sceneData) {
      image =  std::vector<Color>(width*height);
      this->width = width;
      this->height = height;
      this->supersamples = supersamples;
      this->sceneData = sceneData;
    }
    void Rendering();

    Image GetImage();

  };

  inline double clamp(double x) {
    if (x < 0.0)
      return 0.0;
    if (x > 1.0)
      return 1.0;
    return x;
  }

  inline int to_int(double x) {
    return int(pow(clamp(x), 1 / 2.2) * 255 + 0.5);
  }
};

