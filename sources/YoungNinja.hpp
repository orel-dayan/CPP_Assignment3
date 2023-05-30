#pragma once
#include "Ninja.hpp"
namespace ariel
{
   
     const int S_SPEED_YOUNG = 14;
     const int S_INTIAL_HITPOINTS_YOUNG = 100;
     /**
     * @brief The YoungNinja class represents a young ninja character.
     *
     * It is a derived class from the base class Ninja.
     */

    class YoungNinja : public Ninja
    {
    public:
        /**
         * @brief Constructs a YoungNinja object with the given name and location.
         *
         * @param name The name of the young ninja.
         * @param Location The location of the young ninja.
         */

        YoungNinja(const std::string &name, const Point &Location) : Ninja(name, Location, S_SPEED_YOUNG, S_INTIAL_HITPOINTS_YOUNG) {}
    };
}
