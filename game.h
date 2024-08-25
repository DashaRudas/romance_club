#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "cfg_parser.h"
#include "interface.h"
#include "plot_creator.h"

////////////////////////
//////// ENGINE ////////
////////////////////////

class Game {
 public:
  int start();
  Game(int argc, char* argv[]);

 private:
  sf::RenderWindow window;

  ConfigOptions opts;
  std::string resRoot;
};

#endif