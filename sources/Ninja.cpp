#include <iostream>
#include "Ninja.hpp"

using namespace ariel;

std::string Ninja::print() const
{
    std::string pname, phitpoints;
    if (!isAlive())
    {
        pname = "(" + getName() + ")";
        phitpoints = "";
    }
    else
    {
        pname = m_name;
        phitpoints = "Hit points: " + std::to_string(m_hitPoints);
    }

    return "Name: N. " + pname + ", " + phitpoints + ", Position: " + m_location.print();
}

void Ninja::move(const Character *enemy)
{
    if (isAlive())
    {
        Point point_closest = Point::moveTowards(this->m_location, enemy->m_location, this->m_speed);
        m_location = point_closest;
    }
}

void Ninja::attack(Character *enemy)
{
    double disCalc = this->distance(enemy);
    if (disCalc <= 1)
    {
        slash(enemy);
    }
    else
    {
        move(enemy);
    }
}

void Ninja::slash(Character *enemy) const
{
    if (isAlive() == false)
        throw std::runtime_error("Unfortunatly, the ninja is dead");

    if (enemy->isAlive() == false)
        throw std::runtime_error("The enemy is already dead");

    if (enemy == this)
        throw std::runtime_error("A character can't attack itself");

    if (distance(enemy) <= 1)
        enemy->hit(DAMAGE);
}
