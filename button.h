#ifndef BUTTON_H
#define BUTTON_H
#include <string>
#include <SFML/Graphics.hpp>

class Button {
 private:
  sf::Vector2f position_;
  sf::Vector2f size_;
  sf::Vector2f normal_size_;
  sf::Vector2i texture_size_;
  sf::Vector2i texture_start_;
  sf::RenderWindow* window_;
  sf::Color button_color_;
  sf::Color border_color_;
  bool has_border_ = false;
  bool in_bounds_ = true;
  float border_size_ = 0;
  sf::Texture button_texture_;
  sf::Sprite button_sprite_;
  sf::Mouse::Button click_button_;

 public:
  Button(sf::Vector2f pos, sf::Vector2f sizes, sf::RenderWindow* wind);
  void setColor(sf::Color col);
  void setBorder(int width);
  void setBorderColor(sf::Color col);
  void setClickButton(sf::Mouse::Button click);
  bool draw();
};

#endif