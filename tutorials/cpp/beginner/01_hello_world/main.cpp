#include <exception>
#include <iostream>

int main(int argc, char* argv[]) try {
  std::cout << "Hello World\n";
  return 0;
} catch (const std::exception& e) {
  std::cerr << e.what() << "\n";
  return 1;
} catch (...) {
  std::cerr << "An exception occurred.\n";
  return 2;
}
