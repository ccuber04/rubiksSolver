#include "search.h"

#include <climits>

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

Node* bidirectional_best_first_search(const Cube& cube) {
    Node* node_front = new Node{cube};
    Cube solved{3};
    Node* node_back = new Node{solved};
    std::priority_queue<Node*> frontier_front{node_front}; // TODO: learn what is causing this error, operator overload??
    std::priority_queue<Node*> frontier_back{node_back};
    std::unordered_map<Cube, Node*> reached_front{{cube, node_front}};
    std::unordered_map<Cube, Node*> reached_back{{solved, node_back}};
    Node* solution{nullptr};
    while (!terminated(solution, frontier_front, frontier_back)) {
        Node* front_top = frontier_front.top();
        Node* back_top = frontier_back.top();
        if (front_top->cube.max_heuristic() < back_top->cube.max_heuristic()) {
            solution = proceed(true, frontier_front, reached_front, reached_back, solution);
        }
        else {
            solution = proceed(false, frontier_back, reached_back, reached_front, solution);
        }
    }
    return solution;
}

// TODO: implement terminated
bool terminated(Node* solution, const std::priority_queue<Node*>& frontier_front, const std::priority_queue<Node*>& frontier_back) {
    // determines when to stop looking for a new solution, because the first solution might not be the best
}

Node* proceed(const bool& front_dir, std::priority_queue<Node*>& frontier, std::unordered_map<Cube, Node*>& reached, std::unordered_map<Cube, Node*>& reached2, Node* solution){
    Node* node{frontier.top()};
    frontier.pop();

    for (Move m : ALL_MOVES) {
        Cube child = node->cube;
        child.apply_move(m);
        Node* child_node = new Node{child};
        if (!reached.contains(child)) { // TODO: book has path cost, not sure if that should be in this
            reached[child] = child_node;
            frontier.push(child_node);
            if (reached2.contains(child)) {
                Node* solution2 = join_nodes(front_dir, child_node, reached2[child]);
                if (solution2->depth() < solution->depth()) {
                    solution = solution2;
                }
            }
        }
    }
    return solution;
}

// TODO: implement join_nodes
Node* join_nodes(const bool& front_dir, Node* child_node, Node* node) { // TODO: should this be a part of Node class??
    if (front_dir) {

    }
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
