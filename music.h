#ifndef MUSIC_H
#define MUSIC_H

#include <string>

class Music {
 private:
  std::string data;

 public:
  Music(const std::string& path);

  void GenerateMusic();

  // использует путь к файлу для генерации изображения
};

#endif