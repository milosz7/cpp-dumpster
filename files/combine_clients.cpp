#include <fstream>
#include <vector>
#include "../headers/client.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>

#define PATH_CLIENTS_1 "./data/clients.txt"
#define PATH_CLIENTS_2 "./data/clients2.txt"
#define CLIENTS_OUTPUT_PATH "./data/clients_merged.txt"

void populateVector(std::ifstream &file, std::vector<Client> &vector)
{
  Client clientData{};
  while (file >> clientData)
  {
    vector.push_back(clientData);
  }
}

bool needsSwap(Client c1, Client c2)
{
  return c1.getSurname() < c2.getSurname();
}

bool areEqual(Client c1, Client c2)
{
  return c1.getName() == c2.getName() &&
         c1.getAddress() == c2.getAddress() &&
         c2.getSurname() == c2.getSurname();
}

int main()
{
  std::vector<Client> clientsFirst{}, clientsSecond{};
  std::ifstream clientsFirstFile{PATH_CLIENTS_1}, clientsSecondFile{PATH_CLIENTS_2};

  if (!clientsFirstFile || !clientsSecondFile)
  {
    std::cerr << "Error while opening data file." << std::endl;
  }

  populateVector(clientsFirstFile, clientsFirst);
  clientsFirstFile.close();
  std::sort(clientsFirst.begin(), clientsFirst.end(), needsSwap);

  populateVector(clientsSecondFile, clientsSecond);
  clientsSecondFile.close();
  std::sort(clientsSecond.begin(), clientsSecond.end(), needsSwap);

  std::vector<Client> clientsMerged(clientsFirst.size() + clientsSecond.size());

  std::merge(clientsFirst.begin(),
             clientsFirst.end(),
             clientsSecond.begin(),
             clientsSecond.end(),
             clientsMerged.begin(),
             needsSwap);

  std::cout << clientsMerged.size() << std::endl;
  std::vector<Client>::iterator it;
  it = std::unique(clientsMerged.begin(), clientsMerged.end(), areEqual);
  clientsMerged.resize(std::distance(clientsMerged.begin(), it));
  std::cout << clientsMerged.size() << std::endl;

  std::ofstream clientsOut{CLIENTS_OUTPUT_PATH};
  std::ostream_iterator<Client> out_it(clientsOut, "\n");
  std::copy (clientsMerged.begin(), clientsMerged.end(), out_it);

  // for (auto &client : clientsMerged)
  // {
  //   clientsOut << client << std::endl
  //             << std::endl;
  // }

  clientsOut.close();
}
