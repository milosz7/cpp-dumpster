#include <iostream>

int gcd(int a, int b)
{
  while (b != 0)
  {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

class Rational
{
public:
  // constructors
  Rational() : numer(0), denom(1) {}
  Rational(int n) : numer(n), denom(1) {}
  Rational(int n, int d) : numer(n), denom(d) { normalise(); }

  // nonmodifying operations
  int get_numer() const { return numer; }
  int get_denom() const { return denom; }
  double conv_double() const { return double(numer) / denom; } // convert to double

  // modifying operations
  void normalise()
  {
    if (denom == 0)
    {
      std::cerr << "Denominator jest równy 0" << std::endl;
      exit(1);
    }
    if (denom < 0)
    {
      denom = -denom;
      numer = -numer;
    }
    int n = gcd(numer, denom);
    if (n > 1)
    {
      numer /= n;
      denom /= n;
    }
  }

private:
  int numer; // numerator
  int denom; // denominator
};

Rational operator+(const Rational &r1, const Rational &r2);
Rational operator-(const Rational &r1, const Rational &r2);
Rational operator*(const Rational &r1, const Rational &r2);
Rational operator/(const Rational &r1, const Rational &r2);
bool operator==(const Rational &r1, const Rational &r2);
bool operator!=(const Rational &r1, const Rational &r2);
std::ostream &operator<<(std::ostream &os, const Rational &r);

Rational operator+(const Rational &r1, const Rational &r2)
{
  Rational r(r1.get_numer() * r2.get_denom() + r1.get_denom() * r2.get_numer(),
             r1.get_denom() * r2.get_denom());
  r.normalise();
  return r;
}

Rational operator-(const Rational &r1, const Rational &r2)
{
  Rational r(r1.get_numer() * r2.get_denom() - r1.get_denom() * r2.get_numer(),
             r1.get_denom() * r2.get_denom());
  r.normalise();
  return r;
}

Rational operator*(const Rational &r1, const Rational &r2)
{
  Rational r(r1.get_numer() * r2.get_numer(), r1.get_denom() * r2.get_denom());
  r.normalise();
  return r;
}

Rational operator/(const Rational &r1, const Rational &r2)
{
  Rational r(r1.get_numer() * r2.get_denom(), r1.get_denom() * r2.get_numer());
  r.normalise();
  return r;
}

bool operator==(const Rational &r1, const Rational &r2)
{
  return r1.get_numer() * r2.get_denom() == r1.get_denom() * r2.get_numer();
}

bool operator!=(const Rational &r1, const Rational &r2)
{
  return !(r1 == r2);
}

std::ostream &operator<<(std::ostream &os, const Rational &r)
{
  return std::cout << '(' << r.get_numer() << '/' << r.get_denom() << ')';
}