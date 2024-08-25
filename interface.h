#ifndef INTERFACE_H
#define INTERFACE_H
#include "button.h"

class Interface {
 protected:
  int width;
  int height;
  std::string color;
  std::vector<Button> buttons;

 public:
  Interface(int w, int h, const std::string& col) : width(w), height(h), color(col) {
  }

  virtual void draw() const {
    for (const auto& button : buttons) {
      button.draw();
    }
  }
};

#endif