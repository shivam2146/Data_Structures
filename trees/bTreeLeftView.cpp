#include<iostream>
#include<queue>
#include<map>
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
  void leftView(node<T>* root, int level,int &lastlevel);
  void leftView(node<T>* root,int level, auto &map);
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
  void printLeftView();
  void leftView(){
    cout<<"\nLeft view:  ";
    int last_level =0;
    leftView(root,1,last_level);
  }
  void leftViewMap(){
      map<int,int> m;
      leftView(root,1,m);
      cout<<"\nleft view:  ";
      for(auto it : m)
        cout<<it.second<<" ";
  }
};

template <typename T>
void BTree<T>::leftView(node<T>* root,int level, auto &map){
  if(!root)
    return;
  if(map.find(level) == map.end())
    map[level] = root->data;
  leftView(root->left,level+1,map);
  leftView(root->right,level+1,map);
}

template <typename T>
void BTree<T>::leftView(node<T>* root, int level,int &lastlevel){
  if(!root)
    return;
  if(level > lastlevel){
    lastlevel = level;
    cout<<root->data<<" ";
  }
  leftView(root->left,level+1,lastlevel);
  leftView(root->right,level+1,lastlevel);
}

template <typename T>
void BTree<T>::printLeftView(){
  queue<node<T>*> q;
  q.push(root);
  cout<<"\nleft view of tree:  ";
  while(!q.empty()){
    int size = q.size();
    int i=0;
    while(size--){
      node<T> *temp = q.front();
      q.pop();
      if(i++ == 0)
        cout<<temp->data<<" ";
      if(temp->left)
        q.push(temp->left);
      if(temp->right)
        q.push(temp->right);
    }
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
  t.printLeftView();
  t.leftView();
  t.leftViewMap();
  //t.deleteBT();
  return 0;
}
