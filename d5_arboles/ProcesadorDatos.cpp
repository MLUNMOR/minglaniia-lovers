#include "ProcesadorDatos.h"

vector<Rango> ProcesadorDatos::fusionarRangos(vector<Rango> rangos) {
    if (rangos.empty()) return rangos;

    // 1. Ordenar la lista.
    // Uso una función lambda [] para decirle que ordene por el "inicio"
    sort(rangos.begin(), rangos.end(), [](const Rango& a, const Rango& b) {
        return a.inicio < b.inicio;
    });

    vector<Rango> fusionados;
    fusionados.push_back(rangos[0]); // Meto el primero para empezar

    // 2. Recorro el resto para ver si se solapan
    for (size_t i = 1; i < rangos.size(); i++) {
        Rango& actual = fusionados.back();
        Rango& siguiente = rangos[i];

        // Compruebo si el siguiente empieza antes de que acabe el actual
        if (siguiente.inicio <= actual.fin + 1) {
            // Si se solapan, estiro el final del actual
            if (siguiente.fin > actual.fin) {
                actual.fin = siguiente.fin;
            }
        } else {
            // Si no se tocan, lo añado como uno nuevo
            fusionados.push_back(siguiente);
        }
    }

    return fusionados;
}