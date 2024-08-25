#ifndef CONFIG_H
#define CONFIG_H

#include <string>

////////////////////////////////
//////// CONFIGOPTIONS /////////
////////////////////////////////

class ConfigOptions {
 public:
  int width;          // ширина окна
  int height;         // высота окна
  std::string title;  // название игры
  int fps;

  ConfigOptions() = default;
  ConfigOptions(int width_, int height_, std::string title_, int fps_)
      : width(width_), height(height_), title(title_), fps(fps_) {}
};

////////////////////////
//////// CONFIG ////////
////////////////////////

class Config {
 public:
  ConfigOptions parse(std::string filename);
};

#endif