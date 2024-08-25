#ifndef DISPLAYGRAPHICS_H
#define DISPLAYGRAPHICS_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

#include "cfg_parser.h"
#include "config.h"
#include "interface.h"

class DisplayGraphics : public Interface {
 public:
  void handleInput(sf::Event e);
  void render(sf::RenderWindow& window);

 private:
  DisplayGraphics(ConfigOptions _opts);
  DisplayGraphics(DisplayGraphics const&) = delete;
  void operator=(DisplayGraphics const&) = delete;
  static DisplayGraphics* instance;
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

  int delay;

  bool hideText;
  bool musicison = false;

  bool debug;
};

#endif