#include "Team.hpp"
#include <limits>
#include <iostream>

using namespace ariel;

Team::Team(Character *leader) : m_teammates{nullptr}, m_numsOfTeammate(0), m_leader(leader)
{

    if (leader == nullptr)
        throw std::invalid_argument("Error: NULL argument\n");

    if (leader->m_inTeam)
        throw std::runtime_error("Error: Character is already in a team\n");

    std::fill(m_teammates.begin(), m_teammates.end(), nullptr);
    m_teammates[m_numsOfTeammate++] = leader;
    leader->addToTeam();
}

void Team::updateLeader()
{
    m_leader = getNearestCharacter(this, m_leader);
}

void Team::add(Character *teammate)
{
    if (teammate == nullptr)
        throw std::invalid_argument("Error: NULL argument\n");

    if (m_numsOfTeammate == 10)
        throw std::runtime_error("The team is already full\n");

    if (teammate->m_inTeam)
        throw std::runtime_error("Character is already in a team\n");

    m_teammates[m_numsOfTeammate++] = teammate;
    teammate->addToTeam();
}

void Team::print() const
{

    for (size_t i = 0; i < MAX_TEAMMATES * 2; i++)
    {
        const auto &member = *m_teammates[i];
        if (i < 10 && m_teammates[i] != nullptr && (typeid(member) == typeid(Cowboy)))
        {
            std::cout << m_teammates[i]->print();
        }
        else if (i >= 10 && m_teammates[i % 10] != nullptr && (dynamic_cast<Ninja *>(m_teammates[(i % 10)]) != nullptr))
        {
            std::cout << m_teammates[i % 10]->print();
        }
    }
}

void Team::attack(Team *againtTeam)
{

    if (againtTeam == nullptr)
        throw std::invalid_argument("Error: NULL argument\n");

    if (!m_leader->isAlive())
        updateLeader();

    if (m_leader == nullptr)
        throw std::runtime_error("All the team is already dead");

    Character *closet_character = closetTarget(againtTeam);

    if (closet_character == nullptr)
        throw std::runtime_error("All the enemy team is dead");

    size_t i;

    for (i = 0; i < MAX_TEAMMATES * 2; i++)
    {
        if (!closet_character->isAlive())
            closet_character = closetTarget(againtTeam);

        if (closet_character == nullptr)
            return;

        const auto &member = *m_teammates[i % 10];
        if (m_teammates[i % 10] == nullptr || member.isAlive() == 0)
            continue;

        if (i < 10 && (typeid(member) == typeid(Cowboy)))
        {
            m_teammates[i]->attack(closet_character);
        }
        else if (i >= 10 && typeid(member) != typeid(Cowboy))
        {
            m_teammates[i % 10]->attack(closet_character);
        }
    }
}

Character *Team::getNearestCharacter(const Team *source, const Character *dest)
{
    double min = std::numeric_limits<double>::max();
    Character *charcterCloset = nullptr;
    Character *current = nullptr;

    for (size_t i = 0; i < MAX_TEAMMATES; i++)
    {
        current = source->m_teammates[i];
        if (current == nullptr)
            continue;

        double distance = dest->distance(current);
        if (distance < min && current->isAlive())
        {
            charcterCloset = source->m_teammates[i];
            min = distance;
        }
    }

    return charcterCloset;
}

Character *Team::closetTarget(Team *enemy) const
{
    Character *charc = getNearestCharacter(enemy, m_leader);
    return charc;
}

int Team::stillAlive() const
{
    int count = 0;
    for (const Character *chr : m_teammates)
    {
        if (chr != nullptr && chr->isAlive())
        {
            count++;
        }
    }
    return count;
}

Team::~Team()
{
    for (auto &character : m_teammates)
    {
        if (character != nullptr)
        {
            delete character;
        }
    }
}

Character *Team::getTeamMember(size_t i) const { return m_teammates[i]; }
