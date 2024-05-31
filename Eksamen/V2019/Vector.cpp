#include "Vector.h"

double Vector2d::length() {
    return sqrt(pow(x,2) + pow(y,2));
}

Vector2d operator+(const Vector2d& a, const Vector2d& b) {
    //Antar at størrelsen er den samme på begge vektorer
    return Vector2d {a.x + b.x, a.y + b.y};
}

Vector2d Vector2d::operator*(double k) const {
    return Vector2d (this->x * k, this->y * k);
}

//Dette gjør at konstanten k kun kan være til høyre for vector-verdiene hvis man ønsker å gange dem sammen.
//Ved å plassere k til venstre får man error.

std::ostream& operator<<(std::ostream& out, const Vector2d& v) {
    out << "[" << v.x << ", " << v.y << "]";
    return out;
}

Vector2d vectorSum(const std::vector<Vector2d>& vectors) {
    Vector2d sum{0,0};
    for (int i = 0; i < vectors.size(); i++) {
        sum = sum + vectors.at(i);
    }
    return sum;
}