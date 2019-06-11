#include <iostream>
#include "funcs.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Task A") {
  REQUIRE(isDivisibleBy(100, 25) == true);
  REQUIRE(isDivisibleBy(35, 17) == false);
  REQUIRE(isDivisibleBy(10, 2) == true);
}

TEST_CASE("Task B") {
  REQUIRE(isPrime(2) == true);
  REQUIRE(isPrime(13) == true);
  REQUIRE(isPrime(15) == false);
}

TEST_CASE("Task C") {
  REQUIRE(nextPrime(14) == 17);
  REQUIRE(nextPrime(17) == 19);
  REQUIRE(nextPrime(2) == 3);
}

TEST_CASE("Task D") {
  REQUIRE(countPrimes(2, 10) == 4);
  REQUIRE(countPrimes(14, 16) == 0);
  REQUIRE(countPrimes(2, 228) == 49);
}

TEST_CASE("Task E") {
  REQUIRE(isTwinPrime(17) == true);
  REQUIRE(isTwinPrime(2) == false);
  REQUIRE(isTwinPrime(19) == true);
}

TEST_CASE("Task F") {
  REQUIRE(nextTwinPrime(17) == 19);
  REQUIRE(nextTwinPrime(2) == 3);
  REQUIRE(nextTwinPrime(21) == 29);
}

TEST_CASE("Task G") {
  REQUIRE(largestTwinPrime(5, 18) == 17);
  REQUIRE(largestTwinPrime(1, 31) == 31);
  REQUIRE(largestTwinPrime(14, 16) == -1);
}
