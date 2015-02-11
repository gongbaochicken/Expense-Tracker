#include "basicModel.h"

current_time getTime(){
  current_time t;
  time_t now = time(0);
  tm *ltm = localtime(&now);
  //time_t rawtime;
  //struct tm * ltm;
  //time (&rawtime);
  //ltm = localtime (&rawtime);
  t.year=1900+ltm->tm_year;  //since 1900
  t.month = 1+ltm->tm_mon;   // tm_mon counts from 0-11, so plus one 
  t.day_of_month = ltm->tm_mday;
  t.hour = -5+ltm->tm_hour;  //EST (Durham 5 hours behind CST)
  t.min = ltm->tm_min;
  return t;
}

item::item(std::string _name, double _amount, date _date, std::string _label):name(_name),
									      amount(_amount),
									      Date(_date),
									      label(_label){}


item::item(std::string _name, double _amount, std::string _label):name(_name),
								  amount(_amount),
								  label(_label){
  Date.month = getTime().month;
  Date.day = getTime().day_of_month;
  Date.year = getTime().year;
}
			       
date::date(): year(0),
	  month(0),
	  day(0){}
date date::operator=(const date & rhs){
  date ans(rhs);
  return ans;
} 


date::date(const date & rhs){
  year = rhs.year;
  month = rhs.month;
  day = rhs.day;
}

date::date(const int _year,const int _month,const int _day): year(_year),
							     month(_month),
							     day(_day){}

void item::save(FILE * record){
  fprintf(record, "%s,%f,%d,%d,%d,%s\n", name.c_str(), amount, Date.month, Date.day, Date.year, label.c_str());
}

std::string item::getName(){
  return name;
}

double item::getAmount(){
  return amount;
}

date item::getDate(){
  return Date;
}

std::string item::getLabel(){
  return label;
}

void item::erase(){
    this->name = "__test_ITEM";
    this->amount = 0;
    this->label = "__test_label";
    this->Date.day = 0;
    this->Date.month = 0;
    this->Date.year = 0;
}
