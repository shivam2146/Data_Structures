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
  int height(node<T>* root);
public:
  BTree(){
    root = NULL;
  }
  void insert(T data);
  int height(){
    if(root)
      return height(root);
    else
      return 0;
  }
  int iHeight();
};

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
int BTree<T>::height(node<T>* root){
  if(!root)
    return 0;
  else{
      int l= height(root->left)+1;
      int r = height(root->right)+1;
      return (l>r?l:r);
  }
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
  cout<<"\nheight of tree is: "<<t.height();
  cout<<"\nheight of tree is: "<<t.iHeight();
  return 0;
}
