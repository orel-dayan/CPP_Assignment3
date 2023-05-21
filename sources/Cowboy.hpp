#pragma once

#include "Character.hpp"
namespace ariel
{

    /**
     * @brief static members of the class  Cowboy from the introduction of assigment
     *
     */

    static const int MAX_BULLETS = 6;
    static const int INITAIL_HITPOINTS = 110;
    static const int DAMAGE = 10;

    class Cowboy : public Character
    {

    public:
        int m_bullets;

        Cowboy(const std::string &name, const Point &location) : // NOLINT(cppcoreguidelines-pro-type-member-init)
                                                                 Character(name, location, INITAIL_HITPOINTS),
                                                                 m_bullets(MAX_BULLETS)
        {
            m_location.print(); // print the location of the character
        }

        std::string print() const override; // print the character

        void shoot(Character *character); // shoot other character

        bool hasboolets() const
        { // check if the character has bullets
            return m_bullets > 0;
        }

        void reload(); // reload bullets

        void attack(Character *other) override; // attack other character
    };
}
