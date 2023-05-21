#pragma once
#include "Character.hpp"

namespace ariel
{

    class Ninja : public Character
    {

    public:
        static const int DAMAGE = 40;

    private:
        int m_speed;

    protected:
        Ninja(const std::string &name, const Point &location, int speed, int hitPoints) : // NOLINT
                                                                                          Character(name, location, hitPoints), m_speed(speed)
        {
        }

    public:
        /**
         * @brief print the character
         *
         * @return std::string  the character
         */

        std::string print() const override;

        /**
         * @brief move the character to other location
         *
         * @param other  the other character
         */

        void move(const Character *other);

        /**
         * @brief slash other character
         *
         * @param other the other character
         */

        void slash(Character *other) const;

        /**
         * @brief  attack other character
         *
         * @param other the other character
         */

        void attack(Character *other) override;
    };
}
