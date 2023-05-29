#include <string>
#include <iostream>
#include <cmath>

class OrderPosition
{
private:
  std::string title;
  int amount;
  double price;

public:
  bool operator<(const OrderPosition &o) {
    return this->title < o.title; }

  bool operator>(const OrderPosition &o) {
    return this->title > o.title;
  }

  bool operator==(const OrderPosition &o) { return this->title == o.title; }

  friend std::istream &operator>>(std::istream &is, OrderPosition &orderPosition)
  {
    char c;
    getline(is, orderPosition.title, '|');
    is >> orderPosition.price;
    is >> c;
    is >> orderPosition.amount;
    std::cout << orderPosition.title;
    return is;
  }

  friend std::ostream &operator<<(std::ostream &os, const OrderPosition orderPosition)
  {
    os << orderPosition.title << "| " << orderPosition.price << " | " << orderPosition.amount;
    return os;
  }
};
