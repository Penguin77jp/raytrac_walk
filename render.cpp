#include "render.h"

namespace raytrac {

  void Render::Rendering() {
    // ワールド座標系でのスクリーンの大きさ
    const double screen_width = 30.0 * width / height;
    const double screen_height = 30.0;
    // スクリーンまでの距離
    const double screen_dist = 40.0;

    // スクリーンを張るベクトル
    const Vec3 screen_x = normalize(cross(sceneData->camera_dir, sceneData->camera_up)) * screen_width;
    const Vec3 screen_y = -normalize(cross(screen_x, sceneData->camera_dir)) * screen_height;
    const Vec3 screen_center = sceneData->camera_position + sceneData->camera_dir * screen_dist;

    //std::cout << width << "x" << height << " " << samples * (supersamples * supersamples) << " spp" << std::endl;

    // OpenMP
#pragma omp parallel for schedule(dynamic, 1)
    for (int y = 0; y < height; y++) {
      std::cerr << "Rendering (y = " << y << ") " << (100.0 * y / (height - 1)) << "%" << std::endl;
      Random rnd(y + 1+samples);
      for (int x = 0; x < width; x++) {
        const int image_index = y* width + x;
        // supersamples x supersamples のスーパーサンプリング
        for (int sy = 0; sy < supersamples; sy++) {
          for (int sx = 0; sx < supersamples; sx++) {
            const double rate = (1.0 / supersamples);
            const double r1 = sx * rate + rate / 2.0;
            const double r2 = sy * rate + rate / 2.0;
            // スクリーン上の位置
            const Vec3 screen_position =
              screen_center +
              screen_x * ((r1 + x) / width - 0.5) +
              screen_y * ((r2 + y) / height - 0.5);
            // レイを飛ばす方向
            const Vec3 dir = normalize(screen_position - sceneData->camera_position);

            //image[image_index] = image[image_index] + radiance(Ray(sceneData->camera_position, dir), &rnd, 0, sceneData) / (supersamples * supersamples);
            auto cal = radiance(Ray(sceneData->camera_position, dir), &rnd, 0, sceneData) / (supersamples * supersamples);
            image[image_index] = Color(image[image_index].x + cal.x, image[image_index].y + cal.y, image[image_index].z + cal.z);
          }
        }
      }
    }
    samples++;


    // 出力
    //pWrite("image.png", image, width, height * 2);
    //free(image);
  }

  Image Render::GetImage() {
    Image tmp = Image(width, height);
#pragma omp parallel for schedule(dynamic, 1)
    for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
        const int index = y * width + x;
        const int r = to_int(image[index].x / samples);
        const int g = to_int(image[index].y / samples);
        const int b = to_int(image[index].z / samples);

        if (r + g + b == 0) {  

          // ワールド座標系でのスクリーンの大きさ
          const double screen_width = 30.0 * width / height;
          const double screen_height = 30.0;
          // スクリーンまでの距離
          const double screen_dist = 40.0;

          // スクリーンを張るベクトル
          const Vec3 screen_x = normalize(cross(sceneData->camera_dir, sceneData->camera_up)) * screen_width;
          const Vec3 screen_y = -normalize(cross(screen_x, sceneData->camera_dir)) * screen_height;
          const Vec3 screen_center = sceneData->camera_position + sceneData->camera_dir * screen_dist;

          Random rnd(y + 1);
          // スクリーン上の位置
          const Vec3 screen_position =
            screen_center +
            screen_x * ((double)x / width - 0.5) +
            screen_y * ((double)y / height - 0.5);
          // レイを飛ばす方向
          const Vec3 dir = normalize(screen_position - sceneData->camera_position);

          auto cal = radiance_(Ray(sceneData->camera_position, dir), &rnd, 0, sceneData);
          tmp[y][x] = s3d::Color(to_int(cal.x), to_int(cal.y), to_int(cal.z));
        }
        else {
          tmp[y][x] = s3d::Color(r, g, b);
        }
      }
    }
    return tmp;
  }
};
