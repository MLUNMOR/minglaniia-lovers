1. ¿Por qué hemos elegido este problema?
   Porque plantea desafíos acerca de la gestión de memoria, ya que los identificadores de los ingredientes son numeros de
   15 dígitos. Además los rangos que hay en el fichero input.txt pueden solaparse, por lo que resolver esto mediante fuerza
   bruta sería ineficiente. También este problema nos obliga a trabajar con un tipo de datos que no estamos muy acostumbrados
   (como es el long long, de 64 bits) para poder abordar los numeros tan grandes que plantea el problema.

2. Estructura de Datos y Técnica Empleada
   ESTRUCTURA: Hemos implementado manualmente un Árbol Binario de Búsqueda Balanceado. La lógica del árbol está encapsulada
   en la clase ArbolInventario.
   Cada nodo (struct Nodo) almacena un intervalo (inicio,fin) y punteros a sus hijos.
   Gestionamos la memoria manualmente con new y delete.
   TÉCNICA: Antes de construir el árbol, utilizamos una clase auxiliar estática ProcesadorDatos para ordenar los rangos
   cronológicamente y fusionar aquellos que se solapan. Esto garantiza que el árbol contenga intervalos únicos.
   Para evitar que el árbol acabe en una lista enlazada (lo que sería O(N)), construimos el árbol tomando siempre el elemento
   medio del vector ordenado como raíz, así conseguimos una altura logarítmica y búsquedas en tiempo O(log N).
   
