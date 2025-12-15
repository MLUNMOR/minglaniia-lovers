#include "tachyon.h"

TachyonManifold::TachyonManifold(const std::vector<std::string>& input)
{
    grid = input;
    H = grid.size();
    W = grid[0].size();
    memo.clear();
}

int TachyonManifold::countSplits()
{
    for(int i=0;i<H;i++)
        for(int j=0;j<W;j++)
            if(grid[i][j]=='S')
                return dfs(i+1,j);
    return 0;
}

int TachyonManifold::dfs(int x, int y)
{
    if(x>=H || y<0 || y>=W)
        return 0;

    int key = x*W + y;
    if(memo.count(key))
        return memo[key];

    int res = 0;
    char cell = grid[x][y];

    if(cell == '.') {
        res = dfs(x+1,y);
    }
    else if(cell == '^') {
        res = 1 + dfs(x, y-1) + dfs(x, y+1);
    }
    else {
        res = dfs(x+1,y);
    }

    memo[key] = res;
    return res;
}
