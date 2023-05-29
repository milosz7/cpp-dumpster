#include "../headers/client.h"
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
  Client clientData{};
  std::ifstream orders{"./data/orders1.txt"};
  std::string line;
  std::vector<Client> clients{};

  if (!orders)
  {
    std::cerr << "Error while opening data file." << std::endl;
    return -1;
  }

  while (orders >> clientData)
  {
    clients.push_back(clientData);
    while (getline(orders, line) && line != "")
      ;
  }

  orders.close();

  std::cout << clients.size() << std::endl;
  std::ofstream clientsFile{"./data/clients2.txt"};

  for (int i = 0; i < clients.size(); i++)
  {
    std::cout << clients.at(i) << std::endl
                << std::endl;
  }

  for (auto it = clients.begin(); it != clients.end(); it++)
  {
    std::cout << "1: " << *it << std::endl
              << std::endl;
  }

  for (auto &clientData : clients)
  {
    std::cout << "2: " << clientData << std::endl
              << std::endl;
  }

  std::for_each(clients.begin(), clients.end(), [&](Client c)
           { clientsFile << c << std::endl
                       << std::endl; });

  clientsFile.close();

  return 0;
}
