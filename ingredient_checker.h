#ifndef INGREDIENT_CHECKER_H
#define INGREDIENT_CHECKER_H

#include <unordered_set>
#include <vector>
#include <string>

// Clase para gestionar y verificar ingredientes frescos
class IngredientChecker {
private:
    std::unordered_set<int> freshIDs;

public:
    // Añadir un rango de IDs frescos (inclusive)
    void addRange(int start, int end);

    // Comprobar cuántos IDs de la lista están frescos
    int countFresh(const std::vector<int>& availableIDs) const;
};

#endif // INGREDIENT_CHECKER_H
