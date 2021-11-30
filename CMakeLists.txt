cmake_minimum_required(VERSION 3.10)
project(wasm LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
if(CMAKE_CROSSCOMPILING)
  add_executable(wasm wasm.cpp)
  set_property(TARGET wasm PROPERTY SUFFIX ".html")
endif()

# Test
enable_testing()
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.11.0
)
FetchContent_Declare(
  googlebenchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG v1.6.0
)
FetchContent_MakeAvailable(googletest googlebenchmark)

include(GoogleTest)

add_executable(wasm_test wasm_test.cpp wasm.cpp)
target_link_libraries(wasm_test gtest_main)

if(CMAKE_CROSSCOMPILING)
  file(COPY "${CMAKE_SOURCE_DIR}/run_test.sh" DESTINATION ${CMAKE_BINARY_DIR} USE_SOURCE_PERMISSIONS)
  target_link_options(wasm_test PRIVATE "--emrun")
  set_property(TARGET wasm_test PROPERTY SUFFIX ".html")
  set_property(TARGET wasm_test PROPERTY CROSSCOMPILING_EMULATOR "./run_test.sh")
endif()

gtest_discover_tests(wasm_test DISCOVERY_TIMEOUT 20)

# Performance benchmark
add_executable(wasm_perf wasm_perf.cpp wasm.cpp)
target_link_libraries(wasm_perf benchmark_main)
if(CMAKE_CROSSCOMPILING)
  target_link_options(wasm_perf PRIVATE "--emrun")
  set_property(TARGET wasm_perf PROPERTY SUFFIX ".html")
  set_property(TARGET wasm_perf PROPERTY CROSSCOMPILING_EMULATOR "./run_test.sh")
endif()
