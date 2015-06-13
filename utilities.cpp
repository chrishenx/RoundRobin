/*
    Autor: Christian González León
*/

#include "utilities.h"

#include "simple_list.h"
#include "task.h"
#include "pcb.h"

#include <stdlib.h>
#include <utility>

#define SO 2

using namespace std;

list<Task> create_tasks(uint count) {
  uint limit = SO * 1024 - 1;
  uint start_address;
  do  {
    start_address = rand() % limit;
  } while(start_address + count > limit);
  list<Task> tasks;
  for (uint i = 0; i < count; i++) {
    tasks.push_back(Task(start_address + i,
      rand() % 800 + 100));
    tasks.back().create_pages();
  }
  return tasks;
}

list<Process> create_processes(const list<Task>& tasks) {
  list<Process> processes;
  for (list<Task>::const_iterator task_it = tasks.begin(); task_it != tasks.end(); task_it++) {
    const Task& task = *task_it;
    for (list<Page>::const_iterator page_it = task.pages.begin(); page_it != task.pages.end(); page_it++) {
      const Page& page = *page_it;
      if (page.accepted) {
        processes.push_back(Process(make_pair(task.number, page.number)));
        processes.back().assign_random_values();
      }
    }
  }
  return processes;
}

void print_tasks(const list<Task>& tasks) {
  cout << "Tareas: \n" << endl;
  for (list<Task>::const_iterator task_it = tasks.begin(); task_it != tasks.end(); task_it++) {
    const Task& task = *task_it;
    cout << "J" << task.number << endl;
    for (list<Page>::const_iterator page_it = task.pages.begin(); page_it != task.pages.end(); page_it++) {
      cout << *page_it << endl;
    }
    cout << endl;
  }
}

void print_processes(const list<Process>& processes) {
  cout << "Procesos: \n" << endl;
  cout << "  Id   Llegada    Ciclos    Estado   Capacidad   Tipo    Cond   Recursos    Archivos" << endl;
  for (list<Process>::const_iterator it = processes.begin(); it != processes.end(); it++) {
    cout << *it << endl;
  }
}

