#pragma once

#include <string>
#include "Point.hpp"
#include <stdexcept>

namespace ariel
{
	/**
	 * @brief The base class for all characters in the game.
	 */
	class Character
	{

	protected:
		/**
		 * @brief Constructs a Character with the given name, location, and hit points.
		 *
		 * @param name The name of the character.
		 * @param location The location of the character.
		 * @param hitPoints The hit points of the character.
		 */
		Character(const std::string &name, const Point &location, const int hitPoints) : m_name(name),
																																										 m_location(location),
																																										 m_hitPoints(hitPoints),
																																										 m_inTeam(false) // NOLINT
		{
		}

		private:
		std::string m_name; // The name of the character.
		Point m_location;					// The location of the character.
		int m_hitPoints;					// The hit points of the character.
		bool m_inTeam;				// Indicates whether the character is in a team.
		public:

		/**
		 * @brief Deleted copy constructor, assignment operator, move constructor, and move assignment operator,
		 * because we don't want to copy or move characters.
		 */
		Character(const Character &) = delete;						// disable copy constructor
		Character &operator=(const Character &) = delete; // disable assignment operator
		Character(Character &&) = delete;									// disable move constructor
		Character &operator=(Character &&) = delete;			// disable move assignment operator
		Character() = delete;															// disable default constructor

		/**
		 * @brief Virtual destructor for Character.
		 */
		virtual ~Character() = default;

		/**
		 * @brief Returns the name of the character.
		 *
		 * @return The name of the character.
		 */
		const std::string &getName() const
		{
			return m_name;
		}

		bool isInTeam() const
		{
			return m_inTeam;
		}
		void setLoc(const Point loc)
		{
			m_location = loc;
		}

		/**
		 * @brief Returns the location of the character.
		 *
		 * @return The location of the character.
		 */
		const Point &getLocation() const
		{
			return m_location;
		}

		/**
		 * @brief Returns the hit points of the character.
		 *
		 * @return The hit points of the character.
		 */
		const int getHitPoints() const // NOLINT
		{
			return m_hitPoints;
		}

		/**
		 * @brief Returns the character representation according to its type.
		 *
		 * @return The character representation.
		 */
		virtual std::string print() const = 0;

		/**
		 * @brief Attacks another character.
		 *
		 * @param other The character to be attacked.
		 */
		virtual void attack(Character *) = 0;

		/**
		 * @brief Calculates the distance between this character and another character.
		 *
		 * @param other The other character.
		 * @return The distance between the characters.
		 */
		double distance(Character *other) const;

		/**
		 * @brief Reduces the hit points of the character by the specified damage amount.
		 *
		 * @param damage The amount of damage.
		 */
		void hit(int damage);

		/**
		 * @brief Adds the character to the team.
		 */
		void addToTeam()
		{
			m_inTeam = true;
		}

		/**
		 * @brief Checks if the character is alive.
		 *
		 * @return True if the character is alive, false otherwise.
		 */
		bool isAlive() const
		{
			return m_hitPoints > 0;
		}
	};
}
