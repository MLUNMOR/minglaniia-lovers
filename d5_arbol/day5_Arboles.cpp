#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct Rango {
    long long inicio;
    long long fin; //long long porque los números del input son enormes
};

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
    Nodo* construirRecursivo(const vector<Rango>& rangos, int start, int end) {
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

    
    bool buscarRecursivo(Nodo* nodo, long long valor) { // Busca si el valor está en algún nodo del árbol
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

    // Borra la memoria recursivamente para no dejar basura
    void liberarMemoria(Nodo* nodo) {
        if (nodo == nullptr) return;
        
        liberarMemoria(nodo->izquierda);
        liberarMemoria(nodo->derecha);
        delete nodo;
    }

public:
    // Constructor
    ArbolInventario() {
        raiz = nullptr;
    }

    // Destructor. Para borrar la memoria de "new"
    ~ArbolInventario() {
        liberarMemoria(raiz);
    }

    // Función para crear el árbol desde fuera
    void construir(const vector<Rango>& rangos) {
        // Por si acaso llamo a construir dos veces, limpio lo anterior
        liberarMemoria(raiz);
        if (!rangos.empty()) {
            raiz = construirRecursivo(rangos, 0, (int)rangos.size() - 1);
        }
    }

    // Función pública para preguntar si es fresco
    bool esIngredienteFresco(long long id) {
        return buscarRecursivo(raiz, id);
    }
};

// Clase para ordenar los datos antes de meterlos al árbol
class ProcesadorDatos {
public:
    static vector<Rango> fusionarRangos(vector<Rango> rangos) {
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
};

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
    inventario.construir(rangosLimpios);

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