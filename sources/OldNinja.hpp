#pragma once

#include "Ninja.hpp"

namespace ariel
{
    const int OLD_SPEED = 8;
    const int OLD_INTIAL_HITPOINTS = 150;

    class OldNinja : public Ninja
    {
    public:
        OldNinja(const std::string &name, const Point &location) : Ninja(name, location, OLD_SPEED, OLD_INTIAL_HITPOINTS) {} // NOLINT
    };

}
