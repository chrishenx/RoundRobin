/*
    Autor: Christian González León
*/

#include <iostream>
#include <cstdio>

#include "task.h"
#include "pcb.h"
#include "simple_list.h"

#include "utilities.h"

using uint = unsigned int;

using namespace std;

void round_robin_simulation(SList<Process>& processes, uint quantum);
void srtn_simulation(SList<Process>& process);
SList<Process>::Iterator getShortestProcess(const SList<Process>& processes,
  SList<Process>::Iterator& process);

float calculate_TPS(uint* TRP, uint processes_count);

int main() {
  system("cls");
  
  cout << "      IPN" << endl;
  cout << "    ESIME Culhuacan" << endl;
  cout << "\n  Materia: Sistemas operativos" << endl;
  cout << "  Programa creado por Christian Gonzalez Leon\n" << endl;
 
  
  auto tasks = create_tasks(3);
  print_tasks(tasks);

  auto processes = create_proccesses(tasks);
  print_proccesses(processes);

  for (auto& process : processes) {
    process.state = 2;
  }

  cout << "Presione ENTER" << endl;
  system("pause > NUL");

  print_proccesses(processes);
  
  cout << endl;
  system("pause");


  // CAMBIAR LA SIG. LINEA POR "srtn_simulation(processes)"
  // PARA LA SIMULACION CON ESE NOMBRE
  
  round_robin_simulation(processes, 2);


  cout << "\n   Gracias por usar este programa," << endl;
  cout << "   Hasta luego!" << endl;

  cout << "Presione una tecla para salir ...\n" << endl;
  system("pause>NUL");

  return 0;
}

void round_robin_simulation(SList<Process>& processes, uint quantum) {
  uint* TRP = new uint[processes.size()]; // Process return time

  uint remaining_processes = processes.size();
  uint elapsed_cycles = 0;

  auto processes_it = processes.begin();

  while (remaining_processes > 0) {
    auto& process = *processes_it;

    system("cls");
    cout << "Simulacion de algoritmo Round Robin" << endl;

    if (process.cycles > 0) {  
      process.state = 3;
      print_proccesses(processes);
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


    // Management of SList to get a circular list behavior
    if (processes_it.has_next()) {
      processes_it++;
    } else {
      processes_it = processes.begin();
    }
  }

  float TPS = calculate_TPS(TRP, processes.size());

  processes_it = processes.begin();
  cout << "\nTiempos de retorno por proceso: \n" << endl;
  for (uint i = 0; i < processes.size(); i++) {
    printf("J%dP%d : %d ms\n", processes_it->id.first, processes_it->id.second, TRP[i]);
    processes_it++;
  }

  cout << "\nTiempo promedio del sistema: " << TPS << endl;

  delete[] TRP;
}

void srtn_simulation(SList<Process>& processes) {
  uint* TRP = new uint[processes.size()]; // Process return time

  uint remaining_processes = processes.size();
  uint elapsed_cycles = 0;

  auto processes_it = processes.begin();

  while (remaining_processes > 0) {
    auto& process = *processes_it;

    system("cls");
    cout << "Simulacion de algoritmo SRTN" << endl;

    if (process.cycles > 0) {  
      process.state = 3;
      print_proccesses(processes);
      process.state = 2;
      process.cycles -= 1;
      elapsed_cycles += 1;
      printf("\nEjecutando J%dP%d\n", process.id.first, process.id.second);
      if (process.cycles == 0) {
        printf("\nTermina J%dP%d\n", process.id.first, process.id.second);
        TRP[process.coming_time] = elapsed_cycles - process.coming_time;
        remaining_processes--;
        process.state = 5;
        if (remaining_processes > 0) {
          do {
            if (processes_it.has_next()) {
              processes_it++;
            } else {
              processes_it = processes.begin();
            }
          } while (processes_it->cycles == 0);
        }
      } else {
        processes_it = getShortestProcess(processes, processes_it);
      }
      cout << endl;
      system("pause");
    } 
  }

  float TPS = calculate_TPS(TRP, processes.size());

  processes_it = processes.begin();
  cout << "\nTiempos de retorno por proceso: \n" << endl;
  for (uint i = 0; i < processes.size(); i++) {
    printf("J%dP%d : %d ms\n", processes_it->id.first, processes_it->id.second, TRP[i]);
    processes_it++;
  }

  cout << "\nTiempo promedio del sistema: " << TPS << endl;

  delete[] TRP;
}

float calculate_TPS(uint* TRP, uint processes_count) {
  uint sum = 0;
  for (uint i = 0; i < processes_count; i++) {
    sum += TRP[i];
  }
  return float(sum) / processes_count;
}

SList<Process>::Iterator getShortestProcess(const SList<Process>& processes,
    SList<Process>::Iterator& process) {
  auto shortest_process = process;
  do {
    if (shortest_process->cycles > 0 &&
        shortest_process->cycles < process->cycles) {
      return shortest_process;
    }
    if (shortest_process.has_next()) {
      shortest_process++;
    } else {
      shortest_process = processes.begin();
    }
  } while (shortest_process != process);
  printf("\nNingun proceso menor a J%dP%d !\n", process->id.first, process->id.second);
  return shortest_process;
}