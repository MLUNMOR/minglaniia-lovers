#ifndef PROCESADORDATOS_H
#define PROCESADORDATOS_H

#include <vector>
#include <algorithm>
#include "Rango.h"

using namespace std;

// Clase para ordenar los datos antes de meterlos al árbol
class ProcesadorDatos {
public:
    static vector<Rango> fusionarRangos(vector<Rango> rangos);
};

#endif