#pragma once

#include "Ninja.hpp"
namespace ariel
{

	 const int S_SPEED_TRAINED = 12;
	 const int S_INTIAL_HITPOINTS_TRAINED = 120;
	/**
	 * @brief The TrainedNinja class represents a trained ninja character.
	 *
	 * It is a derived class from the base class Ninja.
	 */

	class TrainedNinja : public Ninja
	{
	public:
		/**
		 * @brief Constructs a TrainedNinja object with the given name and position.
		 *
		 * @param name The name of the trained ninja.
		 * @param pos The position of the trained ninja.
		 */
		TrainedNinja(const std::string &name, const Point &Location) : Ninja(name, Location, S_SPEED_TRAINED,
																																				 S_INTIAL_HITPOINTS_TRAINED) {}
	};
}
