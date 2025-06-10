#include "process_management.hpp"
#include <iostream>
#include <cstring>
#include <sys/wait.h>
#include "../encrypt_decrypt/cryption.hpp"

processManagement::processManagement()
{

}

bool processManagement::submit_to_queue(std::unique_ptr<Task> task)
{
  task_queue.push(std::move(task));
  return true;
}

void processManagement::execute_tasks()
{
  while(!task_queue.empty())
  {
    std::unique_ptr<Task> task_to_execute = std::move(task_queue.front());
    task_queue.pop();
    std::cout << "Executing task: " << task_to_execute->to_string() << std::endl;
    execute_cryption(task_to_execute->to_string());
  }
}
