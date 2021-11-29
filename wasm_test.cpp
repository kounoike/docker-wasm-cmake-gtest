#include "gtest/gtest.h"

extern "C" {
int add(int a, int b);
int sub(int a, int b);
}

TEST(WasmAdd, Test1) {
  // 1 + 2
  EXPECT_EQ(3, add(1, 2));
}

TEST(WasmSub, Test1) {
  // 2 - 1
  EXPECT_EQ(1, sub(2, 1));
}
