#ifndef PROCESS_MANAGEMENT_HPP
#define PROCESS_MANAGEMENT_HPP

#include "task.hpp"
#include <queue>
#include <memory>

class processManagement
{
  public:
    processManagement();
    bool submit_to_queue(std::unique_ptr<Task> task);
    void execute_tasks();
  private:
    std::queue<std::unique_ptr<Task>> task_queue;
};

#endif
