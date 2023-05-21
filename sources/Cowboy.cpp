#include "Cowboy.hpp"

using namespace ariel;

std::string Cowboy ::print() const
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
    return "Name: C. " + pname + ", " + phitpoints + ", Position: " + m_location.print();
}

void Cowboy::reload()
{
    if (isAlive() == false)
        throw std::runtime_error("Unfortunatly, the cowboy is dead");
    m_bullets = MAX_BULLETS;
}

void Cowboy::shoot(Character *enemy)
{
    if (hasboolets() == false)
        return;

    if (isAlive() == false)
        throw std::runtime_error("Unfortunatly, the cowboy is dead");

    if (enemy->isAlive() == false)
        throw std::runtime_error("The enemy is already dead");

    if (enemy == this)
        throw std::runtime_error("A character can't attack itself");

    enemy->hit(DAMAGE); // hit the enemy
    m_bullets--;        // reduce the number of bullets
}

void Cowboy::attack(Character *enemy)
{
    if (isAlive() == false)
        return;
    if (hasboolets())
    {
        shoot(enemy); // shoot the enemy
    }
    else
    {
        reload(); // reload the bullets
    }
}
