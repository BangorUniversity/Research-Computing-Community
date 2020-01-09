#include <exception>
#include <iostream>
#include <thread>

void a() {
  for (int i = 0; i < 20; ++i) {
    std::cout << "a\n";
  }
}

void b() {
  for (int i = 0; i < 20; ++i) {
    std::cout << "b\n";
  }
}

int main(int argc, char* argv[]) try {
  std::thread t1(a);
  std::thread t2(b);
  t1.join();
  t2.join();
  return 0;
} catch (const std::exception& e) {
  std::cerr << e.what() << "\n";
  return 1;
} catch (...) {
  std::cerr << "An exception occurred.\n";
  return 2;
}