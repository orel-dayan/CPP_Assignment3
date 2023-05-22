#include "Character.hpp"

using namespace ariel;

double Character::distance(Character *other) const
{
	// Calculate the distance between the current character's location and the other character's location
	return m_location.distance(other->m_location);
}

void Character::hit(int damage)
{
	// Check if the damage is negative and throw an exception
	if (damage < 0)
	{
		throw std::invalid_argument("Cannot hit with a negative damage");
	}

	// Reduce the character's hit points based on the damage
	if (damage >= m_hitPoints)
	{
		// If the damage is greater than or equal to the hit points, set hit points to 0
		m_hitPoints = 0;
	}
	else
	{
		// If the damage is less than the hit points, subtract the damage from the hit points
		m_hitPoints -= damage;
	}
}
