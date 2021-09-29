#include <stack>

#include "../ZLibString.hpp"
#include "gtest/gtest.h"

const std::string k_lorem{
    "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse quis "
    "massa ante. Etiam sed lorem lacus. Cras fringilla ac odio id eleifend. "
    "Cras justo turpis, pretium in mi ac, sodales pretium justo. Pellentesque "
    "habitant morbi tristique senectus et netus et malesuada fames ac turpis "
    "egestas. Donec rhoncus dui nisl, quis finibus metus maximus vel. Praesent "
    "justo augue, eleifend nec sagittis nec, pulvinar efficitur orci. Nullam "
    "tempor vestibulum tortor, vitae vehicula dolor tempus sit amet. Proin "
    "placerat est metus, eget aliquam orci volutpat in. Integer sit amet mi "
    "sem. Cras id porttitor dolor. Quisque et aliquet turpis. "};

const size_t k_lorem_length{k_lorem.length()};

#define TEST_RATIO(_val)                                                       \
  std::string zstring = compress_string(k_lorem, (_val));                      \
  double ratio{static_cast<double>(zstring.length()) /                         \
               static_cast<double>(k_lorem.length())};                         \
  std::cout << "Store ratio " << ratio << std::endl;                           \
  if (_val != 0)                                                               \
    EXPECT_LE(ratio, 1);                                                       \
  else                                                                         \
    EXPECT_GE(ratio, 1);

TEST(Lorem, k_lorem) { EXPECT_EQ(k_lorem.length(), k_lorem_length); }

TEST(Lorem, zlength0) { TEST_RATIO(0); }

TEST(Lorem, zlength1) { TEST_RATIO(1); }

TEST(Lorem, zlength2) { TEST_RATIO(2); }

TEST(Lorem, zlength3) { TEST_RATIO(3); }

TEST(Lorem, zlength4) { TEST_RATIO(4); }

TEST(Lorem, zlength5) { TEST_RATIO(5); }

TEST(Lorem, zlength6) { TEST_RATIO(6); }

TEST(Lorem, zlength7) { TEST_RATIO(7); }

TEST(Lorem, zlength8) { TEST_RATIO(8); }

TEST(Lorem, zlength9) { TEST_RATIO(9); }