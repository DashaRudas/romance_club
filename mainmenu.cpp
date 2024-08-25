#include "mainmenu.h"

struct Constants {
  static const sf::IntRect first_button(100, 30, 300, 50);
  static const sf::IntRect second_button(100, 90, 300, 50);
  static const sf::Color beautiful_sky(sf::Color::Blue);
  static const sf::Color sparkly_snow(sf::Color::White);
  static const sf::Color ugly_sky(sf::Color(129, 181, 221));
}

MainMenu::MainMenu(sf::RenderWindow& win)
    : window(&win), isMenu(true), menuNum(MenuMode::kMain) {
  for (auto it : menuObjectsToTextures) {
    (it.second).loadfromFile("sadness.png");  // теперь очень очень не грустно))
  }
  for (auto it : menuObjectsToTextures) {
    (it.first).setTexture(it.second);
  }

  main_menu.setPosition(100, 30);
  levels_menu.setPosition(100, 90);
  background.setPosition(345, 0);
}

void MainMenu::display() {
  while (isMenu) {
    main_menu.setColor(Constants::sparkly_snow);
    levels_menu.setColor(Constants::sparkly_snow);
    menuNum = MenuMode::kMain;
    window->clear(Constants::ugly_sky);

    if (Constants::first_button.contains(sf::Mouse::getPosition(*window))) {
      main_menu.setColor(Constants::beautiful_sky);
      menuNum = MenuMode::kSettings;
    }
    if (Constants::second_button.contains(sf::Mouse::getPosition(*window))) {
      levels_menu.setColor(Constants::beautiful_sky);
      menuNum = MenuMode::kGame;
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      if (menuNum == MenuMode::kSettings) isMenu = false;
      if (menuNum == MenuMode::kGame) {
        window->draw(info);
        window->display();
        while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
          ;
      }
    }

    window->draw(background);
    window->draw(main_menu);
    window->draw(levels_menu);

    window->display();
  }
}

void menu(sf::RenderWindow& window) {
  MainMenu mainMenu(window);
  mainMenu.display();
}
