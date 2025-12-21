Cómo ejecutar:

g++ rectangle_finder.cpp -o rectangle_finder

./rectangle_finder

¿Por qué usamos una tabla hash?

Usamos una tabla hash porque necesitamos comprobar muchísimas veces si un punto concreto existe en el conjunto.
Si usáramos un vector o lista, cada búsqueda sería O(n) y la solución sería demasiado lenta.

La tabla hash permite que para cada par de puntos necesitamos comprobar si las otras dos esquinas del rectángulo existen.
Con una tabla hash:

insertar → O(1)

buscar → O(1)

Reduciendo drásticamente los tiempos haciendo que la solución sea más eficiente.

¿Cómo lo hemos solucionado?

-Leemos todos los puntos del fichero input.txt y los guardamos en un vector.

-Insertamos cada punto en una tabla hash implementada desde cero para poder buscar coordenadas en O(1).

-Recorremos todos los pares de puntos para ver si pueden ser esquinas opuestas de un rectángulo.

-Para cada par, comprobamos en la tabla hash si existen las otras dos esquinas necesarias.

-Si el rectángulo es válido, calculamos su área y actualizamos el máximo.

-Al final, mostramos el área del rectángulo más grande encontrado.
