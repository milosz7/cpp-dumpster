#include "../headers/orderPosition.h"
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

void readToVector(std::vector<OrderPosition> &ordersVector, std::string filePath);

int main()
{
    std::vector<OrderPosition> orderPositions1{};
    std::vector<OrderPosition> orderPositions2{};

    readToVector(orderPositions1, "./data/order_positions1.txt");
    readToVector(orderPositions2, "./data/order_positions2.txt");

    std::cout << orderPositions1.size() << orderPositions2.size();

    std::vector<OrderPosition> ordersUnique{};
    std::vector<OrderPosition>::iterator lastElement;
    std::sort(orderPositions1.begin(), orderPositions1.end());
    std::sort(orderPositions2.begin(), orderPositions2.end());
    ordersUnique.resize(orderPositions1.size() + orderPositions2.size());
    lastElement = std::set_union(orderPositions1.begin(),
                                 orderPositions1.end(),
                                 orderPositions2.begin(),
                                 orderPositions2.end(),
                                 ordersUnique.begin());
    ordersUnique.resize(std::distance(ordersUnique.begin(), lastElement));
    std::cout << ordersUnique.size();
    std::ofstream orderPositionsMerged{"./data/order_positions_merged.txt"};
    std::copy(ordersUnique.begin(),
              ordersUnique.end(),
              std::ostream_iterator<OrderPosition>{orderPositionsMerged});
}

void readToVector(std::vector<OrderPosition> &ordersVector, std::string filePath)
{
    std::ifstream orderPositionsFile{filePath};
    std::istream_iterator<OrderPosition> it{orderPositionsFile};
    std::istream_iterator<OrderPosition> eos{};
    std::copy(it, eos, std::back_inserter(ordersVector));
    orderPositionsFile.close();
}