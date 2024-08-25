#include "button.h"

Button::Button(sf::Vector2f pos, sf::Vector2f sizes, sf::RenderWindow* wind)
    : position_(pos), size_(sizes), normal_size_(sizes), window_(wind) {}

void Button::setColor(sf::Color col) { button_color_ = col; }

void Button::setBorder(int width) {
  if (width % 2 != 0) {
    border_size_ = width + 1;
  } else {
    border_size_ = width;
  }
  has_border_ = true;
}

void Button::setBorderColor(sf::Color col) {
  border_color_ = col;
  has_border_ = true;
}

void Button::setClickButton(sf::Mouse::Button click) { click_button_ = click; }

bool Button::draw() {
  if (in_bounds_) normal_size_ = size_;

  if (size_.x > texture_size_.x || size_.y > texture_size_.y)
    size_ = normal_size_;

  if (!has_border_) {
    sf::RectangleShape button(size_);
    button.setPosition(position_);
    button.setFillColor(button_color_);
    window_->draw(button);
  }

  if (!has_border_) {
    button_sprite_.setPosition(position_);
    window_->draw(button_sprite_);
  }

  if (has_border_) {
    sf::Vector2f border_vec_size = {border_size_, border_size_};
    sf::Vector2f border_vec_pos = {border_size_ / 2, border_size_ / 2};

    sf::RectangleShape button(size_ - border_vec_size);
    button.setPosition(position_ + border_vec_pos);
    button.setFillColor(button_color_);

    sf::RectangleShape border(size_);
    border.setPosition(position_);
    border.setFillColor(border_color_);

    window_->draw(border);
    window_->draw(button);
  }

  if (has_border_) {
    button_sprite_.setTextureRect(
        sf::IntRect(texture_start_.x, texture_start_.y, size_.x - border_size_,
                    size_.y - border_size_));
    button_sprite_.setPosition(position_.x + border_size_ / 2,
                               position_.x + border_size_ / 2);

    sf::RectangleShape border(normal_size_);
    border.setPosition(position_);
    border.setFillColor(border_color_);

    sf::RectangleShape mask(sf::Vector2f(normal_size_.x - border_size_,
                                         normal_size_.y - border_size_));
    mask.setPosition(position_.x + border_size_ / 2,
                     position_.x + border_size_ / 2);
    mask.setFillColor(sf::Color::Black);
    in_bounds_ = false;

    window_->draw(border);
    window_->draw(mask);
    window_->draw(button_sprite_);
  }

  sf::Vector2i mouse_coords = sf::Mouse::getPosition(*window_);
  sf::Vector2u win_size = window_->getSize();
  if (mouse_coords.x <= win_size.x && mouse_coords.y <= win_size.y &&
      mouse_coords.x >= position_.x &&
      mouse_coords.x <= position_.x + normal_size_.x &&
      mouse_coords.y >= position_.y &&
      mouse_coords.y <= position_.x + normal_size_.y &&
      sf::Mouse::isButtonPressed(click_button_)) {
    return true;
  } else {
    return false;
  }
}