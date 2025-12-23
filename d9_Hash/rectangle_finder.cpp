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
    HashTable(int size) : m(size), table(size, nullptr) {}

    void insert(int x, int y) {// Insertar (x,y) en la tabla
        int idx = hashFunction(x, y);
        Node* n = new Node{{x, y}, table[idx]};// Nuevo nodo al inicio
        table[idx] = n;
    }

    bool find(int x, int y) {// Buscar (x,y) en la tabla
        int idx = hashFunction(x, y);
        Node* cur = table[idx];
        while (cur) {// Recorrer lista enlazada
            if (cur->p.x == x && cur->p.y == y)// Encontrado
                return true;
            cur = cur->next;// Avanzar al siguiente nodo
        }
        return false;
    }
};

int main() {
    vector<Point> points;
    ifstream f("input.txt");// Abrir archivo de entrada

    if (!f) {// ERROR al abrir archivo
        cerr << "No se pudo abrir input.txt\n";
        return 1;
    }

    HashTable H(200003);

    // Leer puntos evitando duplicados
    string line;
    while (getline(f, line)) {// Lectura línea por línea
        int x, y;
        char comma;
        stringstream ss(line);
        if (ss >> x >> comma >> y) {
            if (!H.find(x, y)) {// Evitar duplicados
                H.insert(x, y);
                points.push_back({x, y});// Añadir punto único
            }
        }
    }

    long long maxArea = 0;

    // Comparar todas las parejas
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {

            int x1 = points[i].x, y1 = points[i].y;// Coordenadas del primer punto
            int x2 = points[j].x, y2 = points[j].y;// Coordenadas del segundo punto

            // Cálculo del área
            long long area =(abs(x1 - x2) + 1) *(abs(y1 - y2) + 1);// Se suma 1 ya que la primera columna y fila es 0.

            maxArea = max(maxArea, area);// Actualizar área máxima
        }
    }

    cout << maxArea << endl;// Imprimir área máxima
    return 0;
}
