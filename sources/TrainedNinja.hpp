#pragma once

#include "Ninja.hpp"
namespace ariel
{
    static const int SPEED_TRAINED = 12;
    static const int INTIAL_HITPOINTS_TRAINED = 120;

    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(const std::string &name, const Point &pos) : Ninja(name, pos, SPEED_TRAINED,
                                                                        INTIAL_HITPOINTS_TRAINED) {}
    };
}
