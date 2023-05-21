#pragma once

#include "Team.hpp"
namespace ariel
{
    class Team2 : public Team
    {
    public:
        /**
         * @brief Construct a new Team 2 object
         *
         * @param leader  the leader of the team
         */

        Team2(Character *leader) : Team(leader) {} // NOLINT

        void attack(Team *other) override; // attack the other team

        void print() const override; // print the team
    };
}
