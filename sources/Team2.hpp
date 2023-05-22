#pragma once

#include "Team.hpp"

namespace ariel
{
	/**
	 * @brief Represents a specialized team of characters (Team2).
	 *
	 * This class is derived from the base Team class and provides custom implementations
	 * for the attack and print functions.
	 */
	class Team2 : public Team
	{
	public:
		/**
		 * @brief Constructs a new Team2 object with the specified leader.
		 *
		 * @param leader The leader of the team.
		 */
		Team2(Character *leader) : Team(leader) {} // NOLINT

		/**
		 * @brief Attacks the other team.
		 *
		 * This function overrides the base class implementation to define a custom behavior
		 * for attacking the other team. The exact behavior can be defined in this function.
		 *
		 * @param other The other team to attack.
		 */
		void attack(Team *other) override;

		/**
		 * @brief Prints the team.
		 *
		 * This function overrides the base class implementation to define a custom way of
		 * printing the team. The exact printing format can be defined in this function.
		 */
		void print() const override;
	};
}
