#include <chrono>

#include "cube.h"
#include "iostream"
#include "problem.h"
#include "node.h"
#include "search.h"

bool is_goal(const Cube& cube);
Cube result(Cube cube, const Move& m);
std::list<Move> actions(const Cube& cube);
double action_cost(const Cube&, const Move&, const Cube&);

int main() {
    Cube cube;
    cube.print();
    cube.scramble();
    cube.print();
    std::cout << cube.is_solved() << "\n";

    Problem<Cube, Move> problem{cube, is_goal, result, actions, action_cost};
    Search<Cube, Move> s{};
    auto start = std::chrono::high_resolution_clock::now();
    Node<Cube, Move>* solution1 = s.breadth_first_search(problem);
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    std::cout << "Search took: " << duration.count() << " secs\n";
}

bool is_goal(const Cube& cube) {
    return cube.is_solved();
}

Cube result(Cube cube, const Move& m) {
    cube.apply_move(m);
    return cube;
}

std::list<Move> actions(const Cube&) {
    std::list<Move> m{R, U, F, L, D, B};
    return m;
}

double action_cost(const Cube&, const Move&, const Cube&) {
    return 1;
}