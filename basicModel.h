#ifndef _basicModel_h
#define _basicModel_h

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <string>
#include <ctime>

struct current_time{
  int year;
  int month;
  int day_of_month;
  int hour;
  int min;
};

current_time getTime();

class date{
public:
  int year;
  int month;
  int day;
  date(const int _year,const int _month,const int _day);
  date();
  date(const date & rhs);
  date operator=(const date & rhs);
};

class item{
private:
  std::string name;
  double amount;
  date Date;
  std::string label;
public:
  item(){}
  ~item(){}
  item(std::string _name, double _amount, date _date, std::string _label);
  item(std::string _name, double _amount, std::string _label);
  void save(FILE * record);
  std::string getName();
  double getAmount();
  date getDate();
  std::string getLabel();  
  void erase();
};
#endif
