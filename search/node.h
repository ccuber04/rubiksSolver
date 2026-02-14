#pragma once

#include <memory>

template<typename State, typename Action>
class Node {
public:
    Node(State& state, std::shared_ptr<Node>& parent, const Action& action, const double& path_cost)
        : state{state}, parent{parent}, action{action}, path_cost{path_cost} {}

    int depth(const Node& node) {
        if (node.parent == nullptr) {
            return 0;
        }
        return depth(node.parent) + 1;
    }

private:
    State state;
    Node parent;
    Action action;
    double path_cost;
};