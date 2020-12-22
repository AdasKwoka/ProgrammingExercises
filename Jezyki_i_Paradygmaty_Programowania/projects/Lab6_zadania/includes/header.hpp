#pragma one

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

bool sortBySalary(const pair<int, double> x, const pair<int, double> y)
{
  return x.second > y.second;
}

class Employee
{
public:
  int id;
  string name;
  string surname;
  int departmentId;
  string position;

  void print(double salary)
  {
    cout << id << " " << name << " " << surname << ": " << position << ". Salary: " << salary << endl;
  }
};

class HRMS
{
private:
  int employerId;
  map<int, Employee> mapEmplyees;
  map<int, vector<int>> mapWorkersFromDepartments;
  map<int, double> mapWorkersSalaries;

public:
  HRMS()
  {
    employerId = 0;
  }
  void add(Employee &worker, int departmentId, double salary)
  {
    worker.departmentId = departmentId;
    worker.id = employerId;
    employerId++;
    mapEmplyees[worker.id] = worker;

    vector<int> &vect = mapWorkersFromDepartments[departmentId];
    vect.push_back(worker.id);

    mapWorkersSalaries[worker.id] = salary;
  }
  void printDepartment(int departmentId)
  {
    vector<int> &vect = mapWorkersFromDepartments[departmentId];
    cout << "Printing workers form department: " << departmentId << endl;
    for (int id : vect)
    {
      mapEmplyees[id].print(mapWorkersSalaries[id]);
    }
  }
  void changeSalary(int employedId, double salary)
  {
    mapWorkersSalaries[employerId] = salary;
  }

  void printSalaries()
  {
    map<int, Employee>::iterator it;
    cout << "Print salaries of workers: " << endl;
    for (it = mapEmplyees.begin(); it != mapEmplyees.end(); ++it)
    {
      it->second.print(mapWorkersSalaries[it->first]);
    }
  }

  void printSalariesSorted()
  {
    list<pair<int, double>> sortList;
    map<int, double>::iterator it;
    for (it = mapWorkersSalaries.begin(); it != mapWorkersSalaries.end(); ++it)
    {
      sortList.push_back(make_pair(it->first, it->second));
    }

    // sort(sortList.begin(), sortList.end(), sortBySalary());
    sortList.sort(sortBySalary);

    list<pair<int, double>>::iterator it2;
    cout << "Print sorted salaries of workers: " << endl;
    for (it2 = sortList.begin(); it2 != sortList.end(); ++it2)
    {
      mapEmplyees[it2->first].print(it2->second);
    }
  }
};