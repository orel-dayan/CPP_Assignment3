#pragma once

#include <array>
#include <typeinfo>
#include "Character.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"

namespace ariel
{
	static const int S_MAX_TEAM_SIZE = 10;

	/**
	 * @brief The Team class represents a team of characters.
	 *
	 * It manages a collection of characters and provides functionality for team operations.
	 */

	class Team
	{
	protected:
		/**
		 * @brief The m_teammates array represents the team members.
		 * The array is of size S_MAX_TEAM_SIZE.
		 * The array is initialized to nullptr.
		 * The array is of type Character*.
		 */
		std::array<Character *, S_MAX_TEAM_SIZE> m_teammates; // NOLINT
		/**
		 * @brief The m_leader represents the leader of the team.
		 *
		 */
		Character *m_leader; // NOLINT
		/**
		 * @brief The m_numsOfTeammate represents the number of teammates in the team.
		 *
		 */

		size_t m_numsOfTeammate; // NOLINT

		/**
		 * @brief update the leader of the team
		 */

		void updateLeader();

		/**
		 *
		 * @brief // Get the nearest character to the other character
		 *
		 * @param src - the team
		 * @param dest - the other character
		 * @return Character* - the nearest character to the other character
		 */

		static Character *getNearestCharacter(const Team *src, const Character *dest);

		/**
		 * @brief Find the closest target in the enemy team
		 *
		 * @param enemy - the enemy team
		 * @return Character* - the closest target in the enemy team
		 */

		Character *closetTarget(Team *enemy) const; // NOLINT

	public:
		/**
		 * @brief Constructs a Team object with the given leader.
		 *
		 * @param leader The leader of the team.
		 */
		Team(Character *leader); // NOLINT

		/**
		 * @brief Deletes the copy constructor and move constructor and assignment operators.
		 *
		 * This prevents copying and moving of Team objects.
		 */

		Team() = delete;
		Team(const Team &other) = delete;
		Team(const Team &&other) = delete;

		Team &operator=(Team &other) = delete;
		Team &operator=(Team &&other) = delete;

		virtual ~Team(); // destructor for Team -default implementation

		void add(Character *character); // add character to the team

		virtual void attack(Team *Character); // attack other team

		virtual void print() const; // print the team

		int stillAlive() const; // return the number of alive characters in the team

		Character *getTeamMember(size_t numOfMember) const; // get the member in the index of the array
	};
}
