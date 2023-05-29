#include <string>
#include "./orderPosition.h"
#include "./date.h"
#include "./client.h"
#include <vector>
#include <sstream>

#define CHARS_TO_IGNORE 100

class Order
{
private:
  Client client;
  Date date;
  std::vector<OrderPosition> orderElements;

public:
  std::vector<OrderPosition>* getOrderElements();

  friend std::istream &operator>>(std::istream &is, Order &order)
  {
    std::string line;
    is >> order.client;
    is >> order.date;
    is.ignore(CHARS_TO_IGNORE, '\n');
    order.orderElements.clear();

    while (getline(is, line) && line != "")
    {
      std::istringstream iss{line};
      OrderPosition book;
      iss >> book;
      order.orderElements.push_back(book);
    }
    return is;
  }

  friend std::ostream &operator<<(std::ostream &os, const Order &order)
  {
    os << order.client << std::endl
       << order.date << std::endl;
    for (auto &orderData : order.orderElements)
    {
      os << orderData << std::endl;
    }
    return os;
  }
};

std::vector<OrderPosition>* Order::getOrderElements() {
  return &orderElements;
}
