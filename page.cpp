/*
    Autor: Christian González León
*/

#include "page.h"

#include <stdio.h>

Page& Page::operator=(const Page& other) {
  if (this != &other) {
    number = other.number;
    accepted = other.accepted;
    times_referenced = other.times_referenced;
  }
  return *this;
}

ostream& operator<<(ostream& os, const Page& page) {  
  printf("P%02d      %d", page.number, page.accepted);
  return os;
}