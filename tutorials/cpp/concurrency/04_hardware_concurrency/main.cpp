#include <cstdlib>
#include <iostream>
#include <thread>

int main(int argc, char* argv[]) try {
  unsigned int x = std::thread::hardware_concurrency();
  std::cout << x << " concurrent threads are supported.\n";

  unsigned int y = std::atoi(std::getenv("SLURM_CPUS_PER_TASK"));
  std::cout << "SLURM_CPUS_PER_TASK: " << y << "\n";
  
  return 0;
} catch (const std::exception& e) {
  std::cerr << e.what() << "\n";
  return 1;
} catch (...) {
  std::cerr << "An exception occurred.\n";
  return 2;
}