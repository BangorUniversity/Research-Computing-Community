#include <exception>
#include <iostream>

int main(int argc, char* argv[]) try {
  // An array of integers
  int a[] = {5, 6, 7, 8, 9, 10};
  std::cout << "a[3] = " << a[3] << "\n";
  std::cout << "a = ";
  for (const auto& i : a) {
    std::cout << i << " ";
  }
  std::cout << "\n\n";

  // Copy the contents of array 'a' to array 'b'
  int b[6];
  for (int i = 0; i < 6; ++i) {
    b[i] = a[i];
  }
  std::cout << "b[3] = " << b[3] << "\n";
  std::cout << "b = ";
  for (const auto& i : b) {
    std::cout << i << " ";
  }
  std::cout << "\n\n";

  // Loop C-Style string
  char w[] = "Hello";
  char* p = w;
  std::cout << "w = ";
  for (; *p != 0; ++p) {
    std::cout << *p;
  }
  std::cout << "\n\n";

  // Multidimensional array
  double m[2][2] = {{1, 2}, {3, 4}};
  for (int r = 0; r < 2; ++r) {
    for (int c = 0; c < 2; ++c) {
      std::cout << m[r][c] << " ";
    }
    std::cout << "\n";
  }

  return 0;
} catch (const std::exception& e) {
  std::cerr << e.what() << "\n";
  return 1;
} catch (...) {
  std::cerr << "An exception occurred.\n";
  return 2;
}
