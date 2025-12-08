#include "ingredient_checker.h"

// Añadir un rango de IDs frescos (inclusive)
void IngredientChecker::addRange(int start, int end) {
    for (int id = start; id <= end; ++id) {
        freshIDs.insert(id);
    }
}

// Comprobar cuántos IDs de la lista están frescos
int IngredientChecker::countFresh(const std::vector<int>& availableIDs) const {
    int count = 0;
    for (int id : availableIDs) {// Recorre cada ID disponible
        if (freshIDs.find(id) != freshIDs.end()) {
            ++count;
        }
    }
    return count;// Devuelve el conteo de IDs frescos encontrados
}
