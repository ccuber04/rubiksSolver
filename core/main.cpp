#include <chrono>
#include <iostream>

#include "cube.h"
#include "search.h"

int main() {
    Cube cube{3};
    cube.print();
    cube.scramble("R U R' U' F2 U'");
    cube.print();
    std::cout << cube.is_solved() << "\n";

    auto start = std::chrono::high_resolution_clock::now();
    auto pair = ida_star(cube);
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    std::cout << "Search took: " << duration.count() << " secs\nSolution: ";

    for (auto m : pair.second) {
        std::cout << move_to_string(m) << " ";
    }
}