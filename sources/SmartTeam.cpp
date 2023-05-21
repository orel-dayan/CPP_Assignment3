#include "SmartTeam.hpp"
#include "Team.hpp"
#include <stdexcept>
using namespace ariel;
/**
 *  ninjas attack the closet enemy to them with a higher priority for cowboys
 *  cowboys attack any ninja that is close to a teammate
 */

void SmartTeam::attack(Team *enemy_team)
{
    if (enemy_team == nullptr)
        throw std::invalid_argument("Error: NULL argument\n");

    if (!m_leader->isAlive())
        updateLeader();

    if (m_leader == nullptr)
        throw std::runtime_error("Error: All the team is already dead");

    Character *closet_character = closetTarget(enemy_team);

    if (closet_character == nullptr)
        throw std::runtime_error("Error: All the enemy team is dead");

    for (size_t i = 0; i < MAX_TEAMMATES; i++)
    {
        if (!closet_character->isAlive())
            closet_character = closetTarget(enemy_team);

        if (closet_character == nullptr)
            return;

        if (m_teammates[i] != nullptr && m_teammates[i]->isAlive())
            m_teammates[i]->attack(closet_character);
    }
}

void SmartTeam::print() const
{
    for (size_t i = 0; i < MAX_TEAMMATES; i++)
    {
        if (m_teammates[i] != nullptr)
            m_teammates[i]->print();
    }
}

Character *SmartTeam::findWeakestOpponent(Team *other) const
{
    return nullptr;
}

Character *SmartTeam::findCloseNinja(Team *other) const
{
    Character *closest = nullptr;
    Character *minDistance = nullptr;
    Character *current = nullptr;
    for (size_t i = 0; i < MAX_TEAMMATES; i++)
    {
        current = other->getTeamMember(i);
        if (current != nullptr && typeid(*current) == typeid(Cowboy))
        {
            Character *tmp = other->getNearestCharacter(this, current);
            if (tmp->distance(current) <= 42)
            {
                if (closest == nullptr || (minDistance->m_hitPoints > tmp->m_hitPoints))
                {
                    closest = tmp;
                    minDistance = tmp;
                }
            }
        }
    }
    return closest;
}
