#include "Team2.hpp"
#include <stdexcept>
using namespace ariel;

void Team2::print() const
{
    for (size_t i = 0; i < MAX_TEAMMATES; i++)
    {
        if (m_teammates[i] != nullptr)
            m_teammates[i]->print();
    }
}

void Team2::attack(Team *enemy)
{
    if (enemy == nullptr)
        throw std::invalid_argument("Error: NULL argument\n");

    if (!m_leader->isAlive())
        updateLeader();

    if (m_leader == nullptr)
        throw std::runtime_error("All the team is already dead");

    Character *closet_character = closetTarget(enemy);

    if (closet_character == nullptr)
        throw std::runtime_error("All the enemy team is dead");

    size_t i;
    for (i = 0; i < MAX_TEAMMATES; i++)
    {
        if (!closet_character->isAlive())
            closet_character = closetTarget(enemy);

        if (closet_character == nullptr)
            return;

        if (m_teammates[i] != nullptr && m_teammates[i]->isAlive())
            m_teammates[i]->attack(closet_character);
    }
}
