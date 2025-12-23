#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

// Punto con coordenadas
struct Point {
    int x, y;
};

// Nodo para encadenamiento
struct Node {
    Point p;
    Node* next;
};

// Tabla hash con encadenamiento
class HashTable {
private:
    int m;                     
    vector<Node*> table;       

    // Función hash para (x,y)
    int hashFunction(int x, int y) {
        long long k = (long long)x * 1000003LL + y;
        return (k % m + m) % m;
    }

public:
    // Constructor
    HashTable(int size) : m(size), table(size, nullptr) {}

    // Inserta un punto
    void insert(int x, int y) {
        int idx = hashFunction(x, y);
        Node* n = new Node{{x, y}, table[idx]};
        table[idx] = n;
    }

    // Busca un punto
    bool find(int x, int y) {
        int idx = hashFunction(x, y);
        Node* cur = table[idx];
        while (cur) {
            if (cur->p.x == x && cur->p.y == y)
                return true;
            cur = cur->next;
        }
        return false;
    }
};

int main() {
    vector<Point> points; // Lista de puntos
    ifstream f("input.txt"); // Archivo de entrada

    if (!f) { // Error al abrir
        cerr << "No se pudo abrir input.txt\n";
        return 1;
    }

    HashTable H(200003); // Tabla hash

    // Lectura de puntos x,y evitando duplicados
    string line;
    while (getline(f, line)) {
        int x, y;
        char comma;
        stringstream ss(line);
        if (ss >> x >> comma >> y) {

            // Evitar duplicados
            if (!H.find(x, y)) {
                H.insert(x, y);
                points.push_back({x, y});
            }
        }
    }

    long long maxArea = 0; // Área máxima

    // Comparar todas las parejas
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {

            int x1 = points[i].x, y1 = points[i].y;
            int x2 = points[j].x, y2 = points[j].y;

            if (x1 == x2 || y1 == y2) continue; // No forman rectángulo

            long long area = abs(x1 - x2) * abs(y1 - y2); // Área
            maxArea = max(maxArea, area); // Actualizar máximo
        }
    }

    cout << maxArea << endl; // Mostrar resultado
    return 0;
}
