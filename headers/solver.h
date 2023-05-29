#include "complex.h"

class Quadratic_solver
{
private:
  Complex a{}, b{}, c{}, x1{}, x2{};

public:
  Quadratic_solver(Complex a_, Complex b_ = 0, Complex c_ = 0) : a{a_}, b{b_}, c{c_} {}

  void solve();
  void print() const;
  void check() const;
};

void Quadratic_solver::solve()
{
  Complex delta_sqrt = sqrt(b * b - 4.0 * a * c);
  x1 = (-b + delta_sqrt) / 2.0 * a;
  x2 = (-b - delta_sqrt) / 2.0 * a;
}

void Quadratic_solver::print() const
{
  std::cout << "Rozwiązania równania: " << std::endl;
  std::cout << "x1: " << x1 << std::endl;
  std::cout << "x2: " << x2 << std::endl;
}

void Quadratic_solver::check() const
{
  std::cout << "ax1^2 + bx1 + c = " << a * x1 * x1 + b * x1 + c << std::endl;
  std::cout << "ax2^2 + bx2 + c = " << a * x2 * x2 + b * x2 + c << std::endl;
}