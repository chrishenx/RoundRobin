#include "task.h"
#include "pcb.h"

#include "definitions.h"
#include "utilities.h"

#include <iostream>
#include <list>

#include <stdio.h>
#include <stdlib.h>
#include <conio>

using namespace std;

void main() {

  srand(time(nullptr));

  clrscr();

  cout << "      IPN" << endl;
  cout << "    ESIME Culhuacan" << endl;
  cout << "\n  Materia: Sistemas operativos" << endl;
  cout << "  Programa creado por Christian Gonzalez Leon\n" << endl;
  cout << "  Con contribuciones de Brahian Velazquez Tellez\n" << endl;

  list<Task> tasks = create_tasks(3);
  print_tasks(tasks);

  list<Process> processes = create_processes(tasks);
  print_processes(processes);

  list<Process>::iterator processes_it = processes.begin();
  while (processes_it != processes.end()) {
    (*processes_it).state = 2;
    processes_it++;
  }

  system("pause");

  print_processes(processes);
  
  cout << endl;
  getch();

}