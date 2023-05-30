#pragma once

#include "Character.hpp"
namespace ariel
{

	// Static members

	static const int S_MAX_BULLETS = 6;
	static const int S_INITAIL_HITPOINTS = 110;
	static const int S_DAMAGE = 10;

	/**
	 * @brief The Cowboy class, derived from the Character class.
	 *        Represents a cowboy character in the game.
	 */

	class Cowboy : public Character
	{

	public:
		int m_bullets; // number of bullets

		/**
		 * @brief Constructs a Cowboy character with the given name and location.
		 *
		 * @param name The name of the cowboy.
		 * @param location The location of the cowboy.
		 */

		Cowboy(const std::string &name, const Point &location) : // NOLINT
																														 Character(name, location, S_INITAIL_HITPOINTS),
																														 m_bullets(S_MAX_BULLETS)
		{
			this->getLocation().print();
		}

		/**
		 * @brief Returns a string representation of the Cowboy character.
		 *
		 * @return The string representation of the Cowboy character.
		 */

		std::string print() const override;

		/**
		 * @brief Shoots the given enemy character.
		 *
		 * @param enemy The enemy character to shoot.
		 */

		void shoot(Character *character);

		/**
		 * @brief Checks if the character has bullets.
		 *
		 * @return True if the character has bullets, false otherwise.
		 */

		bool hasboolets() const
		{
			return m_bullets > 0;
		}

		/**
		 * @brief Reloads bullets for the cowboy.
		 */

		void reload();

		/**
		 * @brief Attacks another character.
		 *
		 * @param other The character to be attacked.
		 */

		void attack(Character *other) override;
	};
} // namespace ariel
