# RoundRobin
Práctica del algoritmo RoundRobin utilizado en sistemas operativos

El código usado en este proyecto esta adaptado, por motivos que los prgramadores no podemos controlar, al compilador Borland 5.02.

Estructura del proyecto:

Archivos de cabecera:

page.h         ->   Define la estructura para las páginas.
task.h         ->   Define la estructura para las tareas.
pcb.h          ->   Define la estructura para los procesos.
utilities.h    ->   Prototipo para crear e imprimir listas de tareas y de procesos,
definitions.h  ->   Define constantes globales como: nullptr = 0  |  el tipo uint = unsigned int

Archivos de implementación:

page.cpp       ->   Implementa lo declarado en page.h
task.cpp       ->   Implementa lo declarado en task.h
pcb.cpp        ->   Implementa lo declarado en pcb.h
utilities.cpp  ->   Implementa lo declarado en utilities.h

practica1.cpp  ->   Contiene a la funcion principal "main" e implementa las distintas simulaciones.

El proyecto utiliza rand() para crear números aleatorios. La semilla se debe inicializar
en la primer linea de la función main.


Toma todo lo que quieras de este código. 