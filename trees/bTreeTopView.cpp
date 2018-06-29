#include<iostream>
#include<queue>
#include<map>
#include<utility>
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
  void topView(node<T>*,int,int ,auto &);
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
  void topView(){
    map<int,pair<int,int>> map;
    topView(root,0,0,map);
    cout<<"\ntop view : ";
    for(auto it:map)
      cout<<it.second.first<<" ";
  }
};

template<typename T>
void BTree<T>::topView(node<T>* root,int level,int distance,auto &map){
  if(!root)
    return;
  if(map.find(distance) == map.end() || map[distance].second > level){
    map[distance] = {root->data,level};
  }
  topView(root->left,level+1,distance-1,map);
  topView(root->right,level+1,distance+1,map);
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
  t.topView();
  //t.deleteBT();
  return 0;
}
