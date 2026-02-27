#pragma once

#include <functional>
#include <list>

template<typename State, typename Action>
class Problem {
public:
    Problem(const State& initial, std::function<bool(const State&)> is_goal, std::function<State(State, const Action&)> result, std::function<std::list<Action>(const State&)> actions, std::function<double(const State&, const Action&, const State&)> action_cost)
            : initial{initial}, is_goal{is_goal}, result{result}, actions{actions}, action_cost{action_cost} {}

    State initial;
    std::function<bool(const State&)> is_goal;
    std::function<State(State, const Action&)> result;
    std::function<std::list<Action>(const State&)> actions;
    std::function<double(const State&, const Action&, const State&)> action_cost;
};