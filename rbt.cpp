//rbt cpp file for the class, C++ period 07
#include <iostream>
#include <cstring>
#include <cmath>
#include "title.h"

using namespace std;

RBT::RBT(){
  head = new Node();
}
RBT::~RBT(){
  head->delt();
  delete head;
}
//printing out the RBT
void RBT::print(){
   int numLevels = numlevel(head, 0);
   int nodes[(int)(pow(2, numLevels)) - 1];
   int* arrPtr = nodes;
   memset(nodes, 0, sizeof(nodes));
   populate(arrPtr, 0, head);
    
   int index = 0;
   for(int l=1; l <= numLevels; l++){
       //Initial spaces:
       for(int i=0; i < pow(2, numLevels-l)-1; i++){
           cout << ' ';
       }
       //Nodes:
       for(int n=0; n < pow(2, l-1); n++){
           if(nodes[index] > 0){
               cout << nodes[index] << 'B';
           }
           else if(nodes[index] < 0){
               cout << -nodes[index] << 'R';
           }
           else{
               cout << ' ';
           }
           index++;
           //Spaces between nodes:
           for(int i=0; i < pow(2, numLevels - l + 1) - 1; i++){
               cout << ' ';
           }
       }
       cout << endl;
   }
}
//retrieves the number of levels there are in the RBT
int RBT::numlevel(Node* currenthead, int lvl = 0){
  if(currenthead == 0){//if head is empty then there is nothing in the tree
    return lvl;
  }
  return max(numlevel(currenthead->lchild,lvl+1),numlevel(currenthead->rchild,lvl+1));
}
void RBT::populate(int *& x,int index, Node* node){
  /*
  //nothing is in the node
  if(current == 0){
    return;
  }
  x[index] = current->black ? current->data : -current->data;
  populate(x,index*2+1,current->lchild);
  populate(x,index*2+2,current->rchild);
  */
  if(node == 0){
     return;
  }
  x[index] = node->black ? node->data : -node->data;
  populate(x, index*2+1, node->lchild);
  populate(x, index*2+2, node->rchild);
}
//have to preserve properties after initially adding the number to the tree
void RBT::add(int x){
  preserve(first(head,x));
}
//Adding the number using BST method first
Node* RBT::first(Node* current,int num){
  /*
  if(current->empty()){
    current->data = num;
    current->paintRed();
    current->addleaf();
    return current;
  }
  if(num < current->data){
    return first(current->lchild,num);
  }
  else{
    return first(current->rchild,num);
  }
  */
  if(current->empty()){
    current->data = num;
    current->paintRed();
    current->addleaf();
    return current;
  }
  if(num < current->data){
    return first(current->lchild, num);
  }
  else{
    return first(current->rchild, num);
  }
}
//preseving all of the RBT properties, based on internet articles
void RBT::preserve(Node* inserted){
  /*
  //current is the root
  if(current->parent == 0){
    current->paintBlack();
    return;
  }
  else if(current->parent->black){
    return;
  }//might have to be false
  else if(current->Uncle()->Red()){
    current->parent->paintBlack();
    current->Uncle()->paintBlack();
    current->Grandparent()->paintRed();
    preserve(current->Grandparent());
    return;
  }
  //
  if(current->isrchild() && current->parent->islchild()){
    left(current);
    current = current->lchild;
  }
  else if(current->islchild() && current->parent->isrchild()){
    right(current);
    current = current->rchild;
  }
  current->Grandparent()->paintRed();//red
  current->parent->paintBlack();//black
  if(current->islchild()){
    right(current->parent);
  }
  else{
    left(current->parent);
  }
  */
  if(inserted->parent == 0){
        inserted->paintBlack();
        return;
    }
    else if(inserted->parent->black){
        return;
    }
    else if(inserted->Uncle()->Red()){
        inserted->parent->paintBlack();
        inserted->Uncle()->paintBlack();
        inserted->Grandparent()->paintRed();
        preserve(inserted->Grandparent());
        return;
    }
    if(inserted->isrchild() && inserted->parent->islchild()){
        left(inserted);
        inserted = inserted->lchild;
    }
    else if(inserted->islchild() && inserted->parent->isrchild()){
        right(inserted);
        inserted = inserted->rchild;
    }
    inserted->Grandparent()->paintRed();
    inserted->parent->paintBlack();
    if(inserted->islchild()){
        right(inserted->parent);
    }
    else{
        left(inserted->parent);
    }
}
//left rotation
void RBT::left(Node* current){
  Node* currentpar = current->parent;//currentpar is currents parent
  *parent(currentpar) = current;
  current->parent = current->Grandparent();
  currentpar->Right(current->lchild);
  current->Left(currentpar);
}
//right rotation
void RBT::right(Node* current){
  Node* currentpar = current->parent;
  *parent(currentpar) = current;
  current->parent = current->Grandparent();
  currentpar->Left(current->rchild);
  current->Right(currentpar);
}
Node** RBT::parent(Node* current){
  Node** currentx;
  if(current->parent == 0){//current is the head
    currentx = &head;
  }
  else if(current == current->parent->lchild){
    currentx = &(current->parent->lchild);
  }
  else{
    currentx = &(current->parent->rchild);
  }
  return currentx;
}

