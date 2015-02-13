#ifndef dataWrite_h
#define dataWrite_h

void writeData(std::vector<item> * items, const char * toWrite){

  FILE * f = fopen(toWrite, "w+");
  //std::cout<<"write to "<<toWrite<<std::endl;
  if(items == NULL){
    std::cout<<"0000000000000"<<toWrite<<std::endl;
  }
  for(unsigned int i = 0; i < items->size(); i++){
    (*items)[i].save(f);
  }
  fclose(f);
}

void writeLabel(std::vector<std::string> * labels, const char * toWrite){
  FILE * f = fopen(toWrite, "w+");
  //std::cout<<"write to "<<toWrite<<std::endl;
  for(unsigned int i = 0; i < labels->size(); i++){
    fprintf(f, "%s\n", (*labels)[i].c_str());
  }
  fclose(f);
}

QString filingIn(QString tofiling, int charNum){
  QString tmp = tofiling;
  for(int i = 0; i < (charNum - tofiling.length()); i++){
    tmp = tmp + " ";
  }
  return tmp;
}

void writeShoppingList(std::vector<std::pair<std::string, double> > * shoppingList, const char * toWrite){
  FILE * f = fopen(toWrite, "w+");
  //std::cout<<"write to "<<toWrite<<std::endl;
  for(unsigned int i = 0; i < shoppingList->size(); i++){
      QString nameToAdd = filingIn(QString::fromStdString((*shoppingList)[i].first), 20);
      fprintf(f, "%s,%f\n", nameToAdd.toStdString().c_str(), (*shoppingList)[i].second);
  }
  fclose(f);
}

void writeBudget(double budget, const char * toWrite){
  FILE * f = fopen(toWrite, "w+");
  //std::cout<<"write to "<<toWrite<<std::endl;

  fprintf(f, "%f\n", budget);

  fclose(f);
}
#endif
