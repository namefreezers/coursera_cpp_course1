#include <algorithm>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Date {
public:
  int GetYear() const;
  int GetMonth() const;
  int GetDay() const;
};

istream& operator>>(istream)

bool operator<(const Date& lhs, const Date& rhs);

class Database {
public:
  void AddEvent(const Date& date, const string& event);
  bool DeleteEvent(const Date& date, const string& event);
  int  DeleteDate(const Date& date);

  set<string> Find(const Date& date) const;

  void Print() const;
};

int main() {
  Database db;

  string command;
  while (getline(cin, command)) {
    stringstream ss(command);
    if ()


  }

  return 0;
}
