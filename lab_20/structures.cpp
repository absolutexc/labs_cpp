// #include "head.h"
//
// LineSegment::LineSegment() : x(0), y(0) {}
//
// LineSegment::LineSegment(double x1, double y1) : x(x1), y(y1) {}
//
// LineSegment::LineSegment(const LineSegment& other) : x(other.x), y(other.y) {}
//
// double LineSegment::getX() const { return x; }
// double LineSegment::getY() const { return y; }
// void LineSegment::setX(double newX) { x = newX; }
// void LineSegment::setY(double newY) { y = newY; }
//
// bool LineSegment::is_crossing(const LineSegment& other) const {
//     double left1 = std::min(x, y);
//     double right1 = std::max(x, y);
//     double left2 = std::min(other.x, other.y);
//     double right2 = std::max(other.x, other.y);
//
//     return !(right1 < left2 || right2 < left1);
// }
//
// std::ostream& operator<<(std::ostream& os, const LineSegment& ls) {
//     os << "[" << std::fixed << std::setprecision(2) << ls.x << ", " << ls.y << "]";
//     return os;
// }
//
// double LineSegment::operator!() const {
//     return fabs(y - x);
// }
//
// LineSegment LineSegment::operator++() {
//     x -= 1;
//     y += 1;
//     return *this;
// }
//
// LineSegment LineSegment::operator++(int) {
//     LineSegment temp = *this;
//     x -= 1;
//     y += 1;
//     return temp;
// }
//
// LineSegment::operator int() const {
//     return static_cast<int>(x);
// }
//
// LineSegment::operator double() const {
//     return y;
// }
//
// LineSegment LineSegment::operator-(int d) const {
//     return LineSegment(x, y - d);
// }
//
// bool LineSegment::operator<(const LineSegment& other) const {
//     return is_crossing(other);
// }