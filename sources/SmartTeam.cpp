#include "SmartTeam.hpp"
#include "Team.hpp"
#include <stdexcept>

using namespace ariel;

Character *SmartTeam::findVictim(Team *other) const
{
    Character *victim = nullptr;
    Character *current = nullptr;
    for (size_t i = 0; i <S_MAX_TEAM_SIZE; i++) {
        current = other->getTeamMember(i);
        if (current == nullptr) {
            break;
        }

        if ((victim == nullptr || victim->getHitPoints() > current->getHitPoints()) && current->isAlive()) {
            victim = current;
        }
    }
    return victim;

}


void SmartTeam::attack(Team *enemy_team) {
    if (enemy_team == nullptr) {
        throw std::invalid_argument("NULL argument\n");
    }

    Character *leader =getLeader();

    if (!leader->isAlive()) {
       updateLeader();
        leader = getLeader();
    }

    if (leader == nullptr) {
        throw std::runtime_error("All the team is already dead");
    }

    if (enemy_team->stillAlive() == 0) {
        throw std::runtime_error("All the enemy team is dead");
    }

    Character *closest_ninja = findCloseNinja(enemy_team);
    Character *weakest = findVictim(enemy_team);
    Character *teammate = nullptr;
    Character *closest_to = nullptr;

    // Iterate through all team members
    for (size_t i = 0; i < S_MAX_TEAM_SIZE; i++) {
        teammate = getTeamMember(i);
        if (teammate == nullptr || !teammate->isAlive()) {
            continue;
        }

        // If the teammate is a Cowboy
        if (typeid(*teammate) == typeid(Cowboy)) {
            // Attack the closest Ninja if there is one
            if (closest_ninja != nullptr && closest_ninja->isAlive()) {
                teammate->attack(closest_ninja);
            } else {
                // If there is no close Ninja, attack the weakest enemy
                weakest = weakest->isAlive() ? weakest : findVictim(enemy_team);
                if (weakest != nullptr && weakest->isAlive()) {
                    teammate->attack(weakest);
                }
            }
        } else { // If the teammate is not a Cowboy
            // Attack the closest enemy with a higher priority for Cowboys
            closest_to = getNearestCharacter(enemy_team, teammate);
            if (closest_to != nullptr && closest_to->isAlive()) {
                teammate->attack(closest_to);
            }
        }
    }
}


void SmartTeam::print() const
{
    for (size_t i = 0; i < S_MAX_TEAM_SIZE; i++) // Iterate over the teammates array
    {
        Character *member = getTeamMember(i); // Get the current member
        if(member != nullptr)
           std::cout << member->print(); // Print the member

    }
}

Character *SmartTeam::findCloseNinja(Team *other) const
{
   Character *closest = nullptr;
    Character *minDistance = nullptr;
    Character *current = nullptr;

    for (size_t i = 0; i < S_MAX_TEAM_SIZE; i++) {
        current = other->getTeamMember(i);
        if (current != nullptr && typeid(*current) != typeid(Cowboy) && current->isAlive()) {
            Character *temp = getNearestCharacter(this, current);
            if (temp->distance(current) <= 42) {
                if (closest == nullptr || (minDistance->getHitPoints() > temp->getHitPoints())) {
                    closest = current;
                    minDistance = temp;
                }
            }
        }
    }

    return closest;
}

int SmartTeam::getCountNinjasAlive()
{
   int alive_count = 0;
    for (size_t i = 0; i < S_MAX_TEAM_SIZE; i++) {
        Character *teammate = getTeamMember(i);
        if (teammate != nullptr && typeid(*teammate) == typeid(Cowboy) && teammate->isAlive()) {
            alive_count++;
        }
    }
    return alive_count;

}
