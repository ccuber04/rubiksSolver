#pragma once

#include <deque>
#include <set>
#include <iostream>

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

    std::list<Node<State, Action>> expand(const Problem<State, Action>& problem, const Node<State, Action>* node) {
        State state = node->state;
        std::list<Node<State, Action>> children;
        for (auto action : problem.actions(state)) {
            State new_state = problem.result(state, action);

            double cost = node->path_cost + problem.action_cost(state, action, new_state);
            children.emplace_back(new_state, &node, action, cost);
        }
        return children;
    }

    Node<State, Action> breadth_first_search(Problem<State, Action> problem) {
        Node<State, Action>* node = Node<State, Action>(problem.initial);
        if (problem.is_goal(node->state)) { // not sure
            return node;
        }
        std::deque<Node<State, Action>*> frontier{node}; // look into this line
        std::set<State> reached{problem.initial};

        while (frontier.size() != 0) {
            Node<State, Action>* node = frontier.front();
            frontier.pop_front();
            for (auto child : expand(problem, node)) {
                State s = child.state;
                if (problem.is_goal(s)) {
                    std::cout << "breadth_first_search: reached = " << reached.size() << "\n";
                    std::cout << "breadth_first_search: path length = " << path_actions(child).size() << "\n";
                    return child;
                }
                if (!reached.contains(s)) {
                    reached.insert(s);
                    frontier.push_front(child);
                }
            }
        }
        return nullptr;
    }
};

