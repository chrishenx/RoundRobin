# RoundRobin
Práctica del algoritmo RoundRobin utilizado en sistemas operativos

El código usado en este proyecto esta adaptado, por motivos que los prgramadores no podemos controlar, al compilador Borland 5.02.

Estructura del proyecto:

Archivos de cabecera:

page.h         ->   Define la estructura para las páginas.<br>
task.h         ->   Define la estructura para las tareas.<br>
pcb.h          ->   Define la estructura para los procesos.<br>
utilities.h    ->   Prototipo para crear e imprimir listas de tareas y de procesos.<br>
definitions.h  ->   Define constantes globales como: nullptr = 0  |  el tipo uint = unsigned int<br>

Archivos de implementación:

page.cpp       ->   Implementa lo declarado en page.h<br>
task.cpp       ->   Implementa lo declarado en task.h<br>
pcb.cpp        ->   Implementa lo declarado en pcb.h<br>
utilities.cpp  ->   Implementa lo declarado en utilities.h<br>

practica1.cpp  ->   Contiene a la funcion principal "main" e implementa las distintas simulaciones.

El proyecto utiliza rand() para crear números aleatorios. La semilla se debe inicializar en la primer linea de la función main.

Toma todo lo que quieras de este código. 
