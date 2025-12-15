#ifndef TACHYON_H
#define TACHYON_H

#include <vector>
#include <string>
#include <unordered_map>
#include <utility>

class TachyonManifold {
public:
    TachyonManifold(const std::vector<std::string>& input);

    int countSplits();

private:
    std::vector<std::string> grid;
    int H, W;
    std::unordered_map<int,int> memo;
    int dfs(int x, int y);
};

#endif
