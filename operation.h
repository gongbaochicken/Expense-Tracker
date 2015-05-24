#ifndef _operation_h_
#define _operation_h_

#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

std::string intToMonth(int m){
  //std::string month_name;
  switch(m){
  case 1:
    return "Jan.";
  case 2:
    return "Feb.";
  case 3:
    return "Mar.";
  case 4:
    return "Apr.";
  case 5:
    return "May";
  case 6:
    return "Jun.";
  case 7:
    return "Jul.";
  case 8:
    return "Aug.";
  case 9:
    return "Sept.";
  case 10:
    return "Oct.";
  case 11:
    return "Nov.";
  case 12:
    return "Dec.";
  default:
    return "Input month is invalid!";
  }
}

double Total_Spending(std::vector<item> v){
  double sum = 0.0;
  for (unsigned i = 0; i < v.size(); i++){
    sum += v[i].getAmount();
  }
  return sum;
}

double SpendingLabelMonthly(std::vector<item> * v, int year, int month, std::string name){
  double sum = 0;
  for (unsigned i = 0; i < v->size(); i++){
    if ((*v)[i].getDate().month == month && (*v)[i].getDate().year == year && (*v)[i].getLabel() == name){
      sum += (*v)[i].getAmount();
    }
  }
  return sum;
}
double SpendingLabelYearly(std::vector<item> * v, int year, std::string name){
  double sum = 0;
  for (unsigned i = 0; i < v->size(); i++){
    if ((*v)[i].getDate().year == year && (*v)[i].getLabel() == name){
      sum += (*v)[i].getAmount();
    }
  }
  return sum;
}
double SpendingLabelDayly(std::vector<item> * v, date d, std::string name){
  double ans=0;
  for (unsigned i=0; i<v->size(); i++) {
    if((*v)[i].getDate().day==d.day && (*v)[i].getDate().month==d.month && (*v)[i].getDate().year==d.year && (*v)[i].getLabel() == name) {
      ans += (*v)[i].getAmount();
    }
  }
  return ans;
}


double sumDay(date d,std::vector<item> * v){
  double ans=0.0;
  //  std::vector<item>::size_type n=v.size();
  for (unsigned i=0; i<v->size(); i++) {
    if((*v)[i].getDate().day==d.day && (*v)[i].getDate().month==d.month && (*v)[i].getDate().year==d.year) {
      ans += (*v)[i].getAmount();
    }
  }
  return ans;
}

double sumMonth(int Month, int Year, std::vector<item> * v){
  double ans = 0;
  //std::vector<item>::size_type n=v.size();
  for (unsigned i=0; i < v->size(); i++) {
    if((*v)[i].getDate().month == Month && (*v)[i].getDate().year == Year) {
      ans += (*v)[i].getAmount();
    }
  }
  return ans;
}

double sumYear(int Year, std::vector<item> v){
  double ans=0.0;
  //std::vector<item>::size_type n=v.size();
  for (unsigned i=0; i<v.size(); i++) {
    if(v[i].getDate().year==Year) {
      ans += v[i].getAmount();
    }
  }
  return ans;
}

#endif

