#include "search.h"

#include <climits>
#include <unordered_set>

Node* breadth_first_search(const Cube& cube) {
    Node* node = new Node{cube};
    if (cube.is_solved()) {
        return node;
    }
    std::deque<Node*> frontier{node};
    std::unordered_set<Cube> reached{cube};

    while (!frontier.empty()) {
        Node* front = frontier.front();
        frontier.pop_front();
        for (Move m : ALL_MOVES) {
            Cube child = front->cube;
            child.apply_move(m);
            Node* child_node = new Node{child, front, m};

            if (child.is_solved()) {
                return child_node;
            }

            if (!reached.contains(child)) {
                reached.insert(child);
                frontier.push_back(child_node);
            }
        }
    }
    return nullptr;
}

std::pair<std::deque<Cube>, std::vector<Move>> ida_star(const Cube& cube) {
    int bound = cube.max_sum_heuristic();
    std::deque path{cube};
    std::vector<Move> moves{};

    while (true) {
        int t = depth_first_search(path, moves, 0, bound, max_sum_heuristic);
        if (t == FOUND) {
            return {path, moves};
        }
        bound = t;
    }
}

int depth_first_search(std::deque<Cube>& path, std::vector<Move>& moves, int g, int& bound, std::function<int(const Cube&)> h) {
    Cube cube = path.back();
    int f = g + h(cube);

    if (f > bound) {
        return f;
    }
    if (cube.is_solved()) {
        return FOUND;
    }

    int min = INT_MAX;

    for (Move m : ALL_MOVES) {
        if (!moves.empty() && (m / 3) == (moves.back() / 3)) {
            continue;
        }

        Cube child = cube;
        child.apply_move(m);
        if (std::find(path.begin(), path.end(), child) != path.end()) {
            continue;
        }
        path.push_back(child);
        moves.push_back(m);

        int t = depth_first_search(path, moves, g + 1, bound, h);

        if (t == FOUND) {
            return FOUND;
        }

        if (t < min) {
            min = t;
        }

        path.pop_back();
        moves.pop_back();
    }
    return min;
}

int unoriented_heuristic(const Cube& cube) {
    return cube.unoriented_heuristic();
}

int max_heuristic(const Cube& cube) {
    return cube.max_heuristic();
}

int max_sum_heuristic(const Cube& cube) {
    return cube.max_sum_heuristic();
}
