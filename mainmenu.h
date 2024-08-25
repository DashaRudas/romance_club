#ifndef MAINMENU_H
#define MAINMENU_H
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

enum MenuMode { kMain = 0, kSettings = 1, kGame = 2 };

class MainMenu {
 private:
  sf::Texture main_txt, levels_txt, info_txt, back_txt;
  sf::Sprite main_menu, levels_menu, info, background;
  bool isMenu;
  int menuNum;
  sf::RenderWindow* window;
  std::map<sf::Sprite, sf::Texture> menuObjectsToTextures = {
      {main_menu, main_txt},
      {levels_menu, levels_txt},
      {info, info_txt
  },
      {background
  , back_txt}};

 public:
  MainMenu(sf::RenderWindow& win);

  void display();
};

#endif
