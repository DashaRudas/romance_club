#include "config.h"
#include "cfg_parser.h"
#include <string>

ConfigOptions Config::parse(std::string filename) {

  // считывание из файла opts.json (предварительно лежит не в папке)
  CfgParser settings(filename);

  int width = std::stoi(settings.Parse("width"));
  int height = std::stoi(settings.Parse("height"));
  std::string title = settings.Parse("title");
  int fps = std::stoi(settings.Parse("fps"));
  ConfigOptions opts(width, height, title, fps);
  return opts;
}
