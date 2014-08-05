/**
 * @class Action
 * @brief Operates on the world state.
 *
 * @date  July 2014
 * @copyright (c) 2014 Prylis Inc.. All rights reserved.
 */

#pragma once

struct WorldState;

#include <string>
#include <unordered_map>

class Action {
private:
    std::string name_; // The human-readable action name
    int cost_;         // The numeric cost of this action

    // Preconditions are things that must be satisfied before this
    // action can be taken. Only preconditions that "matter" are here.
    std::unordered_map<std::string, bool> preconditions_;

    // Effects are things that happen when this action takes place.
    std::unordered_map<std::string, bool> effects_;

public:
    Action();
    Action(std::string name, int cost);

    /**
     Is this action eligible to operate on the given worldstate?
     @param ws the worldstate in question
     @return true if this worldstate meets the preconditions
    */
    bool eligibleFor(const WorldState& ws) const;

    /**
     Act on the given worldstate. Still runs if inelgible, but no
     effects will be applied.
     @param the worldstate to act on
     @return a copy worldstate, with effects applied
    */
    WorldState actOn(const WorldState& ws) const;

    /**
     Set the given precondition variable and value.
     @param key the name of the precondition
     @param value the value the precondition must hold
    */
    void setPrecondition(const std::string& key, const bool value) {
        preconditions_[key] = value;
    }

    /**
     Set the given effect of this action, in terms of variable and new value.
     @param key the name of the effect
     @param value the value that will result
    */
    void setEffect(const std::string& key, const bool value) {
        effects_[key] = value;
    }

    int cost() const { return cost_; }

    std::string name() const { return name_; }
};

