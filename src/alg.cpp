// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double flag = 1;
  for (uint16_t i = 0; i < n; i++) {
    flag = flag * value;
  }
  return flag;
}

uint64_t fact(uint16_t n) {
  if (n <= 1) {
    return 1;
  } else {
    return n * fact(n-1);
  }
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double flag = 1;
  for (int i = 1; i <= count; i++) {
    flag = flag + calcItem(x, i);
  }
  return flag;
}

double sinn(double x, uint16_t count) {
  double flag = x;
  for (int i = 2; i <= count; i++) {
    flag = flag + pown(-1, i-1) * calcItem(x, i * 2 - 1);
  }
  return flag;
}

double cosn(double x, uint16_t count) {
  double flag = 1;
  for (int i = 2; i <= count; i++) {
    flag = flag + pown(-1, i-1) * calcItem(x, i * 2 - 2);
  }
  return flag;
}
