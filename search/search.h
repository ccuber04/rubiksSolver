#pragma once

#include <deque>
#include <iostream>
#include <unordered_set>

#include "problem.h"
#include "node.h"

template<typename State, typename Action>
class Search {
public:
    Search() = default;

    std::list<Action> path_actions(const Node<State, Action>* node) {
        std::list<Action> actions;
        while (node->parent != nullptr) {
            actions.push_front(node->action);
            node = node->parent;
        }
        return actions;
    }

    std::list<State> path_states(const Node<State, Action>* node) {
        std::list<State> states;
        while (node->parent != nullptr) {
            states.push_front(node->state);
            node = node->parent;
        }
        return states;
    }

    std::list<Node<State, Action>*> expand(const Problem<State, Action>& problem, Node<State, Action>* node) {
        State state = node->state;
        std::list<Node<State, Action>*> children;
        for (Action action : problem.actions(state)) {
            State new_state = problem.result(state, action);

            double cost = node->path_cost + problem.action_cost(state, action, new_state);
            Node<State, Action>* new_node = new Node<State, Action>(new_state, node, action, cost);
            children.push_back(new_node);
        }
        return children;
    }

    Node<State, Action>* breadth_first_search(const Problem<State, Action>& problem) {
        Node<State, Action>* node = new Node<State, Action>{problem.initial};
        if (problem.is_goal(node->state)) { // not sure
            return node;
        }
        std::deque<Node<State, Action>*> frontier{node}; // look into this line
        std::unordered_set<State> reached{problem.initial}; // integer hash function
        // flatten cube representation from 3D to 1D and store key as 1D int and value as matrix (follow up
        // with Dr. Brown on the matrix, is it the 3D matrix representation for cube?)

        while (!frontier.empty()) {
            Node<State, Action>* node1 = frontier.front();
            frontier.pop_front();
            for (auto child : expand(problem, node1)) {
                State s = child->state;
                if (problem.is_goal(s)) {
                    std::cout << "breadth_first_search: reached = " << reached.size() << "\n";
                    std::cout << "breadth_first_search: path length = " << path_actions(child).size() << "\n";
                    std::cout << "breadth_first_search: actions = ";
                    for (auto action : path_actions(child)) {
                        std::cout << action << " ";
                    }
                    std::cout << "\n";
                    return child;
                }
                if (!reached.contains(s)) {
                    reached.insert(s);
                    frontier.push_back(child);
                }
            }
        }
        return nullptr;
    }
};

