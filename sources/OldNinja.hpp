#pragma once

#include "Ninja.hpp"

namespace ariel
{
  // Static members
  const int S_OLD_SPEED = 8;
  const int S_OLD_INTIAL_HITPOINTS = 150;

  /**
   * @brief The OldNinja class, derived from the Ninja class.
   *        Represents an old ninja character in the game.
   */

  class OldNinja : public Ninja
  {
  public:
    /**
     * @brief Constructs an OldNinja character with the given name and location.
     *
     * @param name The name of the old ninja.
     * @param location The location of the old ninja.
     */
    OldNinja(const std::string &name, const Point &location) : Ninja(name, location, S_OLD_SPEED, S_OLD_INTIAL_HITPOINTS) {} // NOLINT
  };

}
