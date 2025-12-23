Cómo ejecutar:

g++ rectangle_finder.cpp -o rectangle_finder

./rectangle_finder

¿Por qué usamos una tabla hash?

Usamos una tabla hash porque es la forma más eficiente de almacenar y consultar puntos dispersos en un plano, 
evitando estructuras enormes y permitiendo búsquedas rápidas si se necesitan. Además de para verificar si hay puntos repetidos y mantener el vector limpio.

¿Cómo lo hemos solucionado?

-Leemos todos los puntos del fichero input.txt.

-Cada línea contiene una coordenada (x, y) que representa una baldosa roja.

-Antes de guardar un punto, comprobamos en la tabla hash si ya existe.
Esto evita duplicados y mantiene el vector limpio.

-Si el punto no está repetido, lo insertamos en la tabla hash y también en el vector.
La tabla hash permite comprobar la existencia de un punto en O(1).

-Guardamos todos los puntos únicos en un vector.
Esto nos permite recorrerlos fácilmente y comparar todas las parejas posibles.

-Recorremos todas las parejas de puntos del vector.
Cada pareja define dos vértices opuestos de un rectángulo.

-Si los puntos no están alineados (no comparten x ni y), calculamos el área.

-Actualizamos el área máxima encontrada.

-Mostramos el área del rectángulo más grande.
