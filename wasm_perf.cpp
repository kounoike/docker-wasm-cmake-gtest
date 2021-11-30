#include "wasm.hpp"
#include <benchmark/benchmark.h>

static void BM_Add(benchmark::State &state) {
  for (auto _ : state) {
    int ret = add(1, 2);
  }
}
// Register the function as a benchmark
BENCHMARK(BM_Add);

// Define another benchmark
static void BM_Sub(benchmark::State &state) {
  for (auto _ : state) {
    int ret = sub(3, 2);
  }
}
BENCHMARK(BM_Sub);
