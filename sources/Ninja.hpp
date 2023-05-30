#pragma once
#include "Character.hpp"

namespace ariel
{
	/**
   * @brief The Ninja class, derived from the Character class.
   *        Represents a ninja character in the game.
   */

	class Ninja : public Character
	{

	public:
		// Static member
		static const int S_DAMAGE = 40;

	private:
		int m_speed; // speed of the ninja

	protected:
		/**
		 * @brief Constructs a Ninja character with the given name, location, speed, and hit points.
		 *
		 * @param name The name of the ninja.
		 * @param location The location of the ninja.
		 * @param speed The speed of the ninja.
		 * @param hitPoints The hit points of the ninja.
		 */
		Ninja(const std::string &name, const Point &location, int speed, int hitPoints) : // NOLINT
																																											Character(name, location, hitPoints), m_speed(speed)
		{
		}

	public:
		/**
		 * @brief Returns a string representation of the Ninja character.
		 *
		 * @return The string representation of the Ninja character.
		 */

		std::string print() const override;

		/**
		 * @brief Moves the ninja towards another character.
		 *
		 * @param other The character to move towards.
		 */

		void move(const Character *other);

		/**
		 * @brief Performs a slashing attack on another character.
		 *
		 * @param other The character to be slashed.
		 */

		void slash(Character *other) const;

		/**
		 * @brief Attacks another character.
		 *
		 * @param other The character to be attacked.
		 */

		void attack(Character *other) override;

		/**
		 * @brief Returns the speed of the ninja.
		 *
		 */
		
		int getSpeed() const
		{
			return m_speed;
		}
	};
}
