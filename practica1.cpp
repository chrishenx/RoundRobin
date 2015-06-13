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

void round_robin_simulation(list<Process>& processes, uint quantum);
float calculate_TPS(uint* TRP, uint processes_count);

int main() {

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
  system("pause");

  round_robin_simulation(processes, 2);

  cout << "\n   Gracias por usar este programa," << endl;
  cout << "   Hasta luego!" << endl;

  cout << "Presione una tecla para salir ...\n" << endl;
  system("pause>NUL");

  return 0;
}

void round_robin_simulation(list<Process>& processes, uint quantum) {
  uint* TRP = new uint[processes.size()]; // Process return time

  uint remaining_processes = processes.size();
  uint elapsed_cycles = 0;

  list<Process>::iterator processes_it = processes.begin();

  while (remaining_processes > 0) {
    Process& process = *processes_it;

    system("cls");
    cout << "Simulacion de algoritmo Round Robin" << endl;

    if (process.cycles > 0) {
      process.state = 3;
      print_processes(processes);
      process.state = 2;
      printf("\nEjecutando J%dP%d\n", process.id.first, process.id.second);
      uint cycles_to_substract = int(process.cycles) - int(quantum) < 0 ?
        process.cycles : quantum;
      process.cycles -= cycles_to_substract;
      elapsed_cycles += cycles_to_substract;

      if (process.cycles == 0) {
        printf("\nTermina J%dP%d\n", process.id.first, process.id.second);
        TRP[process.coming_time] = elapsed_cycles - process.coming_time;
        remaining_processes--;
        process.state = 5;
      }
      cout << endl;
      system("pause");
    } 


    // Management of std::list to get a circular list behavior
    processes_it++;
    if (processes_it == processes.end()) {
      processes_it = processes.begin();
    }
  }

  float TPS = calculate_TPS(TRP, processes.size());

  processes_it = processes.begin();
  cout << "\nTiempos de retorno por proceso: \n" << endl;
  for (uint i = 0; i < processes.size(); i++) {
    const Process& process = *processes_it;
    printf("J%dP%d : %d ms\n", process.id.first, process.id.second, TRP[i]);
    processes_it++;
  }

  cout << "\nTiempo promedio del sistema: " << TPS << " ms." << endl;

  delete[] TRP;
}

float calculate_TPS(uint* TRP, uint processes_count) {
  uint sum = 0;
  for (uint i = 0; i < processes_count; i++) {
    sum += TRP[i];
  }
  return float(sum) / processes_count;
}
