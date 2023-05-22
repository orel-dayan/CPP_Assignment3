#pragma once
#include <string>

namespace ariel {
    class Point {

    private:
        double m_x;
        double m_y;

    public:
        /**
         * @brief Construct a new Point object
         *
         * @param x - The x-coordinate of the point
         * @param y - The y-coordinate of the point
         */
        Point(const double x, const double y) : m_x(x), m_y(y) {} //NOLINT

        /**
         * @brief Construct a new Point object with default values (0,0)
         *
         */
        Point() : m_x(0), m_y(0) {} //NOLINT

        /**
         * @brief Calculate the distance between this point and another point.
         *
         * @param other - The other point to calculate the distance to
         * @return double - The distance between the points
         */
        double distance(const Point &other) const;

        /**
         * @brief Get a string representation of the point.
         *
         * @return std::string - The string representation of the point
         */
        std::string print() const;

        /**
         * @brief Get the x-coordinate of the point.
         *
         * @return double - The x-coordinate of the point
         */
        double getX() const //NOLINT
        {
          return m_x;
        }

        /**
         * @brief Get the y-coordinate of the point.
         *
         * @return double - The y-coordinate of the point
         */
        double getY() const //NOLINT
        {
          return m_y;
        }

        /**
         * @brief Move the point towards another point by a specified distance.
         *
         * @param src - The source point
         * @param dest - The destination point
         * @param distance - The distance to move towards the destination point
         * @return Point - The new point after moving towards the destination
         */
        static Point moveTowards(const Point &src, const Point &dest, double distance);
    };
}
