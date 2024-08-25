CMAKE_MINIMUM_REQUIRED(VERSION 3.14)
project(HelloWorld)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(HelloWorld answers.cpp game.cpp main.cpp config.cpp cfg_parser.cpp plot_creator.cpp)
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
find_package(nlohmann_json 3.2.0 REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(HelloWorld sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
target_link_libraries(HelloWorld nlohmann_json::nlohmann_json)