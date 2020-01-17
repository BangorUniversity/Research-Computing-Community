#include <exception>
#include <iostream>

class A {
 public:
  explicit A(int i) : x(i) {}

  A& operator=(const A& other) {
    std::cout << "copy assignment of class A\n";
    if (&other == this) {
      std::cout << "  -> Caught self assignment ";
      return *this;
    } else {
      x = other.x;
      return *this;
    }
  }

  int get_x() const { return x; }

 private:
  int x;
};

class B {
 public:
  explicit B(int i) : y(i) {}

  B& operator=(const B& other) = delete;

  int get_y() const { return y; }

 private:
  int y;
};

int main(int argc, char* argv[]) try {
  A a1(1);
  std::cout << "Address of a1 " << &a1 << "\n";
  std::cout << "a1.get_x() returned " << a1.get_x() << "\n\n";

  A a2(2);
  std::cout << "Address of a2 " << &a2 << "\n";
  std::cout << "a2.get_x() returned " << a2.get_x() << "\n\n";

  std::cout << "a2 = a1 calls the ";
  a2 = a1;
  std::cout << "Address of a2 " << &a2 << "\n";
  std::cout << "a2.get_x() returned " << a2.get_x() << "\n\n";

  std::cout << "a2 = a2 calls the ";
  a2 = a2;
  std::cout << "\na2.get_x() returned " << a2.get_x() << "\n\n";

  B b1(1);
  std::cout << "Address of b1 " << &b1 << "\n";
  std::cout << "b1.get_y() returned " << b1.get_y() << "\n\n";

  B b2(2);
  std::cout << "Address of b2 " << &b2 << "\n";
  std::cout << "b2.get_y() returned " << b2.get_y() << "\n\n";

  //b2 = b1; // error: use of deleted function ‘B& B::operator=(const B&)’

  return 0;
} catch (const std::exception& e) {
  std::cerr << e.what() << "\n";
  return 1;
} catch (...) {
  std::cerr << "An exception occurred.\n";
  return 2;
}
