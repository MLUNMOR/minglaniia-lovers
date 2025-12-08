#include <iostream>
#include "desbloquear.h"

int main() {
    std::string archivo = "entrada.txt";

    // Llamada a la función principal
    int veces = desbloquear(archivo);

    if (veces == -1)
        return 1; // error abriendo archivo

    // Mostrar el resultado directamente
    std::cout << "El dial cayo en 0 :" << veces << " veces.\n";
    std::cout << "La contrasenya es " << veces << "\n";
    return 0;
}
