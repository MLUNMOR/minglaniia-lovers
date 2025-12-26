#include "ArbolInventario.h"

// Función recursiva para crear el árbol.


void ArbolInventario::insertarRecursivo(Nodo*& nodo, const Rango& rango) {
    // 1. Si el hueco está vacío, creamos el nodo aquí
    if (nodo == nullptr) {
        nodo = new Nodo(rango.inicio, rango.fin);
        return;
    }

    // 2. Si es menor, bajamos por la izquierda
    if (rango.inicio < nodo->inicio) {
        insertarRecursivo(nodo->izquierda, rango);
    } 
    // 3. Si es mayor (o igual), bajamos por la derecha
    else {
        insertarRecursivo(nodo->derecha, rango);
    }
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

// Función para llamar a la recursiva
void ArbolInventario::insertar(const Rango& rango) {
    insertarRecursivo(raiz, rango);
}

// Función pública para preguntar si es fresco
bool ArbolInventario::esIngredienteFresco(long long id) {
    return buscarRecursivo(raiz, id);
}