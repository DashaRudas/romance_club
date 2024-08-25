#include "answers.h"

Answers::json ParseJsonFile(const std::string& fileName) {
  currentFileBeingProcessed = fileName;
  std::ifstream stream(fileName);
  json jsonData = json::parse(stream);
  return jsonData;
}

Answers::std::string GetLastReadFileName() {
  return currentFileBeingProcessed;
}

Answers::static bool GetBoolean(json object, const std::string& fieldName) {
  bool value = false;
  try {
    value = object[fieldName].get<bool>();
  } catch (json::exception& e) {
    handleError(e, fieldName);
  }
  return value;
}

Answers::static int GetInteger(json object, const std::string& fieldName) {
int value = false;
try {
    value = object[fieldName].get<int>();
} catch (json::exception& e) {
    handleError(e, fieldName);
}
return value;
}

Answers::static std::string GetString(json object, const std::string& fieldName) {
  std::string value;
  try {
    value = object[fieldName].get<std::string>();
  } catch (json::exception& e) {
    handleError(e, fieldName);
  }
return value;
}
