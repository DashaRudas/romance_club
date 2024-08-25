#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include "screen.h"

class Art {
 private:
  std::string data;

 public:
  Art(const std::string& path);

  void GeneratePicture();
  // использует путь к файлу для генерации изображения
};

#endif