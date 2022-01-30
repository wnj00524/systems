cmake_minimum_required(VERSION 3.21)
project(systems)

set(CMAKE_CXX_STANDARD 14)

add_executable(systems main.cpp src/craft.cpp headers/craft.h src/mk1_power_network/power_items.cpp headers/mk1_power_network/power_items.h src/mk1_power_network/electrical_system.cpp headers/mk1_power_network/electrical_system.h src/primitives.cpp headers/primitives.h src/Graph_Template.cpp headers/Graph_Template.h)
