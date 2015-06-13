/*
    Autor: Christian González León
*/

#ifndef UTILITIES_H
#define UTILITIES_H

#include "definitions.h"

#include <list>

struct Task;
struct Process;

std::list<Task> create_tasks(uint count);
std::list<Process> create_processes(const std::list<Task>& tasks);
void print_tasks(const std::list<Task>& tasks);
void print_processes(const std::list<Process>& processes);

#endif // UTILITIES_H