#ifndef dataRead_h
#define dataRead_h
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <QFile>
#include <QTextStream>
item inputItem(std::vector<std::string>& labels){
  
  //ask for name
  std::string name;
  //std::cout<<"Enter name"<<std::endl;
  std::cin>>name;
  //ask for amount
  double amount;
  //std::cout<<"Enter amount"<<std::endl;
  std::cin>>amount;
  //ask for labels
  //std::cout<<"Choose category."<<std::endl;
  for(unsigned i = 0; i < labels.size(); i++){
    //std::cout<<i+1<<". "<<labels[i]<<std::endl;
  }

  std::string label;
  while(true) {
    //std::cout<<"Pick from 1 to "<<labels.size()<<std::endl;
    unsigned num;
    std::cin>>num;
    if(num > 0 && num <= labels.size()){
      label = labels[num-1];
      break;
    }
  }
  //ask for date
  int choice;
  while(true){
    char select;
    //std::cout<<"today? y/n"<<std::endl;
    std::cin>>select;
    if(select == 'y' ||  select == 'n'){
      choice = select;
      break;
    }
  }
  if(choice != 'y'){
    int year, month, day;
    //std::cout<<"Enter month"<<std::endl;
    std::cin>>month;
    //std::cout<<"Enter day"<<std::endl;
    std::cin>>day;
    //std::cout<<"Enter year"<<std::endl;
    std::cin>>year;
    date Date(year, month, day);
    item example(name, amount, Date, label);    
    return example;
  }
  else {
    item example(name, amount, label);
    return example;
  }
  
  
}

/* item lineToItem(std::string strIn) { */
/*   //read from every line, elements seperated by "|" */
/*   std::size_t pos1 = strIn.find(','); */
/*   std::size_t pos2 = strIn.find(',', pos1 + 1); */
/*   std::size_t pos3 = strIn.find(',', pos2 + 1); */
/*   std::size_t pos4 = strIn.find(',', pos3 + 1); */
/*   std::size_t pos5 = strIn.find(',', pos4 + 1); */
  
/*   std::string name = strIn.substr(0, pos1); */
/*   char * pEnd; */
/*   double amount = strtod(strIn.substr(pos1 + 1).c_str(), &pEnd); */
/*   int month = strtol(strIn.substr(pos2 + 1).c_str(), &pEnd, 10); */
/*   int day = strtol(strIn.substr(pos3 + 1).c_str(), &pEnd, 10); */
/*   int year = strtol(strIn.substr(pos4 + 1).c_str(), &pEnd, 10); */
/*   std::string label = strIn.substr(pos5 + 1); */
/*   date Date(year, month, day); */
/*   item thisitem(name, amount, Date, label); */
/*   return thisitem; */
/* } */

/* std::vector<item> readData(const char* fileToRead){ */
/*   std::vector<item> items; */
/*   FILE * dataFile = fopen(fileToRead, "r"); */
/*   //TODO -- throw if failure */
/*   char * line = NULL; */
/*   size_t len = 0; */
/*   ssize_t read; */
/*   while((read = getline(&line, &len, dataFile)) != -1){ */
/*     std::string temp(line); */
/*     std::string content(temp.begin(), temp.end()-1); */
/*     items.push_back(lineToItem(content)); */
/*   } */
/*   free(line); */
/*   fclose(dataFile); */
/*   return items; */
  
/* } */
std::string Trim(std::string& str){
  str.erase(0,str.find_first_not_of(" \t\r\n"));
  str.erase(str.find_last_not_of(" \t\r\n") + 1);
  return str;
}

std::vector<item> * readData(const char* fileToRead){
  std::vector<item> * items = new std::vector<item>;
  std::ifstream fin(fileToRead);
  std::string line;
  while(std::getline(fin,line)){
    std::istringstream sin(line);
    std::vector<std::string> fields;
    std::string field;
    while(std::getline(sin,field,',')){
      fields.push_back(field);
    }
    std::string name = Trim(fields[0]);
    std::string _amount = Trim(fields[1]); 
    double amount = strtod(_amount.c_str(), NULL);
    std::string _month = Trim(fields[2]); 
    int month = strtol(_month.c_str(), NULL, 10);
    std::string _day = Trim(fields[3]); 
    int day = strtol(_day.c_str(), NULL, 10);
    std::string _year = Trim(fields[4]); 
    int year = strtol(_year.c_str(), NULL, 10);
    std::string label = Trim(fields[5]);  
    date date(year, month, day);
    item toSave(name, amount, date, label);
    //std::cout<<toSave.getName()<<" "<<toSave.getAmount()<<" "<<date.month<<"/"<<date.day<<std::endl;
    items->push_back(toSave);
  }
  //  fclose(dataFile); 
  return items; 
  
}
std::vector<std::string> * readLabel(const char* labelToRead){
  std::vector<std::string> * labels = new std::vector<std::string>;
  FILE * labelFile = fopen(labelToRead, "r");
  if(labelFile == NULL) std::cout<<labelToRead<<std::endl;
  //TODO -- throw if failure
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  while((read = getline(&line, &len, labelFile)) != -1){
    std::string temp(line);
    std::string label(temp.begin(), temp.end()-1);
    labels->push_back(label);
  }
  free(line);
  fclose(labelFile);
  return labels;
}

double readBudget(const char* labelToRead){
  FILE * budgetFile = fopen(labelToRead, "r");
  double budget;
  //TODO -- throw if failure
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  while((read = getline(&line, &len, budgetFile)) != -1){
    budget = atof(line);
  }
  free(line);
  fclose(budgetFile);
  return budget;
}


std::vector<std::pair<std::string, double> > * readShoppingList(const char* fileToRead){
  std::vector<std::pair<std::string, double> > * shoppingList = new std::vector<std::pair<std::string, double> >;
  std::ifstream fin(fileToRead);
  std::string line;
  while(std::getline(fin,line)){
    std::istringstream sin(line);
    std::vector<std::string> fields;
    std::string field;
    while(std::getline(sin,field,',')){
      fields.push_back(field);
    }
    std::string name = Trim(fields[0]);
    std::string _amount = Trim(fields[1]);
    double amount = strtod(_amount.c_str(), NULL);
    std::pair<std::string, double> toSave(name, amount);
    //std::cout<<toSave.first<<" "<<toSave.second<<std::endl;
    shoppingList->push_back(toSave);
  }
  //  fclose(dataFile);
  return shoppingList;

}

std::vector<item> * readData(const QString &path){
    std::vector<item> * items = new std::vector<item>;
    QString fileName = path;

    QFile file(fileName);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream stream(&file);
    QString line;
    do {
        line = stream.readLine();
        if (!line.isEmpty()) {

            QStringList pieces = line.split(",");

            std::string name = pieces.value(0).toStdString();
            double amount = atof(pieces.value(1).toStdString().c_str());
            int month = atof(pieces.value(2).toStdString().c_str());
            int day = atof(pieces.value(3).toStdString().c_str());
            int year = atof(pieces.value(4).toStdString().c_str());
            std::string label = pieces.value(5).toStdString();
            date date(year, month, day);
            item toSave(name, amount, date, label);
            std::cout<<toSave.getName()<<" "<<toSave.getAmount()<<" "<<date.month<<"/"<<date.day<<std::endl;
            items->push_back(toSave);
        }
    } while (!line.isEmpty());

    file.close();
    return items;
}


std::vector<std::string> * readLabel(const QString &path)
{
    std::vector<std::string> * labels = new std::vector<std::string>;
    QString fileName = path;
    if (fileName.isEmpty())
        return NULL;
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text))
        return NULL;
    QTextStream stream(&file);
    QString line;
    do {
        line = stream.readLine();
        if (!line.isEmpty()) {
            labels->push_back(line.toStdString());
        }
    } while (!line.isEmpty());
    file.close();
    return labels;
}



double readBudget(const QString &path){

    QString fileName = path;
    QFile file(fileName);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream stream(&file);
    QString line;
    line = stream.readLine();
    file.close();
    double budget = atof(line.toStdString().c_str());
    return budget;
}


std::vector<std::pair<std::string, double> > * readShoppingList(const QString &path){

    std::vector<std::pair<std::string, double> > * shoppingList = new std::vector<std::pair<std::string, double> >;
    QString fileName = path;
    QFile file(fileName);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream stream(&file);
    QString line;
    do {
        line = stream.readLine();
        if (!line.isEmpty()) {
            QStringList pieces = line.split(",");
            std::string name = pieces.value(0).toStdString();
            double amount = atof(pieces.value(1).toStdString().c_str());
            std::pair<std::string, double> toSave(name, amount);
            shoppingList->push_back(toSave);
        }
    } while (!line.isEmpty());
    file.close();
  //  fclose(dataFile);
  return shoppingList;

}


#endif
