#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

// Estructuras

struct Point {
    int x, y;
};

struct Node {
    Point p;
    Node* next;
};

// Tabla Hash con encadenamiento

class HashTable {
private:
    int m;
    vector<Node*> table;

    int hashFunction(int x, int y) {
        long long k = ((long long)x << 32) ^ (unsigned int)y;
        return (k % m + m) % m;   // índice siempre válido
    }

public:
    HashTable(int size) : m(size), table(size, nullptr) {}

    void insert(int x, int y) {
        int idx = hashFunction(x, y);
        Node* n = new Node{{x, y}, table[idx]};
        table[idx] = n;
    }

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

// Programa principal

int main() {
    vector<Point> points;
    ifstream f("input.txt");

    if (!f) {
        cerr << "No se pudo abrir input.txt\n";
        return 1;
    }

    // Lectura robusta
    string line;
    while (getline(f, line)) {
        int x, y;
        char comma;
        stringstream ss(line);
        if (ss >> x >> comma >> y) {
            points.push_back({x, y});
        }
    }

    HashTable H(200003);

    for (auto& p : points)
        H.insert(p.x, p.y);

    long long maxArea = 0;

    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {

            int x1 = points[i].x, y1 = points[i].y;
            int x2 = points[j].x, y2 = points[j].y;

            if (x1 == x2 || y1 == y2) continue;

            if (H.find(x1, y2) && H.find(x2, y1)) {
                long long area =
                    llabs(x1 - x2) * llabs(y1 - y2);
                maxArea = max(maxArea, area);
            }
        }
    }

    cout << maxArea << endl;
    return 0;
}
