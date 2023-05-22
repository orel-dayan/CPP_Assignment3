#pragma once

#include "Team.hpp"
#include <limits>

namespace ariel
{
	/**
	 * @brief The SmartTeam class represents a team with smart attack strategies.
	 *
	 * SmartTeam extends the functionality of the base Team class by implementing
	 * specific attack strategies for its team members.
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
		 * @brief Overrides the attack function to implement the smart attack strategy.
		 *
		 * Ninjas attack the closest enemy to them, with a higher priority for cowboys.
		 * Cowboys attack any ninja that is close to a teammate.
		 *
		 * @param enemy_team The enemy team to attack.
		 */
		void attack(Team *enemy_team) override;

		/**
		 * @brief Overrides the print function to print the team members.
		 */
		void print() const override;

		/**
		 * @brief Finds the weakest opponent character in the enemy team.
		 *
		 * The weakest opponent is determined based on the hit points.
		 *
		 * @param other The enemy team to search in.
		 * @return A pointer to the weakest opponent character, or nullptr if not found.
		 */
		Character *findWeakestOpponent(Team *other) const;

		/**
		 * @brief Finds the closest ninja to any cowboy teammate in the enemy team.
		 *
		 * @param other The enemy team to search in.
		 * @return A pointer to the closest ninja, or nullptr if not found.
		 */
		Character *findCloseNinja(Team *other) const;
	};
}
