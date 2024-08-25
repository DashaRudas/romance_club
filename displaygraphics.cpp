#include "displaygraphics.h"

#include <codecvt>
#include <locale>
#include <sstream>
#include <string>

#include "config.h"
#include "state.h"


struct Naming {
  constexpr std::string pathToTexture((("game/img/").str() + ("1.png").str()));
};


DisplayGraphics::DisplayGraphics(ConfigOptions _opts) {
  opts = _opts;
  hasPrintedText = false;
  hideText = false;
  debug = false;
  textRect.setPosition(sf::Vector2f(16.f, opts.height - 16 - 128));
  textRect.setSize(sf::Vector2f(opts.width - 32.f, 128.f));
  textRect.setOutlineThickness(2); // ура ураааа мы убрали черный

  fadeRect.setSize(sf::Vector2f(opts.width, opts.height));
  fadeRect.setPosition(sf::Vector2f(0, 0));
  fadeRect.setFillColor(sf::Color::Black);

  test.setPosition(sf::Vector2f(10, 10));
  test.setSize(sf::Vector2f(20, 20));
  test.setFillColor(sf::Color::Black);

  if (!textFont.loadFromFile("/fonts/script.ttf")) {
    return 1;
  } else {
    text.setFont(textFont);
    text.setPosition(textRect.getPosition() + sf::Vector2f(7, 5));
    text.setCharacterSize(24);
    Text.setFont(textFont);
  }

  Text.setCharacterSize(18);
  nextStatement();
}

void DisplayGraphics::handleInput(sf::Event e) {
  if (e.type == sf::Event::MouseButtonReleased && delay == 0) {
    nextStatement();
  }

  if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::F3) {
    debug = !debug;
  }
}

void DisplayGraphics::render(sf::RenderWindow& window) {
  window.draw(background);
  if (!hideText) {
    window.draw(textRect);
    window.draw(text);
  }
  if (debug) window.draw(Text);
  fpsCounter.update();
}
