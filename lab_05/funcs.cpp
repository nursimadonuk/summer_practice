#include <iostream>
#include "funcs.h"

/*
If n is divisible by d, the function
should return true, otherwise return false
*/

bool isDivisibleBy(int n, int d) {
  if(n % d == 0) {
    return true;
  }else {
    return false;
  }
}

//return true if n is prime
bool isPrime(int n) {
  if(n < 2) {
    return false;
  }else if(n == 2) {
    return true;
  }else {
    for(int i = 2; i < n; i++) {
      if(n % i == 0) {
        return false;
      }
    }
    return true;
  }
}

//return the smallest prime greater than n
int nextPrime(int n) {
  for (int i = n+1; ; i++) {
    if(isPrime(i) == true) {
      return i;
      break;
    }
  }
}

//return the number of primes in the range a ≤ x ≤ b
int countPrimes(int a, int b) {
  int count = 0;
  for(int i = a; i < b+1; i++) {
    if(isPrime(i) == true) {
      count++;
    }
  }
  return count;
}

/*
A prime number N is called a twin prime if either
N-2 or N+2 (or both of them) is also a prime. For
example, a prime 17 is a twin prime, because 17+2 = 19
is a prime as well. The first few twin primes are: 3, 5,
7, 11, 13, 17, 19, 29, 31 … write a function that
determines whether or not its argument is a twin prime.
*/

bool isTwinPrime(int n) {
  if(isPrime(n) == false) {
    return false;
  }
  if(isPrime(n+2) == true || isPrime(n-2) == true) {
    return true;
  }else {
    return false;
  }
}

//write a function that returns the smallest twin prime greater than n
int nextTwinPrime(int n) {
  for(int i = n+1; ;i++) {
    if(isTwinPrime(i) == true) {
      return i;
      break;
    }
  }
}

/*
write a function that returns the largest twin prime
in the range a ≤ N ≤ b. If there is no twin primes in
range, then return -1.
*/

int largestTwinPrime(int a, int b) {
  int largest = -1;
  for(int i = a; i < b+1; i++) {
    if(isTwinPrime(i) == true) {
      largest = i;
    }
  }
  return largest;
}
