#include "wasm.hpp"
#include "gtest/gtest.h"

TEST(WasmAdd, Test1) {
  // 1 + 2
  EXPECT_EQ(3, add(1, 2));
}

TEST(WasmSub, Test1) {
  // 2 - 1
  EXPECT_EQ(1, sub(2, 1));
}
