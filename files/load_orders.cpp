#include "../headers/order.h"
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

int copyToVector(std::string ordersPath, std::string booksOutputPath, std::string ordersOutputPath);

int main()
{
    copyToVector("./data/orders1.txt", "./data/order_positions1.txt", "./data/orders_new1.txt");
    copyToVector("./data/orders2.txt", "./data/order_positions2.txt", "./data/orders_new2.txt");
}

int copyToVector(std::string ordersPath, std::string booksOutputPath, std::string ordersOutputPath)
{
    std::vector<Order> ordersParsed{};
    std::vector<OrderPosition> allOrderPositions{};

    std::ifstream ordersRaw{ordersPath};
    std::ofstream ordersFile{ordersOutputPath};
    std::ofstream orderPositionsFile{booksOutputPath};

    if (!ordersRaw)
    {
        std::cerr << "Error while opening data files." << std::endl;
        return -1;
    }

    std::copy(std::istream_iterator<Order>{ordersRaw},
              std::istream_iterator<Order>{},
              std::back_inserter(ordersParsed));

    std::copy(ordersParsed.begin(),
              ordersParsed.end(),
              std::ostream_iterator<Order>{ordersFile, "\n"});

    for (auto &order : ordersParsed)
    {
        std::vector<OrderPosition> orderElements = *order.getOrderElements();
        std::copy(orderElements.begin(), orderElements.end(), std::back_inserter(allOrderPositions));
    }

    std::copy(allOrderPositions.begin(),
              allOrderPositions.end(),
              std::ostream_iterator<OrderPosition>{orderPositionsFile, "\n"});

    std::cout << "Order positions amount: " << allOrderPositions.size() << std::endl;

    ordersFile.close();
    orderPositionsFile.close();
    return 0;
}
