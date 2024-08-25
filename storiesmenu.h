#ifndef STORIESMENU_H
#define STORIESMENU_H

#include "mainmenu.h"

class StoriesMenu : public MainMenu {
 public:
  StoriesMenu(int w, int h, const std::string& m) : MainMenu(w, h, m) {
  }

  void start() override {
  }
};

#endif