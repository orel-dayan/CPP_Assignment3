#include "SmartTeam.hpp"
#include "Team.hpp"
#include <stdexcept>

using namespace ariel;

Character *SmartTeam::findWeakestOpponent(Team *other) const
{
    Character *weakest = nullptr;
    int minHitPoints = std::numeric_limits<int>::max();

    for (size_t i = 0; i < S_MAX_TEAM_SIZE; i++)
    {
        Character *current = other->getTeamMember(i);
        // Check if the current character is valid and weaker than the current weakest character
        if (current != nullptr && current->isAlive() && current->getHitPoints() < minHitPoints)
        {
            weakest = current;
            minHitPoints = current->getHitPoints();
        }
    }

    return weakest;
}


void SmartTeam::attack(Team *enemy_team)
{
    if (enemy_team == nullptr) // Check if the enemy is null
        throw std::invalid_argument("Error: NULL argument\n");

    if (!m_leader->isAlive()) // Check if the leader is alive
        updateLeader();

    if (m_leader == nullptr) // Check if the leader is null
        throw std::runtime_error("Error: All the team is already dead");

    Character *closet_character = closetTarget(enemy_team);

    if (closet_character == nullptr) // Check if the closet_character is null
        throw std::runtime_error("Error: All the enemy team is dead");

    for (size_t i = 0; i < S_MAX_TEAM_SIZE; i++)
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
    for (size_t i = 0; i < S_MAX_TEAM_SIZE; i++)
    {
        if (m_teammates[i] != nullptr)
            m_teammates[i]->print();
    }
}



Character *SmartTeam::findCloseNinja(Team *other) const
{
    Character *closest = nullptr;
    Character *minDistance = nullptr;
    Character *current = nullptr;

    for (size_t i = 0; i < S_MAX_TEAM_SIZE; i++)
    {
        current = other->getTeamMember(i);

        if (current != nullptr && typeid(*current) == typeid(Cowboy))
        {
            Character *tmp = other->getNearestCharacter(this, current);

            // Check if the distance between the current ninja and the cowboy is less than or equal to 42
            if (tmp->distance(current) <= 42)
            {
                // Update the closest ninja if it is nullptr or if the current ninja has lower hit points
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
