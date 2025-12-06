#include "desbloquear.h"
#include <fstream>
#include <iostream>

// Aplica una sola rotación al dial
int aplicar_rotacion(int actual, char dir, int val) {
    if (dir == 'R')// Girar a la derecha
        return (actual + val) % 100;
    return (actual - val + 100) % 100;// Girar a la izquierda
}

// Divide y vencerás: cuenta cuántas veces el dial queda en 0
int divide_venceras(const std::vector<Rotacion>& r, int i, int j, int& actual) {
    if (i == j) {
        actual = aplicar_rotacion(actual, r[i].dir, r[i].val);
        return (actual == 0);
    }

    int mid = (i + j) / 2;
    int izq = divide_venceras(r, i, mid, actual);// Parte izquierda
    int der = divide_venceras(r, mid + 1, j, actual);// Parte derecha

    return izq + der;// Suma los resultados de ambas mitades
}

// Función principal que lee el archivo y devuelve cuántas veces cayó en 0
int desbloquear(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {// Verifica si el archivo se abrió correctamente
        std::cout << "No se pudo abrir el archivo.\n";
        return -1;
    }

    std::vector<Rotacion> rot;// Vector para almacenar las rotaciones
    char d;
    int v;

    while (file >> d >> v)// Lee cada línea del archivo
        rot.push_back({d, v});

    int actual = 50;  // posición inicial
    return divide_venceras(rot, 0, rot.size() - 1, actual);// Llama a la función divide y vencerás
}
