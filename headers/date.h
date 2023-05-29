#include <string>
#include <iostream>

class Date
{
private:
  int day, month, year;

public:
  // Date(int _day, int _month, int _year) : day{_day}, month{_month}, year{_year} {}
  // Date() = default;

  friend std::ostream &operator<<(std::ostream &os, const Date &d)
  {
    os << ((d.day < 10) ? "0" : "") << d.day 
       << "." << ((d.month < 10) ? "0" : "")
       << d.month << "." << d.year;
    return os;
  }

  friend std::istream &operator>>(std::istream &is, Date &d)
  {
    char dots[2];
    is >> d.day >> dots[0] >> d.month >> dots[1] >> d.year;
    return is;
  }
};