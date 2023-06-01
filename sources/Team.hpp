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
	private:
		std::array<Character *, S_MAX_TEAM_SIZE> m_teammates;

		Character *m_leader;

		size_t m_numsOfTeammate;

	protected:


		void updateLeader();

		static Character *getNearestCharacter(const Team *src, const Character *dest);

		Character *closetTarget(Team *enemy) const; // NOLINT

		std::array<Character *, S_MAX_TEAM_SIZE> getTeam() const; // NOLINT

	public:

		Team(Character *leader); // NOLINT



		Team() = delete;
		Team(const Team &other) = delete;
		Team(const Team &&other) = delete;

		Team &operator=(Team &other) = delete;
		Team &operator=(Team &&other) = delete;

		virtual ~Team(); // destructor for Team -default implementation

		int getNumOfTeammate() const; // return the number of teammates in the team

		void add(Character *character); // add character to the team

		virtual void attack(Team *Character); // attack other team

		virtual void print() const; // print the team

		int stillAlive() const; // return the number of alive characters in the team

		Character* getLeader() const { return m_leader;}

		Character *getTeamMember(size_t numOfMember) const; // get the member in the index of the array
	};
}
