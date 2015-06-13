/*
    Autor: Christian González León
*/

#ifndef PCB_H 
#define PCB_H

#include "definitions.h"

#include <iostream>
#include <utility>

struct Page;

typedef std::pair<uint, uint> Id;

struct Process {
  Id id;
  uint coming_time;
  uint cycles;
  uint state;
  uint capacity;
  char type;
  uint resources;
  uint files;

  Process()
    : id(0, 0), coming_time(last_coming_time++) {}
  Process(const Id& id)
    : id(id), coming_time(last_coming_time++) {
    state = 1;
  }

  bool operator==(const Process& other) {
    return id.first == other.id.first && id.second == other.id.second;
  }
  bool operator<(const Process& other) { return cycles < other.cycles; }

  void assign_random_values();

 private:
  static uint last_coming_time;
};

ostream& operator<<(ostream& os, const Process& process);


#endif // PCB_H