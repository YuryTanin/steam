#include "lab3.h"

Triad::Triad(const double a, const double b, const double c)
{
    setA(a);
    setB(b);
    setC(c);
}

double Triad::getA() const
{
    return this->a;
}

double Triad::getB() const
{
    return this->b;
}

double Triad::getC() const
{
    return this->c;
}

void Triad::setA(double a)
{
    this->a = a;
}

void Triad::setB(double b)
{
    this->b = b;
}

void Triad::setC(double c)
{
    this->c = c;
}


std::istream& operator>>(std::istream& in, Triad& triad)
{
    double a, b, c;
    in >> a >> b >> c;
    triad = Triad(a, b, c);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Triad& triad)
{
    out << "Triad is:  " << triad.getA() << ", " << triad.getB() << ", " << triad.getC() << std::endl;
    return out;
}

Triad operator+(const Triad& t, const double n)
{
    return Triad(t.getA() + n, t.getB() + n, t.getC() + n);
}

Triad operator*(const Triad& t, const double n)
{
    return Triad(t.getA() * n, t.getB() * n, t.getC() * n);
}

bool operator==(const Triad& t1, const Triad& t2)
{
    if ((t1.getA() == t2.getA()) && (t1.getB() == t2.getB()) && (t1.getC() == t2.getC())) return true;
    else return false;
}

std::istream& operator>>(std::istream& in, Vector3D& v)
{
    double x, y, z;
    in >> x >> y >> z;
    v = Vector3D(x, y, z);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Vector3D& v)
{
    out << "Vector coord:  (" << v.getX() << "; " << v.getY() << "; " << v.getZ() << ")" << std::endl;
    return out;
}

Vector3D operator+(const Vector3D& v1, const Vector3D& v2)
{
    return Vector3D(v1.getX() + v2.getX(), v1.getY() + v2.getY(), v1.getZ() + v2.getZ());
}

double operator*(const Vector3D& v1, const Vector3D& v2)
{
    return v1.getX() * v2.getX() + v1.getY() * v2.getY() + v1.getZ() * v2.getZ();
}

Vector3D::Vector3D(const double x, const double y, const double z)
{
    setX(x);
    setY(y);
    setZ(z);
}

double Vector3D::getX() const
{
    return this->a;
}

double Vector3D::getY() const
{
    return this->b;
}

double Vector3D::getZ() const
{
    return this->c;
}

void Vector3D::setX(double x)
{
    this->a = x;
}

void Vector3D::setY(double y)
{
    this->b = y;
}

void Vector3D::setZ(double z)
{
    this->c = z;
}
