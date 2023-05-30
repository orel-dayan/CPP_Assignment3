#include "Team2.hpp"
#include <stdexcept>
using namespace ariel;

void Team2::print() const
{
  for (size_t i = 0; i < S_MAX_TEAM_SIZE; i++) // Iterate over the teammates array
  {
     Character *member = getTeamMember(i); // Get the current member
     if(member != nullptr)
       member->print(); // Print the member

  }
}

void Team2::attack(Team *enemy)
{
  if (enemy == nullptr) // Check if the enemy is null
    throw std::invalid_argument("Error: NULL argument\n");
  Character *leader = getLeader();

  if (!leader->isAlive()) // Check if the leader is alive
    updateLeader();

  if (leader == nullptr) // Check if the leader is null
    throw std::runtime_error("All the team is already dead");

  Character *cc = closetTarget(enemy);

  if (cc == nullptr) // Check if the closet_character is null
    throw std::runtime_error("All the enemy team is dead");

  for (size_t i = 0; i < S_MAX_TEAM_SIZE; i++) // Iterate over the teammates array
  {
    if (!cc->isAlive()) // Check if the closet_character is alive
      cc = closetTarget(enemy);

    if (cc == nullptr) // Check if the closet_character is null
      break;

    Character *teammember = getTeamMember(i);
    if (teammember != nullptr && teammember->isAlive())
      teammember->attack(cc);



  }
}
