#include <iostream>
#include <cmath>

template <class T>
class Quadratic_solver
{
private:
  T a, b, c, x1, x2;

public:
  Quadratic_solver(T a_, T b_ = T{}, T c_ = T{}) : a{a_}, b{b_}, c{c_} {}

  void solve();
  void print() const;
  void check() const;
};

template <class T>
void Quadratic_solver<T>::solve()
{
  T delta_sqrt = sqrt(b * b - T{4} * a * c);
  x1 = (-b + delta_sqrt) / (T{2} * a);
  x2 = (-b - delta_sqrt) / (T{2} * a);
};

template <class T>
void Quadratic_solver<T>::print() const
{
  std::cout << "Rozwiązania równania: " << std::endl;
  std::cout << "x1: " << x1 << std::endl;
  std::cout << "x2: " << x2 << std::endl;
}
template <class T>
void Quadratic_solver<T>::check() const
{
  std::cout << "ax1^2 + bx1 + c = " << a * x1 * x1 + b * x1 + c << std::endl;
  std::cout << "ax2^2 + bx2 + c = " << a * x2 * x2 + b * x2 + c << std::endl;
}
