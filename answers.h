#ifndef ANSWERS_H
#define ANSWERS_H

#include <fstream>
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Answers {
 public:
  json ParseJsonFile(const std::string& fileName);
  std::string GetLastReadFileName();
  static bool GetBoolean(json object, const std::string& fieldName);
  static std::string GetString(json object, const std::string& fieldName);
  static std::string GetInteger(json object, const std::string& fieldName);
 private:
  std::string currentFileBeingProcessed;
  std::string currentFieldBeingProcessed;
};

#endif
