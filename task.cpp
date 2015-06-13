/*
    Autor: Christian Gonzalez Leon
    Contribuyentes: Brahian Velazquez Tellez
*/

#include "task.h"
#include <stdio.h>
#include <stdlib.h>

uint Task::last_number = 1;
const uint Task::LINES_PER_PAGE = 100;

ostream& operator<<(ostream& os, const Task& task) {
  printf(" J%02d     %03d", task.number, task.loc);
  return os;
}

Task& Task::operator=(const Task& other) {
  if (this != &other) {
    number = other.number;
    loc = other.loc;
    pages = other.pages;
  }
  return *this;
}

void Task::create_pages() {
  for (uint i = 0; i * LINES_PER_PAGE < loc; i++) {
    pages.push_back(Page(i, rand() % 2));
  }
}