Cómo ejecutar:

g++ rectangle_finder.cpp -o rectangle_finder

./rectangle_finder

¿Por qué usamos una tabla hash?

Usamos una tabla hash porque es la forma más eficiente de almacenar y consultar puntos dispersos en un plano, 
evitando estructuras enormes y permitiendo búsquedas rápidas si se necesitan.

¿Cómo lo hemos solucionado?

-Leemos todos los puntos del fichero input.txt.  
    
-Cada línea contiene una coordenada (x, y) que representa una baldosa roja.

-Guardamos todos los puntos en un vector.  
Esto nos permite recorrerlos fácilmente y comparar todas las parejas posibles.

-Insertamos cada punto en una tabla hash.  
La tabla hash almacena los puntos de forma eficiente y permite búsquedas rápidas si se necesitan.

-Recorremos todas las parejas de puntos del vector.  
Cada pareja define dos vértices opuestos de un rectángulo.

-Si los puntos no están alineados (no comparten x ni y), calculamos el área.  

-Actualizamos el área máxima encontrada.

-Mostramos el área del rectángulo más grande.
