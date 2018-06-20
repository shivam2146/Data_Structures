#include<iostream>
#include<queue>
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
  void deleteBT(node<T>* temp);
public:
  BTree(){
    root = NULL;
  }
  void insert(T data);
  void deleteBT(){
    cout<<"\nDeleting the binary tree";
    if(root)
      deleteBT(root);
  }
  void iDeleteBT();
  int iHeight();
};

template <typename T>
void BTree<T>::iDeleteBT(){
  if(!root)
    return;
  cout<<"\nDeleting the binary tree";
  queue<node<T>*> q;
  q.push(root);
  root = NULL;
  while(!q.empty()){
    node<T> *temp = q.front();
    q.pop();
    if(temp->left)
      q.push(temp->left);
    if(temp->right)
      q.push(temp->right);
    delete temp;
  }
}

template <typename T>
void BTree<T>::deleteBT(node<T>* temp){
  if(!temp)
    return;
  deleteBT(temp->left);
  deleteBT(temp->right);
  if(temp == root)
    root= NULL;
  delete(temp);
}

template<typename T>
int BTree<T>::iHeight(){
  if(!root)
    return 0;
  queue<node<T>*> q;
  q.push(root);
  q.push(NULL);
  int h = 0;
  while(!q.empty()){
    node <T>* temp = q.front();
    q.pop();
    if(temp == NULL){
      h++;
      if(!q.empty())
        q.push(NULL);
    }else{
      if(temp->left)
        q.push(temp->left);
      if(temp->right)
        q.push(temp->right);
    }
  }
  return h;
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
  //t.deleteBT();
  t.iDeleteBT();
  cout<<"\nheight of tree is: "<<t.iHeight();
  return 0;
}
