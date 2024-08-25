#include <SFML/Graphics.hpp>

#include "game.h"

int main(int argc, char* argv[]) {
  Game engine(argc, argv);

  return engine.start();
}