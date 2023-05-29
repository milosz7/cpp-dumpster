#include <iostream>
#include <cstddef>

template <class T>
class Equation_system
{
private:
  T a[2][2];
  T b[2];
  T x[2];
  int solutions_number;

public:
  Equation_system(T _a[2][2], T _b[2]);
  Equation_system() = default;
  void solve();
  void check() const;
  void print() const;
};

template <class T>
Equation_system<T>::Equation_system(T _a[2][2], T _b[2])
{
  int arr_size = 2;
  for (int i = 0; i < arr_size; i++)
  {
    b[i] = _b[i];
    for (int j = 0; j < arr_size; j++)
    {
      a[i][j] = _a[i][j];
    }
  }
}

template <class T>
void Equation_system<T>::solve()
{
  T det_main = a[0][0] * a[1][1] - a[0][1] * a[1][0];
  T det_x0 = b[0] * a[1][1] - a[0][1] * b[1];
  T det_x1 = b[1] * a[0][0] - b[0] * a[1][0];

  if (det_main != T{})
  {
    x[0] = det_x0 / det_main;
    x[1] = det_x1 / det_main;
    solutions_number = 1;
  }
  else if (det_x1 == T{} && det_main == T{})
  {
    solutions_number = 100000;
  }
  else
  {
    solutions_number = 0;
  }
}
template <class T>
void Equation_system<T>::print() const
{
  if (solutions_number == 1)
  {
    std::cout << "x0 = " << x[0] << std::endl;
    std::cout << "x1 = " << x[1] << std::endl;
  }
  if (solutions_number == 0)
  {
    std::cout << "Equation has no solutions." << std::endl;
  }
  if (solutions_number > 1)
  {
    std::cout << "Equation has infinitely many solutions" << std::endl;
  }
}

template <class T>
void Equation_system<T>::check() const
{
  T equation_0_check = a[0][0] * x[0] + a[0][1] * x[1] - b[0];
  T equation_1_check = a[1][0] * x[0] + a[1][1] * x[1] - b[1];

  std::cout << "Equation 0 check = " << equation_0_check << std::endl;
  std::cout << "Equation 1 check = " << equation_1_check << std::endl;
}
