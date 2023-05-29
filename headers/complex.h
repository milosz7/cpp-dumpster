#include <cmath>
#include <iostream>

class Complex
{
  double re, im;

public:
  Complex(double r, double i) : re{r}, im{i} {}
  Complex(double r) : re{r}, im{0} {}
  Complex() : re{0}, im{0} {}

  double real() const { return re; }
  void real(double d) { re = d; }
  double imag() const { return im; }
  void imag(double d) { im = d; }

  Complex &operator+=(Complex z)
  {
    re += z.re, im += z.im;
    return *this;
  }

  Complex &operator-=(Complex z)
  {
    re -= z.re, im -= z.im;
    return *this;
  }

  Complex &operator*=(Complex);
  Complex &operator/=(Complex);
};

Complex &Complex::operator*=(Complex z)
{
  double a, b;
  a = re * z.re - im * z.im;
  b = re * z.im + im * z.re;
  re = a;
  im = b;
  return *this;
}

Complex &Complex::operator/=(Complex z)
{
  double a, b;
  a = (re * z.re + z.im * im) / (z.re * z.re + z.im * z.im);
  b = (im * z.re - re * z.im) / (z.re * z.re + z.im * z.im);
  re = a;
  im = b;
  return *this;
}

Complex operator+(Complex a, Complex b) { return a += b; }
Complex operator-(Complex a, Complex b) { return a -= b; }
Complex operator-(Complex a) { return {-a.real(), -a.imag()}; }
Complex operator*(Complex a, Complex b) { return a *= b; }
Complex operator/(Complex a, Complex b) { return a /= b; }

std::ostream &operator<<(std::ostream &os, Complex z)
{
  os << '(' << z.real() << ',' << z.imag() << ')';
  return os;
}

std::istream &operator>>(std::istream &is, Complex &z)
{
  double a, b;
  char chars[3];
  is >> chars[0] >> a >> chars[1] >> b >> chars[2];
  if (chars[0] == '(' && chars[1] == ',' && chars[2] == ')')
  {
    z.real(a);
    z.imag(b);
  } else {
    std::cerr << "Niepoprawne wejście!" << std::endl;
  }
  return is;
}

Complex sqrt(Complex z)
{
  double u, v;
  double a = z.real();
  double b = z.imag();

  u = sqrt(((a + sqrt(a * a + b * b))) / 2.0);
  if (u == 0)
  {
    v = sqrt(-a);
  }
  else
  {
    v = b / (2.0 * u);
  }

  return Complex{u, v};
}

bool operator==(Complex a, Complex b)
{
  return (a.real() == b.real() && a.imag() == b.imag());
}

bool operator!=(Complex a, Complex b)
{
  return !(a == b);
}
