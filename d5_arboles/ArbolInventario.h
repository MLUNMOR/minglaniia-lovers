#ifndef ARBOLINVENTARIO_H
#define ARBOLINVENTARIO_H

#include <vector>
#include "Rango.h"

using namespace std;

struct Nodo {
    long long inicio;
    long long fin;
    Nodo* izquierda;
    Nodo* derecha;

    // Constructor 
    Nodo(long long i, long long f) {
        inicio = i;
        fin = f;
        izquierda = nullptr;
        derecha = nullptr;
    }
};

// Clase para manejar todo lo del árbol
class ArbolInventario {
private:
    Nodo* raiz;

    // Función recursiva para crear el árbol.
    // Cojo el elemento del medio (mid) para que el arbol quede equilibrado.
    Nodo* construirRecursivo(const vector<Rango>& rangos, int start, int end);
    
    // Busca si el valor está en algún nodo del árbol
    bool buscarRecursivo(Nodo* nodo, long long valor);

    // Borra la memoria recursivamente para no dejar basura
    void liberarMemoria(Nodo* nodo);

public:
    // Constructor
    ArbolInventario();

    // Destructor. Para borrar la memoria de "new"
    ~ArbolInventario();

    // Función para crear el árbol desde fuera
    void construir(const vector<Rango>& rangos);

    // Función pública para preguntar si es fresco
    bool esIngredienteFresco(long long id);
};

#endif