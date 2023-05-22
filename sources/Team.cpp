#include "Team.hpp"
#include <limits>
#include <iostream>

using namespace ariel;

Team::Team(Character *leader) : m_teammates{nullptr}, m_numsOfTeammate(0), m_leader(leader)
{

    if (leader == nullptr) // Check if the leader argument is null
        throw std::invalid_argument("Error: NULL argument\n");

    if (leader->m_inTeam) // Check if the leader is already in a team
        throw std::runtime_error("Error: Character is already in a team\n");

    // Initialize the teammates array with null pointers
    std::fill(m_teammates.begin(), m_teammates.end(), nullptr);
    // Add the leader to the team and increment the number of teammates
    m_teammates[m_numsOfTeammate++] = leader;
    leader->addToTeam();
}

void Team::updateLeader()
{
   // Update the team leader based on the nearest character
    m_leader = getNearestCharacter(this, m_leader);
}

void Team::add(Character *teammate)
{
    if (teammate == nullptr) // Check if the teammate argument is null
        throw std::invalid_argument("Error: NULL argument\n");

    if (m_numsOfTeammate == S_MAX_TEAM_SIZE)// Check if the team is full
        throw std::runtime_error("The team is already full\n");

    if (teammate->m_inTeam) // Check if the teammate is already in a team
        throw std::runtime_error("Character is already in a team\n");

    m_teammates[m_numsOfTeammate++] = teammate; // Add the teammate to the team and increment the number of teammates
    teammate->addToTeam();
}

void Team::print() const
{

    for (size_t i = 0; i < S_MAX_TEAM_SIZE * 2; i++) // Iterate over the teammates array
    {
        const auto &member = *m_teammates[i]; // Get the current member
        if (i < S_MAX_TEAM_SIZE && m_teammates[i] != nullptr && (typeid(member) == typeid(Cowboy)))
        {
            std::cout << m_teammates[i]->print(); // Print the member
        }
        else if (i >= S_MAX_TEAM_SIZE && m_teammates[i % S_MAX_TEAM_SIZE] != nullptr && (dynamic_cast<Ninja *>(m_teammates[(i % S_MAX_TEAM_SIZE)]) != nullptr))
        {
            std::cout << m_teammates[i % S_MAX_TEAM_SIZE]->print(); // Print the member
        }
    }
}

void Team::attack(Team *againtTeam)
{

    if (againtTeam == nullptr) // Check if the againtTeam argument is null
        throw std::invalid_argument("Error: NULL argument\n");

    if (!m_leader->isAlive()) // Check if the leader is alive
        updateLeader();

    if (m_leader == nullptr) // Check if the leader is null
        throw std::runtime_error("All the team is already dead");

    Character *cc = closetTarget(againtTeam); // Get the closet character

    if (cc == nullptr) // Check if the closet_character is null
        throw std::runtime_error("All the enemy team is dead");


    for (size_t i = 0; i < S_MAX_TEAM_SIZE * 2; i++) // Iterate over the teammates array
    {
        if (!cc->isAlive()) // Check if the closet_character is alive
            cc = closetTarget(againtTeam);

        if (cc == nullptr) // Check if the closet_character is null
            return;

        const auto &teammember = *m_teammates[i % S_MAX_TEAM_SIZE];
        if (m_teammates[i % S_MAX_TEAM_SIZE] == nullptr || teammember.isAlive() == 0) // Check if the teammate is null or dead
            continue;

        if (i < S_MAX_TEAM_SIZE && (typeid(teammember) == typeid(Cowboy))) // Check if the teammate is a cowboy
            m_teammates[i]->attack(cc);

        else if (i >= S_MAX_TEAM_SIZE && typeid(teammember) != typeid(Cowboy)) // Check if the teammate is a ninja
            m_teammates[i %S_MAX_TEAM_SIZE]->attack(cc);

    }
}

int Team::stillAlive() const
{
    int i = 0; // Initialize the number of alive teammates to 0
    for (const Character *chr : m_teammates)
    {
        if (chr != nullptr && chr->isAlive())
        {
            i++; // Count the number of alive teammates
        }
    }
    return i; // Return the number of alive teammates
}

Character *Team::getNearestCharacter(const Team *source, const Character *dest)
{
    double min = std::numeric_limits<double>::max(); // Initialize the min distance to the max double value
    Character *charcterCloset = nullptr; // Initialize the closet character to null
    Character *current = nullptr; // Initialize the current character to null

    for (size_t i = 0; i < S_MAX_TEAM_SIZE; i++) // Iterate over the teammates array
    {
        current = source->m_teammates[i]; // Get the current character
        if (current == nullptr) // Check if the current character is null then continue
            continue;

        double distance = dest->distance(current);
        if (distance < min && current->isAlive())
        {
            charcterCloset = source->m_teammates[i];
            min = distance; // Update the min distance
        }
    }

    return charcterCloset;
}

Character *Team::getTeamMember(size_t i) const
 {
   return m_teammates[i]; // Return the i'th member of the team
 }

Character *Team::closetTarget(Team *enemy) const
{
   // Find the closest target in the enemy team based on the leader's position
    Character *charc = getNearestCharacter(enemy, m_leader);
    return charc;
}


Team::~Team()
{
   // Delete the dynamically allocated characters in the team
    for (auto &character : m_teammates)
    {
        if (character != nullptr)
             delete character;

    }
}


