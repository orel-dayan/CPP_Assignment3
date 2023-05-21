#pragma once

#include <string>
#include "Point.hpp"
#include <stdexcept>

namespace ariel
{
    class Character
    {

    protected:
        Character(const std::string &name, const Point &location, const int hitPoints) : m_name(name),
                                                                                         m_location(location),
                                                                                         m_hitPoints(hitPoints),
                                                                                         m_inTeam(false) // NOLINT
        {
        }

    public:
        const std::string m_name;
        Point m_location;
        int m_hitPoints;
        bool m_inTeam;

        /**
         * @brief delete copy constructor, assignment operator, move constructor and move assignment operator ,
         * because we don't want to copy or move characters
         *
         */

        Character(const Character &) = delete;            // disable copy constructor
        Character &operator=(const Character &) = delete; // disable assignment operator
        Character(Character &&) = delete;                 // disable move constructor
        Character &operator=(Character &&) = delete;      // disable move assignment operator
        Character() = delete;                             // disable default constructor

        virtual ~Character() = default; // destructor for Character -default implementation

        const std::string &getName() const
        { // return the name of the character
            return m_name;
        }

        const Point &getLocation() const
        { // return the location of the character
            return m_location;
        }

        const int getHitPoints() const //NOLINT
        { 
            return m_hitPoints;
        }

        virtual std::string print() const = 0; // return the character representation according to its type

        virtual void attack(Character *) = 0; // attack other character

        double distance(Character *other) const;

        void hit(int damage); // reduce hitpoints by damage amount

        void addToTeam()
        { // add the character to the team
            m_inTeam = true;
        }

        bool isAlive() const
        { // return true if the character is alive
            return m_hitPoints > 0;
        }
    };
}
