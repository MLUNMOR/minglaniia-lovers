
#ifndef TACHYON_H
#define TACHYON_H

#include <vector>
#include <string>

class TachyonManifold {
public:
    // Construye el grid y prepara la tabla de memoria
    TachyonManifold(const std::vector<std::string>& input);

    // Busca 'S' y calcula el número total de splits desde la celda inferior a 'S'
    int countSplits();

private:
    std::vector<std::string> grid;
    int H, W;

    // Tabla de memorización: memo[x][y] = resultado de F(x,y); -1 => no calculado
    std::vector<std::vector<int>> memo;

    // Devuelve el nº de splits alcanzables empezando en (x,y)
    int dfs(int x, int y);

    // Comprobación de límites
    inline bool inBounds(int x, int y) const {
        return (x >= 0 && x < H && y >= 0 && y < W);
    }
};

#endif
