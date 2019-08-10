# include <Siv3D.hpp>
#include "Scene.h"
#include "render.h"

void Main()
{
  const int width = 500, height = 500;
  //const int width = 1000, height = 800;
  const double MultiSize = 1.5;
  Window::Resize(width*MultiSize, height*MultiSize);
  DynamicTexture texture(width, height);

  raytrac::Scene scene;
  raytrac::Render render = raytrac::Render(width,height,2,&scene);

  int samples = 1;
  while (System::Update())
  {
    ClearPrint();
    
    if (KeyD.down()) {
      if (samples > 1) {
        samples--;
      }
    }
    if (KeyU.down()) {
      samples++;
    }

    for (int s = 0; s < samples; s++) {
      render.Rendering();
    }
    texture.fill( render.GetImage());
    texture.scaled(MultiSize, MultiSize).draw();
    Print << U"samples" << samples;
    Print << U"Total samples" << render.samples;
  }
}
