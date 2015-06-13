/*
    Autor: Christian Gonzalez Leon
    Contribuyentes: Brahian Velazquez Tellez
*/

#include "pcb.h"

#include <stdio.h>
#include <stdlib.h>
#include <utility>

using namespace std;

uint Process::last_coming_time = 0;

ostream& operator<<(ostream& os, const Process& process) {
  printf("J%dP%d     %02d        %02d         %d         %03d       %c      CPU      %02d         %02d",
    process.id.first, process.id.second,
    process.coming_time,
    process.cycles,
    process.state,
    process.capacity,
    process.type,
    process.resources,
    process.files);
  fflush(stdin);
  return os;
}

void Process::assign_random_values() {
  const std::pair<int, int> cycles_range(1, 9);
  const std::pair<int, int> capacity_range(1, 201);
  const std::pair<int, int> type_range(0, 2);
  const std::pair<int, int> resources_range(0, 11);
  const std::pair<int, int> files_range(0, 21);

  cycles = rand() % cycles_range.second + cycles_range.first;
  capacity = rand() % capacity_range.second + capacity_range.first;
  type = rand() % type_range.second + type_range.first == 0 ? 'U' : 'S';
  resources = rand() % resources_range.second + resources_range.first;
  files = rand() % files_range.second + files_range.first;
}

