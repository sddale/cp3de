# Adapted from https://github.com/TheLartians/ModernCppStarter
cmake_minimum_required(VERSION 3.14)

# ---- Project ----
project(
  cp3de
  VERSION 0.0.1
  LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CPM_SOURCE_CACHE "build/.cache")

# ---- Add dependencies via CPM ----
# See https://github.com/TheLartians/CPM.cmake for more info
include(cmake/CPM.cmake)
CPMAddPackage("gh:onqtam/doctest@2.4.11") # Unit testing
CPMAddPackage("gh:TheLartians/Format.cmake@1.7.3") # format check action
# CPMAddPackage("gh:sddale/csm-units#main")
CPMAddPackage("gh:xtensor-stack/xtl#master") # dependency for xtensor
CPMAddPackage("gh:xtensor-stack/xtensor#master")
CPMAddPackage("gh:kthohr/gcem@1.17.0") # constexpr math library

add_subdirectory(test/source)

if(CP3DE_TEST)
  enable_testing()
endif()
