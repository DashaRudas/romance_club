#ifndef PLOTCREATOR_H
#define PLOTCREATOR_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "config.h"
#include "cfg_parser.h"

class PlotCreator {
 public:
  void handleInput(sf::Event e);
  void render(sf::RenderWindow& window);
  void update();
  static PlotCreator* getInstance(ConfigOptions _opts);
  void nextStatement();

 private:
  PlotCreator(ConfigOptions _opts);
  PlotCreator(PlotCreator const&) = delete;
  void operator=(PlotCreator const&) = delete;
  static PlotCreator* instance;
  ConfigOptions opts;
  sf::Music music;
  sf::Texture backgroundTex;
  sf::Sprite background;
  sf::RectangleShape fadeRect;

  int branch;
  int number;

  sf::RectangleShape textRect;
  sf::RectangleShape test;
  sf::Text text;
  sf::Font textFont;
  sf::Clock textClock;
  sf::Clock delayClock;
  std::wstring textStr;
  bool hasPrintedText;
  std::string::size_type textPos;
  sf::Text debugText;
  CfgParser plot("plot.json");

  int delay;

  bool hideText;
  bool musicison = false;

  bool debug;
};

#endif