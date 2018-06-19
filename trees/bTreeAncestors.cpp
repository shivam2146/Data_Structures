#include<iostream>
#include<stack>
using namespace std;

template <typename T>
struct node{
  T data;
  node *left;
  node *right;
};

template <typename T>
class BTree{
  node <T>*root;
  bool ancestors(node<T> *temp,T data);
public:
  BTree(){
    root = NULL;
  }
  void insert(T data);
  bool ancestors(T data);
};

template <typename T>
bool BTree<T>::ancestors(T data){
  cout<<"\n ancestors of "<<data<<"are : ";
  return ancestors(root,data);
}

template <typename T>
bool BTree<T>::ancestors(node<T>*temp,T data){
  if(!temp)
    return false;
  if(temp->data == data)
    return true;
    bool left = ancestors(temp->left,data) ;
    bool right = false;
    if(!left)
    right =  ancestors(temp->right,data);
    if(left||right)
      cout<<temp->data<<" ";
    return left||right;
}

template <typename T>
void BTree<T>::insert(T data){
    cout<<"\ninserting element "<<data;
    node <T> *d = new node<T>;
    d->data = data;
    d->left = NULL;
    d->right = NULL;
    if(!root){
        root = d;
        return;
    }
    queue<node<T>*> q;
    q.push(root);
    while(!q.empty()){
      node<T> *temp = q.front();
      if(temp->left)
        q.push(temp->left);
      else{
        temp->left = d;
        break;
      }
      if(temp->right)
        q.push(temp->right);
      else{
        temp->right = d;
        break;
      }
      q.pop();
    }
    q = queue<node<T>*>();
}



int main(){
  BTree<int> t;
  t.insert(5);
  t.insert(10);
  t.insert(2);
  t.insert(3);
  t.insert(15);
  t.insert(11);
  t.insert(19);
  t.insert(12);
  t.insert(17);
  t.ancestors(15);
}
