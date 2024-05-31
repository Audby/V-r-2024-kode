#pragma once
#include <vector>
#include <cmath>
#include <iostream>

class Vector2d {

private:



public:
    double x;
    double y;
    Vector2d (double x, double y) : x{x}, y{y} {}
    double length();
    Vector2d operator*(double k) const;
};

Vector2d operator+(const Vector2d& a, const Vector2d& b);

std::ostream& operator<<(std::ostream& out, const Vector2d& v);

Vector2d vectorSum(const std::vector<Vector2d>& vectors);