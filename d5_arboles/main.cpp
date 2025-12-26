#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Rango.h"
#include "ProcesadorDatos.h"
#include "ArbolInventario.h"

using namespace std;

// Función para leer el archivo y separar rangos de consultas
bool leerArchivo(const string& nombre, vector<Rango>& rangos, vector<long long>& consultas) {
    ifstream archivo(nombre);
    if (!archivo.is_open()) return false;

    string linea;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;

        size_t guion = linea.find('-');

            if (guion != string::npos) {
                // Es un rango (tiene guion)
                long long inicio = stoll(linea.substr(0, guion));
                long long fin = stoll(linea.substr(guion + 1));
                rangos.push_back({inicio, fin});
            } else {
                // Es una consulta (es solo un número)
                consultas.push_back(stoll(linea));
            }
    }
    
    archivo.close();
    return true;
}

int main() {
    vector<Rango> rangosCrudos;
    vector<long long> consultas;

    // 1. Leer los datos del archivo
    if (!leerArchivo("input.txt", rangosCrudos, consultas)) {
        cerr << "Error: No encuentro el archivo input.txt" << endl;
        return 1;
    }

    // 2. Limpiar y fusionar los rangos superpuestos
    vector<Rango> rangosLimpios = ProcesadorDatos::fusionarRangos(rangosCrudos);

    // 3. Crear el árbol con los datos limpios
    ArbolInventario inventario;
    for (size_t i = 0; i < rangosLimpios.size(); i++) {
        inventario.insertar(rangosLimpios[i]);
    }

    // 4. Contar cuántos ingredientes son frescos
    int conteoFrescos = 0;
    
    for (size_t i = 0; i < consultas.size(); i++) {
        long long id = consultas[i];
        if (inventario.esIngredienteFresco(id)) {
            conteoFrescos++;
        }
    }

    cout << "Total de ingredientes frescos: " << conteoFrescos << endl;

    return 0;
}