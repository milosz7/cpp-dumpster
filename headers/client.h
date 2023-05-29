#include <string>
#include <iostream>

#define CHARS_TO_IGNORE 100

class Client
{
private:
  std::string name, surname, address;

public:
  Client(std::string _name, std::string _surname, std::string _address) : 
    name(_name), surname{_surname}, address{_address} {}
  
  Client() = default;

  void setName(std::string _name) { name = _name; }
  void setSurname(std::string _surname) { surname = _surname; }
  void setAddress(std::string _address) { address = _address; }

  std::string getName() const { return name; }
  std::string getSurname() const { return surname; }
  std::string getAddress() const { return address; }
};

std::ostream &operator<<(std::ostream &os, const Client &c) {
  os << c.getName() << " " << c.getSurname() << std::endl;
  os << c.getAddress();
  return os;
}

std::istream &operator>>(std::istream &is, Client &c) {
  std::string name, surname, address;
  is >> name >> surname;
  is.ignore(CHARS_TO_IGNORE, '\n');
  getline(is, address);
  c.setName(name);
  c.setSurname(surname);
  c.setAddress(address);
  return is;
}
