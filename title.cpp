//Colin Aslett, Red Black Tree Insertion, C++ Period 07
#include <iostream>

using namespace std;

struct Node{
  Node* lchild;
  Node* rchild;
  int data;
  Node* parent;
  bool color;//black is true, red is false
  Node(int datax,bool colorx = false) : lchild(0), rchild(0), parent(0){
    data = datax;
    color = colorx;
  }
  Node() : lchild(0), rchild(0), parent(0){
    data = 0;
    color = true;
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
    if(parent == 0){
      return 0;
    }
    return parent->parent;
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
  //setting a node's color
  void Color(char x){
    if(x == 'r'){
      color = false;
    }
    else{
      color = true;
    }
  }
  //retrieves the direction of a node's child
  bool child(char dir){
    if(dir = '1'){
      return parent->lchild == this;
    }
    else{
      return parent->rchild == this;
    }
  }
};
Node* root;

int main(){
  cout << "HELLO!" << endl;
}
