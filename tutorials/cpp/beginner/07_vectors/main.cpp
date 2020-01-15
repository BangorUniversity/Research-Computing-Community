#include <iostream>
#include <vector>

void print_vector(const std::vector<int>& v) {
  for (const auto& i : v) {
    std::cout << i << " ";
  }
  std::cout << "\n";
}

int main(int argc, char* argv[]) try {
  // Create a vector of integers
  std::vector<int> a = {2, 3, 4, 5, 6, 7, 8};
  print_vector(a);

  // Print the size of vector a
  std::cout << a.size() << "\n";

  // Add two elements to the end of vector a
  a.push_back(9);
  a.push_back(10);
  print_vector(a);

  // Remove the last element of vector a
  a.pop_back();
  print_vector(a);

  // Print the first element of vector a
  std::cout << a.front() << "\n";

  // Print the last element of vector a
  std::cout << a.back() << "\n";

  // Print the third index of vector a
  std::cout << a[3] << "\n";

  // Update the third index of vector a
  a[3] = 100;
  print_vector(a);

  // Insert the value 99 at index 2 of vector a
  a.insert(a.begin() + 2, 99);
  print_vector(a);

  // Erase the value 99 at index 2 of vector a
  a.erase(a.begin() + 2);
  print_vector(a);

  // Clear vector a
  a.clear();
  print_vector(a);

  return 0;
} catch (const std::exception& e) {
  std::cerr << e.what() << "\n";
  return 1;
} catch (...) {
  std::cerr << "An exception occurred.\n";
  return 2;
}