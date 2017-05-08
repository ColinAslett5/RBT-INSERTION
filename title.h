//Colin Aslett, Red Black Tree Insertion, C++ Period 07, title header file
#include <iostream>
#pragma once

using namespace std;

struct Node{
  Node* lchild;
  Node* rchild;
  int data;
  Node* parent;
  bool black;//black is true, red is false
  Node(int datax,bool blackx = false) : lchild(0), rchild(0), parent(0){
    data = datax;
    black = blackx;
  }
  Node() : lchild(0), rchild(0), parent(0){
    data = 0;
    black = true;
  }
  bool Red(){
    return !black;
  }
  void paintBlack(){
    black = true;
  }
  void paintRed(){
    black = false;
  }
  void addleaf(){
    Left(new Node());
    Right(new Node());
  }
  //retrieving the node's uncle
  Node* Uncle(){
    Node* gp = Grandparent();
    if(gp == 0){
      return 0;
    }
    if(gp->lchild == parent){
      gp->rchild;
    }
    return gp->lchild;
  }
  //retrieving the node's GP
  Node* Grandparent(){
    return parent == 0 ? 0 : parent->parent;
    /*
    if(parent == 0){
      return 0;
    }
    return parent->parent;
    */
  }
  //setting the left node
  void Left(Node* node){
    lchild = node;
    if(node != 0){
      node->parent = this;
    }
  }
  //setting the right node
  void Right(Node* node){
    rchild = node;
    if(node != 0){
      node->parent = this;
    }
  }
  //retrieves the direction of a node's child
  bool islchild(){
    return parent->lchild == this;
  }
  bool isrchild(){
    return parent->rchild == this;
  }
  void delt(){
    if(lchild != 0){
      lchild->delt();
    }
    if(rchild != 0){
      rchild->delt();
    }
    delete lchild;
    delete rchild;
  }
  //checking whether the nodes left and right are null
  bool empty(){
    return lchild == 0 && rchild == 0;
  }
  ~Node(){}
};

class RBT{
 public:
  RBT();
  ~RBT();
  void add(int x);//adding a number to the tree
  bool empty();
  void print();//printing out the RBT
 private:
  Node* head;//root, but i like to call it head
  void left(Node* current);//left rotation
  void right(Node* current);//right rotation
  int numlevel(Node* head,int lvl);
  void populate(int *& x,int index, Node* current);
  Node* first(Node* current,int num);//We add the number first using the BST method
  void preserve(Node* current);//preserving the RBT properties
  Node** parent(Node* current);
};
