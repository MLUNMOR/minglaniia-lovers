Cómo ejecutar:
g++ grafosd11.cpp -o grafosd11
./grafosd11

¿Por qué usamos un grafo y una tabla hash?
Usamos un grafo porque el sistema de dispositivos y conexiones se modela naturalmente como un grafo dirigido, lo que permite recorrer todas las rutas desde “you” hasta “out”. La tabla hash (unordered_map) se utiliza para asociar cada nombre de dispositivo con su nodo de forma eficiente, evitando búsquedas costosas y permitiendo inserciones rápidas.
¿Cómo lo hemos solucionado?

Leemos todas las líneas del fichero input.txt.
Cada línea indica un dispositivo y sus salidas.
Creamos un grafo dirigido donde cada dispositivo es un nodo y cada salida una arista.
Para mapear nombres a nodos usamos unordered_map, que nos da acceso O(1) promedio.
Implementamos DFS para explorar todas las rutas desde “you” hasta “out”.
Si solo queremos contar rutas, usamos memoización para evitar recalcular subproblemas.
Mostramos el número total de rutas encontradas.

¿Qué he aprendido?
He aprendido a modelar problemas como grafos, a usar unordered_map para optimizar el acceso a nodos y a diferenciar cuándo aplicar DFS frente a otros algoritmos como Dijkstra o programación dinámica.
