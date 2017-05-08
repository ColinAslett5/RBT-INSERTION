//Colin Aslett, Red Black Tree Insertion, C++ Period 07
#include <iostream>
#include "title.h"
#include <fstream>

using namespace std;
void add(RBT &rbt);//getting numbers to the tree manually
void file(RBT &rbt);//getting numbers to the tree via file
void insert(RBT &rbt,char* list);//adding the list of numbers to the RBT
int main(){
  cout << "HELLO! You have entered the Red Black Tree Insertion" << endl;
  bool kg = true;
  while(kg == true){
    RBT tree;//RBT called tree
    cout << "You have 3 options, 1 = add numbers, 2 = add numbers via file, 3 = quit program :(" << endl;
    char input;
    cin >> input;
    if(input == '1'){
      add(tree);
    }
    else if(input == '2'){
      file(tree);
    }
    else if(input == '3'){
      break;
    }
    else{
      cout << "???" << endl;
      continue;
    }
    while(true){
      cout << "You have 4 options, 1 = add numbers, 2 = add numbers via file, 3 = print, 4 = quit" << endl;
      char dput;
      cin >> dput;
      if(dput == '3'){
	cout << "RBT: " << endl;
	tree.print();
      }
      else if(dput == '2'){
	file(tree);
      }
      else if(dput == '1'){
	add(tree);
      }
      else if(dput == '4'){
	break;
      }
      else{
	cout << "???" << endl;
      }
    }
    /*
    if(dput == '4' || input == '3'){
      kg = false;
      break;
    }
    */
  }
  return 0;
}
//adding numbers manually
void add(RBT &rbt){
  char list[200];
  cout << "Enter numbers seperated by spaces: " << endl;
  cin.ignore();
  cin.getline(list,200);
  insert(rbt,list);
}
//adding numbers via file
void file(RBT &rbt){
  char filex[64];
  cout << "File Name: " << endl;
  cin >> filex;
  ifstream stream(filex);
  if(stream.is_open()){
    char list[10000];
    stream.getline(list,10000,0);
    stream.close();
    insert(rbt,list);
  }
  else{
    cout << "No file exists with that name" << endl;
  }
}
//inserting numbers into the RBT, individually, first seperating them
void insert(RBT &rbt,char* list){
  int num = 0;
  while(list[num]){
    if(isdigit(list[num])){
      int numb = list[num] - '0';
      while(isdigit(list[++num])){
	numb = 10*num + (list[num] - '0');
      }
      rbt.add(numb);
    }
    else{
      num++;
    }
  }
}
