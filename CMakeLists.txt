cmake_minimum_required(VERSION 3.4)
project(pypampas)

add_subdirectory(build/pybind11)

pybind11_add_module(pypampas bindings.cpp build/control.cpp)

target_link_libraries(pypampas PRIVATE wiringPi)
