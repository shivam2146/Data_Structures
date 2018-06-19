#include<iostream>
#include<queue>
#include<stack>
#include<utility>
using namespace std;

template <typename T>
struct node{
  int data;
  node *left;
  node *right;
};

template <typename T>
class BTree{
  node <T>*root;
  bool isIdentical(node<T> *root1,node<T> *root2);
  bool iIsIdentical(node<T> *root1,node<T> *root2);
public:
  BTree(){
    root = NULL;
  }
  void insert(T data);
  node<T>* getRoot(){
    return root;
  }
  bool isIdentical(BTree<T> t){
      node<T>* r = t.getRoot();
      //return isIdentical(this->root,r);
      return iIsIdentical(this->root,r);
  }
};

template <typename T>
bool BTree<T>::isIdentical(node<T> *root1, node<T> *root2){
  if(root1==NULL && root2==NULL)
    return true;
  if(!(root1 && root2))
    return false;
  if(root1->data != root2->data)
    return false;
  bool left = isIdentical(root1->left,root2->left);
  bool right = isIdentical(root1->right,root2->right);
  return (left&&right);
}

template<typename T>
bool BTree<T>::iIsIdentical(node<T> *root1, node<T> *root2){
  if(root1 == NULL && root2 == NULL)
    return true;
  if(!(root1&&root2))
    return false;
  stack<pair<node<T>*,node<T>*>> st;
  st.push(pair<node<T>*,node<T>*>(root1,root2));
  while(!st.empty()){
    node<T> *x = st.top().first;
    node<T> *y = st.top().second;
    st.pop();
    if(x->data != y->data)
      return false;
    if(x->left && y->left)
      st.push({x->left,y->left});
    else if(x->left || y->left)
      return false;

    if(x->right && y->right)
      st.push({x->right,y->right});
    else if(x->right || y->right)
      return false;
  }
  return true;
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
  BTree<int> t,t1;
  t.insert(5);
  t.insert(10);
  t.insert(2);
  t.insert(3);
  t.insert(15);
  t.insert(11);
  t.insert(19);
  t.insert(12);
  t.insert(17);
  t1.insert(5);
  t1.insert(10);
  t1.insert(2);
  t1.insert(3);
  t1.insert(15);
  t1.insert(11);
  t1.insert(19);
  t1.insert(12);
  t1.insert(17);
  cout<<"\ntrees are "<<(t.isIdentical(t1)?"Identical":"not Identical");
  return 0;
}
