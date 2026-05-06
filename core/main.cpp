#include <chrono>
#include <iostream>

#include "cube.h"
#include "search.h"

int main() {
    Cube cube{3};
    cube.print();
    cube.scramble("R' U B2 L2 D' F2 L2 F"); // 2 L' D2 L U B R U' B' F'
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

    // auto start = std::chrono::high_resolution_clock::now();
    // auto node = breadth_first_search(cube);
    // auto end = std::chrono::high_resolution_clock::now();
    //
    // auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    // std::cout << "Search took: " << duration.count() << " secs\nSolution: ";
    //
    // for (auto move : node->moves()) {
    //     std::cout << move_to_string(move) << " ";
    // }
}