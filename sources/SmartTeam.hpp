#pragma once

#include "Team.hpp"
#include <limits>
#include <iostream>

namespace ariel
{
	/**
	 * @brief The SmartTeam class represents a team with smart attack strategies.
	 * 
	 *
	 */
	class SmartTeam : public Team
	{
	public:
		/**
		 * @brief Constructs a new SmartTeam object with the specified captain.
		 *
		 * @param captain The captain of the team.
		 */
		SmartTeam(Character *captain) : Team(captain) {}

		/**
		 * @brief  The attack function is the main function that determines the attack strategy of the team.
		 * The function first checks if the enemy team is not nullptr, if the team captain is alive,
		 * and if there are still alive characters in the enemy team.
		 * Then, it finds the closest Ninja to any of the team members and the weakest enemy in the enemy team.
		 * It then iterates through all the team members and attacks the closest Ninja if there is one and the teammate is a Cowboy,
		 * or attacks the weakest enemy if there is no close Ninja and the teammate is a Cowboy.
		 * If the teammate is not a Cowboy, it attacks the closest enemy with a higher priority for Cowboys.
		 * @param other  The enemy team to attack.
		 */

		void attack(Team *other) override;

		/**
		 * @brief Overrides the print function to print the team members.
		 */

		void print() const override;

		/**
		 * @brief function finds the weakest (lowest hit points) alive character in the enemy team.
		 *
		 * @param other The enemy team to attack.
		 * @return Character* The weakest alive character in the enemy team.
		 */

		Character *findVictim(Team *other) const;

		/**
		 * @brief The  function finds the closest Ninja to any of the team members, provided the distance is less than or equal to 42.
		 *
		 *
		 * @param other The enemy team to attack.
		 * @return Character* The closest Ninja to any of the team members.
		 */

		Character *findCloseNinja(Team *other) const;

		/**
		 * @brief  counts the number of alive Cowboys in the team and returns the count.
		 *
		 */

		int getCountNinjasAlive();
	};
}
