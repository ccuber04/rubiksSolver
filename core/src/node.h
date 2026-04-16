#pragma once

#include "cube.h"

class Node {
public:
    Node(Cube cube);
    Node(Cube cube, Node* parent, const Move& move);
    ~Node();

    std::vector<Move> moves();

    Cube cube;
    Node* parent;
    Move move;
};