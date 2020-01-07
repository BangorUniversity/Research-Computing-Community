#include <exception>
#include <iostream>

int main(int argc, char* argv[]) try {
  int a = 1;
  std::cout << "a = " << a << "\n";
  std::cout << "The address of 'a' is " << &a << "\n";

  int* b = &a;
  std::cout << "b = " << b << "\n";
  std::cout << "The contents of address " << b << " is " << *b << "\n\n";

  char c = 'x';
  std::cout << "c = " << c << "\n";
  std::cout << "The address of 'c' is " << static_cast<void*>(&c) << "\n";

  char* d = &c;
  std::cout << "d = " << static_cast<void*>(d) << "\n";
  std::cout << "The contents of address " << static_cast<void*>(d) << " is " << *d << "\n";

  double* e = nullptr;
  if (e) {
    std::cout << "e is not null";
  } else {
    std::cout << "e is null";
  }

  return 0;
} catch (const std::exception& e) {
  std::cerr << e.what() << "\n";
  return 1;
} catch (...) {
  std::cerr << "An exception occurred.\n";
  return 2;
}
