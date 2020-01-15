#include <exception>
#include <iostream>

class A {
 public:
  explicit A(int i) : x(i) {}

  ~A() {}

  A(const A& other) : x(other.x) { std::cout << "A :: Copy constructor\n"; }

  int get_x() const { return x; }

 private:
  int x;
};

int main(int argc, char* argv[]) try {
  A a(1);
  std::cout << "a : x=" << a.get_x() << "\n";

  A b(a);
  std::cout << "b : x=" << b.get_x() << "\n";

  return 0;
} catch (const std::exception& e) {
  std::cerr << e.what() << "\n";
  return 1;
} catch (...) {
  std::cerr << "An exception occurred.\n";
  return 2;
}
