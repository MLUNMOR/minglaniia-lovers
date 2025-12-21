
#include "tachyon.h"
#include <algorithm> // std::max

TachyonManifold::TachyonManifold(const std::vector<std::string>& input)
{
    grid = input;
    H = static_cast<int>(grid.size());
    W = (H > 0) ? static_cast<int>(grid[0].size()) : 0;

    // Validación opcional: asegurar que todas las filas tienen la misma longitud
    // (si no lo tuviesen, podríamos normalizarlas o lanzar error)
    for (int i = 1; i < H; ++i) {
        if (static_cast<int>(grid[i].size()) != W) {
            // Por simplicidad, aquí asumimos grid bien formado; en caso contrario:
            // W = std::min(W, static_cast<int>(grid[i].size()));
            // o lanzar una excepción.
        }
    }

    // Inicializa la tabla de memorización a -1 (no calculado)
    memo.assign(H, std::vector<int>(W, -1));
}

int TachyonManifold::countSplits()
{
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] == 'S') {
                // Comienza debajo de 'S' si existe esa fila
                if (i + 1 < H) return dfs(i + 1, j);
                return 0;
            }
        }
    }
    // Si no hay 'S' en el grid, el resultado es 0
    return 0;
}

int TachyonManifold::dfs(int x, int y)
{
    // Fuera de límites => no hay splits
    if (!inBounds(x, y)) return 0;

    // Si ya fue calculado, devolverlo (PD con memoria)
    int &cached = memo[x][y];
    if (cached != -1) return cached;

    char cell = grid[x][y];

    int res = 0;
    switch (cell) {
        case '.':
            // Camino libre: desciende
            res = dfs(x + 1, y);
            break;
        case '^':
            // Split: cuenta 1 y bifurca abajo-izquierda y abajo-derecha
            res = 1
                + dfs(x + 1, y - 1)
                + dfs(x + 1, y + 1);
            break;
        case '#':
            // Obstáculo: bloquea
            res = 0;
            break;
        default:
            // Cualquier otro símbolo: tratamos como camino libre que desciende
            res = dfs(x + 1, y);
            break;
    }

       cached = res;          // Guardar en la tabla de memoria
    return cached;

