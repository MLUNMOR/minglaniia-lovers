#ifndef DESBLOQUEAR_H
#define DESBLOQUEAR_H

#include <vector>
#include <string>

// Estructura para representar una rotación
struct Rotacion {
    char dir;
    int val;
};

// Declaraciones de funciones
int aplicar_rotacion(int actual, char dir, int val);
int divide_venceras(const std::vector<Rotacion>& r, int i, int j, int& actual);
int desbloquear(const std::string& filename);

#endif
