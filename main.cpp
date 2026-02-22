#include "cube.h"
#include "iostream"

int main() {
    Cube cube;
    cube.print();

    std::cout << cube.is_solved() << "\n";
}