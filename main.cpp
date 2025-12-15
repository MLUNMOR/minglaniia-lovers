#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "tachyon.h"

int main()
{
    std::vector<std::string> input;
    std::ifstream infile("grid.txt");

    if(!infile) {
        std::cerr << "No se pudo abrir grid.txt" << std::endl;
        return 1;
    }

    std::string line;
    while(std::getline(infile, line)) {
        if(!line.empty())
            input.push_back(line);
    }
    infile.close();

    if(input.empty()) {
        std::cerr << "Archivo grid.txt vacío" << std::endl;
        return 1;
    }

    TachyonManifold manifold(input);
    int total_splits = manifold.countSplits();
    std::cout << "Total splits: " << total_splits << std::endl;

    return 0;
}
