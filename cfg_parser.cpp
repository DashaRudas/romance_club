#include "cfg_parser.h"
#include <iostream>

CfgParser::CfgParser(std::string file) : filename(file) {
}

std::string CfgParser::Parse(std::string key) {
  std::ifstream file(filename);
  nlohmann::json data = nlohmann::json::parse(file);
  return data[key].get<std::string>();
}