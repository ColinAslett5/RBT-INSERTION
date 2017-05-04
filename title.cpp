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
void add();//adding numbers manually
bool fileadd();//adding numbers via a file
void print();//printing out the tree
void insert(int num);//inserting node into tree
void preserve(Node* xx);//preserving the red black tree state
void first(Node* node,int numb);//initial insertion is BST
int main(){
  cout << "HELLO! You have entered the Red Black Tree Insertion" << endl;
  bool kg = true;
  while(kg == true){
    char input;
    cout << "you have two options, 1 = insert numbers manually, 2 = file name, 3 = quit" << endl;
    cin >> input;
    //adding manually
    if(input == '1'){
      add();
    }
    //adding via file
    else if(input == '2'){
      if(!fileadd()){
	continue;
      }
    }
    //quitting program
    else if(input == '3'){
      kg = false;
      break;
    }
    //something that is not one of the three
    else{
      cout << "not one of the three inputs" << endl;
      continue;
    }
    //next step
    while(true){
      cout << "Three options: 1 = print, 2 = add numbers manually, 3 = add numbers via file, 4 = quit" << endl;
      cin >> input;
      if(input == '1'){
        cout << "RBT:" << endl;
        print();
      }
      else if(input == '2'){
        add();
      }
      else if(input == '3'){
        fileadd();
      }
      else if(input == '4'){
        break;
      }
      else{
        cout << "Command not recognized" << endl;
      }
    }
  }
}
//adding numbers manually
void add(){
  char list[200];
  cout << "Enter numbers seperated by spaces" << endl;
  cin.ignore();
  cin.getline(list,200);
  //next part
  int index = 0;
  while(list[index]){
    if(isdigit(list[index])){
      int num = list[index] - '0';
      while(isdigit(list[++index])){
	num = 10*num + (list[index] - '0');
      }
      insert(num);
    }
    else{
      index++;
    }
  }
}
//adding numbers via file
bool fileadd(){
  
}
//printint out the tree
void print(){
  
}
//inserting number to node
void insert(int num){
  preserve(first(root,num));
}
//preserving the RBT properties
void preserve(Node* xx){
  if(xx->parent == 0){//node is head
    xx->Color('b');
    return;
  }
  else if(xx->parent->color){//parent is black
    return;
  }
  else if(xx->Uncle()->color == false){//parent is red, and uncle
    xx->parent->Color('b');
    xx->Uncle()->Color('b');
    xx->Grandparent()->Color('r');
    preserve(xx->Grandparent());
    return;
  }
}
void first(Node* node,int numb){
  
}
