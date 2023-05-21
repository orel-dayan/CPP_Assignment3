#pragma once

#include "Team.hpp"

namespace ariel
{
    class SmartTeam : public Team
    {
    public:
        SmartTeam(Character *captain) : Team(captain) {}

        void attack(Team *other) override;

        void print() const override;

        Character *findWeakestOpponent(Team *other) const;
        Character *findCloseNinja(Team *other) const;
    };
}
