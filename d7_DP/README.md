g++ -std=c++17 -O2 main.cpp tachyon.cpp -o tachyon
./tachyon


Hemos elegido este problema porque combina simulación de propagación de rayos con divisiones en splitters, lo que permite aplicar técnicas de optimización como la memoización para evitar recalcular rutas repetidas. Representamos el manifold como un grid 2D y usamos una función recursiva con memoización para contar el número total de splits, considerando que cada splitter genera dos rayos laterales y detiene el rayo original.

Como alternativa, se podría implementar BFS iterativo para manejar correctamente los rayos laterales que convergen y evitar problemas de stack en grids grandes. La experiencia nos permitió aprender a identificar subproblemas repetitivos dentro de una simulación y aplicar programación dinámica para mejorar eficiencia, combinando claridad y rendimiento en la resolución de problemas de propagación en 2D.
