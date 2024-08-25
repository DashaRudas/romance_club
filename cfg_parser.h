#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <fstream>
#include <nlohmann/json.hpp>  // через cmake
#include <string>

///////////////////////////
//////// CFGPARSER ////////
///////////////////////////

// ищет заданый параментр в json файле

class CfgParser {
 private:
  std::string filename;

 public:
  explicit CfgParser(std::string file);
  std::string Parse(std::string);
};

#endif