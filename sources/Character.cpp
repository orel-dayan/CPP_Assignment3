#include "Character.hpp"

using namespace ariel;

double Character::distance(Character *other) const
{
    return m_location.distance(other->m_location);
}

void Character::hit(int damage)
{
    if (damage < 0)
    {
        throw std::invalid_argument("Can not hit with a negative damage");
    }
    if (damage >= m_hitPoints)
    {
        m_hitPoints = 0;
    }
    else
    {
        m_hitPoints -= damage;
    }
}
