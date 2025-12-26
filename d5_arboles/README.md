1. ¿Por qué hemos elegido este problema?
   
   Porque plantea desafíos acerca de la gestión de memoria, ya que los identificadores de los ingredientes son numeros de
   15 dígitos. Además los rangos que hay en el fichero input.txt pueden solaparse, por lo que resolver esto mediante fuerza
   bruta sería ineficiente. También este problema nos obliga a trabajar con un tipo de datos que no estamos muy acostumbrados
   (como es el long long, de 64 bits) para poder abordar los numeros tan grandes que plantea el problema.

2. Estructura de Datos y Técnica Empleada
   
   ESTRUCTURA: Hemos implementado manualmente un Árbol Binario de Búsqueda. La lógica del árbol está encapsulada en la clase
   ArbolInventario.
   Cada nodo (struct Nodo) almacena un intervalo (inicio,fin) y punteros a sus hijos.
   Gestionamos la memoria manualmente con new y delete.
   TÉCNICA: Antes de construir el árbol, utilizamos la clase ProcesadorDatos para ordenar los rangos
   cronológicamente y fusionar aquellos que se solapan. Así el árbol tendrá intervalos únicos.
   Hemos implementado la inserción dinámica elemento a elemento. Recorremos el vector de datos limpios e insertamos cada
   rango en el árbol mediante una función recursiva (insertarRecursivo) que decide la posición del nodo navegando por las
   ramas (izquierda si es menor, derecha si es mayor) hasta encontrar una posición vacía (nullptr).

   Hemos utilizado esta estructura debido a la magnitud de los datos, ya que estos numeros tan grandes hacen que sea imposible
   utilizar estructuras de acceso directo como arrays o tablas hash convencionales, ya que requerirían una cantidad de memoria
   RAM inviable.

3. Descripción de la resolucion.

   Primero leemos cada linea del fichero input.txt y la dividimos entre rangos(si encontramos un guión) o consultas (si no
   hay un guión).
   Ahora tenemos que ordenar los rangos porque puede ser que se solapen (10-20 con 15-25), así conseguiremos un árbol limpio.
   Iteramos sobre el vector de rangos ya limpios. En cada iteración, llamamos al método insertar() del árbol. Este método
   utiliza recursividad y paso de punteros por referencia (Nodo*&) para enlazar correctamente los nuevos nodos
   Por último, debemos ir añadiendo uno a un contador cada vez que un ID caiga dentro de uno de los intervalos que ya tenemos
   limpios.

4. Valoración personal.
   Creemos que la realización de este ejercicio nos ha ayudado sobre todo a comprender de una forma más asentada el tema de
   los punteros por referencia, ya que debíamos utilizar esta técnica en la función de inserción, para poder modificar el
   árbol real y no solo una copia que luego al terminar la propia función se borraría.
   

   
   
