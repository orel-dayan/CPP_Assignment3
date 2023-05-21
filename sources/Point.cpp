
#include "Point.hpp"
#include <stdexcept>
#include <cmath>
using namespace ariel;

double Point::distance(const Point &other) const
{
    double x_diff = m_x - other.m_x;
    double y_diff = m_y - other.m_y;
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}

Point Point::moveTowards(const Point &src, const Point &dest, double distance)
{
    if (distance < 0)
    {
        throw std::invalid_argument("Can not move with a negative distance");
    }

    double distanceBetweenPoints = src.distance(dest);
    if (distanceBetweenPoints <= distance)
    {
        return Point(dest);
    }

    double u_x = (dest.m_x - src.m_x) / distanceBetweenPoints;
    double u_y = (dest.m_y - src.m_y) / distanceBetweenPoints;

    double s_x = u_x * distance;
    double s_y = u_y * distance;

    return Point(src.m_x + s_x, src.m_y + s_y);
}

std::string Point::print() const
{
    return "(" + std::to_string(m_x) + "," + std::to_string(m_y) + ")";
}
