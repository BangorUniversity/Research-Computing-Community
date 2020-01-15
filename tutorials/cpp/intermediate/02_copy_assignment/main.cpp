#include <exception>
#include <iostream>

class A {
 public:
  explicit A(int i) : x(i) {}

  ~A() {}

  A& operator=(const A& other) {
    std::cout << "A :: Copy assignment\n";
    x = other.x;
    return *this;
  }

  int get_x() const { return x; }

 private:
  int x;
};

int main(int argc, char* argv[]) try {
  A a(1);
  std::cout << "a : x=" << a.get_x() << "\n";

  A b(2);
  std::cout << "b : x=" << b.get_x() << "\n";

  b = a;
  std::cout << "b : x=" << b.get_x() << "\n";

  return 0;
} catch (const std::exception& e) {
  std::cerr << e.what() << "\n";
  return 1;
} catch (...) {
  std::cerr << "An exception occurred.\n";
  return 2;
}
