#include "../headers/solver_template.h"
#include <iostream>
#include <complex>
#include "../headers/complex.h"
#include "../headers/equation_system.h"

int main()
{
  Complex a{}, b{}, c{};

  std::cin >> a >> b >> c;
  Quadratic_solver<std::complex<double>> solver({1, 2}, {3, 4}, {5, 6});
  Quadratic_solver<::Complex> solver2(a, b, c);

  solver.solve();
  solver.print();
  solver.check();
  solver2.solve();
  solver2.print();
  solver2.check();

  return 0;
}