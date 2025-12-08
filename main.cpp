#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "ingredient_checker.h"

int main() {
    std::ifstream file("entrada.txt");// Abre el archivo de entrada
    if (!file) {// Verifica si el archivo se abrió correctamente
        std::cerr << "No se pudo abrir el archivo de entrada.\n";
        return 1;
    }

    IngredientChecker checker;
    std::string line;
    bool readingRanges = true;
    std::vector<int> availableIDs;

    while (std::getline(file, line)) {
        if (line.empty()) {// Línea vacía indica el cambio de sección
            readingRanges = false;
            continue;
        }

        if (readingRanges) {// Leer rangos de IDs frescos
            int start, end;
            char dash;
            std::istringstream iss(line);
            iss >> start >> dash >> end;
            checker.addRange(start, end);// Añadir el rango al verificador
        } else {// Leer IDs disponibles
            int id = std::stoi(line);
            availableIDs.push_back(id);// Añadir ID a la lista de disponibles
        }
    }

    int freshCount = checker.countFresh(availableIDs);// Contar IDs frescos disponibles
    std::cout << "Cantidad de IDs frescos: " << freshCount << "\n";// Mostrar el resultado

    return 0;
}
