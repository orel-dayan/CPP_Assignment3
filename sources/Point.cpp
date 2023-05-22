
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

std::string Point::print() const
{
	return "(" + std::to_string(m_x) + "," + std::to_string(m_y) + ")"; // Return a string representation of the point in the format "(x,y)"
}

Point Point::moveTowards(const Point &src, const Point &dest, double distance)
{
	if (distance < 0)
		throw std::invalid_argument("Can not move with a negative distance");

	double distanceBetweenPoints = src.distance(dest);
	if (distanceBetweenPoints <= distance)
		return Point(dest); // Return the destination point if the distance is greater than or equal to the specified distance

	double u_x = (dest.m_x - src.m_x) / distanceBetweenPoints; // Unit vector in the x-direction
	double u_y = (dest.m_y - src.m_y) / distanceBetweenPoints; // Unit vector in the y-direction

	double s_x = u_x * distance; // Distance to move in the x-direction
	double s_y = u_y * distance; // Distance to move in the y-direction

	return Point(src.m_x + s_x, src.m_y + s_y); // Return the new point after moving towards the destination
}
