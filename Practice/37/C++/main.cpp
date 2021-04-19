#include <iostream>
#include <cmath>
using namespace std;

double sqr(double a);
bool equal(double a, double b, double e = 1E-10);

enum coord_system {
    Cartesian,
    Polar
};

class Point {
    double a1, a2;
    coord_system thirt;
public:
    Point(double a1 = 0, double a2 = 0, coord_system thirt = Cartesian) {
        if (thirt == Cartesian) {
            this->a1 = a1;
            this->a2 = a2;
        }
        else {
            this->a1 = a1 * cos(a2);
            this->a2 = a1 * sin(a2);
        }
    }
    double get_x() {
        return a1;
    }
    double get_y() {
        return a2;
    }
    double get_r() {
        return sqrt((a1 * a1) + (a2 * a2));
    }
    double get_phi() {
        return atan2(a2, a1);
    }
    double set_x(double a) {
        return a1 = a;
    }
    double set_y(double a) {
        return a2 = a;
    }
    double set_r(double r) {
        double phi = get_phi();
        a1 = cos(phi) * r;
        a2 = sin(phi) * r;
        return a1, a2;
    }
    double set_phi(double phi) {
        double r = get_r();
        a1 = cos(phi) * r;
        a2 = sin(phi) * r;
        return a1, a2;
    }

    bool operator==(Point& point) {
        if (abs(get_x() - point.get_x() < pow(10, -10)) and abs(get_y() - point.get_y() < pow(10, -10)))
            return true;
        else
            return false;
    }

};

class Vector {
public:
    Point buffer_vector;
    Vector():buffer_vector(1, 0) {}
    Vector(Point end):buffer_vector(end.get_x(), end.get_y()) {}
    Vector(Point begin, Point end) :buffer_vector(end.get_x() - begin.get_x(), end.get_y() - begin.get_y()) {
    }

    bool operator==(Vector count) {
        return buffer_vector == count.buffer_vector;
          }

    Vector operator-() {
        Point buff = buffer_vector;
        buff.set_x(-(buff.get_x()));
        buff.set_y(-(buff.get_y()));
        return Vector(buff);
    }


    Vector operator-(Vector count) {
        Point buff = buffer_vector;
        buff.set_x(buffer_vector.get_x() - count.buffer_vector.get_x());
        buff.set_y(buffer_vector.get_y() - count.buffer_vector.get_y());
        return Vector(buff);
    }



    Vector operator+(Vector count) {
        Point buff = buffer_vector;
        buff.set_x(buffer_vector.get_x() + count.buffer_vector.get_x());
        buff.set_y(buffer_vector.get_y() + count.buffer_vector.get_y());
        return Vector(buff);
    }


    Vector operator*(double count) {
        Point buff = buffer_vector;
        buff.set_x(buff.get_x() * count);
        buff.set_y(buff.get_y() * count);
        return Vector(buff);
    }

    double length() {
        return buffer_vector.get_r();
    }

    double operator*(Vector count) {
        double buff = length() * count.length() * cos(buffer_vector.get_phi() - count.buffer_vector.get_phi());

        return buff;
    }
};



int main()
{
    Vector a(Point(1, 2)), b(Point(-2, 0), Point(-1, 2));
    if (a == b && b == a) cout << "Equality test passed\n";
    else cout << "Equality test failed\n";

    Vector na(Point(-1, -2)), ox(Point(1, 0)), nox(Point(-1, 0)), oy(Point(0, 1)), noy(Point(0, -1));
    if (a == -na && na == -a && -ox == nox && -oy == noy) cout << "Invert test passed\n";
    else cout << "Invert test failed\n";

    if (ox + oy + oy == a && -ox == -a + oy + oy) cout << "Summation test passed\n";
    else cout << "Summation test failed\n";

    if (-ox + oy == oy - ox && -oy + ox == ox - oy) cout << "Subtraction test passed\n";
    else cout << "Subtraction test failed\n";

    if (ox * 3 == ox + ox + ox &&
        oy * 3 == oy + oy + oy &&
        ox * (-3) == -ox - ox - ox &&
        oy * (-3) == -oy - oy - oy) cout << "buff by number test passed\n";
    else cout << "buff by number test failed\n";

    if (equal(ox.length(), 1) &&
        equal(oy.length(), 1) &&
        equal((ox * 3 + oy * 4).length(), 5)) cout << "Length test passed\n";
    else cout << "Length test failed\n";

    if (equal(ox * ox, sqr(ox.length())) &&
        equal(oy * oy, sqr(oy.length())) &&
        equal((ox * 3 + oy * 4) * (ox * 3 + oy * 4), sqr((ox * 3 + oy * 4).length()))) cout << "buff by Vector test passed\n";
    else cout << "buff by Vector test failed\n";
}

bool equal(double a, double b, double e) {
    if (-e < a - b && a - b < e) return true;
    else return false;
}

double sqr(double a) {
    return a * a;
}
