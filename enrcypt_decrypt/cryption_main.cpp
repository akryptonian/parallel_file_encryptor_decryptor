#include <iostream>
#include "cryption.hpp"

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << "Usage: ./cryption <task_data>" << std::endl;
    return 1;
  }
  execute_cryption(argv[1]);
  return 0;
}
