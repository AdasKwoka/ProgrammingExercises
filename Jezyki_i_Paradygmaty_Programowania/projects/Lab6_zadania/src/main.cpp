#include <iostream>
#include <map>

#include "../includes/header.hpp"

using namespace std;

int main()
{
  HRMS data;
  Employee person;

  person.name = "Adam";
  person.surname = "Mickiewicz";
  person.position = "Boss";
  data.add(person, 0, 6000.22);

  person.name = "Michal";
  person.surname = "Mickiewicz";
  person.position = "Boss";
  data.add(person, 0, 9000.02);

  person.name = "Marcin";
  person.surname = "Nieznany";
  person.position = "Agent";
  data.add(person, 0, 7721.02);

  person.name = "Michal";
  person.surname = "Aniol";
  person.position = "Courier";
  data.add(person, 1, 1000.99);

  person.name = "Franciszek";
  person.surname = "Bosowy";
  person.position = "Boss";
  data.add(person, 1, 7892.99);

  person.name = "Marek";
  person.surname = "Michalek";
  person.position = "Agent";
  data.add(person, 1, 6029.99);

  person.name = "Zbigniew";
  person.surname = "Stonoga";
  person.position = "Manager";
  data.add(person, 2, 4000.99);

  person.name = "Ludomir";
  person.surname = "Franek";
  person.position = "Assistent";
  data.add(person, 2, 2000.99);

  person.name = "Lukasz";
  person.surname = "Malysz";
  person.position = "Boss";
  data.add(person, 2, 7092.99);

  person.name = "Jaroslaw";
  person.surname = "Platynow";
  person.position = "Developer";
  data.add(person, 2, 5472.99);

  data.printDepartment(0);
  data.printDepartment(1);
  data.printDepartment(2);

  data.printSalaries();
  data.printSalariesSorted();

  return 0;
}