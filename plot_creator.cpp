#include "plot_creator.h"

#include <codecvt>
#include <locale>
#include <sstream>
#include <string>

#include "config.h"
#include "state.h"

PlotCreator* PlotCreator::getInstance(ConfigOptions _opts) {
  if (instance == nullptr) {
    instance = new PlotCreator(_opts);
  }
  return instance;
}

void PlotCreator::nextStatement() {
  number++;
  if (state.GetDiplomacy > state.GetStrength) {
    branch = 1;
  } else {
    branch = 2;
  }

  text.setString(
      plot.Parse(std::to_string(branch) + "." + std::to_string(number)));
  hasPrintedText = false;
  textPos = 0;

  if (!musicison) {
    musicon = true;
    music.setLoop(true);
    music.play();
  }

  nextStatement();
  return;
}

void PlotCreator::update() {
  if (!hasPrintedText && textClock.getElapsedTime().asMilliseconds() > 30) {
    textPos++;
    if (textPos >= textStr.size()) {
      hasPrintedText = false;
    } else {
      std::wstring newStr = text.getString().toWideString();
      newStr += textStr[textPos];
      sf::String newsfStr(newStr);
      sf::String wrappedStr = Utils::wrapText(
          newsfStr, static_cast<unsigned int>(textRect.getSize().x), textFont,
          24.f);
      text.setString(wrappedStr);
    }
  }
}