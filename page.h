/*
    Autor: Christian Gonzalez Leon
    Contribuyentes: Brahian Velazquez Tellez
*/

#ifndef PAGE_H
#define PAGE_H

#include "definitions.h"

#include <iostream>

struct Page {
  uint number;
  bool accepted;

  uint times_referenced;

  Page() : number(0), accepted(false), times_referenced(0) {}
  Page(uint number, bool accepted)
    : number(number), accepted(accepted), times_referenced(0) {}

  Page& operator=(const Page& other);
  bool operator==(const Page& other) { return number == other.number; }
  bool operator<(const Page& other) { return number < other.number; }
};

ostream& operator<<(ostream& os, const Page& page);

#endif // PAGE_H