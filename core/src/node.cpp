#include "node.h"

#include <algorithm>

Node::Node(Cube cube)
    : cube{cube}, parent{nullptr}, move{} {}

Node::Node(Cube cube, Node* parent, const Move& move)
    : cube{cube}, parent{parent}, move{move}{}

Node::~Node() {}

std::vector<Move> Node::moves() {
    std::vector<Move> moves;
    Node* current = this;
    while (current->parent != nullptr) {
        moves.push_back(current->move);
        current = current->parent;
    }
    std::reverse(moves.begin(), moves.end());
    return moves;
}