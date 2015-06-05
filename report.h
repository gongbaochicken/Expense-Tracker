#ifndef _report_h_
#define _report_h_

#include <cstdlib>
#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>
#include "operation.h"

double report_Total_Spending(std::vector<item> v) {
  double sum=Total_Spending(v);
  return sum;
  //std::cout<<"The total expense is $" <<sum<< "!" <<std::endl;
}

//work below this has been done

// for bar chart

//Month in Year
std::vector<std::pair<std::string, double> > report_sum_MinY(int Year, std::vector<item> * v){
  std::vector<std::pair<std::string, double> > ans;
  for(unsigned i = 1; i <= 12; i++){
    double sum=sumMonth(i, Year, v);
    std::string monthName = intToMonth(i);
    std::pair<std::string, double> monthAmount(monthName, sum);
    ans.push_back(monthAmount);
  }
  return ans;
} 

int dayToNum(date currDay){
  int day_tab[12]={31,28,31,30,31,30,31,30,31,31,30,31};
  int ans = 0;
  for(int i = 0; i < currDay.month - 1; i++){
    ans += day_tab[i];
  }
  ans += currDay.day;
  if((currDay.month > 2) && ((currDay.year%4 == 0 && currDay.year%100 != 0) || currDay.year%400==0)){
     return ans+1;
  }
  else return ans;
}

date numToDay(int daynum, int year){
  int day_tab1[12]={31,28,31,30,31,30,31,30,31,31,30,31};
  int day_tab2[12]={31,29,31,30,31,30,31,30,31,31,30,31};
  int month = 0;
  int day = 0;
  int i = 0;
  int * day_tab = ((year%4 == 0 && year%100 != 0) || year%400==0)?day_tab2:day_tab1;
  while(daynum > 0){
    day = daynum;
    daynum -= day_tab[i];
    month += 1;
    i++;
  }
  date ans(year, month, day);
  return ans;
}


std::string num2str(int i)
{
  std::stringstream ss;
  ss<<i;
  return ss.str();
}

std::vector<std::pair<std::string, double> > report_sum_DinX(date currDay,const int range, std::vector<item> * v){
  std::vector<std::pair<std::string, double> > ans;
  int dayNumber = dayToNum(currDay);
  for(int i = 0; i < range; i++){
    int dayInList = dayNumber - (range - i -1);
    date dateInList = numToDay(dayInList, currDay.year);
    double daySum = sumDay(dateInList, v);
    std::string dayName = num2str(dateInList.month) + "/" + num2str(dateInList.day) + "/" +num2str(dateInList.year);
    std::pair<std::string, double> dayAmount(dayName, daySum);
    //std::cout<<dayName.c_str()<<"   "<<daySum<<std::endl;
    ans.push_back(dayAmount);
  }
  return ans;
} 
//Day in last 30 days
std::vector<std::pair<std::string, double> > report_sum_Din30(date currDay, std::vector<item> * v){
  return report_sum_DinX(currDay, 30, v);
}
//Day in last 7 days
std::vector<std::pair<std::string, double> > report_sum_Din7(date currDay, std::vector<item> * v){
  return report_sum_DinX(currDay, 7, v);
}
//Day in month
std::vector<std::pair<std::string, double> > report_sum_DinM(const int month,const int year, std::vector<item> * v){
  int day_tab1[12]={31,28,31,30,31,30,31,30,31,31,30,31};
  int day_tab2[12]={31,29,31,30,31,30,31,30,31,31,30,31};
  int * day_tab = ((year%4 == 0 && year%100 != 0) || year%400==0)?day_tab2:day_tab1;  
  date currDay(year, month, day_tab[month-1]);
  return report_sum_DinX(currDay, day_tab[month-1], v);
}
//for pi chart

//Category Sums in X days
std::vector<std::pair<std::string, double> > report_sum_Label_DinX(date currDay,const int range, std::vector<item> * v, std::vector<std::string> * label){
  std::vector<std::pair<std::string, double> > ans;
  int dayNumber = dayToNum(currDay);
  for(unsigned j = 0; j < label->size(); j++){
    double categorySum = 0;
    for(int i = 0; i < range; i++){
      int dayInList = dayNumber - (range - i -1);
      date dateInList = numToDay(dayInList, currDay.year);
      double daySum = SpendingLabelDayly(v, dateInList, (*label)[j]);
      categorySum += daySum;
    }
    std::pair<std::string, double> categoryAmount((*label)[j], categorySum);
    ans.push_back(categoryAmount);
  }
  return ans;
} 

std::vector<std::pair<std::string, double> > report_sum_Label_Din30(date currDay, std::vector<item> * v, std::vector<std::string> * label){
  return report_sum_Label_DinX(currDay, 30, v, label);
}

std::vector<std::pair<std::string, double> > report_sum_Label_Din7(date currDay, std::vector<item> * v, std::vector<std::string> * label){
  return report_sum_Label_DinX(currDay, 7, v, label);
}

//category sum in month
std::vector<std::pair<std::string, double> > report_SLM(std::vector<item> * v, std::vector<std::string> * labels,const int year, const int month) {
  std::vector<std::pair<std::string, double> > ans;
  for(unsigned i = 0; i < labels->size() ; i++){
    double sum=SpendingLabelMonthly(v, year, month, (*labels)[i]);
    std::pair<std::string ,double> categoryAmount((*labels)[i], sum);
    ans.push_back(categoryAmount);
  }
  return ans;
}

//category sum in year
std::vector<std::pair<std::string, double> > report_SLY(std::vector<item> * v, std::vector<std::string> * labels,const int year) {
  std::vector<std::pair<std::string, double> > ans;
  for(unsigned i = 0; i < labels->size() ; i++){
    double sum=SpendingLabelYearly(v, year, (*labels)[i]);
    std::pair<std::string ,double> categoryAmount((*labels)[i], sum);
    ans.push_back(categoryAmount);
  }
  return ans;
}


#endif
