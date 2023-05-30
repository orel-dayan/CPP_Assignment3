#include "Cowboy.hpp"

using namespace ariel;

std::string Cowboy ::print() const
{
	std::string pname, phitpoints;
	if (!isAlive())
	{
		pname = "(" + getName() + ")";
		phitpoints = "";
	}
	else
	{
		pname = getName();
		phitpoints = "Hit points: " + std::to_string(getHitPoints());
	}
    return "Name: C. " + pname + ", " + phitpoints + ", Location: " + getLocation().print() ;
}

void Cowboy::reload()
{
	if (isAlive() == false)
		throw std::runtime_error("Unfortunatly, the cowboy is dead");
	m_bullets = S_MAX_BULLETS; // Reload the bullets to the maximum value
}

void Cowboy::attack(Character *enemy)
{

	if (hasboolets()) // If the cowboy has bullets, shoot the enemy
		shoot(enemy);
	else // If the cowboy has no bullets, reload
		reload();
}

void Cowboy::shoot(Character *enemy)
{
	if (hasboolets() == false) // If there are no bullets, return without shooting
		return;

	if (isAlive() == false)
		throw std::runtime_error("Unfortunatly, the cowboy is dead");

	if (enemy->isAlive() == false)
		throw std::runtime_error("The enemy is already dead");

	if (enemy == this)
		throw std::runtime_error("A character can't attack itself");

	enemy->hit(S_DAMAGE); // Hit the enemy with the specified damage
	m_bullets--;					// Reduce the number of bullets
}
