#pragma once

#include <deque>
#include <functional>
#include <queue>
#include <unordered_set>

#include "cube.h"
#include "node.h"

const int FOUND = -1;
const std::vector<Move> ALL_MOVES{R, Rp, R2, U, Up, R2, F, Fp, F2, L, Lp, L2, D, Dp, D2, B, Bp, B2};
const std::vector<Move> PHASE_2_MOVES{R2, U, U2, F2, L2, D, D2, B2};

Node* breadth_first_search(const Cube& cube);
Node* bidirectional_best_first_search(const Cube& cube);
bool terminated(Node* solution, const std::priority_queue<Node*>& frontier_front, const std::priority_queue<Node*>& frontier_back);
Node* proceed(const bool& front_dir, std::priority_queue<Node*>& frontier, std::unordered_map<Cube, Node*>& reached,
              std::unordered_map<Cube, Node*>& reached2, Node* solution);
Node* join_nodes(const bool& front_dir, Node* child_node, Node* node);

std::pair<std::deque<Cube>, std::vector<Move>> ida_star(const Cube& cube);
int depth_first_search(std::deque<Cube>& cube, std::vector<Move>& moves, int g, int& bound, std::function<int(const Cube&)> h);
// int phase_one(std::deque<Cube>& cube, int g, int& bound, std::function<int(Cube)> h);
// int phase_two(std::deque<Cube>& cube, int g, int& bound, std::function<int(Cube)> h);
int unoriented_heuristic(const Cube& cube);
int max_heuristic(const Cube& cube);
int max_sum_heuristic(const Cube& cube);