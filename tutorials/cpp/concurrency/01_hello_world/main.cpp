#include <exception>
#include <iostream>
#include <thread>

void hello_world() { std::cout << "Hello World!\n"; }

int main(int argc, char* argv[]) try {
  std::thread t(hello_world);
  t.join();
  return 0;
} catch (const std::exception& e) {
  std::cerr << e.what() << "\n";
  return 1;
} catch (...) {
  std::cerr << "An exception occurred.\n";
  return 2;
}