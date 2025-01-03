cmake_minimum_required(VERSION 3.4)
project(pycontrol)

add_subdirectory(build/pybind11)

pybind11_add_module(pycontrol bindings.cpp build/control.cpp)

target_link_libraries(pycontrol PRIVATE wiringPi)
