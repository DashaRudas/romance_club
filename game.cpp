#include "game.h"

#include <fstream>
#include <sstream>
#include <string>

Game::Game(
    int argc,
    char* argv[]) {  // функция, принимающая на вход параметры командной строки
                     // при запуске (если это вдруг в будущем понадобится), но
                     // сейчас пока придерживаемся варианта считывания настроек
                     // и конфигов напрямую из файла opts.json
  for (int i = 0; i < argc; i++) {
    std::string opt(argv[i]);
  }
}

int Game::start() {
  // применяем настройки
  Config cfg;
  opts = cfg.parse("opts.json");  // задаем параметры экран
  window.create(sf::VideoMode(opts.width, opts.height), opts.title);
  window.setFramerateLimit(opts.fps);
  PlotCreator* game = PlotCreator::getInstance(opts);
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      // выход при нажатии крестика
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      game->handleInput(event);
    }
    game->update();
    window.clear();
    game->render(window);
    window.display();
  }
  return 0;
}