#include <exception>
#include <iostream>

void print_num(const double& i) { std::cout << i << "\n"; }

int main(int argc, char* argv[]) try {
  int a = 1;
  std::cout << "a = " << a << "\n";

  int& b = a;
  std::cout << "b = " << b << "\n\n";

  double c = 1.2;
  std::cout << "c = " << c << "\n";

  double& d = c;
  std::cout << "d = " << c << "\n\n";

  c = 3.4;
  std::cout << "c = " << c << "\n";
  std::cout << "d = " << d << "\n\n";

  d = 5.6;
  std::cout << "c = " << c << "\n";
  std::cout << "d = " << d << "\n\n";

  print_num(c);
  print_num(d);

  return 0;
} catch (const std::exception& e) {
  std::cerr << e.what() << "\n";
  return 1;
} catch (...) {
  std::cerr << "An exception occurred.\n";
  return 2;
}
