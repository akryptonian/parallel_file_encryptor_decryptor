#include <iostream>
#include <filesystem>
#include "./src/app/processes/process_management.hpp"
#include "./src/app/processes/task.hpp"

//namespace fs = std::filesystem;

int main(int argc, char* argv[])
{
  std::string dir;
  std::string action;

  std::cout << "Enter the directory path: " << std::endl;
  std::getline(std::cin, dir);

  std::cout << "Enter the action (encrypt/decrypt): " << std::endl;
  std::getline(std::cin, action);

  try
  {
    if (std::filesystem::exists(dir) && std::filesystem::is_directory(dir))
    {
      processManagement process_management;
      for(const auto &entry: std::filesystem::recursive_directory_iterator(dir))
      {
        std::string file_path = entry.path().string();
        IO io(file_path);
        std::fstream f_stream = std::move(io.get_file_stream());
        if (f_stream.is_open())
        {
          Action task_action = (action == "encrypt" ? Action::ENCRYPT : Action::DECRYPT);
          auto task = std::make_unique<Task>(std::move(f_stream), task_action, file_path);
          process_management.submit_to_queue(std::move(task)); 
        }
        else
        {
          std::cout << "Unable to open the file: " << file_path << std::endl;
        }
      }
      process_management.execute_tasks();
    }
    else
    {
      std::cout << "Invalid directory path: " << std::endl;
    }
  }
  catch(const std::filesystem::filesystem_error& ex)
  {
    std::cout << "Filesystem error: " << ex.what() << std::endl;
  }
  return 0;
}
