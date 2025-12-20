#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

// Estructuras

struct Point {
    int x, y;  // Coordenadas del punto
};

struct Node {
    Point p;   // Punto almacenado en el nodo
    Node* next; // Puntero al siguiente nodo (encadenamiento en la tabla hash)
};

// Tabla Hash con encadenamiento

class HashTable {
private:
    int m;                  // Tamaño de la tabla hash
    vector<Node*> table;    // Vector de punteros a nodos para cada índice

    // Función hash combinando x e y en un entero de 64 bits
    int hashFunction(int x, int y) {
        long long k = ((long long)x << 32) ^ (unsigned int)y; 
        return (k % m + m) % m;   // Garantiza un índice no negativo
    }

public:
    HashTable(int size) : m(size), table(size, nullptr) {}

    void insert(int x, int y) {
        int idx = hashFunction(x, y);
        // Inserción al inicio de la lista en el índice correspondiente
        Node* n = new Node{{x, y}, table[idx]};
        table[idx] = n;
    }

    bool find(int x, int y) {
        int idx = hashFunction(x, y);
        Node* cur = table[idx];
        // Recorremos la lista enlazada buscando el punto
        while (cur) {
            if (cur->p.x == x && cur->p.y == y)
                return true;
            cur = cur->next;
        }
        return false;
    }
};

// Programa principal

int main() {
    vector<Point> points;
    ifstream f("input.txt");

    //Error al abrir el txt
    if (!f) {
        cerr << "No se pudo abrir input.txt\n";
        return 1;
    }

    // Lectura robusta línea por línea
    string line;
    while (getline(f, line)) {
        int x, y;
        char comma;
        stringstream ss(line);
        if (ss >> x >> comma >> y) {
            points.push_back({x, y});  // Guardamos el punto leído
        }
    }

    HashTable H(200003); // Inicializamos tabla hash con tamaño primo grande

    // Insertamos todos los puntos en la tabla hash
    for (auto& p : points)
        H.insert(p.x, p.y);

    long long maxArea = 0;

    // Recorremos todos los pares de puntos para buscar rectángulos
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {

            int x1 = points[i].x, y1 = points[i].y;
            int x2 = points[j].x, y2 = points[j].y;

            if (x1 == x2 || y1 == y2) continue; 
            // Saltamos puntos que estén alineados vertical u horizontalmente

            // Verificamos si existen los otros dos vértices del rectángulo
            if (H.find(x1, y2) && H.find(x2, y1)) {
                // Calculamos el área del rectángulo formado
                long long area = llabs(x1 - x2) * llabs(y1 - y2);
                maxArea = max(maxArea, area); // Guardamos el área máxima
            }
        }
    }

    cout << maxArea << endl; // Imprime el área máxima encontrada
    return 0;
}
