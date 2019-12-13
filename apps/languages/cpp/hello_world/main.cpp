#include <exception>
#include <iostream>

int main() try {
  std::cout << "Hello World" << std::endl;
  return 0;
} catch (const std::exception& e) {
  std::cerr << e.what() << std::endl;
  return 1;
} catch (...) {
  std::cout << "An exception occurred." << std::endl;
  return 2;
}
