cmake_minimum_required(VERSION 3.5)

project(fuji-steg)

include_directories(include)

# Make executable with main.c and steg.cpp
add_executable(steg src/main.c src/steg.c)