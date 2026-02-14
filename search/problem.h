#pragma once

#include <functional>
#include <list>

template<typename State, typename Action>
class Problem {
public:
    Problem(const State& initial, std::function<bool()> is_goal, std::function<Action> result, std::function<std::list<Action>> actions, std::function<double()> action_cost)
            : initial{initial}, is_goal{is_goal}, result{result}, actions{actions}, action_cost{action_cost} {}

private:
    State initial;
    std::function<bool()> is_goal;
    std::function<Action> result;
    std::function<std::list<Action>> actions;
    std::function<double()> action_cost;

};