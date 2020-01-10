#include <exception>
#include <iostream>
#include <thread>

struct A {
  int x;
  int y;
  void operator()() const { std::cout << "x=" << x << ", y=" << y << "\n"; }
};

class B {
 public:
  B(int x, int y) : x(x), y(y) {}
  void operator()() const { std::cout << "x=" << x << ", y=" << y << "\n"; }

 private:
  int x;
  int y;
};

int main(int argc, char* argv[]) try {
  A a;
  a.x = 1;
  a.y = 2;
  std::thread t1(a);
  t1.join();

  B b(3, 4);
  std::thread t2(b);
  t2.join();

  return 0;
} catch (const std::exception& e) {
  std::cerr << e.what() << "\n";
  return 1;
} catch (...) {
  std::cerr << "An exception occurred.\n";
  return 2;
}