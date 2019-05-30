#include <iostream>
#include "funcs.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Task A") {
  CHECK(square(3) == 9);
  CHECK(square(7) == 49);
  CHECK(square(0) == 0);
  CHECK(square(-2) == 4);
}

TEST_CASE("Task B") {
  range(1, 10);
  range(0, 11);
  range(30, 32);
}

TEST_CASE("Task C") {
  array();
}

TEST_CASE("Task D") {
  fibonacci(10);
}
