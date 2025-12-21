g++ -std=c++17 -O2 main.cpp tachyon.cpp -o tachyon
./tachyon



¿Por qué elegí este problema?

-Porque me parecía una buena forma de practicar programación dinámica y memorización. Es un problema sencillo de entender (un grid con símbolos y un punto de inicio), pero que tiene subproblemas que se repiten, así que es perfecto para aplicar esta técnica.



¿Qué técnica y estructuras de datos se usan?

-Técnica: Programación dinámica en forma de recursión con memorización (top‑down).
Estructuras:

-Una tabla 2D (memo) para guardar los resultados ya calculados y no repetir trabajo.
Un vector<string> para almacenar el grid.



¿Cómo he abordado la resolución?

-Primero he definido qué significa cada celda:

'.' → seguir hacia abajo.
'^' → cuenta un split y bifurca hacia abajo a izquierda y derecha.
'#' → obstáculo, no se puede pasar.
S → punto de inicio.

-Luego he planteado la función dfs(x,y) que devuelve cuántos splits se pueden conseguir desde esa posición. Si la celda está fuera del grid, devuelve 0. Si ya calculé ese estado antes, lo saco de la tabla memo. Si no, aplico la lógica según el carácter y guardo el resultado.

-De esta forma, cada subproblema se calcula una sola vez y se reutiliza. Esto reduce mucho el coste comparado con una recursión pura.

-Para probarlo, he usado el fichero grid.txt y he añadido un main.cpp que lee el grid, crea el objeto y muestra el total de splits.
