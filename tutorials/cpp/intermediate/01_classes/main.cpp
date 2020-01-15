#include <exception>
#include <iostream>

class A {
 public:
  A(int i) : x(i) { std::cout << "A :: Constructor\n"; }

  ~A() { std::cout << "A :: Deconstructor\n"; }

  void print_x() { std::cout << "x=" << x << "\n"; }

  int get_x() { return x; }

 private:
  int x;
};

class B {
 public:
  // By default, declare single-argument constructors explicit to avoid
  // unintended conversions.
  explicit B(int i) : y(i) { std::cout << "B :: Constructor\n"; }

  ~B() { std::cout << "B :: Deconstructor\n"; }

  void print_y() { std::cout << "y=" << y << "\n"; }

  int get_y() { return y; }

 private:
  int y;
};

int main(int argc, char* argv[]) try {
  A a1(1);
  a1.print_x();

  A a2 = 2;
  std::cout << "x=" << a2.get_x() << "\n";

  B b1(3);
  b1.print_y();

  //B b2 = 4; // error: conversion from ‘int’ to non-scalar type ‘B’ requested
  // std::cout << "y=" << b2.get_y() << "\n";

  return 0;
} catch (const std::exception& e) {
  std::cerr << e.what() << "\n";
  return 1;
} catch (...) {
  std::cerr << "An exception occurred.\n";
  return 2;
}
