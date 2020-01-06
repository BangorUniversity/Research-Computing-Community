#include <exception>
#include <iostream>
#include <iomanip>

int main(int argc, char* argv[]) try {
  // Boolean
  bool b = true;
  std::cout << "b = " << b << "\t\t\t size of 'b' is " << sizeof(b) << " byte(s) \n";

  // Char
  char c = 'a';
  std::cout << "c = " << c << "\t\t\t size of 'c' is " << sizeof(c) << " byte(s) \n";

  // Integer
  int i = 1'000;
  std::cout << "i = " << i << "\t\t size of 'i' is " << sizeof(i) << " byte(s) \n";

  std::cout << std::setprecision(16);

  // Float - single precision
  float f = 1.111111111111111f;
  std::cout << "f = " << f << "\t size of 'f' is " << sizeof(f) << " byte(s) \n";

  // Double - double precision
  double d = 1.111111111111111;
  std::cout << "d = " << d << "\t size of 'd' is " << sizeof(d) << " byte(s) \n";

  return 0;
} catch (const std::exception& e) {
  std::cerr << e.what() << "\n";
  return 1;
} catch (...) {
  std::cerr << "An exception occurred.\n";
  return 2;
}
