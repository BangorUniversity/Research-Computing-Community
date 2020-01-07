#include <exception>
#include <iostream>
#include <iomanip>
#include <limits>

int main(int argc, char* argv[]) try {
  // Integer
  std::cout << "Size of 'int' is\t\t" << sizeof(int) << " byte(s)";
  std::cout << "\t range (" << std::numeric_limits<int>::min() << " to " << std::numeric_limits<int>::max() << ")\n";

  std::cout << "Size of 'signed int' is\t\t" << sizeof(signed int) << " byte(s)";
  std::cout << "\t range (" << std::numeric_limits<signed int>::min() << " to " << std::numeric_limits<signed int>::max() << ")\n";

  std::cout << "Size of 'unsigned int' is\t" << sizeof(unsigned int) << " byte(s)";
  std::cout << "\t range (" << std::numeric_limits<unsigned int>::min() << " to " << std::numeric_limits<unsigned int>::max() << ")\n";

  std::cout << "Size of 'long int' is\t\t" << sizeof(long int) << " byte(s)";
  std::cout << "\t range (" << std::numeric_limits<long int>::min() << " to " << std::numeric_limits<long int>::max() << ")\n";

  std::cout << "Size of 'short int' is\t\t" << sizeof(short int) << " byte(s)";
  std::cout << "\t range (" << std::numeric_limits<short int>::min() << " to " << std::numeric_limits<short int>::max() << ")\n\n";

  std::cout << "Size of 'signed long int' is\t" << sizeof(signed long int) << " byte(s)";
  std::cout << "\t range (" << std::numeric_limits<signed long int>::min() << " to " << std::numeric_limits<signed long int>::max() << ")\n";

  std::cout << "Size of 'unsigned long int' is\t" << sizeof(unsigned long int) << " byte(s)";
  std::cout << "\t range (" << std::numeric_limits<unsigned long int>::min() << " to " << std::numeric_limits<unsigned long int>::max() << ")\n";

  std::cout << "Size of 'signed short int' is\t" << sizeof(signed short int) << " byte(s)";
  std::cout << "\t range (" << std::numeric_limits<signed short int>::min() << " to " << std::numeric_limits<signed short int>::max() << ")\n";

  std::cout << "Size of 'unsigned short int' is\t" << sizeof(unsigned short int) << " byte(s)";
  std::cout << "\t range (" << std::numeric_limits<unsigned short int>::min() << " to " << std::numeric_limits<unsigned short int>::max() << ")\n\n";

  // Char
  std::cout << "Size of 'char' is\t\t" << sizeof(char) << " byte(s)";
  std::cout << "\t range (" << (int)std::numeric_limits<char>::min() << " to " << (int)std::numeric_limits<char>::max() << ")\n";

  std::cout << "Size of 'signed char' is\t" << sizeof(signed char) << " byte(s)";
  std::cout << "\t range (" << (int)std::numeric_limits<signed char>::min() << " to " << (int)std::numeric_limits<signed char>::max() << ")\n";

  std::cout << "Size of 'unsigned char' is\t" << sizeof(unsigned char) << " byte(s)";
  std::cout << "\t range (" << (int)std::numeric_limits<unsigned char>::min() << " to " << (int)std::numeric_limits<unsigned char>::max() << ")\n\n";

  // Double
  std::cout << "Size of 'double' is\t\t" << sizeof(double) << " byte(s)";
  std::cout << "\t range (" << std::numeric_limits<double>::min() << " to " << std::numeric_limits<double>::max() << ")\n";

  std::cout << "Size of 'long double' is\t" << sizeof(long double) << " byte(s)";
  std::cout << "\t range (" << std::numeric_limits<long double>::min() << " to " << std::numeric_limits<long double>::max() << ")\n";

  return 0;
} catch (const std::exception& e) {
  std::cerr << e.what() << "\n";
  return 1;
} catch (...) {
  std::cerr << "An exception occurred.\n";
  return 2;
}
