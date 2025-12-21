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
   TÉCNICA: Antes de construir el árbol, utilizamos la clase ProcesadorDatos para ordenar los rangos
   cronológicamente y fusionar aquellos que se solapan. Así el árbol tendrá intervalos únicos.
   Para evitar que el árbol acabe en una lista enlazada (lo que sería O(N)), construimos el árbol tomando siempre el elemento
   medio del vector ordenado como raíz, así conseguimos una altura logarítmica y búsquedas en tiempo O(log N).

   Hemos utilizado esta estructura debido a la magnitud de los datos, ya que estos numeros tan grandes hacen que sea imposible
   utilizar estructuras de acceso directo como arrays o tablas hash convencionales, ya que requerirían una cantidad de memoria
   RAM inviable.

3. Descripción de la resolucion.

   Primero leemos cada linea del fichero input.txt y la dividimos entre rangos(si encontramos un guión) o consultas (si no
   hay un guión).
   Ahora tenemos que ordenar los rangos porque puede ser que se solapen (10-20 con 15-25), así conseguiremos un árbol limpio.
   Ya podemos llamar al metodo recursivo de construcción, este genera un árbol equilibrado ya que cada vez tomamos como raíz
   la mitad del intervalo.
   Por último, debemos ir añadiendo uno a un contador cada vez que un ID caiga dentro de uno de los intervalos que ya tenemos
   limpios.

   
   
