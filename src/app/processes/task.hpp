#ifndef TASK_HPP
#define TASK_HPP

#include <string>
#include <fstream>
#include "../file_handling/IO.hpp"
#include <sstream>

enum class Action
{
  ENCRYPT,
  DECRYPT
};

struct Task
{
  std::string file_path;
  std::fstream f_stream;
  Action action;

  Task(std::fstream && stream, Action act, std::string file_path) : f_stream(std::move(stream)), action(act), file_path(file_path) {} // What is the funcion of &&?

  std::string to_string()
  {
    std::ostringstream oss;
    oss << file_path << "," << (action == Action::ENCRYPT ? "ENCRYPT" : "DECRYPT");
    return oss.str();
  }

  static Task from_string(const std::string &task_data)
  {
    std::istringstream iss(task_data);
    std::string file_path;
    std::string action_str;

    if(std::getline(iss, file_path, ',') && std::getline(iss, action_str))
    {
      Action action = (action_str == "ENCRYPT" ? Action::ENCRYPT : Action::DECRYPT);
      IO io(file_path);
      std::fstream f_stream = std::move(io.get_file_stream());
      if (f_stream.is_open())
      {
        return Task(std::move(f_stream), action, file_path);
      }
      else
      {
        throw std::runtime_error("Failed to open file: " + file_path);
      }
    }
    else
    {
      throw std::runtime_error("Invalid task data format");
    }
  }
};

#endif
