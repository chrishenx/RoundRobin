/*
    Autor: Christian Gonzalez Leon
    Contribuyentes: Brahian Velazquez Tellez
*/

#ifndef TASK_H
#define TASK_H

#include "page.h"
#include "definitions.h"

#include <list>
#include <iostream>

struct Task {
  static const uint LINES_PER_PAGE;

  uint number;
  uint loc;
  std::list<Page> pages;

  Task() : number(last_number++), loc(0) {}
  Task(uint address, uint loc) : number(last_number++), loc(loc) {}

  Task& operator=(const Task& other);
  bool operator==(const Task& other) { return number == other.number; }
  bool operator<(const Task& other) { return loc < other.loc; }

  void create_pages();
 private:
  static uint last_number;
};

ostream& operator<<(ostream& os, const Task& task);

#endif // TASK_H