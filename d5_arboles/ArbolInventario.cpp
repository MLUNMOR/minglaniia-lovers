#include "ArbolInventario.h"

// Función recursiva para crear el árbol.


Nodo* ArbolInventario::construirRecursivo(const vector<Rango>& rangos, int start, int end) {
    // Caso base: si el inicio es mayor que el fin, no quedan elementos
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    
    Nodo* nodo = new Nodo(rangos[mid].inicio, rangos[mid].fin);

    // Llamo a la función otra vez para rellenar izquierda y derecha
    nodo->izquierda = construirRecursivo(rangos, start, mid - 1);
    nodo->derecha = construirRecursivo(rangos, mid + 1, end);

    return nodo;
}

bool ArbolInventario::buscarRecursivo(Nodo* nodo, long long valor) { 
    // Si llego a un camino sin salida, es que no está
    if (nodo == nullptr) {
        return false;
    }

    // Si el valor está dentro de los números de este nodo, lo encontré
    if (valor >= nodo->inicio && valor <= nodo->fin) {
        return true;
    }

    if (valor < nodo->inicio) {
        return buscarRecursivo(nodo->izquierda, valor);
    } else {
        return buscarRecursivo(nodo->derecha, valor);
    }
}

// Borra la memoria recursivamente
void ArbolInventario::liberarMemoria(Nodo* nodo) {
    if (nodo == nullptr) return;
    
    liberarMemoria(nodo->izquierda);
    liberarMemoria(nodo->derecha);
    delete nodo;
}

// Constructor
ArbolInventario::ArbolInventario() {
    raiz = nullptr;
}

// Destructor. Para borrar la memoria de "new"
ArbolInventario::~ArbolInventario() {
    liberarMemoria(raiz);
}

// Función para crear el árbol desde fuera
void ArbolInventario::construir(const vector<Rango>& rangos) {
    // Por si acaso llamo a construir dos veces, limpio lo anterior
    liberarMemoria(raiz);
    if (!rangos.empty()) {
        raiz = construirRecursivo(rangos, 0, (int)rangos.size() - 1);
    }
}

// Función pública para preguntar si es fresco
bool ArbolInventario::esIngredienteFresco(long long id) {
    return buscarRecursivo(raiz, id);
}