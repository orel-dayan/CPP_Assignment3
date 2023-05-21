#pragma once
#include "Ninja.hpp"
namespace ariel
{

    static const int SPEED_YOUNG = 14;
    static const int INTIAL_HITPOINTS_YOUNG = 100;

    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(const std::string &name, const Point &pos) : Ninja(name, pos, SPEED_YOUNG, INTIAL_HITPOINTS_YOUNG) {}
    };
}
