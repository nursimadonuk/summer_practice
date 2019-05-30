#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "funcs.h"
#include "doctest.h"

TEST_CASE("Task A") {
  CHECK(smaller(15, -24) == -24);
  CHECK(smaller(0, 9) == 0);
  CHECK(smaller(42678, 4576) == 4576);
  CHECK(smaller(90, 98) == 90);
  CHECK(smaller(0, 0) == 0);
}

TEST_CASE("Task B") {
  CHECK(smallest(3287, 80, 8797) == 80);
  CHECK(smallest(30, 90, 180) == 30);
  CHECK(smallest(-90, -100, 80) == -100);
  CHECK(smallest(0, 9, 02) == 0);
  CHECK(smallest(9, 6, 8) == 6);
  CHECK(smallest( 70, 87, 68) == 68);
}

TEST_CASE("Task C") {
  CHECK(leap(2016) == "Leap year");
  CHECK(leap(2017) == "Common year");
  CHECK(leap(2018) == "Common year");
  CHECK(leap(2019) == "Common year");
  CHECK(leap(2020) == "Leap year");
}

TEST_CASE("Task D") {
  CHECK(numOfDays(5, 2017) == 31);
  CHECK(numOfDays(4, 2012) == 30);
  CHECK(numOfDays(2, 2017) == 28);
  CHECK(numOfDays(2, 2016) == 29);
  CHECK(numOfDays(12, 2009) == 31);
  CHECK(numOfDays(89, 2008) == 0);
  CHECK(numOfDays(11, 2002) == 30);
}
