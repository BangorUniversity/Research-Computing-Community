#include <exception>
#include <iostream>

class A {
 public:
  explicit A(int i) : x(i) {}

  A(const A& other) : x(other.x) {
    std::cout << "copy constructor of class A\n";
  }

  int get_x() const { return x; }

 private:
  int x;
};

class B {
 public:
  explicit B(int* i) : y(i) {}

  B(const B& other) = delete;  // Can no longer call the copy constructor

  int* get_y() const { return y; }

 private:
  int* y;
};

int main(int argc, char* argv[]) try {
  A a1(1);
  std::cout << "Address of a1 " << &a1 << "\n";
  std::cout << "a1 : x=" << a1.get_x() << "\n\n";

  std::cout << "A a2(a1) calls the ";
  A a2(a1);
  std::cout << "Address of a2 " << &a2 << "\n";
  std::cout << "a2 : x=" << a2.get_x() << "\n\n";

  int b = 1;
  B b1(&b);
  std::cout << "Address of b1 " << &b1 << "\n";
  std::cout << "b1 : y=" << b1.get_y() << "\n\n";

  //B b2(b1); // error: use of deleted function ‘B::B(const B&)’

  return 0;
} catch (const std::exception& e) {
  std::cerr << e.what() << "\n";
  return 1;
} catch (...) {
  std::cerr << "An exception occurred.\n";
  return 2;
}
