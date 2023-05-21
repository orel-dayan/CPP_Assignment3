#pragma once

#include <array>
#include <typeinfo>
#include "Character.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"

namespace ariel
{
    static const int MAX_TEAMMATES = 10;

    class Team
    {
    protected:
        /**
         * @brief array of pointers to characters
         * I prefer to use array instead of vector because it's more efficient here ,
         *  and the size of the array is constant and
         *
         */
        std::array<Character *, MAX_TEAMMATES> m_teammates; // NOLINT

        Character *m_leader; // NOLINT

        size_t m_numsOfTeammate; // NOLINT

        void updateLeader(); // update the leader of the team

        static Character *getNearestCharacter(const Team *src, const Character *dest); // get the nearest character to the other character

        Character *closetTarget(Team *enemy) const; // NOLINT

    public:
        Team(Character *leader); // NOLINT

        /**
         * @brief delete the copy constructor and the move constructor and the assignment operator
         *
         */

        Team() = delete;
        Team(const Team &other) = delete;
        Team(const Team &&other) = delete;

        Team &operator=(Team &other) = delete;
        Team &operator=(Team &&other) = delete;

        virtual ~Team(); // destructor for Team -default implementation

        void add(Character *character); // add character to the team

        virtual void attack(Team *Character); // attack other team

        virtual void print() const; // print the team

        int stillAlive() const; // return the number of alive characters in the team

        Character *getTeamMember(size_t numOfMember) const; // get the member in the index of the array
    };
}
