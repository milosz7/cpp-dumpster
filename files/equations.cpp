#include "../headers/complex.h"
#include "../headers/equation_system.h"
#include "../headers/rationals.h"

int main()
{
  Complex a[2][2] = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};
  Complex b[2] = {{1, 2}, {3, 4}};

  Equation_system<::Complex> eq_complex(a, b);
  std::cout << "Complex equation" << std::endl;
  eq_complex.solve();
  eq_complex.print();
  eq_complex.check();

  double c[2][2] = {{1, 2}, {3, 4}};
  double d[2] = {5, 6};

  Equation_system<double> eq_double(c, d);
  std::cout << "Double equation" << std::endl;
  eq_double.solve();
  eq_double.print();
  eq_double.check();

  Rational e[2][2] = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};
  Rational f[2] = {{1, 2}, {3, 4}};

  Equation_system<Rational> eq_rationals(e, f);
  std::cout << "Rational equation" << std::endl;
  eq_rationals.solve();
  eq_rationals.print();
  eq_rationals.check();
}
