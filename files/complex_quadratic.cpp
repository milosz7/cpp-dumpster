#include <iostream>
#include "../headers/complex.h"

int main()
{
  Complex a{}, b{}, c{}, delta{}, x1{}, x2{};
  std::cin >> a >> b >> c;
  delta = b * b - 4.0f * a * c;
  std::cout << "delta = " << delta << std::endl;
  delta = sqrt(delta);
  std::cout << "delta sqrt = " << delta << std::endl;

  x1 = (-b + delta) / (2.0f * a);
  x2 = (-b - delta) / (2.0f * a);
  std::cout << "x1 = " << x1 << std::endl;
  std::cout << "x2 = " << x2 << std::endl;
  std::cout << "ax1^2 + bx1 + c = " << a * x1 * x1 + b * x1 + c << std::endl;
  std::cout << "ax2^2 + bx2 + c = " << a * x2 * x2 + b * x2 + c << std::endl;

  return 0;
}
