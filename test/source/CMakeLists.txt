# Test Executable
add_executable(${PROJECT_NAME}_test main.cpp ex.cpp)

target_link_libraries(
  ${PROJECT_NAME}_test PRIVATE doctest::doctest gcem xtensor
)

target_include_directories(
  ${PROJECT_NAME}_test PRIVATE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/test>
                               $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

set_property(
  TARGET ${PROJECT_NAME}_test PROPERTY CMAKE_EXPORT_COMPILE_COMMANDS ON
)

# Compiler Properties for testing
target_compile_features(${PROJECT_NAME}_test PRIVATE cxx_std_23)
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(${PROJECT_NAME}_test PRIVATE /bigobj /W4 /WX)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(
    ${PROJECT_NAME}_test
    PRIVATE -g
            -Wall
            -Wextra
            -Wpedantic
            -Werror
            -Wno-psabi # disable abi change warnings
            -Wno-macro-redefined
            -std=c++2b
  )
else()
  target_compile_options(
    ${PROJECT_NAME}_test
    PRIVATE -g
            -Wall
            -Wextra
            -Wpedantic
            -Werror
            -Wno-macro-redefined
            -std=c++2b
  )
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lc++abi")
endif()

enable_testing()
include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)
doctest_discover_tests(${PROJECT_NAME}_test)
