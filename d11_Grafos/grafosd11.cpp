
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <cctype>
using namespace std;

// Arista con nombres de nodos tipo string
struct Arista {
    string origen;
    string destino;
};

struct Grafo {
    // lista de adyacencia: nodo -> destinos
    unordered_map<string, vector<string>> adj;

    Grafo() = default;

    // Añadir arista dirigida u -> v
    void agregarArista(const string& u, const string& v) {
        adj[u].push_back(v);
        // Asegurar que el destino existe como clave (aunque no tenga salientes)
        if (!adj.count(v)) adj[v] = {};
    }

    // Comprobar existencia de una arista u -> v
    bool existeArista(const string& u, const string& v) const {
        auto it = adj.find(u);
        if (it == adj.end()) return false;
        for (const auto& d : it->second) {
            if (d == v) return true;
        }
        return false;
    }

    // Imprimir el grafo
    void imprimir() const {
        for (const auto& par : adj) {
            const string& u = par.first;
            const auto& lista = par.second;
            cout << u << ": ";
            for (const auto& v : lista) {
                cout << "(" << u << " --> " << v << ") ";
            }
            cout << "\n";
        }
    }

    // DFS con backtracking para enumerar caminos simples (sin repetir nodos)
    void dfs(const string& actual,
             const string& destino,
             unordered_set<string>& visitado,
             vector<string>& camino,
             vector<vector<string>>& res) const
    {
        camino.push_back(actual);

        if (actual == destino) {
            res.push_back(camino);
            camino.pop_back();
            return;
        }

        visitado.insert(actual);

        auto it = adj.find(actual);
        if (it != adj.end()) {
            for (const auto& v : it->second) {
                if (!visitado.count(v)) {
                    dfs(v, destino, visitado, camino, res);
                }
            }
        }

        visitado.erase(actual);
        camino.pop_back();
    }

    // Interfaz pública: todos los caminos de origen a destino
    vector<vector<string>> caminosNodos(const string& origen, const string& destino) const {
        if (!adj.count(origen)) {
            throw invalid_argument("caminosNodos: el nodo origen no existe: " + origen);
        }
        if (!adj.count(destino)) {
            throw invalid_argument("caminosNodos: el nodo destino no existe: " + destino);
        }

        vector<vector<string>> res;
        vector<string> camino;
        unordered_set<string> visitado;

        dfs(origen, destino, visitado, camino, res);
        return res;
    }

    // (Opcional) caminos que comienzan con arista A=(u->v) y terminan con arista B=(x->y)
    vector<vector<string>> caminosEntreAristas(const Arista& A, const Arista& B) const {
        if (!existeArista(A.origen, A.destino)) {
            throw invalid_argument("caminosEntreAristas: la arista A no existe en el grafo");
        }
        if (!existeArista(B.origen, B.destino)) {
            throw invalid_argument("caminosEntreAristas: la arista B no existe en el grafo");
        }

        // Caminos de A.destino hasta B.origen
        auto intermedios = caminosNodos(A.destino, B.origen);

        vector<vector<string>> res;
        res.reserve(intermedios.size());

        for (auto& mid : intermedios) {
            // Construir [A.origen, (A.destino ... B.origen), B.destino]
            vector<string> completo;
            completo.reserve(mid.size() + 2);
            completo.push_back(A.origen);
            completo.insert(completo.end(), mid.begin(), mid.end());
            completo.push_back(B.destino);
            res.push_back(move(completo));
        }
        return res;
    }

    // Utilidad: imprimir una lista de caminos
    static void imprimirCaminos(const vector<vector<string>>& paths) {
        if (paths.empty()) {
            cout << "No hay caminos.\n";
            return;
        }
        for (const auto& p : paths) {
            cout << "[ ";
            for (size_t i = 0; i < p.size(); ++i) {
                cout << p[i];
                if (i + 1 < p.size()) cout << " -> ";
            }
            cout << " ]\n";
        }
    }

    // Cargar grafo desde fichero .txt (formato: "origen: dest1 dest2 ...")
    void cargarDesdeFichero(const string& nombreArchivo) {
        ifstream in(nombreArchivo);
        if (!in) {
            throw runtime_error("No se pudo abrir el archivo: " + nombreArchivo);
        }

        string linea;
        while (getline(in, linea)) {
            if (linea.empty()) continue;

            // Buscar ':'
            auto pos = linea.find(':');
            if (pos == string::npos) continue;

            // Extraer origen y rhs
            string origen = linea.substr(0, pos);
            string rhs    = linea.substr(pos + 1);

            // Quitar posibles espacios al final de 'origen'
            while (!origen.empty() && isspace(static_cast<unsigned char>(origen.back()))) {
                origen.pop_back();
            }
            // Quitar posibles espacios al principio de 'rhs'
            size_t k = 0;
            while (k < rhs.size() && isspace(static_cast<unsigned char>(rhs[k]))) {
                ++k;
            }
            rhs = rhs.substr(k);

            // Asegurar que el origen exista
            if (!adj.count(origen)) adj[origen] = {};

            // Tokenizar destinos de la arista separados por espacios
            istringstream toks(rhs);
            string dest;
            while (toks >> dest) {
                agregarArista(origen, dest);
            }
        }
    }
};

int main() {
    const string ruta = "input.txt";

    Grafo g;
    try {
        g.cargarDesdeFichero(ruta);
    } catch (const exception& e) {
        cerr << e.what() << "\n";
        return 1;
    }

    cout << "Grafo cargado:\n";
    g.imprimir();

    // Buscar todos los caminos desde "you" hasta "out"
    try {
        auto paths = g.caminosNodos("you", "out");
        cout << "\nCaminos de 'you' a 'out':\n";
        Grafo::imprimirCaminos(paths);
    } catch (const exception& e) {
        cerr << "Error al buscar caminos: " << e.what() << "\n";
        return 2;
    }

    return 0;
}
