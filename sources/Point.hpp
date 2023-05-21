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
     * @param x  - the coordinate x
     * @param y  - the coordinate y
     */
        Point(const double x, const double y) : m_x(x), m_y(y) {} //NOLINT

        /**
         * @brief Construct a new Point object with default values (0,0)
         * 
         */

        Point(): m_x(0), m_y(0) {} //NOLINT

        double distance(const Point &other) const; // distance between two points

        std::string print() const; // print point

       double getX() const// NOLINT
         { return m_x; } 
        double getY() const // NOLINT  
        { return m_y; } 

        static Point moveTowards(const Point &src, const Point &dest, double distance); // move point towards another point , static because it doesn't change the object
    };
}

